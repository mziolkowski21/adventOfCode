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

bool isSymbol(char character);
void map_locations_of_nums_and_symbols(std::vector<Number> &numbers, 
std::vector<std::string> const &inputTable, std::vector<Coords> &symbols);

bool is_adjacent_to_symbol(Number const &num, std::vector<Coords> const &symbols);

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

    for(auto number : numbers)
    {
        // std::cerr << number.number << '\n';

        if (is_adjacent_to_symbol(number, symbols))
        {
            total += number.number;
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
            else if (isSymbol(inputTable[i][j]))
            {
                Coords cord;
                cord.col = i;
                cord.row = j;
                symbols.push_back(cord);
            }
        }
    }
}

bool isSymbol(char character)
{
    return (!isdigit(character) && character != '.');
}

bool is_adjacent_to_symbol(Number const &num, std::vector<Coords> const &symbols)
{
    for(auto symbol : symbols)
    {
        for(auto offset : offsets)
        {
            if (symbol.col + offset.col == num.cords.col && (symbol.row + offset.row >= num.cords.row 
            && symbol.row + offset.row < num.cords.row + num.length))
            {
                // std::cerr << "col: " << offset.col << " row: " << offset.row << '\n'; 
                return true;

            }
        }
    }
    return false;
}