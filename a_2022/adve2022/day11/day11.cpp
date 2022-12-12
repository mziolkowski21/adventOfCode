#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>



const unsigned stressRelief = 1; // for part 1 => 3, for part 2 => 1
const unsigned rounds = 20; // for part 1 => 20, for part 2 => 10000



struct Monkey
{
    unsigned num;
    std::vector<unsigned> items;
    std::pair<char,std::string> operation;
    unsigned divideBy;
    unsigned ifTrue;
    unsigned ifFalse; 
    unsigned inspectedNTimes;
};


std::vector<unsigned> parseNums(std::string &str)
{
    std::string temp;
    unsigned found;
    std::vector<unsigned> result;

    std::stringstream sstr(str);

    while(!sstr.eof())
    {
        sstr >> temp; // extracting word by word
        if(std::stringstream(temp) >> found) // stream to unsigned unsigned, i.e. string is an integer
        {
            result.push_back(found);
        }
    }

    return result;
}

unsigned doOperation(std::pair<char,std::string>op,unsigned oldVal)
{
    unsigned calculation = (std::isdigit(op.second[0])) ? stoi(op.second) : oldVal;
    // unsigned calculation = std::isdigit(op.second) * static_cast<unsigned>(op.second) + std::isalpha(op.second)*oldVal; // if string numeric convert it to uint else it must be an old value
    if (op.first == '*')
    {
        oldVal *= calculation;
    }
    else if (op.first == '+')
    {
        oldVal += calculation;
    }

    return static_cast<unsigned>(oldVal/stressRelief);
}


int main()
{
    std::vector<Monkey> monkeVec;

    std::ifstream input("testInput11.txt");
    std::string line;
    std::string delim;
    
    // Parsing
    while(!input.eof())
    {
        getline(input,line);
        if(!line.empty())
        {
            Monkey monke;
            monke.num = parseNums(line)[0];
            monke.inspectedNTimes = 0;
            
            getline(input,line); //items
            monke.items = parseNums(line);
            std::cout << '\n';

            getline(input,line); // op
            std::stringstream sstr(line);
            sstr >> delim >> delim >> delim >> delim >> monke.operation.first >> monke.operation.second;

            getline(input,line); //test
            monke.divideBy = parseNums(line)[0];

            getline(input,line); // if true throw to # monke
            monke.ifTrue = parseNums(line)[0];

            getline(input,line); // if false throw to # monke
            monke.ifFalse = parseNums(line)[0];

            monkeVec.push_back(monke);
        }
    }


    for(unsigned i=0; i<rounds; ++i)
    {
        for(Monkey monke:monkeVec)
        {
            unsigned initialSize = monke.items.size();
            for(unsigned j=0; j<initialSize; ++j)
            {
                unsigned newVal = doOperation(monke.operation,monke.items.back());
                if (newVal % monke.divideBy == 0)
                {
                    monkeVec[monke.ifTrue].items.push_back(newVal);
                }
                else 
                {
                    monkeVec[monke.ifFalse].items.push_back(newVal); 
                }   
                monke.items.pop_back();
                monke.inspectedNTimes++;  
                monkeVec[monke.num] = monke;
            }
        }

            for(Monkey monke:monkeVec)
            {
                std::cout << monke.num << " inspected : " << monke.inspectedNTimes << '\n';
            }
            std::cout << "--------------------------\n";
        
    }

            // for(unsigned item:monke.items)
            // {
            //     unsigned newVal = doOperation(monke.operation,item);
            //     if (newVal % monke.divideBy == 0)
            //     {
            //         monkeVec[monke.ifTrue].items.push_back(newVal);
            //     }
            //     else 
            //     {
            //         monkeVec[monke.ifFalse].items.push_back(newVal); 
            //     }   
            //     auto ite = std::find(monke.items.begin(),monke.items.end(),newVal);
            //     monkeVec[monke.num].items.erase(ite); // erase resulted in weird errors only possible in debugger - possibly i was trying to access stuff that i removed or something
            //     monke.inspectedNTimes = 5;                
            // }
    // }

    std::vector<unsigned> solution;
    for(Monkey monke:monkeVec)
    {
        std::cout << monke.num << ": " << monke.inspectedNTimes << '\n';
        solution.push_back(monke.inspectedNTimes);
    }
    std::sort(solution.begin(),solution.end(), std::greater<unsigned>());
    std::cout << solution[0] << " * " << solution[1] << " = " << static_cast<long>(solution[0]*solution[1]) << '\n';


}