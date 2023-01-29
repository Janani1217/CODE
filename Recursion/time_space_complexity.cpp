/*

Time and space complexity of recursive algo:

Time complexity : time required to run an algorith based on the input provided.

1.  counting problem : print in decreasing order

    base case : n == 0 , return 0 -> constant time (k)
    recursive rel = f(n) -> f(n-1)
    TC recursive relation = T(n) -> k + T(n-1)

    solve recr relation:
    T(n) = k + t(n-1)
    t(n-1) = k + t(n-2)
    t(n-2) = k + t(n-3)
    ..
    ..
    ..
    t(0) = base case = take K time = k

    If we add up or solve the above pattern , t(n-1) replaced by below expression
    Same t(n-2) will be replaced by its expression.
    At last t(1) will be replaced by t(0) = k

    So total , from t(n-1) to t(1), only k remains in all cases
    So there are total n times k and last 1 extra k1 for t(0),

    Final output : T(n) = (n*k)+k1 = O(n)




2.  factorial :

    base case : n==1 return 1 -> k
    recr relt : f(n) = n * f(n-1)   // TC concerned only about functions
    TC recur  : T(n) = n*K + T(n-1) = K + T(n-1)
    Same as prev TC = O(n)


3.  fibonocci :

    base case : n==1 || n==0 , return 1 -> k
    recr rela : f(n) = f(n-1)+f(n-2)
    TC rec rl : T(n) = T(n-1)+T(n-2)

    solve:
    T(n) = t(n-1) + t(n-2)
    t(n-1) = t(n-2) + t(n-3)
    ...
    ..
    t(2) = t(1) + t(0)
    t(1) = 1
    t(0) = 1

    So , overall T(n) = 2 * T(n-1)
                      = 2*n * O(n)
                      = O(n)



4.  Binary search : 

    base case: n==0 , return -1 -> k
               arr[mid] == target , return mid
    recr rela: f(n) -> f(n/2)
    TC recr  : T(n) -> T(n/2)

    solve:
    t(n) = k + t(n/2)
    t(n/2) = k + t(n/4)
    t(n/4) = k + t(n/8)
    ..
    ..
    t(1) = k (can be eq to target or anything like -1)

    now everythings gets cancelled out and remaining comes out as :
    f(n) = n/(2^0) = n
    f(n/2) = n/(2^1) = n/2
    f(n/4) = n/(2^2) = n/4
    ..
    ..
    in the ath iteration : base case 
    f(1) = f(n/2^a) = 1
    n/(2^a) = 1
    n = (2^a)
    log n = a

    So T(n) at the final ath iteration will be = O(log n)


5. Merge Sort :

*** We always write T(n...) only when there is a recursive call in any of the function.
    For the iterative case , we can directly write the total TC in that function.
    Like if a function which is not recursive , has while or for loops, we write
    the TC of it directly after calculation. There is no need of the recursive
    TC Function to be solved like previous cases.

    Now in merge sort we have total 2 functions : partition & Sorting
    Partition has 2 recursive calls within it for left and right part division into 
    2 halves.
    Sorting function / Merge function is a iterative function , used to merge 2 sorted
    arrays obtained from the above 2 recursive divisions.

    So we need to calcl the TC for below algo:
    MergeSort (Arr)
    {
        //base case
        size = 1 return

        int mid = (l+r)/2
        partition(arr , l , mid)
        partition(arr , mid+1 , r)
        merge(arr , l , r)
    } 

    T(n) = k1 + k2 + T(n/2) + T(n/2) + ___

    Now the merge function if we see , we have 2 for loops and 2 while loops 
    which runs on both the arrays independently , so overall it will throw TC
    of O(n) 

    So the TC equation becomes

    T(n) = k + 2T(n/2) + n
    T(n/2) = k + 2T(n/4) + n
    T(n/4) = k + 2T(n/8) + n
    ..
    ..

    T(1) = 2T(0) 
    This is some ith iteration which has termination condition.
    Now , 2T cannot be cancelled out with T, so multiply 2

    T(n) = 2T(n/2) + n*p
    2T(n/2) = 4T(n/4) + 2np
    4T(n/4) = 8T(n/8) + 4np
    ..
    ..
    T(1) = 2T(0)
    
    So here other things gets cancelled out , and the np runs for everytime half size
    So it runs totally logn times

    T(n) = logn (np)
         = nlogn


6.  

