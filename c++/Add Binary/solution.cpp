/*
 * RJOrdway
 * 1st Solution, LeetCode 67: Add Binary
 * 
 * Method: # Reverse Strings
 *         # Iterate through indexes until shorter string complete
 *         # Add digits and keep track of a carry digit according to this table:
 *              
 *              |  Carry  |  False  |  True   |
 *              |   0,0   |   0,F   |   1,F   |
 *              | 1,0/0,1 |   1,F   |   0,T   |
 *              |   1,1   |   0,T   |   1,T   |
 *          
 *         # Once done, add remaining carry to remaining digits of longer string
 *         # If all digits in longer string iterated and carry is still present,
 *           add a new digit (1).
 *         # Reverse and Return
 * 
 * Concern: # May be better to use reverse iterators
 *          # Solution is ugly, hard to read
 *          # bitshifting would make you seem cooler
 * 
 * Result:  # Indeterminate runtime, mediocre memory
 *          Runtime 0 ms    Beats 100%
 *          Memory 6.4 MB   Beats 39.38%
 * 
 * Started: 2/13/2023
 * Submitted: 2/14/2023
 */

#include <string>
#include <algorithm>
#include <iostream>

using std::string;

string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // if (b.size() > a.size()) {
    //     a = a.append(b.substr(a.size(), b.size()-a.size()));
    //     b = b.substr(0, a.size());
    // }
    string* shorter;
    string* longer;
    if (a.size() >= b.size()){
        shorter = &b;
        longer = &a;
    }
    else {
        shorter = &a;
        longer = &b;
    }

    bool carry = false;
    int i = 0;
    while (i < shorter->size()) {
        if (!carry){
            if ((*shorter)[i] == '1') {
                if ((*longer)[i] == '1') {
                    carry = true;
                    (*longer)[i] = '0';
                }
                else
                    (*longer)[i] = '1';
            }
            // no changes needed if no carry and short = 0 long = 1
            // or if no carry and both = 0
        }
        else {
            if ((*shorter)[i] == '0') {
                // s0 l0 
                if ((*longer)[i] == '0') {
                    carry = false;
                    (*longer)[i] = '1';
                }
                //s0 l1
                else {
                    (*longer)[i] = '0';
                }
            }
            else {
                //s1l0
                if ((*longer)[i] == '0') {
                    (*longer)[i] == '1';
                }
                // both = 1 with a carry leaves everything the same
            }
        }
        i++;
    }

    while (i < longer->size() && carry) {
        if ((*longer)[i] == '1') {
            (*longer)[i] = '0';
        }
        else {
            (*longer)[i] = '1';
            carry = false;
        }
        i++;
    }

    if (carry) {
        (*longer).append("1");
    }

    reverse((*longer).begin(), (*longer).end());

    return (*longer);    
}

int main() {

    //addBinary("11", "1");
    //addBinary("1010", "1011");
    addBinary("110111", "101");

    return 1;
}
