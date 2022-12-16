#include <iostream>
#include <regex> // istnieje
#include <fstream>
#include <vector>

struct Entry {
    unsigned id;
    unsigned x,y;
    unsigned width,height;

    void printOut(); // method - a function in the class
};

void Entry::printOut()
{
    std::cout << "id: " << id << ", (x, y): " << x << ", " << y
            << ", (w,h): " << width << ", " << height << '\n';
}


int main()
{

    std::ifstream input("input3.txt");
    // std::vector <Entry> entries;
    Entry e;

    std::cin.ignore();
    std::cin >> e.id;
    /*
    algorytm jak działa dla zczytywania liczb
    char symbol;
    std::cin >> symbol;
    while (symbol >= '0' && symbol <= '9') {
        e.id = e.id * 10 + symbol - '0';
        std::cin >> symbol;
        }
    */

    std::cin.ignore(3);
    std::cin >> e.x;
    std::cin.ignore();
    std::cin >> e.y;
    std::cin.ignore(2); // could ignore(1) (space), cin ignores white characters
    std::cin >> e.width;
    std::cin.ignore();
    std::cin >> e.height;

    // >> - formated input

    e.printOut();

    return 0;
}
