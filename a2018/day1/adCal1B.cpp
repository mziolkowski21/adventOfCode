#include <iostream>
#include <fstream>
#include <set>
#include <vector>

bool isInCollection(int num, const std::set <int> &collection)
{
    return collection.find(num) != collection.end();
}

int main()
{

    std::ifstream myInput("input1.txt");
    if(myInput.fail())
    {
        std::cout << "No file found in provided directory";
        return 0;
    }

    std::vector <int> inputVector;
    int num;
    while(myInput >> num)
    {
        inputVector.push_back(num);
    }

    std::set <int> alreadyUsed;
    int sum = 0;
    alreadyUsed.insert(sum);

    while(true)
    {
        for(auto freq:inputVector)
        {
            sum += freq;
            if(isInCollection(sum,alreadyUsed))
            {
                std::cout << sum << '\n';
                return 0;
            }
            alreadyUsed.insert(sum);
        }
    }
}