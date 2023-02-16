/*
 * RJOrdway
 * 1st Solution, LeetCode 989: Add to Array-Form of Integer
 * 
 * Method: # Reverse iterate through array [i] until iteration done or k == 0
 *              ## Create digit from k%10,
 *              ## Add digit + existing value in array index (+1 if carry over from 
 *                 last operation)
 *              ## If greater than 10, reduce by 10 and set carry to true
 *              ## Set num[i] to digit
 *              ## k = k / 10
 *              ## repeat
 * 
 *         # If k done before iterated through num, make sure carry is false:
 *              ## add and iterate similar to above (but without k)
 *              ## end if carry = false or finished iterating
 * 
 *         # If iterating done before k is 0, loop until k == 0:
 *              ## digit = k%10 (+1 if carry is true)
 *              ## set k = k/10
 *              ## if digit is 10, insert 0 to front of num and keep carry true
 *              ## else insert digit to front of num and set carry false
 * 
 *         # Final Carry check, if true, insert 1 in front of num;
 * 
 * 
 * Concern: Could be cleaner, self documenting code
 *          Maybe better to use reverse iterator?
 *          Might be way to avoid insert O(n) in cases where n has more digits than num,
 *          but based on given constraints, num can be 10^4 elements, k can only be =10^4
 *          therefore there can only ever be 3 of these costly inserts vs almost a thousand
 *          normal operations
 * 
 * Result: Not as bad as expected
 *         Runtime 30 ms    Beats 73.1%
 *         Memory  27.3 MB  Beats 86.27%
 * 
 * Started:     2/14/23
 * Submitted:   2/15/23
 */

#include <vector>

using std::vector;


vector<int> addToArrayForm(vector<int>& num, int k) {
    bool carry = false;
    int digit = 0;

    int i;
    for (i = num.size() - 1; i > -1 && k > 0; i--) {
        digit = k % 10;
        k=k/10;
        num[i] += digit + carry*1;
        if (num[i] >= 10) {
            carry = true;
            num[i] -= 10;
        }
        else
            carry = false;
    }

    while(i > -1 && carry) {
        digit = num[i] + carry*1;
        if (digit == 10) {
            num[i] = 0;
        }
        else {
            num[i] = digit;
            carry = false;
        }
        i--;
    }

    while (k > 0) {
        digit = k % 10;
        k=k/10;
        
        if (digit + carry*1 == 10){
            num.insert(num.begin(), 0);
        }
        else {
            num.insert(num.begin(), digit + carry*1);
            carry = false;
        }
    }

    if (carry) {
        num.insert(num.begin(), 1);
    }

    return num;
}

int main() {
    vector<int> testnum1 {6};
    int testk1 = 809;
    addToArrayForm(testnum1, testk1);

    return 1;
}
