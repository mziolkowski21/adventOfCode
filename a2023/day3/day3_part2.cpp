#include <iostream>
#include <vector>
#include <string>

struct Coords
{
    int col;
    int row;
};

struct Number 
{
    Coords cords {};
    int number;
    int length; 
};                                        

const std::vector<Coords> offsets{ 
    {-1, -1}, //  top left
    {-1, 0}, //  top
    {-1, 1}, //  top right
    {0, -1}, //  left
    {0, 1}, //  right
    {1, -1}, //  bottom left
    {1, 0}, //  bottom
    {1, 1} //  right
};

bool isGear(char character);
void map_locations_of_nums_and_symbols(std::vector<Number> &numbers, 
std::vector<std::string> const &inputTable, std::vector<Coords> &symbols);
std::pair <int, std::vector<int>> how_many_times_adjacent_to_gear(std::vector<Number> const &nums, Coords const &symbol, std::vector<std::string> const &inputTable);

int main()
{
    std::string row {};
    std::vector <std::string> inputTable {};
    std::vector <Number> numbers;
    std::vector <Coords> symbols;
    std::vector<bool> is_direction_available_vec {};
    int total {0};

    while(getline(std::cin, row))
    {
        inputTable.push_back(row);
    }

    map_locations_of_nums_and_symbols(numbers, inputTable, symbols);

    for(auto symbol : symbols)
    {
        // std::cerr << number.number << '\n';
        
        std::pair <int, std::vector<int>> adjacent = how_many_times_adjacent_to_gear(numbers, symbol, inputTable);
        if(adjacent.first == 2)
        {
            total += adjacent.second[0] * adjacent.second[1];    
        }
    }

    std::cout << total << '\n';
}


void map_locations_of_nums_and_symbols(std::vector<Number> &numbers, 
std::vector<std::string> const &inputTable, std::vector<Coords> &symbols)
{ 
    for(unsigned int i = 0; i < inputTable.size(); ++i)
    {
        for(unsigned int j = 0; j < inputTable[i].length(); ++j)
        {

            if(isdigit(inputTable[i][j]))
            {
                Number num;
                std::string num_representation {inputTable[i][j]};
                num.cords.col = i;
                num.cords.row = j;
                num.length = 1;
                ++j;
                while(isdigit(inputTable[i][j]))
                {
                    num_representation.push_back(inputTable[i][j]);
                    ++j;
                    ++num.length;
                }
                num.number = stoi(num_representation);
                numbers.push_back(num);
                --j; // fix indexing
            }
            else if (isGear(inputTable[i][j]))
            {
                Coords cord;
                cord.col = i;
                cord.row = j;
                symbols.push_back(cord);
            }
        }
    }
}

bool isGear(char character)
{
    return (character == '*');
}

std::pair <int, std::vector<int>> how_many_times_adjacent_to_gear(std::vector<Number> const &nums, Coords const &symbol, std::vector<std::string> const &inputTable)
{
    int total {0};
    bool is_adjacent {false};
    std::vector<int> adjacentNums {};
    for(auto num : nums)
    {
        is_adjacent = false;
        for(auto offset : offsets)
        {
            for (int i = 0; i < num.length; ++i)
            {
                if (num.cords.col + offset.col == symbol.col &&
                 (num.cords.row + offset.row + i == symbol.row) && !is_adjacent)
                {
                    is_adjacent = true;
                    adjacentNums.push_back(num.number);
                    total++;
                }
            }
        }
    }
    
    std::cerr << "(" << symbol.col << ',' << symbol.row << ") adjacent " << total << " times" << '\n';
    return std::pair<int, std::vector<int>> {total, adjacentNums};
}

