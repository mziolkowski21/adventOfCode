#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>

struct Coordinate
{
    int x = 0;
    int y = 0;
};

const unsigned knots = 10;


int main()
{
    std::ifstream input("input9.txt");
    std::string line;
    char direction;
    int steps;
    

    Coordinate rope[knots]; // array of coordinates for both knots [0] - head, [1] - tail

    std::map<std::string, bool> visited;
    visited.insert({"0:0", true});

    while(getline(input,line))
    {
        sscanf(line.c_str(), "%c %d", &direction, &steps);
        
        for(int i = 0; i < steps; ++i)
        {
            // Head movement
            if(direction == 'U') ++rope[0].y; 
            else if(direction == 'D') --rope[0].y;
            else if(direction == 'L') --rope[0].x;
            else if(direction == 'R') ++rope[0].x;

            for(int knot = 1; knot < knots; knot++)
            {
                int dx = rope[knot-1].x - rope[knot].x;
                int dy = rope[knot-1].y - rope[knot].y;
                if(sqrt(dx*dx + dy*dy) > 1.5) // tail does not touch directly head, even diagonally
                {
                    if(dx > 0) rope[knot].x++;
                    else if(dx < 0) rope[knot].x--;

                    if(dy > 0) rope[knot].y++;
                    else if(dy < 0) rope[knot].y--;

                    // if the knot is the tail, record its position on the map
                    if(knot == knots-1){
                        char keyChar[10];
                        sprintf(keyChar, "%d:%d", rope[knot].x,rope[knot].y);
                        visited.insert({std::string(keyChar), true});
                    }
                }

            }
        }
    }
    // for(auto &pair:visited)
    // {
    //     std::cout << pair.first << '\n';
    // }
    std::cout << visited.size() << '\n';
}