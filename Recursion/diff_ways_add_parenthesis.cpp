/*
Different Ways to Add Parentheses :

Given a string expression of numbers and operators.

Return all possible results from computing all the
different possible ways to group numbers and operators.

You may return the answer in any order.

eg:
Input: expression = "2-1-1"
Output: [0,2]

Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2

....................................................................................

Approach :

1.  think given exp as exp trees

2.  travserse over the exp and when we encounter an operator , divide
    the exp into right and left part into 2 subtrees and evaluate them
    seperately till we reach a situation where the exp is
    purely a single number

    simply retirn that no.

3.  sinve there will be miltiple ways in evaluating an expr

4.  depending on which operator is picked first , this will lead
    to forming a list of results from left and right part.

5.  now we have poss results from let and right part of the tree.
    we can use them to find out all poss results for the current
    operator.

** shown diagramatiicaly in notebook **

*/

class Solution
{
public:
    int perform(int x, int y, char op)
    {
        if (op == '+')
            return x + y;
        if (op == '-')
            return x - y;
        if (op == '*')
            return x * y;

        return 0;
    }
    vector<int> solve(string exp)
    {
        vector<int> res;

        bool isNum = true;

        // loop over exp

        for (int i = 0; i < exp.length(); i++)
        {
            char curr = exp[i];

            if (!isdigit(curr))
            {
                // make the flag false ****
                isNum = 0;

                // its an operator - divide the exp
                vector<int> left = solve(exp.substr(0, i));
                vector<int> rt = solve(exp.substr(i + 1));

                // now loop over the left and right ans
                for (int x : left)
                {
                    for (int y : rt)
                    {
                        int value = perform(x, y, curr);
                        res.push_back(value);
                    }
                }
            }
        }

        // only 1 number is left in the expr
        if (isNum == 1)
        {
            res.push_back(stoi(exp));
        }
        return res;
    }

    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> res = solve(expression);
        return res;
    }
};