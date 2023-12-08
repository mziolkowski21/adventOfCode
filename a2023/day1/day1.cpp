#include <iostream>
#include <string>
#include <vector>



int main()
{
    std::string input_line {};
    int sum {0};
    while(std::getline(std::cin, input_line))
    {
        std::vector<char> my_list {};
        std::string number {};
        for(char c : input_line)
        {
            if(std::isdigit(c))
            {
                my_list.push_back(c);
                // std::cerr << c << '\n';
            }
        }
        number = number + my_list.front() + my_list.back();
        // std::cerr << number << '\n';
        sum += stoi(number);
    }
    std::cout << sum << '\n';
}