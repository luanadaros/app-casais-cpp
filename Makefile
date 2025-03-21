CXX = g++
CXXFLAGS = -Wall -Wextra -Wunused-parameter -std=c++17 -g

SRCS = $(wildcard *.cpp) $(wildcard */*.cpp */*/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all: prog

objs: $(OBJS)

prog: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS): %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: prog
	valgrind --leak-check=full --show-leak-kinds=all ./prog

clean:
	rm -f $(OBJS) prog
