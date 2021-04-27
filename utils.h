#pragma once
#include<vector>

float euclideanDistance(std::vector<float> v1,std::vector<float> v2);
bool checkObstacle(std::vector<float> spot,std::vector<float> box);
std::vector<float> readObstacleData(int size);
std::vector<float> getCloserPoint(std::vector<float> node, std::vector<float> qrand,float step);
std::vector<float> getRandomPoint(std::vector<float> low,std::vector<float> high);

