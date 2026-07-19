CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

TARGET = university_hostel
 
SRC = src/main.cpp src/hostel.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -f src/*.o $(TARGET)