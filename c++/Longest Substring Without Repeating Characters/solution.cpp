/*
 * RJOrdway
 * 1st Solution, LeetCode 3: Longest Substring Without Repeating Characters
 * 
 * Method:
 * 
 * Concern: Horrible, but it works
 * 
 * Result:
 * 
 * Started:
 * Submitted:   
 */

#include <unordered_set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> used;      // set used will hold all chars used in current substring
    int longest = 0;     // length of longest substring so far (will be returned)
    //int start = 0;       // starting index of temp
    int current = 0;
    int temp = 0;        // tracks length of current substring
    bool reset;
    
    for (int start = 0; s.size() - start > longest; start++) {
        used.clear();
        used.insert(s[start]);
        current = start + 1;
        reset = false;
        for (current; current < s.size() && reset == false; current++) {
            if (used.find(s[current]) == used.end()) {
                used.insert(s[current]);
            }
            else {
                reset = true;
            }
        }
        temp = used.size();
        longest = longest*(longest>=temp)+temp*(temp>longest);
    }
    return longest;
}

int main() {
    lengthOfLongestSubstring("asdjaGBDDFasdaVGABCDEfFgGhH");
}