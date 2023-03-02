/*
 * RJOrdway
 * 1st Solution, LeetCode 912: Sort an Array

 * 
 * Method: Heap Sort
 * 
 * Concern: Though it handles all cases with time complexity of O(nlog(n)),
 *          it never exceeds this, even when the vector is already mostly sorted.
 *          Could be worth trying with a hybrid sort approach like Timsort
 * 
 * Result:
 *          Runtime 250 ms  Beats 43.93%
 *          Memory 61.3 MB  Beats 56.41%
 * 
 * Started:     02/28/23
 * Submitted:   03/01/23
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void heapify(vector<int>& nums, int n, int i);

// Heap Sort Version
vector<int> sortArray(vector<int>& nums) {

    for (int i = nums.size()/2 - 1; i >= 0; i--) {
        heapify(nums, nums.size(), i);
    }

    for (int i = nums.size() - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }

    return nums;
}

void heapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest]) {
        largest = left;
    }

    if (right < n && nums[right] > nums[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

int main() {
    vector<int> test1 {5,1,1,2,0,0};

    vector<int> result1 = sortArray(test1);

    cout << "First Test results Sorted: " << endl;
    for (int i = 0; i < result1.size() - 1; i++) {
        cout << result1[i] << ", ";
    }
    cout << result1[result1.size() - 1] << endl;

    cout << "Expected: " << endl;
    cout << "0, 0, 1, 1, 2, 5" << endl;
}

