#include <iostream>
#include <string>
#include <sstream>

int MAX_RED = 12;
int MAX_GREEN = 13;
int MAX_BLUE = 14;

int main()
{
    std::string string_entry {};
    int temp_val {0};

    unsigned int how_many_games_possible {0};
    unsigned int game_num {0};
    bool isGameValid {false};

    while(getline(std::cin, string_entry))
    {
        game_num += 1;    
        std::stringstream ss {string_entry};
        ss >> string_entry >> string_entry; // ignore Game Num
        while(ss >> temp_val >> string_entry)
        {
            if (string_entry.back() == ',' || string_entry.back() == ';')
                string_entry.pop_back();
                
            if (string_entry == "blue")
            {
                isGameValid = temp_val <= MAX_BLUE;
                // if (!isGameValid)
                //     std::cerr << game_num << ": INVALID BLUE" << '\n';
            }
            else if (string_entry == "red")
            {
                isGameValid = temp_val <= MAX_RED;
                // if (!isGameValid)
                //     std::cerr << game_num << ": INVALID RED" << '\n';
            }
            else if (string_entry == "green")
            {
                isGameValid = temp_val <= MAX_GREEN;    
                // if (!isGameValid)
                //     std::cerr << game_num << ": INVALID GREEN" << '\n';
            }

            if (!isGameValid)
                break;
        }
        if (isGameValid)
        {
            how_many_games_possible += game_num;
            // std::cerr << game_num << '\n';
        }
        else
            continue;

    }
    std::cout << how_many_games_possible << '\n';
}