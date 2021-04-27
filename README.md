# rrt_star

Implementation of RRT* algorithm on a 2-D space with a domain of [0,10] X [0,10]
#### How to inpurt start, goal states and obstacles
* main.cpp -> contains variables that store start,goal and obstacle number.
* obstacles.dat -> Input data for obstacles, which are modelled as rectangles. Each obstacle requires 2 corner points in the order <br />{x1 y1}\n{x2 y2}.
* results.dat->Contains the path from start to goal in the format: <br />{x1 y1}\n{x2 y2}\n{x2 y2}....{xn yn}
* 
#### How to run ####
* The makefile contains necessary commands to compile and clean
```
make
./out
```
#### Plotting ####
* [gnuplot](http://www.gnuplot.info/) is used to plot the resulting path and obstacles
![picture alt](https://github.com/safarve/rrt_star/blob/main/plot1.png "A demo plot")


