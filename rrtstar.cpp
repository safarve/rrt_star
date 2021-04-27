#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <string>  
#include <iostream>
#include "rrtstar.h"
#include "utils.h"
using namespace std;

bool Node::operator==(Node n)
{
  std::vector<float> temp=n.gridPoint;
  for(unsigned int i=0;i<2;i++)
    if(gridPoint[i]!=temp[i])
      return false;
  return true;
}

void Node::display()
{
  for(int i=0;i<2;i++)
    cout<<gridPoint[i]<<",";
    cout<<endl;
}
   
void nodeTree::addNode(Node* n)
{
  list.push_back(n);
}
    
Node* nodeTree::nearestNeighbour(std::vector<float> qrand)
{
  Node *a;
  float distance;
  //maximum distance defined as distance from start point
  float min=euclideanDistance(list[0]->gridPoint,qrand);
  a=list[0];
  for (int i=1;i<list.size();i++)
  {
    distance=euclideanDistance(list[i]->gridPoint,qrand);
    if(distance<min)
    {
      min=distance;
      a=list[i];
    }
  }
  return a;
}

std::vector<std::vector<float> > nodeTree::getPath()
{
  Node* a;
  std::vector<std::vector<float> > path;
      
  a=list[list.size()-1];
  while(a->parent!=NULL)
  {
    path.push_back(a->gridPoint);
    a=a->parent;
  }
  path.push_back(a->gridPoint);
  return path;
}

Node* nodeTree::improveParent(std::vector<float> point,float neighbourhoodRadius)
{
  std::vector<Node*> neighbourhood;
  float leastCost;
  int i,index;
  for (i=0;i<list.size();i++)
    if (euclideanDistance(point,list[i]->gridPoint)<=neighbourhoodRadius)
      neighbourhood.push_back(list[i]);

  leastCost=neighbourhood[0]->cost;
  index=0;
  for(i=1;i<neighbourhood.size();i++)
  {
    if(neighbourhood[i]->cost<leastCost)
    {
      leastCost=neighbourhood[i]->cost;
      index=i;
    }
  }
  return neighbourhood[index];
}

// RRT star algorithm
std::vector<std::vector<float> > RRTstar(std::vector<float> start,std::vector<float>goal,std::vector<float>obstacles,float goalBias,float step,float stepCost)
{
  // initializations 
  Node *node,*intermediateNode,*startNode,*parentNode;
  startNode=new Node;
  startNode->gridPoint=start;
  startNode->parent=NULL;
  startNode->cost=0;
  nodeTree tree;
  //add start node
  tree.addNode(startNode); 
  
  std::vector<std::vector<float> > path;  //vector to store output 

  std::vector<float> qrand;   //Random point 
  std::vector<float> closerPoint; //In case random point is farther then stepsize 
  std::vector<float> low(2,0),high(2,10); //Define domain for random point generation
  
  int i,j;  //iterative var
  bool goalReached=false;  //boolean to check if goal is reached

  while(!goalReached)
  {
    if((float)rand()/RAND_MAX<goalBias) // to bias random number generation towards goal
    {
      qrand=goal; 
      goalReached= true;
    }
    else
    {
      qrand=getRandomPoint(low,high); // else choose random point
    }

    node=tree.nearestNeighbour(qrand);  //Find the nearest node

    if (euclideanDistance(qrand,node->gridPoint)<=step) //Check if the random point is within step size
    {
      if(checkObstacle(qrand,obstacles))  //Check obstacles
        continue;
      if (goalReached)
        cout<<"goal reached"<<endl;
      else
        goalReached=false;
      parentNode=tree.improveParent(qrand); //Find better parent node
      //Initialise new node
      intermediateNode=new Node;
      intermediateNode->gridPoint = qrand;
      intermediateNode->parent=parentNode;
      intermediateNode->cost = parentNode->cost+stepCost;
    }
    //If the random point is farther than stepsize...
    else
    {
      goalReached=false;
      closerPoint=getCloserPoint(node->gridPoint,qrand,step); 
      if(checkObstacle(closerPoint,obstacles))
        continue;
      parentNode=tree.improveParent(closerPoint);
      intermediateNode=new Node;
      intermediateNode->gridPoint = closerPoint;
      intermediateNode->parent=parentNode;
      intermediateNode->cost = parentNode->cost+stepCost;
    }
    //Add the new node to the tree
    tree.addNode(intermediateNode); 
    if(!(node==parentNode))
    {
        node->parent=intermediateNode; // rewire the tree
    }
   
  };
  path=tree.getPath();  //store result of the rrt* 
  std::reverse(path.begin(),path.end()); //reverse the path so it is form start to goal
  //Store the results into results.dat file
  ofstream MyFile("results.dat"); 
    for(i=0;i<path.size();i++)
  {
    for (j=0;j<path[i].size();j++)
      MyFile<<path[i][j]<<" ";
    MyFile<<endl;
  }
  MyFile.close();
  return path;
}
