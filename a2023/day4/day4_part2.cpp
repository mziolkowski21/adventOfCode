#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

int main ()
{
    std::string line_input;
    std::vector <int> winning_numbers {};
    // std::vector <int> possesed_numbers {};
    int card_number {1};
    std::map <int, int> how_many_cards_copied {};
    int checked_num {0};


    while(std::getline(std::cin, line_input))
    {
        int number_times_won {0};
        std::stringstream ss {line_input};
        ss >> line_input >> line_input; // skip "Card x:"    

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
        while(ss >> checked_num)
        {
            if (std::find(winning_numbers.begin(), winning_numbers.end(), checked_num) != winning_numbers.end())
                number_times_won++;
            // possesed_numbers.push_back(checked_num);
        }        
        // for(int num : possesed_numbers)
        // {
        //     if (std::find(winning_numbers.begin(), winning_numbers.end(), num) != winning_numbers.end())
        //     {
        //         number_times_won++;
        //     }
        // }


        how_many_cards_copied[card_number]++;
        for(int j = card_number + 1; j <= card_number + number_times_won; j++)
        {
            how_many_cards_copied[j] += how_many_cards_copied[card_number]; 
        }

        card_number++;
        winning_numbers.clear();
    }

    int amount_of_cards_won {0};
    for(auto elem : how_many_cards_copied)
    {
        std::cerr << "Card " << elem.first << ": " << elem.second << " won" << '\n'; 
        amount_of_cards_won += elem.second;
    }
    std::cout << amount_of_cards_won << '\n';
}