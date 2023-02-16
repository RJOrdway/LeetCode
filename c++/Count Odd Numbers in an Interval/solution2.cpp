/*
 * RJOrdway
 * 1st Solution, LeetCode 1523: Count Odd Numbers in an Interval Range
 * 
 * Method: Take (high-low)/2 and return (high-low)/2 +1 if high or low are odd, else return (high-low)/2
 *         Without setting variable this time
 * 
 * Concern: None
 * 
 * Result: Better Memory performance(reduction of over 100kb?!?), faster runtime may have been glitch (0 ms)
 *          
 * 
 * Started:     02/12/23
 * Submitted:   02/12/23
 */

int countOdds(int low, int high) {
    if (low%2==1 || high%2==1)
        return (high-low)/2+1;
    else
        return (high-low)/2;
}
