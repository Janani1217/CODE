/*
 *  Valid Sudoku :
 * 
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated 
 * according to the following rules:
 * 
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 
 * without repetition.
 * 
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 * 
 * https://leetcode.com/problems/valid-sudoku/description/
 * 
 */

public class valid_sudoku {
    public boolean isValidSudoku(char[][] board) {
        int m = board.length;
        int n = board.length;

        if (m != 9 || n != 9)
            return false;

        // *** array of maps ***
        Map<Character, Integer> hm_r[] = new HashMap[m];
        Map<Character, Integer> hm_c[] = new HashMap[m];
        Map<Character, Integer> hm_g[] = new HashMap[m];

        for (int i = 0; i < m; i++) {
            hm_r[i] = new HashMap<>();
            hm_c[i] = new HashMap<>();
            hm_g[i] = new HashMap<>();
        }

        // traverse the board :
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];

                if (hm_r[i].containsKey(c) || hm_c[j].containsKey(c) || hm_g[(i / 3) * 3 + j / 3].containsKey(c))
                    return false;

                hm_r[i].put(c, 1);
                hm_c[i].put(c, 1);
                hm_g[(i / 3) * 3 + j / 3].put(c, 1);
            }
        }
        return true;
    }
}
