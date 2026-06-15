CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -g
LDFLAGS := $(shell pkg-config --libs raylib)

SRC := src/*.cpp
INC := include/*.hpp
OUT := game

$(OUT): $(SRC) 
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

run: $(OUT)
	./$(OUT)

clean: 
	rm -rf $(OUT)
