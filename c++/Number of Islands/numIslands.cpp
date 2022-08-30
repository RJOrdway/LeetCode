/*
 * RJOrdway
 * 1st Solution, LeetCode 200: Number of Islands
 * 
 * Method:  Possibly excessive but absolutely complete island mapping per DFS
 * 
 * Concern: I think I could get around checking left and above, above by default,
 *          and left by adding a check for any freshly found '1' that ends up
 *          connecting to any '2' which would then decrement the island count
 *          to remove the false positive increment.
 * 
 * Started:     8/29/22
 * Submitted:   8/29/22
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int numIslands(vector<vector<char>>& grid);
void mapIslands(vector<vector<char>>& grid, int i, int k);

int main() {
    vector<vector<char>> tgrid1 {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    int islandCount1 = 1;
    int countedIslands1 = numIslands(tgrid1);
    cout << "Example 1:" << endl;
    cout << islandCount1 << " expected, " << countedIslands1 << " returned" << endl;
    cout << endl;

    vector<vector<char>> tgrid2 {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    int islandCount2 = 3;
    int countedIslands2 = numIslands(tgrid2);
    cout << "Example 2:" << endl;
    cout << islandCount2 << " expected, " << countedIslands2 << " returned" << endl;
    cout << endl;


    return 0;
}

int numIslands(vector<vector<char>>& grid) {
    int icount = 0;
    for (int i = 0; i < grid.size(); i++) {

        int rl = grid[0].size();
        
        for (int k = 0; k < rl; k++) {
            if (grid[i][k] == '1') {
                icount++;
                mapIslands(grid, i, k);
            }
        }
    }
    return icount;
}

void mapIslands(vector<vector<char>>& grid, int i, int k) {
    // Change value to '2'
    grid[i][k] = '2';
    // Check Above
    if (i > 0 && grid[i-1][k] == '1')
        mapIslands(grid, i-1, k);
    // Check Left
    if (k > 0 && grid[i][k-1] == '1')
        mapIslands(grid, i, k - 1);
    // Check Right
    if (k+1 < grid[0].size() && grid[i][k+1] == '1')
        mapIslands(grid, i, k+1);
    // Check Down
    if ( i+1 < grid.size() && grid[i+1][k] == '1')
        mapIslands(grid, i+1, k);
}