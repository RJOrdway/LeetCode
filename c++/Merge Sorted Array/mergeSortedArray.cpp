/*
 * RJOrdway
 * 1st Solution, LeetCode 88: Merge Sorted Arrays
 * 
 * Method: Use a copy of relevant values of nums1, which comes at a memory cost,
 *         and iterate over the copy and nums2 until reaching the end of one. Then
 *         dump remaining values from vector that wasn't fully iterated over into nums1.
 *         Also decided this was a good example to test branchless programming.
 * 
 * Concern: Memory cost of copied array is probably avoidable, maybe bool x can also be eliminated.
 *          Code readability is hampered by branchless attempts.
 * 
 * Outcome: As expected, the code is in the top quartile for speed,
 *          and lower end of 3rd quartile for memory use
 * 
 * Started:     9/2/22
 * Submitted:   9/2/22
 */

#include <iostream>
#include <vector>
#include <algorithm> // for copy_n


using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
void vectorCompare(vector<int> expected, vector<int> actual);

int main() {

    vector<int> nums1a {1,2,3,0,0,0};
    int m1 = 3;
    vector<int> nums1b {2,5,6};
    int n1 = 3;
    vector<int> expected1 {1,2,2,3,5,6};
    merge(nums1a, m1, nums1b, n1);
    vectorCompare(expected1, nums1a);

    vector<int> nums2a {1};
    int m2 = 1;
    vector<int> nums2b {};
    int n2 = 0;
    vector<int> expected2 {1};
    merge(nums2a, m2, nums2b, n2);
    vectorCompare(expected2, nums2a);

    vector<int> nums3a {0};
    int m3 = 0;
    vector<int> nums3b {1};
    int n3 = 1;
    vector<int> expected3 {1};
    merge(nums3a, m3, nums3b, n3);
    vectorCompare(expected3, nums3a);
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // copy method - memory cost
    vector<int> cpnums1(nums1.cbegin(), next(nums1.cbegin(), m));

    int i = 0, cpnums1counter = 0, nums2counter = 0;
    // Attempting branchless this time, I think this is a good opportunity and I am
    // already paying a memory tax, might as well go all in on speed
    while (cpnums1counter < m && nums2counter < n) {
        // x for nums2 advance, !x for cpnums1 advance
        bool x = (cpnums1[cpnums1counter] >= nums2[nums2counter]);
        nums1[i] = (cpnums1[cpnums1counter] * (!x))  +  (nums2[nums2counter] * x);
        i++;
        nums2counter += 1*x;
        cpnums1counter += 1*!x;
    }
    // in either case of remaining values we have not iterated, we just need to dump them in
    // vector pointer depends on boolean test
    vector<int>* finalVector;
    int finalIterator;
    if (cpnums1counter < m) {
        finalVector = &cpnums1;
        finalIterator = cpnums1counter;
    }
    else {
        finalVector = &nums2;
        finalIterator = nums2counter;
    }
    while (i < m+n) {
        nums1[i] = (*finalVector)[finalIterator];
        i++;
        finalIterator++;
    }
}

void vectorCompare(vector<int> expected, vector<int> actual) {
    cout << "Expected:\t";
    for (int i = 0; i < expected.size()-1; i++) {
        cout << expected[i] << ",\t";
    }
    cout << expected.back() << endl;
    cout << "Result:\t\t";
    for (int k = 0; k < actual.size()-1; k++) {
        cout << actual[k] << ",\t";
    }
    cout << actual.back() << endl << endl;
}