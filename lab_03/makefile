# Plik wykonywalny i flagi
EXEC = exec
CXXFLAGS = -g -O0 -Wall -pedantic -std=c++14

$(EXEC): main.o MapPoint.o
	g++ main.o MapPoint.o -o $(EXEC)
	
main.o: main.cpp MapPoint.h
	g++ $(CXXFLAGS) -c main.cpp

MapPoint.o: MapPoint.cpp MapPoint.h
	g++ $(CXXFLAGS) -c MapPoint.cpp

# Dodatkowe narzędzia
#.PHONY: clean run valgrind

clean:
	rm -rf *.o $(EXEC)
	
run: $(EXEC)
	./$(EXEC)
	
valgrind: $(EXEC)
	valgrind ./$(EXEC)
	
