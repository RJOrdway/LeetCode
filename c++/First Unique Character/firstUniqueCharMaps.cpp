/* 
 * RJOrdway
 * 1st Solution, Leetcode 387: 1st Unique Char in a String
 * 
 * Method: Map characters from string with bool to indicate
 *         when they were no longer unique
 * 
 * Concern: Using a map allows fast loading and lookup, but
 *          the string must be iterated over a 2nd time to
 *          find the 1st string element that is also unique.
 *          I wanted to have the map key composed of char
 *          so checking the rest of the string didn't get
 *          too expensive.
 * 
 * Submitted: 8/15/22
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int firstUniqChar(string s);

int main(){
    string test1 = "leetcode";
    string test2 = "loveleetcode";
    string test3 = "aabb";
    string test4 = "a";
    string test5 = "grjsdjnvsfdvfidrlgqarjnjgndfbndbthdffgn";
}

int firstUniqChar(string s) {
    map<char, bool> t;
    map<char, bool>::iterator it;

    for (int i = 0; i < s.size(); i++){
        it = t.find(s[i]);
        if (it != t.end()){
            it->second = false;
        }
        else{
            t.insert(it, pair<char, bool>(s[i], true));
        }
    }
    for (int k = 0; k < s.size(); k++){
        it = t.find(s[k]);
        if (it->second == true)
            return k;
    }
    return -1;
};