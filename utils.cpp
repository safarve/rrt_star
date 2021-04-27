#include<iostream>
#include <math.h>
#include <fstream>
#include "utils.h"
using namespace std;
//Euclidean distance([x1,y1],[x2,y2]) = sqrt((x1-x2)^2+(y1-y2)^2)
float euclideanDistance(std::vector<float> v1,std::vector<float> v2)
{
  float distance=0;
  for (int i=0;i<2;i++)
    distance+=((v1[i]-v2[i]))*((v1[i]-v2[i]));
  return sqrt(distance);
}

//Check if a point is inside an obstacle. Return true if inside obstacle else return false
bool checkObstacle(std::vector<float> spot,std::vector<float> box)
{
  for(int i=0;i<box.size()/4;i++){
  	if(spot[0]>box[4*i]&&spot[0]<box[4*i+2]&&spot[1]>box[4*i+1]&&spot[1]<box[4*i+3])
      return true;  
  }
  
  return false;
}

//Saves obstacles.dat values into a  vector
std::vector<float> readObstacleData(int size){
	size=2*size;
	ifstream inputFile;
	std::vector<float> obstacles;
	float temp;
	inputFile.open("obstacles.dat");
	if (inputFile.is_open()){

		for(int i=0;i<size*2;i++){
		inputFile>>temp; 
		obstacles.push_back(temp);
		}
	}
	inputFile.close();
	return(obstacles);
}

//To get a closer point from a random point 
std::vector<float> getCloserPoint(std::vector<float> node, std::vector<float> qrand,float step)
{
  std::vector<float> v;
  float x;
  x=step/euclideanDistance(qrand,node);
  for(int i=0;i<2;i++)
    v.push_back(node[i]+((qrand[i]-node[i])*x));
  return v;
}

// random point generation
std::vector<float> getRandomPoint(std::vector<float> low,std::vector<float> high)
{

  std::vector<float> point;
  for(int i=0;i<2;i++)
    point.push_back((((float)rand()/RAND_MAX)*(high[i]-low[i]))+low[i]);
  return point;
}