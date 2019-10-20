#include <iostream>
#include <cstddef>
#include "util.hpp"
#include "bookdata.hpp"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//using namespace std;

void pause()
{
#ifdef _WIN32
    // pause on windows
    system("pause");
#else
    // on unix systems, read one character and then continue
    system("read -n 1 -s -p \"\t\t\t\t        Press any key to continue...\"");
#endif
}

size_t findCaseInsensitive(std::string data, std::string target)
{
    int position = 0;
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    transform(target.begin(), target.end(), target.begin(), ::tolower);
    return data.find(target, position);
}


bookType** bookValueToPointer(bookType array[]) {
    bookType** pointerBooks = new bookType*[20];

    for (int i = 0; i < 20; i++) {
        pointerBooks[i] = &array[i];
    }

    return pointerBooks;
}

void testKeyboard() {
    int c = 0;
    while(1)
    {
        c = 0;

        switch((c= getch ())) {
        case KEY_UP:
            cout << endl << "Up" << endl;//key up
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            break;
        case KEY_LEFT:
            cout << endl << "Left" << endl;  // key left
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;  // key right
            break;
        default:
            cout << endl << "null" << endl;  // not arrow
            break;
        }
}
