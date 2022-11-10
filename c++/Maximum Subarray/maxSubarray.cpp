/*
 * RJOrdway
 * 1st Solution, LeetCode 53: Maximum Subarray
 * 
 * Method:  Kadane's Algorithm
 * 
 * Concern: Tried in place instead of creating second vector for max, memory was
 *          slightly improved, runtime was awful. Alternatively, avoiding <algorithm> using
 *          C++17 tools might perform better, but I would have to learn those tools.
 * 
 * Started:     8/31/22
 * Submitted:   8/31/22
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums);

int main() {

    vector<int> t1 {-2,1,-3,4,-1,2,1,-5,4};
    int expect1 = 6;
    int result1 = maxSubArray(t1);
    cout << "Expected: " << expect1 << ", Result: " << result1 << endl;

    vector<int> t2 {1};
    int expect2 = 1;
    int result2 = maxSubArray(t2);
    cout << "Expected: " << expect2 << ", Result: " << result2 << endl;

    vector<int> t3 {5,4,-1,7,8};
    int expect3 = 23;
    int result3 = maxSubArray(t3);
    cout << "Expected: " << expect3 << ", Result: " << result3 << endl;


}

int maxSubArray(vector<int>& nums) {
        vector<int> localMax(nums.size());

        localMax[0] = nums[0];
        int x = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            localMax[i] = max(nums[i], localMax[i-1] + nums[i]);
            x = max(x, localMax[i]);
        }
        return x;
}