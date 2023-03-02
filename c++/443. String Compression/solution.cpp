/*
 * RJOrdway
 * 1st Solution, LeetCode 443: String Compression
 * 
 * Method: Loop through original vector,
 *         Keep separate insertion and loop indexes,
 *         Replace characters according to insertion index,
 *         Count duplicates, when dupe run ends, insert the char and stringified dupe tally
 *         
 * 
 * Concern: Verbose,
 *          Had issues with solution looking at string (as specified in problem.md -- resolved)
 *          (Still resolving) Cannot see vector elements properly due to vscode+gcc issues
 *                            This amplified issues with the final string order.
 * 
 * Result:  
 *          Runtime 6 ms    Beats 53.56%
 *          Memory 9 MB     Beats 83.2%
 * 
 * Started:     03/01/23
 * Submitted:   03/01/23
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int compress(vector<char>& chars) {
    int tally = 0;          // Tracks sequential chars
    int compIndex = 0;      // Holds the comparison index
    int insertionIndex = 0; // Holds the index for replacement insertion, will also represent char.end()

    for (int i = 0; i < chars.size(); i++) {
        if (tally == 0) {
            compIndex = i;
            tally++;
        }
        else {
            if (chars[i] == chars[compIndex]) {
                tally++;
            }
            else {
                chars[insertionIndex++] = chars[compIndex];
                if (tally > 1) {
                    for (char c: to_string(tally)) {
                        chars[insertionIndex++] = c;
                    }
                }
                tally = 0;
                i--;
            }
        }
    }
    // clear tally buffer
    if (tally != 0) {
        chars[insertionIndex++] = chars[compIndex];
        if (tally > 1) {
            for (char c: to_string(tally)) {
                chars[insertionIndex++] = c;
            }
        }
    }
    
    chars = vector<char>(chars.begin(), chars.begin()+insertionIndex);
    return chars.size();
}

int main() {
    vector<char> test1 {'a','a','b','b','c','c','c'};

    int result1 = compress(test1);
    cout << result1 << endl;

    for (int i = 0; i < test1.size(); i++) {
        cout << test1[i];
    }

    return 1;
}