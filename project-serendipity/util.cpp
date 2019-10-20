#include <iostream>
#include <cstddef>
#include "util.hpp"
#include "bookdata.hpp"

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
