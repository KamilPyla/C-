# Plik wykonywalny i flagi
EXEC = exec
CXXFLAGS = -g -O0 -Wall -pedantic -std=c++14

$(EXEC): main.o MyList.o
	g++ main.o MyList.o -o $(EXEC)
	
main.o: main.cpp MyList.h
	g++ $(CXXFLAGS) -c main.cpp

MyList.o: MyList.cpp MyList.h
	g++ $(CXXFLAGS) -c MyList.cpp

# Dodatkowe narzędzia
.PHONY: clean run valgrind

clean:
	rm -rf *.o $(EXEC)
	
run: $(EXEC)
	./$(EXEC)
	
valgrind: $(EXEC)
	valgrind ./$(EXEC)
	
