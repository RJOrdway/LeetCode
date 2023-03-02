/*
 * RJOrdway
 * 1st Solution, LeetCode 1011: Capacity To Ship Packages Within D Days
 * 
 * Method:
 * 
 * Concern:
 * 
 * Result:
 * 
 * Started:
 * Submitted:   
 */

#include <vector>
#include <algorithm>

using namespace std;

int shipWithinDays(vector<int>& weights, int days) {
        int largestPackage = weights[0];
        int sumOfPackages = weights[0];

        for (int i = 1; i < weights.size(); i++) {
            largestPackage = weights[i]*(weights[i]>largestPackage) + largestPackage*(largestPackage>=weights[i]);
            sumOfPackages += weights[i];
        }

        if (days == 1)
            return sumOfPackages;
        
        int divide = sumOfPackages/days; 
        int smallest = largestPackage*(largestPackage>)
}