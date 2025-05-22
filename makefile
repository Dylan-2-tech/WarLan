CXX = g++
CXXFLAGS = -std=c++17 -pthread -Wall -Wextra -I./network -I./class 
LDFLAGS = -lenet
SRC = main.cpp \
      network/client.cpp \
      network/server.cpp \
      class/pawn.cpp \
      class/map.cpp

OBJ = $(SRC:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

