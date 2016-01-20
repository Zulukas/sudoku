OBJ=driver.o grid.o cell.o
FLAGS=-lcoordinate -std=c++14 -g

a.out: $(OBJ)
	g++ $(OBJ) $(FLAGS)

driver.o: driver.cpp cell.h
	g++ driver.cpp -c $(FLAGS)

grid.o: grid.cpp grid.h cell.h
	g++ grid.cpp -c $(FLAGS)

cell.o: cell.cpp cell.h
	g++ cell.cpp -c $(FLAGS)

clean:
	-rm -f *.o a.out *.cpp~ *.h~