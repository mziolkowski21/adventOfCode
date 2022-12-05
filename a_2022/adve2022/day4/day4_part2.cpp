#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

int main()
{
    using std::string;
    std::ifstream input("input4.txt");
    std::cout << input.is_open() << '\n';
    string line;
    int result = 0;

    while(getline(input, line))
    {
        int r1S, r1E, r2S, r2E;
        std::set<int> set1;
        std::set<int> set2;
        std::vector<int> resultant;

        sscanf(line.c_str(), "%d-%d,%d-%d", &r1S,&r1E,&r2S,&r2E);

        for(int i=r1S; i<=r1E; ++i)
        {
            set1.insert(i);
        }
        for(int i=r2S; i<=r2E; ++i)
        {
            set2.insert(i);
        }

        std::set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),std::inserter(resultant, resultant.begin()));

        // std::cout << '\n';
        // for(int s:resultant){
        //     std::cout << s << ' ';
        // }
        // std::cout << '\n' << resultant.size();

        if (resultant.size() > 0)
        {
            result += 1;
        }


    }
    std::cout << result << '\n';
}