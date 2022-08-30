/*
 * RJOrdway
 * 1st Solution, LeetCode 48: Rotate Image (grid/matrix)
 * 
 * Method:  Outside-in 4-point rotational swap
 * 
 * Concern: This code is completely unreadable, even with notes
 *          need to assign variables with better names
 * 
 * Started:     8/30/22
 * Submitted:   NA
 */

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix);
void printMatrix(vector<vector<int>>& matrix);

int main() {

    vector<vector<int>> tmatrix1  {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> expected1  {{7,4,1},{8,5,2},{9,6,3}};
    printMatrix(tmatrix1);
    rotate(tmatrix1);
    cout << "Expected:" << endl;
    printMatrix(expected1);
    cout << "Result:" << endl;
    printMatrix(tmatrix1);

    vector<vector<int>> tmatrix2  {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> expected2  {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
    printMatrix(tmatrix2);
    rotate(tmatrix2);
    cout << "Expected:" << endl;
    printMatrix(expected2);
    cout << "Result:" << endl;
    printMatrix(tmatrix2);

}


/*
 * [0][0] -> [0][n] -> [n][n] -> [n][0] -> [0][0]
 * [0][0+1] -> [0+1][n] -> [n][n-1] -> [n-1][0] -> [0][0+1]
 * [$0][0++] -> [0++][$n] -> [$n][n--] -> [n--][$0] -> [$0][0++]
 * OR
 * [0][0++] to temp
 * [$0][0++] = [n--][$0], [n--][$0] = [$n][n--], [$n][n--] = [0++][$n]
 * [0++][$n] = temp
 */
void rotate(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int rings = r/2;
    int n = r-1;
    // outer loop will rotate a ring layer (onion)
    // i++ will offset 0, n-- will offset previous final index
    for (int i = 0; i < rings; i++, n--) {

        // inner loop consists of n 4-point swaps
        for (int k = 0; k < n-i; k++) {
            // store top 'left' corner in temp
            int temp = matrix[i][i+k];
            // store 'bottom' left in top 'left'
            matrix[i][i+k] = matrix[n-k][i];
            // store bottom 'right' in 'bottom' left
            matrix[n-k][i] = matrix[n][n-k];
            // store 'top' right in  bottom 'right'
            matrix[n][n-k] = matrix[i+k][n];
            // now temp to 'top' right
            matrix[i+k][n] = temp;
        }
    }
}

// just for print testing
void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        cout << matrix[i][0];
        for (int k = 1; k < matrix.size(); k++) {
            cout << ", " << matrix[i][k];
        }
        cout << endl;
    }
    cout << endl;
}