/* https://leetcode.com/problems/word-ladder/ */

import java.util.*;

class Pair {
    String first;
    int sec;

    public Pair(String first, int sec) {
        this.first = first;
        this.sec = sec;
    }
}

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord))
            return 0;
        /* *** convert to set to avoid TLE */
        Set<String> wordSet = new HashSet(wordList);

        // insert into the queue : the str and its level in bfs
        Queue<Pair> q = new LinkedList<>();

        // insert begin word and its count will be 1
        q.add(new Pair(beginWord, 1));

        // once a word is inserted into the queu , remove from the wordlist
        wordSet.remove(beginWord);

        // run bfs
        while (!q.isEmpty()) {
            Pair p = q.poll();
            String curr = p.first;
            int dist = p.sec;

            // if dest is reached
            if (curr.equals(endWord))
                return dist;

            // if not arrived till dist : traverse over the str and replace with 26 alpha
            char[] currArry = curr.toCharArray();

            for (int i = 0; i < curr.length(); i++) {
                char originalChar = currArry[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    currArry[i] = ch;

                    String newCurr = new String(currArry);
                    // check if its present in wordlist
                    if (wordSet.contains(newCurr)) {
                        q.add(new Pair(newCurr, dist + 1));
                        wordSet.remove(newCurr); // done to avoid revisiting
                    }
                }

                // keeping back the original char in place
                currArry[i] = originalChar;
            }

        }

        return 0;
    }
}