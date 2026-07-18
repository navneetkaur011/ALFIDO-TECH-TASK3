# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

# Output executable name
TARGET = university_hostel

# Source files and objects
SRC = src/main.cpp src/Hostel.cpp
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Clean up build files
clean:
	rm -f src/*.o $(TARGET)