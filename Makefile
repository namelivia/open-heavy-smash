CPP_FILES := $(shell find ./src -name *.cpp)
OBJ_FILES := $(CPP_FILES:%.cpp=%.o)

run: $(OBJ_FILES)
	g++ -lSDL2 -o $@ $^

%.o: %.cpp
	g++ -c -o $@ $<

clean:
	rm $(OBJ_FILES)
