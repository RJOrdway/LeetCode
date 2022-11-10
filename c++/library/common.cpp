/*
 * RJOrdway
 * common.cpp
 * C++ library for leetcode + G4G problem code debugging
 */
#pragma once

#include "common.h"
#include <iostream>
#include <vector>

// prints a (hopefully) nicely formatted visualization of int matrix in stdout
void printMatrix(std::vector<std::vector<int>> intMatrix)
{
    // empty vector check
    if (intMatrix.size() == 0) 
    {
        std::cout << "Vector of vectors is empty" << std::endl;
        return;
    }
    else if (intMatrix[0].size() == 0) 
    {
        std::cout << "Inner vectors are empty" << std::endl;
        return;
    }
    /*
    // needs section to determine if all inner vectors are of equal size
    else if {

    }
    */
    else 
    {
        int m = intMatrix.size();
        int n = intMatrix[0].size();
        for (int i = 0; i < m; i++) 
        {
            printf("%i", intMatrix[i][0]);
            for (int k = 1; k < n; k++) 
            {
                printf(",\t%i", intMatrix[i][k]);
            }
            printf("\n");
        }

    }

};
