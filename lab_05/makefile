# Plik wykonywalny i flagi
EXEC = exec
CXX = g++
CXXFLAGS = -g -O0 -Wall -pedantic -std=c++14
LIBS = -lm

# Czarna magia :)
SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $+ $(LIBS) -o $@

-include $(DEPS)

# Dodatkowe narzędzia
.PHONY: clean run valgrind

clean:
	rm -rf *.o *.d $(EXEC)
	
run: $(EXEC)
	./$(EXEC)
	
valgrind: $(EXEC)
	valgrind ./$(EXEC)
	
