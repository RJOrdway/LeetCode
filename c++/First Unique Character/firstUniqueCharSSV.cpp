/* 
 * RJOrdway
 * 2nd Solution, Leetcode 387: 1st Unique Char in a String
 * 
 * Method:  Using two sets of chars, set (a) acts as a "char
 *          found 1st time store", if a char is found again
 *          it goes in set (b).  Once the string has been 
 *          loaded the string is compared again to find the
 *          first char not in set b.
 * 
 * Concern: I thought this was a novel approach compared to
 *          my 1st approach of map<char, bool>, but the
 *          procedure ends up very similar. According to
 *          LeetCode's runtime/memory eval, it is slightly
 *          less performant with slightly more memory cost.
 *          While I don't hold absolute faith in LC benchmarks,
 *          this relative assessment seems valid
 * 
 * Submitted: 8/16/22
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
    set<char> a;
    set<char> b;
    set<char>::iterator ait;
    set<char>::iterator bit;
    vector<pair<char, int>> v;

    for (int i = 0; i < s.size(); i++){
        ait = a.find(s[i]);
        bit = b.find(s[i]);

        if (bit == b.end()) {
            if (ait == a.end()) {
                a.insert(s[i]);
                v.push_back(pair<char,int>(s[i], i));
            }
            else {
                b.insert(s[i]);
                bool found = false;
                for (int k = 0; found == false; k++) {
                    if (v[k].first == s[i]) {
                        v.erase(v.begin() + k);
                        found = true;
                    }
                }
            }
        }
    }
    if (v.size() != 0)
        return v[0].second;
    else
        return -1;
};