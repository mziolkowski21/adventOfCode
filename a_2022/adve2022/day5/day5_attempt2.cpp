#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


int main()
{
    using std::string;
    std::ifstream input("input5.txt");
    std::cout << input.is_open() << '\n';
    
    string line;
    string stack[10];
    
    while(getline(input,line))
    {
        if(std::isdigit(line[1])) break;

        for(int pos=1, i=0; pos<static_cast<int>(line.length());pos+=4, ++i)
        {
            if(std::isalpha(line[pos]))
            {
                stack[i] += line[pos]; // basically columns/stack
            }
        }
    }

    for(auto &s: stack)
    {
        std::reverse(s.begin(),s.end()); // reversing the stack so adding to it will appear at the "top"
    }

    while(getline(input, line)) // continuining along the stream
    {
        if(line.length() == 0) continue; // if string of length = 0

        int howMany, from, to;
        sscanf(line.c_str(), "move %d from %d to %d", &howMany, &from, &to);
        //have to convert to c style string to perfrom scan from it

        --from;
        --to; // decrementing for indeces purposes

        for(int i=0; i<howMany; i++) // take howMany letters from one and add to another stack
        {
            stack[to] += stack[from].back(); // back returns last char from string
            stack[from].pop_back(); // remove last char from string
        }
    }

    string sol = "";
    for(auto &s: stack)
    {
        if(s.length() > 0)
        sol += s.back(); // only need the "top" values, so in reversed stack it's gonna be last one
    }

    std::cout << sol << '\n';
}