
out: main.o rrtstar.o utils.o
	g++ main.o rrtstar.o utils.o -o out

main.o: main.cpp
	g++ -c main.cpp
rrtstar.o: rrtstar.cpp rrtstar.h
	g++ -c rrtstar.cpp
utils.o: utils.cpp utils.h
	g++ -c utils.cpp
	
clean:
	rm *.o out