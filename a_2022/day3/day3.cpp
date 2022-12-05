#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>

int main()
{
    std::string bag;
    std::ifstream input("input3.txt");

    if(input.fail()){
        std::cout << "KURA";
    }
    int total =0;

    while(input >> bag)
    {
        std::set<char> a, b;
        for(char ch: bag.substr(0,bag.size()/2))
        {
            a.insert(ch);
        }
        for(char ch: bag.substr(bag.size()/2,bag.size()))
        {
            b.insert(ch);
        }

        std::vector<char> sol;
        std::set_intersection(a.begin(),a.end(),
                              b.begin(),b.end(),
                              std::back_inserter(sol));
        char ch = *sol.begin();
        if(int(ch)>=97) total += int(ch) - 'a' + 1;
        else total += int(ch) - 38;
    }
    std::cout << total;

}