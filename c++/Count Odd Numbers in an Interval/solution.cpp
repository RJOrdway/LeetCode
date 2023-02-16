/*
 * RJOrdway
 * 1st Solution, LeetCode 1523: Count Odd Numbers in an Interval Range
 * 
 * Method: Take (high-low)/2 and return (high-low)/2 +1 if high or low are odd, else return (high-low)/2
 * 
 * Concern: None
 * 
 * Result: setting int d = (high-low)/2;   caused an extra 100kb+ of memory use?!?!
 *          
 * 
 * Started:     02/12/23
 * Submitted:   02/12/23
 */

int countOdds(int low, int high) {
    int d = (high - low)/2;
    if (low%2==1 || high%2==1)
        return d+1;
    else
        return d;
}
