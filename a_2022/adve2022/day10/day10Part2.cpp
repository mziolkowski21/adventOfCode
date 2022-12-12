#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>

void displayDisplay(const std::vector<std::string> &myVec)
{
    for(std::string a : myVec)
    {
        std::cout << a << " " << a.size() << '\n';
    }
    
}

void updateDisplay(std::vector<std::string> &myVec, int X, unsigned cycle)
{
    int row = static_cast<unsigned>(cycle/40);
    if (cycle%40 == 0) row -= 1;
    if (cycle == 121)
    {
        std::cout << 'a';
    }
    cycle -= 40*row;

    

    if (cycle >= X && cycle <= X+2)
    {
        myVec[row][(cycle-1)] = '#'; // 1-based -> 0-based
    }
}

int main()
{
    std::ifstream input("input10.txt");

    std::string line;
    std::string instruction;
    int signalStrength;
    std::vector<int> execReg;
    bool checkItOnce = true;
    int X = 1;
    unsigned cycle = 0;

    std::vector<std::string> spriteDisplay;
    std::string emptyLine;
    emptyLine.append(40,'.');

    for(unsigned i=0; i<6; ++i)
    {
        spriteDisplay.push_back(emptyLine);        
    }
    displayDisplay(spriteDisplay);

    while(getline(input,line))
    {
        int xRegister = 0;
        std::stringstream ss(line);
        ss >> instruction;
        if(instruction != "noop")
        {
            for(unsigned i=0; i<2; ++i)
            {
                cycle += 1;
                updateDisplay(spriteDisplay,X,cycle);
            }
            ss >> xRegister;
            X += xRegister;
        }
        else
        {
            cycle += 1;     
            updateDisplay(spriteDisplay,X,cycle);
        }
    
    }

    std::cout << "==================================================================\n"; 
    displayDisplay(spriteDisplay);

}