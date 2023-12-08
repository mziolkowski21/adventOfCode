#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main ()
{
    std::string line_input;
    std::vector <int> winning_numbers {};
    int owned_num {0};    
    int total_score {0};

    while(std::getline(std::cin, line_input))
    {
        std::stringstream ss {line_input};
        ss >> line_input >> line_input; // skip "Card x:"
        int number_times_won {0};
        int score {0};


        while(ss >> line_input)
        {
            if (isdigit(line_input[0]))
            {
                winning_numbers.push_back(stoi(line_input));
            }
            else // |
            {
                break;
            }
        }
        while(ss >> owned_num)
        {
            // std::cout << owned_num << '\n';
            if (std::find(winning_numbers.begin(), winning_numbers.end(), owned_num) != winning_numbers.end())
            {
                number_times_won++;
                score = std::pow(2,number_times_won-1);
                // std::cerr << score << '\n';
            }
        }
        
        total_score += score;
        winning_numbers.clear();
    }
    std::cout << total_score << '\n';
}