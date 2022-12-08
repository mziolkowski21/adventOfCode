#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::vector;


const bool inBounds(int row, unsigned max_rows, int col, unsigned max_cols)
{
    return (row < max_rows && row >= 0 && col < max_cols && col >= 0);
}

int main() {

  std::string line;
  std::fstream input("input8.txt");

  vector<vector<int>> grid;

  while(getline(input,line))
  {
    vector<int> treeRow;
    for(char treeHeight:line)
    {
        treeRow.push_back(treeHeight-'0');
    }
    grid.push_back(treeRow);
  }

  vector<vector<int>> scores(grid.size(),vector(grid[0].size(),1));  // basically equivalent of matlab's ones(num_rows,num_cols)

  const vector<vector<int>> motions {
    {0,1}, //right
    {1,0}, // up
    {0,-1}, // left
    {-1,0} // down
  };
  
  const unsigned max_rows = grid.size();
  const unsigned max_cols = grid[0].size();


  for (int row = 0; row < grid.size(); ++row) // map grid with invidual scores
  {
    for (int col = 0; col < grid[0].size(); ++col)
    {
        for(auto motion: motions)
        {
            unsigned score = 0;
            auto current = vector<int> {row+motion[0], col+motion[1]};
            while(inBounds(current[0],max_rows, current[1],max_cols) && (grid[current[0]][current[1]] < grid[row][col])) // if in grid bounds, and the checked tree is still smaller than scored one
            {
                ++score;
                current[0] += motion[0];
                current[1] += motion[1];
            }
            if (inBounds(current[0],max_rows,current[1],max_cols)) ++score;
            scores[row][col] *= score;
        }
    }
  }

int result = 0;
  for (vector<int> scoreRow:scores) 
  {
    for (int score:scoreRow)
    {
        if (score > result) result = score;
    }
  }

std::cout << result << '\n';

}