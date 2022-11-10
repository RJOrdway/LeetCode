/*
 * RJOrdway
 * 1st Solution, LeetCode 350: Intersection of Two Arrays
 * 
 * Method:  Build Multimap from array one, values set to false.
 * 
 * Concern: 
 * 
 * Started:     9/4/22
 * Submitted:   
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * No testing done, code entered into IDE and worked.
 */

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> intersect;
    map<int, int> v; // v for validation, 1st int is the integer found,
                     // second int is how many
    map<int,int>::iterator it;
    for (int i = 0; i < nums1.size(); i++) {
        it = v.find(nums1[i]);
        if (it == v.end()) {
            v.insert(pair<int,int>(nums1[i],1));
        }
        else {
            it->second++;
        }
    }
    for (int k = 0; k < nums2.size(); k++) {
        it = v.find(nums2[k]);
        if (it != v.end()) {
            intersect.push_back(nums2[k]);
            if (it->second == 1) {
                v.erase(it);
            }
            else {
                it->second--;
            }
        }
    }
    return intersect;
}