# rrt_star

Implementation of RRT* algorithm on a 2-D space with a domain of [0,10] X [0,10]
* main.cpp -> Driver code. Contains values of start,goal and obstacle number.
* obstacles.dat -> Input data for obstacles, which are modelled as rectangles. Each obstacle requires 2 corner points in the order <br />{x1 y1}\n{x2 y2}.
* results.dat->Contains the path from start to goal in the format: <br />{x1 y1}\n{x2 y2}\n{x2 y2}....{xn yn}
*  rrtstar.cpp->Contains class definitions of a node and a random tree. 
*  utils.cpp->Contians some helper functions

#### Plotting ####
* [gnuplot](http://www.gnuplot.info/) is used to plot the resulting path and obstacles

#### how to run ####
* The makefile contains necessary commands to compile and clean
```
make
./out
```
