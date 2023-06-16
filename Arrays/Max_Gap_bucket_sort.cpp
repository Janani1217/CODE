/*
Maximum Gap :

Given an integer array nums, return the maximum difference between
two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in **** linear time and uses *****linear extra space.

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9],
either (3,6) or (6,9) has the maximum difference 3.

.................................................................................................
******

Approach : Pigeonhole method : there are 1 less holes than the total no. of pigeons. And try to
fit pigeons in the holes.

By using buckets and sorting them based on the magic formula:

Ip nums = [3,6,9,1]
n = 4


******

Calc :
#intervals = (max_num - min_num) / n-1 = (9-1)/3 = 3  (always take ceil value)
#elements = n = 4
#buckets = ele - 1 = 3

Magic formula : (num - min) / intervals

This is applied for each num present in the arr , in order to get the bucket in which the
num will fall into. So this formula will help to arrange each ele in buckets.

[3,6,9,1]

3 -> 3-1 / 3 = 0 = 0
6 -> 6-1 / 3 = 1.x = 1
9 -> 9-1 / 3 = 2.x = 2
1 -> 1-1 / 3 = 0 = 0

1....3  ...6  ...9

So (1,3) falls into one bucket
6 falls into second bucket
9 falls into third bucket

No we can observe that the list is also sorted.
So max work for the problem has been accomplished.

.................................................................................................


*****

Now we need to get the max gap between these numbers arranged.
we will get the max diff only between a max number - min number .

2nd bucket min ele (present on most left) - 1st bucket max ele (present on most right of its bucket)

will give us one of the ans for the max_gap.

We dont need to store all the numbers , we have to get the max and min number in each
bucket and that will resolve the problem.
Becuase the numbers which come in btw these min and max , wont be of any use , since
we would need the max gap.

.................................................................................................

For that :

1. take the min and max buckets of size n-1 = BucketMin[n-1] , BucketMin[n-1]
2. fill buckets with some init values
3. start filling buckets for reach ele
4. dont put the max and min ele calc

5. so process the numbers and use the magic formula to get the bucket index.
6. now when we get the bucket index , we compare the min and max and put them
   in the index of max and min buckets

7. so by doing this , if suppose we have 5 numbers inside the same bucket {3,4,6,8,9}
   but the min[index] will have 3
   and the max[index] will have 9

   because we need the same to compare with the adjacent buckets

8. once we fill the buckets , we need to compare the buckets and find the max_gap
9. take a var = prev -> store the minEle
10. start comparing the curr bucket Min ele with the prev
11. then keep prev = bucketMax[i]
12. and if any bucket is empty just ignore

13. at last compare the maxEle with the prev and find the diff
14. calc the maxgap and return.

.................................................................................................

TC = O(n)
SC = O(n)

.................................................................................................
*/

class Solution
{
public
   int maximumGap(int[] nums)
   {
      if (nums.length < 2)
         return 0;
      int n = nums.length;

      // find the min and max value
      int maxEle = nums[0];
      int minEle = nums[0];
      for (int i = 0; i < n; i++)
      {
         maxEle = Math.max(maxEle, nums[i]);
         minEle = Math.min(minEle, nums[i]);
      }

      // find the interval
      // take care of ceil ? convert the ans into decimal and wrte ceil and then convert back to int
      int interval = (int)Math.ceil((maxEle - minEle + 0.0) / (n - 1));
      int buckets = n - 1;

      // declare the max and min bucket
      int[] bucketMin = new int[n - 1];
      int[] bucketMax = new int[n - 1];

      // initialize the array
      Arrays.fill(bucketMin, Integer.MAX_VALUE);
      Arrays.fill(bucketMax, -1);

      // find the bucket for each ele using the magic formula
      // dont include the min and max ele into bucket
      // compare 1st bucket with the min ele
      // compare last bucket with the max ele

      for (int i = 0; i < n; i++)
      {
         if (nums[i] == minEle || nums[i] == maxEle)
            continue;

         int bucket = (nums[i] - minEle) / interval;
         bucketMin[bucket] = Math.min(bucketMin[bucket], nums[i]);
         bucketMax[bucket] = Math.max(bucketMax[bucket], nums[i]);
      }

      // compare the adjacent elements
      int max_gap = 0;

      // compare with the first min ele
      int prev = minEle;
      for (int i = 0; i < n - 1; i++)
      {
         // handle empty bucket
         if (bucketMax[i] == -1)
            continue;
         max_gap = Math.max(max_gap, bucketMin[i] - prev);
         prev = bucketMax[i];
      }

      // now we need to compare with the maxEle
      max_gap = Math.max(max_gap, maxEle - prev);
      return max_gap;
   }
}