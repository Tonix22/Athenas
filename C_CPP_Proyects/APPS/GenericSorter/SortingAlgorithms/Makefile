
CXX=g++
OBJ_FOLDER=obj
OBJS=BubbleSort.o main.o

SRC=$(wildcard $(.)/*.cpp)
OBJS=$(patsubst($(.)/*.cpp,$(OBJ)/%.o,$(SRC))

all : main

main : $(OBJ_FOLDER)/$(OBJS)
	$(CXX) $(OBJ_FOLDER)/$(OBJS) -o $@

$(OBJ_FOLDER)/%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm $(OBJ_FOLDER)/*.o