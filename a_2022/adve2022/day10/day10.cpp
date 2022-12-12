#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>


int main()
{
    std::ifstream input("input10.txt");

    std::string line;
    std::string instruction;
    int signalStrength;
    int cycle = 0;
    std::vector<int> execReg;
    bool checkItOnce = true;
    unsigned n = 0;
    int x = 1;

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
                if(cycle == 20+40*n)
                {
                    n += 1;
                    execReg.push_back(cycle*x);
                }
            }
            ss >> xRegister;
            x += xRegister;
        }
        else
        {
            cycle += 1;
            if(cycle == 20+40*n)
            {
                n += 1;
                execReg.push_back(cycle*x);
            }
        }
        std::cout << instruction << " " << xRegister <<  '\n';
    
    }
    for(int y:execReg)
    {
        std::cout << y << '\n';
    }
    std::cout << std::accumulate(execReg.begin(),execReg.end(),0);
    

}