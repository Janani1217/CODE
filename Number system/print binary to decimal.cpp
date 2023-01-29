#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 0;
    cin >> n;
    int i = 0, res = 0;

    /*
      while(n != 0) {
          int bit = n & 1;
          if(bit == 1)
          res = res + pow(2,i);
          n = n >>1;
          i++;
      }
    */

    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            res = res + pow(2, i);
        }
        n = n / 10;
        i++;
    }
    cout << res;
}

/*
First part = whenever we are playing with bits then we have to use = & and >> or <<
So here since we provide the input in int , the compiler will convert that binary form suppose 110 into again
binary and then do the bit processing on it.

So when we are providing binary numbers into int format , then we have to use digits i.e %10 and instead of
shifts , we need to use /10.
*/
