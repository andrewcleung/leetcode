# Define variables
CXX := g++
CXXFLAGS := -fsanitize=address -g
OUTPUT := test

build:
	@echo "Building $(INPUT)..."
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(IN)