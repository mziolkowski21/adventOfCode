#include <iostream>
#include <string>
#include <map>

int MAX_RED = 12;
int MAX_GREEN = 13;
int MAX_BLUE = 14;


int main()
{
    std::string string_entry {};
    std::map <std::string, unsigned int> color_value_map {};
    int temp_val {0};

    unsigned int how_many_games_possible {0};
    unsigned int game_num {0};

    while(std::cin >> string_entry)
    {
        // std::cerr << string_entry << '\n';
        if (string_entry == "Game")
        {   
            

            if (color_value_map["blue"] <= MAX_BLUE &&
            color_value_map["red"] <= MAX_RED &&
            color_value_map["green"] <= MAX_GREEN && game_num != 0)
            {
                how_many_games_possible += game_num;
                std::cerr << "game_num: " << game_num <<  " blue: " << color_value_map["blue"] << " green: " << color_value_map["green"] << " red: " << color_value_map["red"] << '\n';
            }

            game_num += 1;
            color_value_map.clear();

            std::cin >> string_entry;
            // std::cerr << string_entry << '\n';
            continue;
        }
        else
        {
            temp_val = stoi(string_entry);
            std::cin >> string_entry;
            if (string_entry.back() == ',' || string_entry.back() == ';')
                string_entry.pop_back();

            if(color_value_map.find(string_entry) != color_value_map.end())
                color_value_map.insert_or_assign(string_entry, temp_val+color_value_map[string_entry]);
            else    
                color_value_map.insert_or_assign(string_entry, temp_val);
        }
    }

    // last game
    if (color_value_map["blue"] <= MAX_BLUE &&
    color_value_map["red"] <= MAX_RED &&
    color_value_map["green"] <= MAX_GREEN && game_num != 1)
    {
        how_many_games_possible += game_num;
        std::cerr << "game_num: " << game_num <<  " blue: " << color_value_map["blue"] << " green: " << color_value_map["green"] << " red: " << color_value_map["red"] << '\n';
    }

    std::cout << how_many_games_possible << '\n';


}