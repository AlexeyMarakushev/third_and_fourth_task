CXX = g++
CXXFLAGS = -Wall

ifdef DEBUG
CXXFLAGS += -g
endif

TARGET = a.exe
OBJ = main.o list.o 

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

main.o: main.cpp list.h
	$(CXX) $(CXXFLAGS) -c main.cpp

list.o: list.cpp list.h
	$(CXX) $(CXXFLAGS) -c list.cpp

clean:
	rm -f $(OBJ) $(TARGET)
