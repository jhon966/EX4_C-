
CXX = g++
CXXFLAGS = -Wall -Wextra -g

MAIN = main
TESTS = tests

all: $(MAIN) $(TESTS)

$(MAIN): main.cpp Mycontainer.hpp
	$(CXX) $(CXXFLAGS) -o $(MAIN) main.cpp

$(TESTS): tests.cpp Mycontainer.hpp
	$(CXX) $(CXXFLAGS) -o $(TESTS) tests.cpp

make Main: $(MAIN)
	./$(MAIN)

make valgrind: $(MAIN)
	valgrind ./$(MAIN)

make test: $(TESTS)
	./$(TESTS)

clean:
	rm -f $(MAIN) $(TESTS)
