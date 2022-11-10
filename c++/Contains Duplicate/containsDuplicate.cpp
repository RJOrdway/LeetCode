/*
 * RJOrdway
 * 1st Solution, LeetCode 217: Contains Duplicate
 * 
 * Method:  add to set, check it.
 * 
 * Concern: I am not sure if the intent was to have me make my own set/map/BST,
 *          but they didn't say so, so this time, I am not.
 * 
 * Started:     8/30/22
 * Submitted:   8/30/22
 */
#include <set>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> v;
    for (int i = 0; i < nums.size(); i++) {
        if (v.find(nums[i]) == v.end())
            v.insert(nums[i]);
        else
            return true;
    }
    return false;
}