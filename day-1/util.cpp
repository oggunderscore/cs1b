#include <iostream>
#include <string>

//organize things more with a path
#include "util.hpp"

using namespace std;

namespace util {
    string getCity(){
        string city; 

        cout << "What city do you live in?";
        //google how to use this...probably better than cin
        getline(cin, city);

        return city; 
    }

    void showCity(string city){
        cout << "So you live in " << city << ".\n\n";     
    }
}