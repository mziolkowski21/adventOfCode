#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{

    std::ifstream input_file("input1.txt");
    std::string calories;
    int sum = 0;
    std::vector <int> top;

    while(std::getline(input_file, calories))
    {   
        if(!calories.empty())
        {
            sum += std::stoi(calories);
        }
        else if(calories.empty())
        {
            top.push_back(sum);
            sum = 0;
        }
    }
    sum =0;
    std::sort(top.begin(),top.end(), std::greater<int>());
    for(unsigned int i=0; i<3; ++i){
        std::cout << top[i] << '\n';
         sum += top[i];
    }
    std::cout << sum;

}