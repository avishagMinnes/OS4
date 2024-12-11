# Compiler
CXX = g++
CC = gcc

# Compiler flags
CXXFLAGS = -g -Wall -lpthread
CFLAGS = -g -Wall -lpthread

# Targets
TARGETS = singleton race guard_example graph

# All target
all: $(TARGETS)

# Singleton target
singleton: singleton.o
	$(CXX) -o singleton singleton.o $(CXXFLAGS)

singleton.o: singleton.cpp
	$(CXX) -c singleton.cpp $(CXXFLAGS)

# Race condition target
race: race.o
	$(CC) -o race race.o $(CFLAGS)

race.o: race.c
	$(CC) -c race.c $(CFLAGS)

# Guard example target
guard_example: guard.o
	$(CXX) -o guard_example guard.o $(CXXFLAGS)

guard.o: guard.cpp
	$(CXX) -c guard.cpp $(CXXFLAGS)

# Graph target
graph: graph3.o
	$(CXX) -o graph graph3.o $(CXXFLAGS)

graph3.o: graph3.cpp
	$(CXX) -c graph3.cpp $(CXXFLAGS)

# Clean target
clean:
	rm -f *.o $(TARGETS)

# Valgrind target for race condition
valgrind_race: race
	valgrind --tool=helgrind ./race

# GDB target for race condition
gdb_race: race
	valgrind --vgdb=yes --vgdb-error=0 ./race

# Phony targets
.PHONY: all clean valgrind_race gdb_race


