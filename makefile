CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -g
CPPFLAGS := -Iinclude
LDFLAGS := $(shell pkg-config --libs raylib)

SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp,build/%.o,$(SRC))
OUT := game

$(OUT): $(OBJ) 
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

run: $(OUT)
	./$(OUT)

clean: 
	rm -rf build $(OUT)
