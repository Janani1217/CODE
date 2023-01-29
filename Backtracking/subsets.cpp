/*
Problem statement :
Given an array : {1,2,3} of unique elemnts
Return a set of all subsets of the given input array
Return format : vector <vector<int>> ans;

......................................................................................................
......................................................................................................

Algo :

1.  Its a kind of include - exclude pattern BUT WITH BACKTRACKING
2.  If we include , put the number in output and move the index forward
3.  If we exclude , then dont include in op and move index forward
4.  Base case : If index reaches the end of the ip arr, then return
5.  Now after the recr call has been made, do the backtracking to retain original
    op -> copy the old to current

......................................................................................................
......................................................................................................

Now if we put the exclude case ahead of include case in code , then there is no need
of backtracking here.

So to show how backtracking works , this is the example.

*** It has vector<vector> , so its not able to execute in vscode ***

......................................................................................................
......................................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int> nums, vector<vector<int>> &op, int index, vector<int> temp)
{
    // base case :
    if (index == nums.size())
    {
        op.push_back(temp);
        return;
    }

    // include the curr number
    temp.push_back(nums[index]);
    index = index + 1;
    findSubsets(nums, op, index, temp);

    // backtrack : exclude case
    temp.pop_back();
    findSubsets(nums, op, index, temp);
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    // in funct we need ip, op vector , current index, temp vector
    vector<vector<int>> op;
    int index = 0;
    vector<int> temp;

    findSubsets(nums, op, index, temp);

    for (int i = 0; i < op.length(); i++)
    {
        for (int j = 0; j < op[0].length(); j++)
        {
            cout << op[i][j] << " ";
        }
        cout << endl;
    }
}