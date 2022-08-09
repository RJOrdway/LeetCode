// Return Richest Customer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts);

int main()
{
    vector<vector<int>> test1{
        {1,2,3},
        {3,2,1}
    };

    cout << maximumWealth(test1) << endl;

    vector<vector<int>> test2{
        {1,5},
        {7,3},
        {3,5}
    };

    cout << maximumWealth(test2) << endl;

    vector<vector<int>> test3{
        {2,8,7},
        {7,1,3},
        {1,9,5}
    };

    cout << maximumWealth(test3) << endl;

    vector<vector<int>> test4{
        {1},
        {5},
        {11}
    };

    cout << maximumWealth(test4) << endl;

    vector<vector<int>> test5{
        {123}
    };

    cout << maximumWealth(test5) << endl;
}

int maximumWealth(vector<vector<int>>& accounts) {
    int highest = 0, temp;
    for (int r = 0; r < accounts.size(); r++) {
        temp = 0;
        for (int c = 0; c < accounts[r].size(); c++) {
            temp += accounts[r][c];
        }
        highest = temp * (temp > highest) + highest * (temp <= highest);
    }
    return highest;
}