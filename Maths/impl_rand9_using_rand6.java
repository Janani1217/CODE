/* 

PS : Implement rand9() using rand6()

Given already a func rand6() which will give a randon number from 1 to 6 with equal probability. 
Write one liner function rand9() using rand6() which will return a random 
number between 1 to 9 with equal probability.

Solution should minimize the number of calls to rand6()
use of any library functions and floating point arithmetic are not alowed

.................................................................................................

Approaches :

rand6() op = 1,2,3,4,5,6
rand9() op = 1,2,3,4,5,6,7,8,9

Appr 1 : if we use only one call to rand6()
    1.  we cannot map smaller range of values to a bigger range of val
    2.  like 1->6 cant be mapped to 1->9, one number can be mapped only to one single num only
    3.  so we need to use more calls to rand6()

Appr 2 : if 2 calls are made 
    1.  now we have suppose 2 6-faced dice. Think rand6() in that manner
    2.  how may occuurances are poss -> 36 (since there are 2 dice)
    3.  now the range has increased to 36 
    4. by using some formula we can map 36 to 9 occurances
    
    suppose we have the question , using rand6() impl rand5() we would just 
    need one call/occurance to rand6() , since range of outer is 5 < 6.
    
So Appr 2 can be used.

.................................................................................................


Approach : 

Look into Note book for better undertsnaing.


 */

package Maths;

public class impl_rand9_using_rand6 {

    // random function which can return anything
    // between 1->6
    public int rand6() {
        return 0;
    }

    public int solve() {
        int x = rand6();
        int y = rand6();
        int val = (x - 1) * 6 + y;
        int ans = val % 9 + 1;
        return ans;
    }
}
