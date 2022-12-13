#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <deque>
using std::vector;
using std::pair;

// implements BFS - Breadth First Search Algorithm 
// ("special-case of Dijkstra's algorithm on unweighted graphs, where the priority queue degenerates into a FIFO queue.")

struct Cords
{
    int row;
    int col;
};

bool part1 = false;

unsigned findAdjacent(unsigned row, unsigned col, std::deque<unsigned> &rowQue, std::deque<unsigned> &colQue,
                    vector<vector<bool>> &visited, const vector<vector<char>> &grid)
{
    unsigned nodesInNextLayer = 0;
    int leftToRight[4] = {0,0,-1,+1}; // left, right 
    int downToUp[4] = {-1,1,0,0};
    int movedRow, movedCol;

    for(unsigned i=0; i<4; ++i)
    {
        movedRow = static_cast<int>(row + leftToRight[i]);
        movedCol = static_cast<int>(col + downToUp[i]);

        // Skip out of bound locations
        if (movedRow < 0 || movedCol < 0) continue;
        if (movedRow >= grid.size() || movedCol >= grid[0].size()) continue;

        // Skip visited locations or blocked cells
        if (visited[movedRow][movedCol]) continue;
        if (part1)
        {
            if (grid[movedRow][movedCol] - grid[row][col] > 1) continue;
        }
        else
        {
            if (grid[row][col] - grid[movedRow][movedCol] > 1) continue;
        }

        rowQue.push_back(movedRow);
        colQue.push_back(movedCol);
        visited[movedRow][movedCol] = true;

        ++nodesInNextLayer;
    }
    return nodesInNextLayer;
}

unsigned solve(const Cords &Scords, const Cords &Ecords, 
                const vector<vector<bool>> &emptyVisited, const vector<vector<char>> &grid)
{
    unsigned moveCount = 0;
    bool reachedEnd = false;

    int nodesLeftInLayer = 1;
    int nodesInNextLayer = 0;

    std::deque<unsigned> rowQue; // queue for 1st, row dimension
    std::deque<unsigned> colQue; // queue for 2nd, col dimension
    vector<vector<bool>> visited = emptyVisited;

    rowQue.push_back(Scords.row);
    colQue.push_back(Scords.col);
    visited[Scords.row][Scords.col] = true;

    while (rowQue.size() > 0) // or colQue.size() > 0
    {
        unsigned row = rowQue.front(), col = colQue.front();
        rowQue.pop_front();
        colQue.pop_front();

        if(part1)
        {
            if (Ecords.row == row && Ecords.col == col) // got there (visited[Ecords.row][Ecords.col] resulted in found one step to quickly)
            {
                reachedEnd = true;
                break;
            }
        }
        else
        {
            if (grid[row][col] == 'a') // got there 
            {
                reachedEnd = true;
                break;
            }
        }

        nodesInNextLayer += findAdjacent(row,col,rowQue,colQue,visited,grid);

        --nodesLeftInLayer;
        if (nodesLeftInLayer == 0)
        {
            nodesLeftInLayer = nodesInNextLayer;
            nodesInNextLayer = 0;
            ++moveCount;
            // for(vector<bool> row:visited)
            // {
            //     for(bool col:row)
            //     {
            //         std::cout << col << " ";
            //     }
            //     std::cout << '\n';
            // }
            // std::cout << "----------------------------------   " << moveCount << '\n';
        }
    }
    if (reachedEnd) return moveCount;
}



int main()
{
    vector<vector<char>> grid;
    Cords Scords, Ecords;

    // Parse input
    std::ifstream input("input12.txt");
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
                Scords.row = rowTemp;
                Scords.col = colTemp;
                height = 'a';
            }
            else if(height=='E')
            {
                if (part1){
                    Ecords.row = rowTemp;
                    Ecords.col = colTemp;
                }
                else
                {
                    Scords.row = rowTemp;
                    Scords.col = colTemp;
                }
                height = 'z';
            }
            row.push_back(height);
            colTemp++;
        }
        rowTemp++;
        grid.push_back(row);
    }
    // end of parsing

    unsigned R = grid.size(), C = grid[0].size();
    vector<vector<bool>> emptyVisited(R,vector<bool>(C,false)); // zeros(R,C)

    unsigned solution = solve(Scords, Ecords, emptyVisited, grid);

    std::cout << solution;

}