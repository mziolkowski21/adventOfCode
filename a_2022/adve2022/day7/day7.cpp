#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

std::string joinPath(std::vector<std::string> &directory)
{
    std::string joined = "";
    for(std::string dir: directory)
    {
        joined += "/" + dir;
    }
    return joined;
}

int main()
{
    std::ifstream input("input7.txt");
    if(!input.is_open())
    {
        std::cout << "no such file" << '\n';
        return 0;
    }

    std::string line;
    std::string delim;
    std::vector <std::string> directory;
    std::map <std::string, unsigned int> sizes;

    // std::stringstream ss("dupa blada hahaha");
    // ss >> line >> delim;
    // std::cout << line << " | " << delim << '\n'; //sstream ignores spaces

    // input >> line;
    // std::cout << line << '\n'; // stream approach gives you one symbol at a time

    while(getline(input, line))
    {
        std::stringstream ssLine(line);

        if(ssLine.peek() == '$') // command
        {
            std::string command;
            ssLine >> delim >> command;
            if(command == "cd")
            {
                std::string param;
                ssLine >> param;
                if(param == "/")
                {
                    directory.clear();
                }
                else if(param == "..")
                {
                    directory.pop_back();
                }
                else 
                {
                    directory.push_back(param);
                }
            }
            // else if(command == "ls")
            // {
            //    continue;
            // }
        }
        else // i have info about current directory in vector, no need to do the dir logic
        {
            unsigned int size;
            ssLine >> size;
            std::vector<std::string> directoryCopy(directory);
            if(line[0] == 'd')
            {
                continue;
            }

            while(!directoryCopy.empty())
            {
                std::string dir = joinPath(directoryCopy);
                auto itr = sizes.find(dir); // itr returns a reference/hook to the sizes map at which given directory is
                // e.g. place where d/ab/ce (key) and its knows size 600 is 
                if(itr != sizes.end()) // if you found it
                {
                    sizes.insert_or_assign(dir, itr->second + size); // it->first = (*it).first, first is a key, second is a value
                    // add to already existing value or insert it for given key
                }
                else
                {// not sure what's the difference between insert and insert_or_assign
                    sizes.insert({dir,size});
                }
                directoryCopy.pop_back();
            }
            auto itr = sizes.find("/");
            if (itr != sizes.end())
            {
                sizes.insert_or_assign("/", itr->second+size);
            }
            else
            {
                sizes.insert({"/",size});
            }
        }
    }

    unsigned int part =2;

    if(part == 1)
    {
    // part 1
        unsigned int sum= 0;
        for(auto &it: sizes)
        {
            std::cout << it.first << " " << it.second << '\n';
            if(it.second <= 100000)
            {
                sum += it.second;
            }
        }
        std::cout << sum << '\n';
    }
    if(part == 2)
    {
        unsigned int temp = 70000000;
        unsigned int space_left = 70000000 - sizes.find("/") -> second;
        unsigned int required = 30000000 - space_left;

        
        
        std::vector <unsigned int> sizesss;
        for(auto &it: sizes)
        {
            if(it.second >= required && it.second <= temp) temp = it.second;
            sizesss.push_back(it.second);
        }
        std::sort(sizesss.begin(),sizesss.end());
        for(auto s: sizesss)
        {
            std::cout << s << '|';

        }
        
        std::cout << "\nSPACE LEFT " << space_left << '\n' << "REQUIRED: " << required << '\n';
        std::cout << "SMALLEST SUITABLE: " << temp << '\n';
    }

}