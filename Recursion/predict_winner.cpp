/*

Problem Statememt :
There is an array representing the score of players.
There are 2 players : p1, p2

Always p1 starts the game.

Players can select any of the : first ele in the arr or the last ele

After selection , the ele gets removed from the arr, size reduces by 1
and the number adds to the score of the player

Return true if p1 wins. if both scores are equal then also p1 wins
Both players play the game to win always

Approach:
1. Both players have 2 options each time : either selct starting ele or last ele
2. Now among them which gives the max scode, player will select that ele.

    ele1 = first ele in arr
    ele2 = last ele in arr

    option 1 = pick the first element = score_p1 + ele1 , call recr on rem ele
    option 2 = last ele picked = score_p1 + ele2 , call recr on rem ele

    score_p1 = max (option 1 , option 2);

3. Now p2 will play in the remaining set of elements.
4. Now whoever player plays its turn, it will always want itself to win.
5. It will win only when the opposite player scores lesser than itself.
6. So the next player will win only if it gives out the min ele from the recur
    call which will add to the score of the previous player which has made the
    call.

    option_1_player 1 = score_p1 + ele_selected + min(recr call on remaining ele)

    Here the recur call will be for the next player.

    The next player will want that player 1 total score should be min than itself.
    So it will pass the min of the whole recursive function output.

    Hence the min(...) call has been made.

7. It means it selects the ele in both 2 options and then when it calls the recur
    function for the next play which its opp player will play , it calls with
    min of the both options

*/

#include <iostream>
#include <vector>
using namespace std;

int predictWinnerUtils(vector<int> &nums, int i, int j)
{
    // base case
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return nums[i];
    }

    /*
    recursive function :

    suppose player 1 plays
    there are 2 options for him : either first ele or last ele select
    accordingly the score adds to him.

   if p2 selects arr[i+1], remaining will be i+2 -> j
   else if p2 selects arr[j] , remaining will be i+1 -> j

   eg : inital arr = [5,2,4,7,6]
   p1 -> op1 = i on 5 -> selects 5
         remaing = [2,4,7,6] for p2

         op2 = j on 6 -> selects 6
         remaing = [5,2,4,7] for p2

   since p1 is playing to win the game -> increase its score than p2
   so p1 thinks :
   if p2 -> op1 = i+1 on 2 -> selects 2
            remaing = [4,7,6] for p1

            op2 = j-1 on 7 -> selects 7
            remaing = [5,2,4] for p2

    now the next call is for p2.

    now p2 knows it has to return some output , which will be added to p1 score
    via the recursive call.

    so , p2 what it does , it selects one element and then whatever answer it recieves
    from the next recursive call, among them the min , score it pases to p1 recur call.
    suppose p2 recieves 13, 17 after adding its own ele , so it finds the min 13
    and passes it to p1, which will be added to p1 score.
   */

    /* selects first element in arr
      passes the min of the future calls output is added to previous / called
      player score */

    /* if p1 starts the play, the recursive call is played by p2, so whatever p2
       thinks , that min val should be added to p1 score */

    int option_1 = nums[i] + min(predictWinnerUtils(nums, i + 2, j),
                                 predictWinnerUtils(nums, i + 1, j - 1));

    // selects last element in arr
    int option_2 = nums[j] + min(predictWinnerUtils(nums, i + 1, j - 1),
                                 predictWinnerUtils(nums, i, j - 2));

    return max(option_1, option_2);
}

bool predictWinner(vector<int> &nums, int n)
{
    // get the p1 score first
    int p1_score = predictWinnerUtils(nums, 0, n - 1);

    // calc the total score for both
    int total_score = 0;

    for (int i = 0; i < n; i++)
    {
        total_score += nums[i];
    }

    // find the remaining as the p2 score
    int p2_score = total_score - p1_score;

    return p1_score >= p2_score ? true : false;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(233);
    nums.push_back(7);

    int n = nums.size();

    cout << predictWinner(nums, n);
}