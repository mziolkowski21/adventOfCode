#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using std::vector;
using std::pair;

// implements BFS - Breadth First Search Algorithm 
// ("special-case of Dijkstra's algorithm on unweighted graphs, where the priority queue degenerates into a FIFO queue.")


vector<pair<int,int>> findAdjacencyList(pair<int,int> cords, const vector<vector<char>> &grid)
{

    vector<pair<int,int>> adjacentList;
    if(!(cords.first - 1 < 0) && static_cast<int>(grid[cords.first-1][cords.second] - grid[cords.first][cords.second]) <= 1)
        adjacentList.push_back({cords.first-1,cords.second});
    if(!(cords.first + 1 >= grid.size()) && static_cast<int>(grid[cords.first+1][cords.second] - grid[cords.first][cords.second]) <= 1)
        adjacentList.push_back({cords.first+1,cords.second});
    if(!(cords.second - 1 < 0) && static_cast<int>(grid[cords.first][cords.second-1] - grid[cords.first][cords.second]) <= 1)
        adjacentList.push_back({cords.first, cords.second-1});
    if(!(cords.second + 1 >= grid[0].size()) && static_cast<int>(grid[cords.first][cords.second+1] - grid[cords.first][cords.second]) <= 1)
        adjacentList.push_back({cords.first ,cords.second+1});

    return adjacentList;
}


vector<vector<pair<int,int>>> solve(pair<int,int> Scords, vector<vector<bool>> emptyVisited, const vector<vector<char>> &grid) 
{
    // solves graph starting at S coordinates and returns a grid of coordinates from which it got to given pos
    
    // create a queue structure
    bool reached_end = false;
    vector<pair<int,int>> queue;
    queue.push_back(Scords);

    vector<vector<bool>> visited = emptyVisited;
    visited[Scords.first][Scords.second] = true;
    
    vector<vector<pair<int,int>>> prev(emptyVisited.size(), vector<pair<int,int>>(emptyVisited[0].size(),{999,999})); // holds a parent or from where we got to these cords
    // 999 - auxillary null value
    
    while(!queue.empty())
    {
        pair<int,int> cords = queue.back();
        queue.pop_back();
        if (grid[cords.first][cords.second] == 'E')
        {
            reached_end = true;
            break;
        }
        vector<pair<int,int>> neighbours = findAdjacencyList(cords,grid);
        for(pair<int,int>next:neighbours)
        {
            if (!visited[next.first][next.second])
            {
                queue.push_back(next);
                visited[next.first][next.second] = true;
                prev[next.first][next.second] = cords;
            }
        }
    }
    
    return prev;
}

// vector<vector<bool>> reconstructPath(pair<int,int> Scords, pair<int,int> Ecords, vector<vector<pair<int,int>>> prev, vector<vector<bool>> emptyVisited)
// {
//     vector<vector<bool>> path = emptyVisited;
//     for(pair<int,int> row = Ecords; row != {999,999}; row = prev[])
// }


int main()
{


    vector<vector<char>> grid;
    std::pair <int,int> SCords, ECords, currCords;


    // Parse input
    std::ifstream input("testInput.txt");
    std::string line;
    unsigned rowTemp=0;
    while(getline(input,line))
    {
        unsigned colTemp=0;
        vector<char> row;
        for(char height:line)
        {
            if(height=='S')
            {
                SCords.first = rowTemp;
                SCords.second = colTemp;
                // height = 'a';
            }
            else if(height=='E')
            {
                ECords.first = rowTemp;
                ECords.second = colTemp;
                // height = 'z';
            }
            row.push_back(height);
            colTemp++;
        }
        rowTemp++;
        grid.push_back(row);
    }
    // end of parsing

    for(vector<char> row: grid)
    {
        for(char col: row)
        {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";


    vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));

     vector<vector<pair<int,int>>>  prev = solve(SCords,visited,grid);

}