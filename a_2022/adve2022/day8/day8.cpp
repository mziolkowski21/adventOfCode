#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
using std::vector;


void displayVisibility(vector<vector<bool>> visible)
{
        for (vector row:visible)
    {
        for(int visib:row)
        {
            std::cout << '|' << visib << '|';
        }
        std::cout << '\n';
    }
    std::cout << "---------------------------\n";
}


int main()
{
    std::ifstream input("input8.txt");
    std::string line;
    vector<vector<int>> grid;

    while(getline(input,line))
    {
        vector<int> treeRow;
        for(char treeSize: line)
        {
         treeRow.push_back(static_cast<int>(treeSize-'0'));
        }
        grid.push_back(treeRow);
    }



    // vector(size_of_vector, values_at_each_element)
    vector<vector<bool>> visible(grid.size(),vector<bool>(grid[0].size(),false));

    const unsigned max_rows = grid.size();
    const unsigned max_cols = grid[0].size();

    // making edges visible
    for (int row = 0; row < grid.size(); ++row)
    {
        visible[row][0] = true; //left edge
        visible[row][max_cols-1] = true; // right edge, -1 because 0 based
    }
    for (int col = 0; col < grid[0].size(); ++col)
    {
        visible[0][col] = true; // top edge
        visible[max_rows-1][col] = true; // botom edge
    }

    for (int row = 0; row < grid.size(); ++row)
    {
        int max_yet_right = grid[row][0];
        int max_yet_left = grid[row][max_cols-1];
        for (int col =0; col < grid[0].size()-1; ++col)
        {
            if (max_yet_right < grid[row][col+1]) // left to right
            {
                visible[row][col+1] = true;
                max_yet_right = grid[row][col+1]; //pfpfpfsafpaspfsafpsafspafapsfaps a assigned visible instead of grid SILLY
            }
            if (max_yet_left < grid[row][max_cols - col - 1 -1]) // right to left, -1 because of 1-based -> 0-based, -1 to get one before 
            {
                visible[row][max_cols - col - 1 - 1] = true;
                max_yet_left = grid[row][max_cols - col - 1 - 1];
            }
        }
    }

    for (int col = 0; col < grid[0].size(); ++col)
    {
        int max_yet_down = grid[0][col];
        int max_yet_up = grid[max_cols-1][col];
        for (int row =0; row < grid.size()-1; ++row) 
        {
            if (grid[row+1][col] > max_yet_down) // up to down
            {
                visible[row+1][col] = true;
                max_yet_down = grid[row+1][col];
            }
            if (grid[max_rows-1-1 - row][col] > max_yet_up) // down to up 
            {
                visible[max_rows-row-1-1][col] = true; // forgot to subtract row, ffs
                max_yet_up = grid[max_rows-1-1][col];
            }
        }
    }

    unsigned sum = 0;
    // displayVisibility(visible);
    for (vector row:visible)
    {
        for (int treeVis:row)
        {
            sum += treeVis;
        }
        // sum += std::accumulate(row.begin(),row.end(),0);
    }

    std::cout << sum << '\n';

}