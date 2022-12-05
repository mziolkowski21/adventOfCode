#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> extractIntegerWords(std::string str)
{
    std::cout << str << '\n';
    std::stringstream ss;
    std::vector <int> result;
    /* Storing the whole string into string stream */
    ss << str;
 
    /* Running loop till the end of the stream */
    std::string temp;
    int found;
    while (!ss.eof()) {
 
        /* extracting word by word from stream */
        ss >> temp;
 
        /* Checking the given word is integer or not */
        if (std::stringstream(temp) >> found)
        {
            result.push_back(found);        
        }
        /* To save from space at the end of string */
        temp = "";
        
    }

    return result;
}

int main()
{
    // int boxSize = 3;
    // int space = 1;
    std::string rowString;
    std::vector<std::string> boxes;
    std::vector<std::string> moves;
    std::ifstream input("input5.txt");
    int i = 0;
    while(std::getline(input, rowString))
    {
        if(i<8) boxes.push_back(rowString);
        if(i>9) moves.push_back(rowString); 
        i++;
    }
    std::cout << *moves.begin() << '\n';

    for(std::string move: moves)
    {
        int rows = boxes.size();
        int cols = 9; 
        std::vector <int> processed;
        processed = extractIntegerWords(move);
        
        for(int a:processed)
        {
            std::cout << a << " ";
        }
        std::cout << '\n';
    }
    
    

}