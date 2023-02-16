/*
 * RJOrdway
 * 1st Solution, LeetCode <problem number>: <problem name>
 * 
 * Method: Nesting conditionals
 * 
 * Concern: Code is too nested, looks ugly and would be undesirable to maintain.
 *          
 * Result: Reasonable, Runtime beats 47.5% and memory beats 70.49% - not much to
 *         read into though as results show normal LeetCode metric oddness
 * 
 * Started: 01/02/23
 * Submitted:  01/02/23
 */
#include <string>

using std::string;

bool detectCapitalUse(string word) {
    if (word.size() == 1) {
        return true;
    } 
    if (isupper(word[0])) {
        if (isupper(word[1])) {
            for (int i = 2; i < word.length(); i++) {
                if (!isupper(word[i])) {
                    return false;
                }
            }
            return true;
        }
        else {
            for (int i = 2; i < word.length(); i++) {
                if (isupper(word[i])) {
                    return false;
                }
            }
            return true;
        }
    }
    else {
        for (int i = 1; i < word.length(); i++) {
            if (isupper(word[i])) {
                return false;
            }
        }
        return true;
    }
}