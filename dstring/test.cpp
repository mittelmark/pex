///usr/bin/g++ -o "${0%.cpp}" dstring.cpp "$0" && exec "${0%.cpp}"
// compile with g++ dstring.cpp test.cpp -o test
#include <iostream> 
#include <filesystem>
#include "dstring.hpp"

int main(int argc, char** argv) {
    pex::dstring hello = "Hello";
    std::string world = "World";
    std::cout << "hello starts with hel? " << hello.starts_with("hel") << std::endl;
    std::cout << "hello == world?        " << (hello == world) << std::endl;
    std::cout << "hello != world?        " << (hello != world) << std::endl;
    std::cout << "length of std::string: " << hello.get().length() << std::endl;
  return(0);
} 
