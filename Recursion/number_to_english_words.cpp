/*
Problem statement :

--> could not solve here, but approach is correct : solved in leetcode: "Integer to english word" problem :

Given a number n , convert into english words repr.
Eg: n = 123
op => one hundred twenty three

n = 24567
op -> twenty four thousand five hundred sixty seven

n = 897
op -> eight hundred ninety seven

........................................................................................................
........................................................................................................

Dry Run for the approach :

Eg 1:

1.  need to tell the compiler to map for few numbers are strings in some map DS

    1 till 19 -> one , two, three ... nine..eleven..nineteen.
    20,30,40,....90 -> twenty , thirty ,,,,,, ninety
    100 -> hundred
    1000 -> thousand
    1000000 -> million
    1000000000 -> billion


2.  n = 123

    Check if n > billion - no , million - no , thousand - no , hundred - yes

    n lies btw 100 -> 999
    so, base = 100

3.  now divide by that base number : num = 123 / 100 = 1 : check in map for num :
    print -> num , base
    it will print : one hundred
    remaining : 23
    send f(23) to solve

4.  now n becomes = 23
    check for base : n > 20
    base = 20

5.  if (n < 100) :
    we will print "base" only from map = twenty
    remaining : 3
    send f(3) to solve

5.  now n = 3
    from map DS , we get direct mapping : three

6.  Total printing statement : one hundred twenty three


........................................................................................................

Eg 2 :

1.  n = 3456
    check for base condition with million,billion,thousand -> yes
    base = thousand

2.  find the number : n/base = 3456/1000 = 3
    num = three : check in map for num :

3.  print : three thousand
    remaining : f(456)

4.  base = 100
    n !<100 -> find number : n/base = 456/100 = 4
    num = four :check in map for num :

    print : four hundred
    remaining : f(56)

5.  n<100 -> base = 50
    print base : fifty
    remaining (6)

6.  print "six"

7.  total print : three thousand four hundred fifty six

........................................................................................................

Eg 3 :

1.  n = 12345
    base = billion, million, housand -> yes
    n > 100 :
    num = 12345/1000 = 12 : check in map for num :
    print : twelve thousand

2.  f(345) -> base 100
    n > 100
    num = 345/100 = three : check in map for num :
    print : three hundred

4.  f(45) -> n < 100
    base = 40
    print fourty

5.  f(5) -> print five

6. total print : twelve thousand three hundred fourty five


........................................................................................................

Eg 4 :

1.  n = 1234567
    base -> 1234567 > 1000000 = million
    num : 1234567/1000000 = one
    print : one million

2.  f(234567) :
    base -> 234567 > 1000 = thousand

    now num = 234 : check in map for num :
    english word not found in mapping : means we need to call again for this

    2.1     f(234) :
            base = 100 = hundred
            num : 234 / 100 = 2 = two

            f(34) :
            n < 100 : 34/30 : thirty

            f(4) :
            n < 100 : 4 : four

    2.2     return the print "two hundred thirty four"

    Total print : two hundred thirty four thousand


3.  f(567):
    /// remaining we know



........................................................................................................

Eg 5 :

1.  n = 1010
    base : 1010 > 1000 : thousand
    num : 1010 / 1000 = 1 : in map : one
    rem = 1010 % 1000 = 10

2.  f(10)
    base = 10 : ten

3.  print total "one thousand ten"


........................................................................................................

Eg 6 :

1.  n = 12000
    base : 12000 > 1000 = thousand
    num = 12000 / 1000 = 12 : in map : twelve
    rem = 12000 % 1000 = 0 : nothing
    print : twelve thousand


........................................................................................................

Eg 7 :

1.  n = 102
    base : 102 > 100 : hundred
    num : 102/100 = 1 : in map : one
    rem = 102%100 = 2 : f(2)

2.  n = 2 : < 100 : in map : two
3.  total print : one hundred two


........................................................................................................
........................................................................................................

Approach :

1.  create a 2D vector to store the number and its english words for that : map <int ,string> for :
    1 - 19 ,
    20 30 40 50 60 70 80 90 100 ,
    1000 , 1000000, 1000000000

2.  Get the base : need to compare with numbers in map : so run a loop
    if (n >= i.first)

3.  There are total 3 things to do once we get the base :

    3.1     find the num : n/i.first
            send in recr call, to get the mapping done : eg: if num = 12
            f(12) -> in return statement, first condition nothing , second condition it will print
            from the mapping , third nothing will be passed , and it gets back to the last called
            point in the parent call of recr.

    3.2     printing the base number from the mapping

    3.3     for the remaining number left in n : send a recr function :
            f (n % i.first);


*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, string>> arr = {{1000000000, "Billion "}, {1000000, "Million "}, {1000, "Thousand "}, {100, "Hundred "}, {90, "Ninety "}, {80, "Eighty "}, {70, "Seventy "}, {60, "Sixty "}, {50, "Fifty "}, {40, "Forty "}, {30, "Thirty "}, {20, "Twenty "}, {19, "Nineteen "}, {18, "Eighteen "}, {17, "Seventeen "}, {16, "Sixteen "}, {15, "Fifteen "}, {14, "Fourteen "}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

string solve(int n)
{
    // base
    if (n == 0)
        return "Zero ";

    // to get base : compare from the mapping
    for (auto i : arr)
    {
        // comparing with bases
        if (n >= i.first)
        {
            /*
            1.  if n >= 100 , then to get the num call further , else anyhow we will be printing base
                indicated by the second param next.
            2.  print english word of num
            3.  further recursive call for remaining elements of n.
                if no number is not left after 20/20 == 0, then nothing to send in recr call.
            */
            return (n >= 100 ? solve(n / i.first) : "") + (i.second) + ((n % i.first == 0) ? "" : solve(n % i.first));
        }
    }
    return "";
}

int main()
{
    int n = 1234;
    string result = solve(n);
    // remove the space for the last word, since we need spacing in the result between the words
    result.pop_back();
    cout << result;
}