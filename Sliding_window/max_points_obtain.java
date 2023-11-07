https://www.youtube.com/watch?v=1DkVU2i3sOA

There are several cards arranged in a row, and each card has an associated number of points. 
  The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. 
  However, choosing the rightmost card first will maximize your total score. 
  The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.




  

class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int total_sum = 0;

        //1. get the toatal sum of arr
        for(int i : cardPoints) {
            total_sum += i;
        }

        //2. init req len 
        int req_len = n - k;

        // 3. init traversing var from start and end
        int start_index = 0;
        int curr_sum = 0;
        int min_sum = total_sum; // to store the minimal sum of the mid subarr out of wndw

        if(k == n) // if whole window is covered
            return min_sum;

        for(int i=0 ; i<n ; i++) {
            curr_sum += cardPoints[i];
            int curr_len = i - start_index + 1;
            
            // check validity of this window
            if(curr_len == req_len) {
                // upfate the sum calculated for the wndw
                min_sum = Math.min(min_sum, curr_sum);

                // move the strt index for the next window
                curr_sum -= cardPoints[start_index];
                start_index++;
            }
        }

        // ret the sum of the actual boundary window : 
        return total_sum - min_sum;
    }
}
