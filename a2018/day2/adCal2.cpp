#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>

int main()
{
    std::ifstream input_file("inputDay2.txt");
    if(input_file.fail())
    {
        std::cout << "no such file";
        return 0;
    }

    int thrice = 0;
    int twice = 0;

    std::string inputString;
    while(input_file >> inputString)
    {
        std::set<char> singleOccurance(begin(inputString),end(inputString));
        std::vector<char> myVec(begin(inputString),end(inputString));

        for(auto elems: myVec)
        {
            std::cout << elems;
        }
        std::cout << '\n';

        for(auto elems: singleOccurance)
        {
            int counter = std::count(myVec.begin(),myVec.end(),elems);
            if(counter == 3)
            {
                //std::cout << elems << " occurs exactly 3 times\n";
                thrice += 1;
                continue;
            }
            else if(counter == 2)
            {
                //std::cout << elems << " occurs exactly 2 times\n";
                twice += 1;
                break;
            }
        }
    }

    std::cout << "Twice * thrice = " << twice << "*" << thrice << " = " << twice*thrice << '\n';


}