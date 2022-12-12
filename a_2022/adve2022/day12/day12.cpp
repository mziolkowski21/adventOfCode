#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using std::vector;
using std::pair;


bool moveHorizontally(pair<int,int> &currCords, std::vector<std::vector<char>> grid, vector<std::vector<bool>> &beenThere,int dx)
{
    if((dx > 0) && !(currCords.second+1 >= grid.size())) // try to move to the right
    {
        if((grid[currCords.first][currCords.second]-grid[currCords.first+1][currCords.second] < 1) 
            && !beenThere[currCords.first][currCords.second+1])
            {
                currCords.second++;
                beenThere[currCords.first][currCords.second] = true;
                return true;
            }
    }
    else if((dx < 0) && !(currCords.second-1 < 0)) // try to move to the left
    {
        if((grid[currCords.first][currCords.second]-grid[currCords.first-1][currCords.second] < 1)
            && !beenThere[currCords.first][currCords.second-1])
            {
                currCords.second--;
                beenThere[currCords.first][currCords.second] = true;
                return true;
            }
    }
    return false;
}

bool moveVertically(pair<int,int> &currCords, std::vector<std::vector<char>> grid, vector<std::vector<bool>> &beenThere,int dy)
{
    if((dy < 0) && !(currCords.first-1 < 0)) // try to move up
    {
        if((grid[currCords.first][currCords.second]-grid[currCords.first+1][currCords.second] < 1) 
            && !beenThere[currCords.first][currCords.second-1])
            {
                currCords.first--;
                beenThere[currCords.first][currCords.second] = true;
                return true;
            }
    }
    else if((dy > 0) && !(currCords.first+1 >= grid.size())) // try to move down
    {
        if((grid[currCords.first][currCords.second]-grid[currCords.first+1][currCords.second] < 1)
            && !beenThere[currCords.first+1][currCords.second])
            {
                currCords.first++;
                beenThere[currCords.first][currCords.second] = true;
                return true;
            }
    }
    return false;
}

int main()
{


    vector<vector<char>> grid;
    std::pair <int,int> SCords, ECords, currCords;

    std::ifstream input("testInput.txt");
    std::string line;

    unsigned rowTemp=0;
    while(getline(input,line))
    {
        unsigned colTemp=0;
        vector<char> row;
        for(char height:line)
        {
            row.push_back(height);
            if(height=='S')
            {
                SCords.first = rowTemp;
                SCords.second = colTemp;
            }
            else if(height=='E')
            {
                ECords.first = rowTemp;
                ECords.second = colTemp;
            }
            colTemp++;
        }
        rowTemp++;
        grid.push_back(row);
    }

    vector<vector<bool>> beenThere(grid.size(),vector<bool>(grid[0].size(),false));

    beenThere[SCords.first][SCords.second] = true;

        for(std::vector<bool> row: beenThere)
    {
        for(bool cols: row)
        {
            std::cout << cols << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "{" << SCords.first << ',' << SCords.second << '}' << '\n';
    std::cout << "{" << ECords.first << ',' << ECords.second << '}' << '\n';

    currCords = SCords;

    int dx = ECords.first-SCords.first;
    int dy = ECords.second-SCords.second;
    while (dx!=0 && dy!=0)
    {
        dx = ECords.first-SCords.first;
        dy = ECords.second-SCords.second;

        if(std::abs(dx)>=std::abs(dy)) // try move horizontally first
        {
            if(moveHorizontally(currCords,grid,beenThere,dx)) continue;
            else if (moveVertically(currCords,grid,beenThere,dy)) continue; // can't go horizontally try vertically
            else if (moveVertically(currCords,grid,beenThere,-dy)) continue; // can't; go other way vertically then
            else if (moveHorizontally(currCords,grid,beenThere,-dx)) continue; // can't; go other way horizontally then
            else std::cout << "Dupa, can't go anywhere";
        }
        else // try move vertically first
        {
            if(moveVertically(currCords,grid,beenThere,dy)) continue;
            else if (moveHorizontally(currCords,grid,beenThere,dx)) continue; // can't go horizontally try vertically
            else if (moveHorizontally(currCords,grid,beenThere,-dx)) continue; // can't; go other way vertically then
            else if (moveVertically(currCords,grid,beenThere,-dy)) continue; // can't; go other way horizontally then
            else std::cout << "Dupa, can't go anywhere";
        }


    }

    for(std::vector<bool> row: beenThere)
    {
        for(bool cols: row)
        {
            std::cout << cols << ' ';
        }
        std::cout << '\n';
    }

}