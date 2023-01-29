/*
**************
PS : min sideways jump

There are 3 lane road of length = n
Each lan has n+1 POINTS : 0 -> n

A frog in the 2nd lane start from point 0 and want to jump to point n.
There could be obstacles in between

Obstacles[n+1] : given arr of n+1 size
Obstacles[i] : 0 <= i <= 3 , where i repr the lane
If obs[i]==0 : no obs at point i
There will be atmost(max) 3 obstacles at each point in the 3 lanes

Eg :
obs[2]==1 : -> there is an obs at lane 1 at point 2

So a frog can jump from point[i] to point[i+1] on same lane if no ons on i+1
If obs present at point[i+1], then from can take side lane jump also.
It can jump to the another lane at same point if no obs in the new lane
And the side lane it jump may or may not be adjacent.

Eg :
A frog can jump from [lane3, point3] to [lane1, point3]

Return MIN NO. OF SIDE JUMPS THE FROG NEEDS TO DO TO REACH 0 TILL N , if frog
starts from lane2 , point0.

....................................................................................

Approach :

1.  if the frog's curr pos reaches till the endpos of any lane , i.e n-1 pos ,
    then we can return , which forms the bc

2.  Now at every pos , thr frog has 3 options : move front, up, down =>
    based on the below conditions checked :
        1.  no obstacle in new pos
        2.  not out of bound

3.  obs[0] = i : it means at pos 0 , at lane i , obs is present , so i will have
    only 3 values since 3 lanes only

4.  Front move condition : if(obs[currPos]+1 != currLane)

*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<int> obs, int pos, int n)
{
    // bc : if frog pos reaches till end of lane
    if (pos == n - 1)
    {
        return 0;
    }
}

int main()
{
    vector<int> obs;
    obs.push_back(0);
    obs.push_back(1);
    obs.push_back(2);
    obs.push_back(3);
    obs.push_back(0);

    int n = obs.size();

    int ans = solveRec(obs, 0, n);
}