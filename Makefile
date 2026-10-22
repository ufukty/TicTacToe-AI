CXX      := g++
CXXFLAGS := -std=c++17 -Wall -O2 -MMD -MP
SRCS     := $(wildcard src/*.cpp)
OBJS     := $(SRCS:src/%.cpp=obj/%.o)

build/TicTacToe: $(OBJS)
	mkdir -p build
	$(CXX) $^ -o $@

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)