#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class TestCase{
  std::string str;
  std::ostream cerr;
  public:
    TestCase(std::string _str, std::ostream cerr);
  	TestCase& check_equal(T& a,T& b);                  // check operator ==. Here there is no bug.
  	TestCase& check_different(T& a,T& b);             // check operator !=. Here there is no bug.
  	TestCase& check_function(void* (foo)(T& a, T& b), T& a, T& b);      // check a function int->int.     Here there is no bug.
    TestCase& check_output(T& a, std::string str);    // check output operator <<
  	TestCase& print();//prints str first
};
