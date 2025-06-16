#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN // make main for runing the test
#include "doctest.h"
#include "MyContainer.hpp"
#include <string> 
#include "iostream"


//Checks whether the remove func  work correctly under a variety of conditions
TEST_CASE("MyContainer [remove]") {
    Mycontainer<std::string>a; //   new container 
    a.add("123"); // we will add 2 elemnts 
    a.add("abc");
    a.remove("abc"); // we will remove this element
    CHECK(a.getsize()==1);  //size suppose to be 1
    CHECK_THROWS(a.remove("ttttt"));// not supoose to be found
    CHECK_THROWS(a.remove("AAA"));// not supoose to be found
   Mycontainer<double>b; //   new container 
   b.add(3); // we will add 2 elemnts
   b.add(5);
    CHECK(b.getsize()==2); //size suppose to be 2
    b.remove(3);// remove this elemnts
    CHECK(b.getsize()==1);
    CHECK_THROWS(b.remove(120));// not supoose to be found
    CHECK_THROWS(b.remove(100));// not supoose to be found
}


//Checks whether the size  and  change correctly under a variety of conditions
TEST_CASE("MyContainer [size and add check]") {
    Mycontainer<std::string>a; //   new container 
    a.add("123"); // we will add 3 elemnts 
    a.add("abc");
    a.add("def");
    CHECK(a.getsize()==3);  //size suppose to be 3
   Mycontainer<double>b; //   new container 
   b.add(5); // we will add 2 elemnts
   b.add(44);
    CHECK(b.getsize()==2); //size suppose to be 2
    Mycontainer<> c; //   new container default int
    c.add(12);
    CHECK(c.getsize()==1); //size suppose to be 1
}

TEST_CASE("MyContainer [size and add check]") {
    Mycontainer<std::string>a; //   new container 
    a.add("123"); // we will add 3 elemnts 
    a.add("abc");
    a.add("def");
    std::cout<<a;
}

