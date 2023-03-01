/*
 * RJOrdway
 * 1st Solution, LeetCode <problem number>: <problem name>
 * 
 * Method: Iterative approach
 *       # We can divide recursively into quadrants because the length and
 *         height of the grid are both 2ⁿ and equal to one another (sqare grid)
 * 
 * Concern: Uneducated guess says I could implement this using Nearest Neighbor algo faster
 * 
 * Result:
 *          Runtime 20 ms   Beats 37.10%
 *          Memory 15.6 MB  Beats 79.50%
 * 
 * Started:     02/27/23
 * Submitted:   02/28/23   
 */

// stdlib and stdio included to make NULL work within Node class
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using std::vector;

// LeetCode QuadTree class:
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// END OF LeetCode included Class

Node* recurseGrid(vector<vector<int>>& grid, int minX, int maxX, int minY, int maxY);

Node* construct(vector<vector<int>>& grid) {
        return recurseGrid(grid, 0, grid.size() - 1, 0, grid.size() - 1);
}

Node* recurseGrid(vector<vector<int>>& grid, int minX, int maxX, int minY, int maxY) {
    Node* quadrant = new Node();
    quadrant->isLeaf = true;
    quadrant->val = (grid[minY][minX] == 1);    
    for (int i = minY; i <= maxY && quadrant->isLeaf == true; i++) {

        for (int j = minX; j <= maxX; j++) {
            if (grid[i][j] != grid[minY][minX]){
                quadrant->isLeaf = false;
                break;
            }
        }
    }

    if (quadrant->isLeaf == false) {
        quadrant->topLeft = recurseGrid(grid, minX, minX+(maxX-minX)/2, minY, minY+(maxY-minY)/2);
        quadrant->topRight = recurseGrid(grid, minX+(maxX-minX)/2 + 1, maxX, minY, minY+(maxY-minY)/2);
        quadrant->bottomLeft = recurseGrid(grid, minX, minX+(maxX-minX)/2, minY+(maxY-minY)/2 + 1, maxY);
        quadrant->bottomRight = recurseGrid(grid, minX+(maxX-minX)/2 + 1, maxX, minY+(maxY-minY)/2 + 1, maxY);
    }
    return quadrant;
}

int main() {
    vector<vector<int>> test1 = vector<vector<int>>{
        vector<int>{1,1,1,1,0,0,0,0},
        vector<int>{1,1,1,1,0,0,0,0},
        vector<int>{1,1,1,1,1,1,1,1},
        vector<int>{1,1,1,1,1,1,1,1},
        vector<int>{1,1,1,1,0,0,0,0},
        vector<int>{1,1,1,1,0,0,0,0},
        vector<int>{1,1,1,1,0,0,0,0},
        vector<int>{1,1,1,1,0,0,0,0}
};

    vector<vector<int>> test2 = vector<vector<int>>{
        vector<int>{1,1,0,0,1,1,0,0},
        vector<int>{1,1,0,0,1,1,0,0},
        vector<int>{0,0,1,1,0,0,1,1},
        vector<int>{0,0,1,1,0,0,1,1},
        vector<int>{1,0,1,0,1,1,1,1},
        vector<int>{0,1,0,1,1,1,1,1},
        vector<int>{1,0,1,0,1,1,1,1},
        vector<int>{0,1,0,1,1,1,1,1}
};

Node* tree1 = construct(test1);

return 1;
}
