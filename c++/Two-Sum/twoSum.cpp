/*
 * RJOrdway
 * 1st Solution, LeetCode 1: Two-Sum
 * 
 * Method:  Naive
 * 
 * Concern: This is in the O(n^2) space
 * 
 * Started:     8/31/22
 * Submitted:   8/31/22
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main() {
	vector<int> nums1 { 2,7,11,15 };
	int target1 = 9;
    vector<int> expected1 {0, 1};
    vector<int> result1 = twoSum(nums1, target1);
    cout << "Expected: {" << expected1[0] << "," << expected1[1] <<  
            "}, Result: {" << result1[0] << "," << result1[1] << "}" << endl;

	vector<int> nums2 { 3,2,4 };
	int target2 = 6;
    vector<int> expected2 {1, 2};
    vector<int> result2 = twoSum(nums2, target2);
    cout << "Expected: {" << expected2[0] << "," << expected2[1] <<  
            "}, Result: {" << result2[0] << "," << result2[1] << "}" << endl;

	vector<int> nums3 { 3, 3 };
	int target3 = 6;
    vector<int> expected3 {0, 1};
    vector<int> result3 = twoSum(nums3, target3);
    cout << "Expected: {" << expected3[0] << "," << expected3[1] <<  
            "}, Result: {" << result3[0] << "," << result3[1] << "}" << endl;

    return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {

    for (int i = 0; i < nums.size(); i++) {

        for (int k = i + 1; k < nums.size(); k++) {
            if (nums[i] + nums[k] == target)
                return vector<int> {i,k};
        }
    }
    // failed
    return vector<int>(0);
}