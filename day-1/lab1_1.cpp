// Compile with:
// gcc -o main.o lab1_1.cpp

#include <iostream>

//remember to include string class 
#include <string> 

#include "util.hpp"

int main(){
    std::string city;

    city = util::getCity();

    util::showCity(city);
  
    //system("pause") for Visual Studio Compiler (-_-)
    return 0;
}

// gcc lab1_1.cpp util.cpp -o main.o