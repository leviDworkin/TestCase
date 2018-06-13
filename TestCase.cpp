#include "TestCase.hpp"

TestCase::TestCase(string _str, ostream& cerr):os(cerr),str(_str){
  failed = passed = 0;
}
void TestCase::print(){
  os<<str<<": "<<failed<<" failed, "<<passed<<" passed, "<<passed+failed<<" total."<<endl<<"---"<<endl;
}
