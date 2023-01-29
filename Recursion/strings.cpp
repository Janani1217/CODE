#include <iostream>
#include <vector>
using namespace std;

/*
1. subseq of string
2. addition of 2 str
*/

vector<string> subsequence(string s, int index, string ans, vector<string> &output)
{
    // base case
    if (s.length() == index)
    {
        // cout << ans << "\n";
        output.push_back(ans);
        return output;
    }

    // either exclude or include the current character and move index in both cases
    //  1. include in ans
    subsequence(s, index + 1, ans + s[index], output);
    // 2. exclude in ans
    subsequence(s, index + 1, ans, output);
    return output;
}

string reverseStr(string &str, int i, int j)
{
    // base case
    if (i == j || i > j)
        return str;

    // swap
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    return str;
}

string addNumbers(string s1, string s2, string &output, int i, int j, int carry)
{
    // base case
    if (i == s1.length() && j == s2.length())
    {
        if (carry == 1)
        {
            output += "1";
        }
        return output;
    }

    if (i >= s1.length())
    {
        // means i reached last already and j has elements in it
        int second = (int)s2[j] - '0';
        int sum = carry + second;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        string res = to_string(sum);
        output += res;

        addNumbers(s1, s2, output, i, j + 1, carry);
    }
    else if (j >= s2.length())
    {
        int first = (int)s1[i] - '0';
        int sum = carry + first;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        string res = to_string(sum);
        output += res;

        addNumbers(s1, s2, output, i + 1, j, carry);
    }
    else
    {

        // add two numbers
        int first = (int)s1[i] - '0';
        int second = (int)s2[j] - '0';
        int sum = carry + first + second;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        string res = to_string(sum);
        output += res;

        addNumbers(s1, s2, output, i + 1, j + 1, carry);
    }

    return output;
}

int main()
{
    string str = "abc";

    // vector<string> output;
    // string ans = "";
    // output = subsequence(str, 0, ans, output);

    // for (int i = 0; i < output.size(); i++)
    // {
    //     cout << output[i] << "\n";
    // }

    string s1 = "909";
    string s2 = "1";

    // add 2 numbers
    // reverse both str
    int n1 = s1.length();
    int n2 = s2.length();
    s1 = reverseStr(s1, 0, n1 - 1);
    s2 = reverseStr(s2, 0, n2 - 1);

    // now add both str
    string ans = "";
    ans = addNumbers(s1, s2, ans, 0, 0, 0);
    ans = reverseStr(ans, 0, ans.length() - 1);
    cout << ans << "\n";
}