/*
 * RJOrdway
 * 1st Solution, LeetCode 566: Reshape the Matrix
 * 
 * Method:  
 * 
 * Concern: May be able to optimize by creating new matrix shape in batches of n
 *          this would also allow a
 * 
 * Started:     9/5/22
 * Submitted:   9/6/22
 */
#include <iostream>
#include <vector>
#include "C:\Users\Rober\source\repos\RJOrdway\LeetCode\c++\library\common.h"

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);
//static void printMatrix(std::vector<std::vector<int>> intMatrix);

int main() {
    vector<vector<int>> input1 = {
        {1,2},
        {3,4}
    };
    int r1 = 1;
    int c1 = 4;
    vector<vector<int>> expected1 = {
        {1,2,3,4}
    };
    vector<vector<int>> result1 = matrixReshape(input1, r1, c1);

    printMatrix(expected1);
    printMatrix(result1);


}

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();
    if (m*n != r*c || n == c)
        return mat;
    else {
        vector<int> holder(m*n);
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                holder.push_back(mat[i][k]);
            }
        }
        int p = 0;
        for (p; p < r-1; p++) {
            mat[p] = vector<int>(holder[p*c], holder[(p+1)*c+1]);
        }
        mat[p] = vector<int>(holder[p*c], holder[(m*n)]);
    return mat;
    }
}