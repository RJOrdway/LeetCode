/*
 * RJOrdway
 * 0th Solution, LeetCode 48: Rotate Image (grid/matrix)
 * 
 * Method:  Allocating another 2d matrix
 *          Test run, not submitted, does not follow rules
 * 
 * Concern: This is a test run because it disobeys the instruction not to
 *          allocate a new 2d array.
 * 
 * Started:     8/29/22
 * Submitted:   NA
 */

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix);

int main() {

    vector<vector<int>> tmatrix1  {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> expected1  {{7,4,1},{8,5,2},{9,6,3}};

    vector<vector<int>> tmatrix2  {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> expeted2  {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};

}

void rotate(vector<vector<int>>& matrix) {
    vector<vector<int>> dummy = matrix;
    int r = matrix.size();

    // Start:  last row to first column
    // Finish: first row to last column
    // row will do the same for origin row index
    // col can function as destination column index
    // x will be the 'other' index for both: origin column & destination row
    int row = r-1;
    for (int col = 0; col < r; col++, row--) {
        for (int x = 0; x < r; x++) {
            dummy[x][col] = matrix[row][x];
        }
    }

    matrix = dummy;
}