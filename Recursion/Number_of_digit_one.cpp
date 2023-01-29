/*
***** VVI ****
Problem statement : Number of digit 1 :

Given an ip integer number.
Op = give total number of 1's appearing in all non-negative integers appearing in
that number.

............................................

Eg 1:
n = 13 : 0,1,2,3,4,5,6,7,8,9,10,11,12,13

Total number of 1's in : 1 = 1 , 10 = 1 , 11 = 2 , 12 = 1 , 13 = 1
OP ==> 6

Eg 2:
n = 0 : 0
OP = 0


............................................

Approach :

Eg 1: n = 7162 , find total no. of 1's

1.  Lets break this n as follows:

    find total 1's between :

    7000 -> 7162 = f(162)
    6000 -> 6999 = f(999)
    5000 -> 5999 = f(999)
    4000 -> 4999 = f(999)
    3000 -> 3999 = f(999)
    2000 -> 2999 = f(999)

    1000 -> 1999 = f(999) + for all 1000 number in this range , 1 in the first place will also be there
                 = f(999) + 1000

    0 -> 999 = f(999)

2.  So total we find 3 cases here :

    a.  f(999) = 7 times = first digit of n = 7
    b.  f(162) = n / 1000 = n % base
    c.  Add 1000 = base // one's in base

    Final formula comes out to be :

    base = 1000 //conside

    int digit = n%base      // 7

    f(n) = [ digit * f(base-1) ] +
           [ f(n / base)] +
           [ base ]

............................................


Eg 2 : n = 13
Op = 6

1.  Take 1st digit = 1
2.  So for 1st digit as 1 , the case will be different
3.  here base = 10 , so break 13 as :

    digit = 1
    base = 10

    0 -> 9 = f(9)  // digit * f(base-1)
    10 -> 13 = 4  //  [ n - base + 1 ]



4. final formula becomes here :

    f(n) = [ f(n / base) ] +
           [ n - base + 1]

............................................

Eg 3 : n = 74899

1.  Find Base :
    length(n) = 5
    base = 10^len-1 = 100000

2.  Break n :
    70000 -> 74899 = f(4899)
    60000 -> 69999 = f(9999)
    50000 -> 59999 = f(9999)
    40000 -> 49999 = f(9999)
    30000 -> 39999 = f(9999)
    20000 -> 29999 = f(9999)
    10000 -> 19999 = f(9999) + 10000
    0 -> 9999 = f(9999)

3.  Put in formula :

    digit = n%base
    digit != 1 :

    f(74899) = f(4899) + [7*f(9999)] + 10000
    f(n) = f(n/base) + [digit * f(base-1)] + base

............................................

Eg 4 : n = 15888

1.  Find Base :
    len = 5
    base = 10^len-1 = 10000

2.  break n :

    digit = n%base
    digit == 1 :

    10000 -> 15888 = f(5888) + 5889 //since we have total [15888 - 10000 + 1] 1's in the first place
    0 -> 9999 = f(9999)

    f(15888) = f(5888) + 5889 + [ 1 * f(9999) ]
    f(n) = f(n/base) + [n-base+1] + [ digit * f(base-1) ]

............................................

******
So the main difference in formula depends on the first digit of n:
1.  if n == 1 , then f(n) = f(n/base) + [n-base+1] + [ digit * f(base-1) ]
2.  if n != 1 , then f(n) = f(n/base) + [base] + [ digit * f(base-1) ]
******

............................................

Code approach :

1.  base case :
    if(n < = 0) return 0
    if(n < 10) return 1

2.  find len = getLength(n);
3.  find base = 10 ^ (len-1);
4.  find digit = (n / base);

5.  condition applies :

    if(digit == 1){
        one_in_base = (n-base+1)
    }else{
        one_in_base = base
    }

6.  find the remaining parameters and return result :

    int result = f(n%base) + (digit * f(base-1)) + one_in_base;
    return result ;
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getTotalOne(int n)
{
    // base case
    if (n <= 0)
        return 0;
    if (n < 10)
        return 1;

    // find required params
    int len = to_string(n).length();
    int base = pow(10, len - 1);
    int digit = n / base;
    int one_in_base = 0;

    // cout << digit << endl;
    if (digit == 1)
    {
        one_in_base = n - base + 1;
    }
    else
    {
        one_in_base = base;
    }

    int formula_result = getTotalOne(n % base) + (digit * getTotalOne(base - 1)) + one_in_base;

    return formula_result;
}

int main()
{
    int n = 13;
    int result = getTotalOne(n);
    cout << result << endl;
    return 0;
}