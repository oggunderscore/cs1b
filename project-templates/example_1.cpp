#include <iostream>

using namespace std;

template <class bucky>

bucky addCrap(bucky a, bucky b) {
    return a + b;
}

int main () {
    int x = 7;
    int y = 43;
    int z;

    double a = 4.5;
    double b = 27.8;
    double c;

    char w = 'a';
    char t = 'b';
    char u;

    string s = "Hello ";
    string p = "World";
    string q;

    z = addCrap(x, y);
    cout << z << endl;

    c = addCrap(a, b);
    cout << c << endl;

    u = addCrap(w, t);
    cout << u << endl;

    q = addCrap(s, p);
    cout << q << endl;

}
