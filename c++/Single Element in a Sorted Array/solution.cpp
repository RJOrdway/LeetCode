/*
 * RJOrdway
 * 1st Solution, LeetCode 540: Single Element in a Sorted Array

 * 
 * Method: partition and search
 * 
 * Concern: Rough, needs to be cleaned up and may have room for optimization
 * 
 * Result:
 *          Runtime 40 ms   Beats 17.22%
 *          Memory  22.3 MB Beats 93.44%
 * 
 * Started: 02/21/23
 * Submitted: 02/21/23
 */

#include <vector>

using std::vector;

int singleNonDuplicate(vector<int>& nums) {
    return recurSearch(nums, 0, nums.size()-1);
}

//TODO: REMOVE INT SOLUTION, change to return after testing
int recurSearch(vector<int>& nums, int lowerIndex, int upperIndex) {
    if (upperIndex-lowerIndex <= 1)
        return nums[lowerIndex];
    int partSize = upperIndex - lowerIndex + 1;
    int medIndex = lowerIndex + (upperIndex - lowerIndex)/2;
    int solution;

    // even partition
    if ((upperIndex-medIndex)%2 == 0) {
        // median & median +1 are the same, go upper partition
        if (nums[medIndex] == nums[medIndex + 1])
            solution = recurSearch(nums, medIndex + 2, upperIndex);
        // if not, we go lower partition
        else {
            // but first, we check if our median is our singleton
            if (nums[medIndex] != nums[medIndex - 1])
                return nums[medIndex];
            else
                solution = recurSearch(nums, lowerIndex, medIndex - 2);
        }

    }
    // odd partition
    else {
        // median & median -1 are the same, go upper
        if (nums[medIndex] == nums[medIndex - 1])
            solution = recurSearch(nums, medIndex + 1, upperIndex);
        // if not, go lower
        else {
            /*if (nums[medIndex - 1] != nums[medIndex - 2])
                return nums[medIndex - 1];
            else*/
                solution = recurSearch(nums, lowerIndex, medIndex - 1);
        }
    }

    return solution;
}

int main() {
    vector<int> test1 {1,2,2,3,3};
    singleNonDuplicate(test1);
}