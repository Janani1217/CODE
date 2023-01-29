/*

**********
Problem statement :
Rat in a maze :

Given a matrix of cells.
Each cell represent 2 things : open cell , closed cell
open cell - repr by (.)
closed cell - repr by (*)

Return whether the rat can reach from source to dest or not.

*** Diagramatiically repr in note book ***

.........................................................................................................
Approach :

1.  To reverse back the path , if we cannot continue , then we need to have a matrix
    to repr - visited the cell or not

2.  Next to move the rat to next cell , it has to satisfy few conditions :
    if curr pos = (i,j) , it has 4 direc to move on (i+1,j) (i,j+1) (i,j-1) (i-1,j)

    2.1     next move is within the index boundary , not crossing the length
    2.2     Next cell to be visited is marked as "false" in vis[][]
    2.3     Next cell to be vis, is marked as "OPEN"

    Then its safe to move forward



.........................................................................................................
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> board, int srcx, int srcy, vector<vector<bool>> &vis)
{
    // find the size of board
    int rowSize = board.size();
    int colSize = board[0].size();

    if ((srcx <= rowSize && srcy <= colSize) && (srcx >= 0 && srcy >= 0) &&
            vis[srcx][srcy] == false && board[srcx][srcy] = '.')
    {
        return true;
    }
    return false;
}

bool solve(vector<vector<int>> board, int srcx, int srcy, int destx, int desty, vector<vector<bool>> &vis)
{
    // base case : when rat reached the dest
    if (srcx == destx && srcy == desty)
    {
        return true;
    }

    // rat can move for down position : check condition
    int newx = srcx + 1;
    int newy = srcy;
    bool down = false;
    if (isSafe(board, newx, newy, vis))
    {
        vis[newx][newy] = true;
        down = solve(board, newx, newy, destx, desty, vis);
        vis[newx][newy] = false;
    }

    // rat can move for right position : check condition
    newx = srcx;
    newy = srcy + 1;
    bool right = false;
    if (isSafe(board, newx, newy, vis))
    {
        vis[newx][newy] = true;
        right = solve(board, newx, newy, destx, desty, vis);
        vis[newx][newy] = false;
    }

    // rat can move for left position : check condition
    newx = srcx;
    newy = srcy - 1;
    bool left = false;
    if (isSafe(board, newx, newy, vis))
    {
        vis[newx][newy] = true;
        left = solve(board, newx, newy, destx, desty, vis);
        vis[newx][newy] = false;
    }

    // rat can move for up position : check condition
    newx = srcx - 1;
    newy = srcy;
    bool up = false;
    if (isSafe(board, newx, newy, vis))
    {
        vis[newx][newy] = true;
        up = solve(board, newx, newy, destx, desty, vis);
        vis[newx][newy] = false;
    }

    if (down || up || left || right)
        return true;
    else
        return false;
}

int main()
{
    int srcx = 0;
    int srcy = 0;
    int destx = 4;
    int desty = 4;

    vector<vector<char>> board(4, vector<char>(4, '.'));
    board[0][3] = '*';
    board[1][1] = '*';
    board[0][2] = '*';
    board[3][1] = '*';

    vector<vector<bool>> vis(4, vector<bool>(4, false));

    bool result = solve(srcx, srcy, destx, desty, vis);
    cout << result << endl;
}