#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class TestCase{
  ostream& os;
  string str;
  size_t failed,passed;
  public:
    TestCase(string _str, ostream& cerr);
  	template <typename T> TestCase& check_equal(T a,T b){
      if(a==b){
        passed++;
        return *this;
      }
      failed++;
      ostringstream oss;
      oss<<str<<": Failure in test #"<<passed+failed<<": "<<a<<" should equal "<<b<<"!"<<endl;
      os.write(oss.str().c_str(), oss.str().size());
      return *this;
    }
  	template <typename T> TestCase& check_different(T a,T b){
      if(a!=b){
        passed++;
        return *this;
      }
      failed++;
      ostringstream oss;
      oss<<str<<": Failure in test #"<<passed+failed<<": "<<a<<" should differ than "<<b<<"!"<<endl;
      os.write(oss.str().c_str(), oss.str().size());
      return *this;
    }
  	template <typename T,typename T1,typename T2> TestCase& check_function(T foo, T1 a, T2 b){
      T2 c = foo(a);
      if(b==c){
        passed++;
        return *this;
      }
      failed++;
      ostringstream oss;
      oss<<str<<": Failure in test #"<<passed+failed<<": Function should return "<<b<<" but returned "<<c<<"!"<<endl;
      os.write(oss.str().c_str(), oss.str().size());
      return *this;
    }
    template <typename T> TestCase& check_output(T a, string str){
      ostringstream oss,check;
      check<<a;
      if(check.str()==str){
        passed++;
        return *this;
      }
      failed++;
      oss<<str<<": Failure in test #"<<passed+failed<<": string value should be "<<a<<" but is "<<str<<endl;
      os.write(oss.str().c_str(), oss.str().size());
      return *this;
    }
    void print();
};
