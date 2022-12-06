#include <iostream>
#include <fstream>
#include <string>
#include <set>


int main()
{
    std::ifstream input("input6.txt");
    std::string buffer;

    std::getline(input,buffer);

    // int n = 4; //part1
    int n =14; // part2

    for(int i=0; i<buffer.length()-n; ++i)
    {
        std::string myString = buffer.substr(i,n);
        std::set <char> unique(begin(myString),end(myString));
        if(unique.size() == n)
        {
            std::cout << i+n << '\n';
            std::cout << buffer.substr(i,n) << '\n';
            return 0;
        }
    }

}