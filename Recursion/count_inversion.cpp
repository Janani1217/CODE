/*
Problem Statement : find the inversion count in the array
Inversion Count = for an array , inversion count indicates how far an element is from being sorted
If the arr is already sorted then the inversion count = 0.
If the arr is sorted in reverse order , the inversion count is MAX.
2 ele for inversion if , a[i]>a[j] && i<j

So to get the count , we need to check this condition
a[i] > a[j] && i<j

Eg: [6,3,5,2,7]
count = 5
inversions = {[6,3], [6,5], [6,2], [3,2], [5,2]}

My analysis : for each element , find how many ele are smaller than itself on its right part in the arr

Brute force : for each ele , find in the remaining arr , which are smaller = O(n^2)

*/