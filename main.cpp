#include "gnuplot.h"
#include "rrtstar.h"
#include "utils.h"

using namespace std;
int main()
{
	//inititialisation
	std::vector<float> start;
	std::vector<float> goal;
	start.push_back(1);			//Start-x coordinate
	start.push_back(1);			//Start-y coordinate

	goal.push_back(5);			//goal-x coordinate
	goal.push_back(8);			//goal-y coordinate

	int numberOfObstacles = 2;		//number of obstacle boxes
	std::vector<float> obstacles;
	obstacles=readObstacleData(numberOfObstacles);		//Read obstacle coordinates from file

	std::vector<std::vector<float> >path =RRTstar(start,goal,obstacles);	//RRT* algorithm implementation
	
	//Plotting
	string s="";
	gnuplot p; 	//gnuplot class
	int i;

	//draw rectangular boxes for the obstacles
	for(i=0;i<obstacles.size()/4;i++){
		s="set object "+to_string(i+1)+" rect from "+to_string(obstacles[4*i])+","+to_string(obstacles[4*i+1])+" to "+to_string(obstacles[4*i+2])+","+to_string(obstacles[4*i+3]);
		p(s);		
	}
	//Draw green circle for start point
	s="set object "+to_string(i+1)+" circle front at "+to_string(start[0])+","+to_string(start[1])+" size 0.05 fillcolor rgb \"green\" lw 1";
	p(s);
	//Draw red circle for goal point
	s="set object "+to_string(i+2)+" circle front at "+to_string(goal[0])+","+to_string(goal[1])+" size 0.05 fillcolor rgb \"red\" lw 1";
	p(s);
	//Set domain as {0:10} in both x and y
	p("set xrange[0:10]");
	p("set yrange[0:10]");	
	//plot output from RRT*
	p("plot \'results.dat\'");

}