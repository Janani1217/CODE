/*
Given an encoded string, return its decoded string.

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Input: s = "3[a2[c]]"
Output: "accaccacc"

*/

class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st; // to store the char

        // traverse through the string to apply logic
        for (int i = 0; i < s.size(); i++)
        {

            // push if u dont encounter closing backet
            if (s[i] != ']')
            {
                st.push(s[i]);
            }

            // closing bracket found
            else
            {
                // pop untill u get a open bracket
                string curr_str = "";

                while (!st.empty() && st.top() != '[')
                {
                    curr_str = st.top() + curr_str;
                    st.pop();
                }

                // pop the open bracket also : which ic of no use further
                st.pop();

                // find the number of times it has to be repeated in the ans str
                string num = "";

                while (!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }

                // convert this num into int
                int k = stoi(num);

                // push k times each char of the curr str
                while (k--)
                {
                    for (int i = 0; i < curr_str.size(); i++)
                    {
                        st.push(curr_str[i]);
                    }
                }
            }
        }

        // the decoded str is present in the stack
        string ans = "";

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
