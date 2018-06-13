CXX = clang++-5.0
CXXFLAGS = -std=c++17
a.out: main.o TestCase.o
	$(CXX) $(CXXFLAGS) main.o TestCase.o -o a.out
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
TestCase.o: TestCase.cpp TestCase.hpp
	$(CXX) $(CXXFLAGS) -c TestCase.cpp
clean:
	rm *.o a.out
