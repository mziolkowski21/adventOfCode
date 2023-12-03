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
    int total {0};

    while(getline(std::cin, string_entry))
    {
        unsigned int min_red {0};
        unsigned int min_green {0};
        unsigned int min_blue {0};
        std::stringstream ss {string_entry};
        ss >> string_entry >> string_entry; // ignore Game Num
        while(ss >> temp_val >> string_entry)
        {
            if (string_entry.back() == ',' || string_entry.back() == ';')
                string_entry.pop_back();
                
            if (string_entry == "blue" && temp_val > min_blue)
            {
                min_blue = temp_val;
            }
            else if (string_entry == "red" && temp_val > min_red)
            {
               min_red = temp_val;
            }
            else if (string_entry == "green" && temp_val > min_green)
            {
               min_green = temp_val;
            }
        }
        int temp_total = min_blue * min_green * min_red;
        // std::cerr << min_blue << " " << min_green << " " <<  min_red << " = total " << temp_total << '\n';
        total += temp_total;

    }
    std::cout << total << '\n';
}