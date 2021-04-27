#pragma once
#include <vector>
/*Node class
1.gridpoint -> Vector with 2 elements--{x,y}
2.parent -> pointer to previous node
3.cost -> cumulative cost calculated  
4.display()-> print gridpoint seperated by a comma
*/
class Node
{
	public:
  std::vector<float> gridPoint;
  Node *parent;
  float cost;

  
    // to compare 2 nodes
    bool operator==(Node n);

     // displaying a node
    void display();

};
/*RRT tree class--a linked list
1.addNode(input:pointer to the node)-> Add a new node pointer to the list
2.nearestNeighbour(input:vector containing cordinates of the point)-> for a given outside point find the nearest node in the tree
3.getPath()->Output a 2D vector with points from goal to start
4.improveParent(input:vector containing cordinates of the point)->
*/
class nodeTree
{
  
  public:
  	std::vector<Node*> list;

    
    void addNode(Node* n);
    Node* nearestNeighbour(std::vector<float> qrand);
    std::vector<std::vector<float> > getPath();
    Node* improveParent(std::vector<float> point,float neighbourhoodRadius=0.15);

};
std::vector<std::vector<float> > RRTstar(std::vector<float> start,std::vector<float>goal,std::vector<float>obstacles,float goalBias=0.3,float step=0.1,float stepCost=0.1);



