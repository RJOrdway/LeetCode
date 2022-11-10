/*
 * RJOrdway
 * 1st Solution, LeetCode 1323: Maximum 69 Number

 * 
 * Method: lazy conversion
 * 
 * Concern: 
 * 
 * Started:     11/6/22
 * Submitted:   
 */

#include <iostream>

using namespace std;

int maximum69Number (int num) {
    string strnum = to_string(num);
    for (int i = 0; i < strnum.length(); i++) {
        if (strnum[i] == '6') {
            strnum[i] = '9';
            break;
        }
    }
    return stoi(strnum);
}

