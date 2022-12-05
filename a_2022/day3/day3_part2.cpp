#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>


std::set <char> makeUnique(std::string str)
{
    std::set <char> result;
    for(char ch:str)
    {
        result.insert(ch);
    }
    return result;

}

int main()
{
    std::string bag1,bag2,bag3;
    std::ifstream input("input3.txt");

    if(input.fail()){
        std::cout << "KURA";
    }
    int total = 0;
    while(input >> bag1 && input >> bag2 && input >> bag3)
    {
        std::set<char> a,b,c;
        a = makeUnique(bag1);
        b = makeUnique(bag2);
        c = makeUnique(bag3);

        std::set<char> common12;
        std::set<char> sol;
        std::set_intersection(a.begin(),a.end(),
                              b.begin(),b.end(),
                              std::inserter(common12,common12.begin()));
        std::set_intersection(common12.begin(),common12.end(),
                              c.begin(),c.end(),
                              std::inserter(sol,sol.begin()));
        char ch = *sol.begin();
        if(int(ch)>=97) total += int(ch) - 'a' + 1;
        else total += int(ch) - 38;
    }
    
    std::cout << total;

}