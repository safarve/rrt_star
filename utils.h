#pragma once
#include<vector>
//Euclidean distance([x1,y1],[x2,y2]) = sqrt((x1-x2)^2+(y1-y2)^2)
float euclideanDistance(std::vector<float> v1,std::vector<float> v2);
//Check if a point is inside an obstacle. Return true if inside obstacle else return false
bool checkObstacle(std::vector<float> spot,std::vector<float> box);
//Saves obstacles.dat values into a  vector
std::vector<float> readObstacleData(int size);
//To get a closer point from a random point 
std::vector<float> getCloserPoint(std::vector<float> node, std::vector<float> qrand,float step);
// random point generation
std::vector<float> getRandomPoint(std::vector<float> low,std::vector<float> high);

