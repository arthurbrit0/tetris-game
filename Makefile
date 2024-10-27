# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Libraries and dependencies
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Source files
SRC = ./src/main.cpp ./src/grid.cpp ./src/block.cpp ./src/position.cpp ./src/colors.cpp ./src/game.cpp

# Output executable
OUT = main

# Build target
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LIBS)

# Clean target to remove the executable
clean:
	rm -f $(OUT)
