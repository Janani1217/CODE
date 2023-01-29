/*
***
INCOMPLETE *********

Problem statement :
Minimze operations to reduce a and b both to 1 by :
1. decr 1
2. div a/b or b/a
3.  if a divides b perfectly && b div a perfectly , then a/b &&
    b/a both are considered as 1 operation


For 3 case : if a div b and b div a perfectly , it means
a % b == 0
b % a == 0

***
This will only happen if both a and b are equal case :
a == b.
Now if both are equal then the given operations a/b && b/a , both
will return 1 as op in that case. So it means if (a==b) return 1
***

.....................................................................

Eg:
a = 13
b = 5

convert both to 1

Way 1 :
1. decr both by 1 -> a=12 , b=4 -> 2 operations
2. a = div a/b : a = 12/4 = 3 -> 1 op
3. decr b : b = 3 -> 1 op
4. now, a=3 && b==3 , so a==b -> 3rd condition satisfies ,
   return 1 : 1 operation

Total = 5 operations

Such there can be many , min we need to find

.....................................................................

Algorithm :
1.  base cases :

    if, we got the final ans , i.e a == 1 && b == 1, then return 0
    0: operations needed anymore.

    if, (a == b)  ||  (a%b== 0 && b%a==0)
        return 1 : considered as 1 operation


2.  remaining options take out ans and return the min among them :

    int ans1 = solve(a-1 , b)
    int ans2 = solve(a, b-1)

    if(a%b==0)
    int ans3 = solve(a/b , b)

    if(b%a==0)
    int ans4 = solve(a ,b/a)

    return min(min(ans1 , ans2) , min(ans3, and4)) ;


*/

#include <iostream>
using namespace std;

int findMinOperations(int a, int b)
{
    // base cases :
    if (a == 0 || b == 0)
        return 0;
    // final ans that is req is a==1 and b==1 , both then return 0 operations
    if (a == 1 && b == 1)
        return 0;

    // now if both a and b are equal , 3rd case considered as 1 operation
    if (a % b == 0 && b % a == 0)
        return 1;

    // remaining options
    int ans1 = findMinOperations(a - 1, b);
    int ans2 = findMinOperations(a, b - 1);
    int ans3 = 0;
    int ans4 = 0;

    if (b % a == 0)
        ans3 = findMinOperations(a, b / a);

    if (a % b == 0)
        ans4 = findMinOperations(a / b, b);

    return min(ans1, min(ans2, min(ans3, ans4)));
}

int main()
{
    int a = 13;
    int b = 5;
    int result = findMinOperations(a, b);
    cout << result << endl;
}