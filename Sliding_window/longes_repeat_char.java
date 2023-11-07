You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4



class Solution {
    public int characterReplacement(String s, int k) {
        Map<Character, Integer> mp = new HashMap<>();
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = s.length();
        int max_freq_ele = 0;

        for(r=0; r<n; r++) {
            char ch = s.charAt(r);

            if(!mp.containsKey(ch)) {
                mp.put(ch, 0);
            }

            mp.put(ch, mp.get(ch)+1);

            // get max freq element :
            max_freq_ele = Math.max(max_freq_ele, mp.get(ch));

            // check window validity : 
            int window_sz = r - l + 1;
            int uniq_ele = window_sz - max_freq_ele;

            if(uniq_ele > k) {
                // window has to shrink : 
                char remove_ch = s.charAt(l);
                mp.put(remove_ch, mp.get(remove_ch) - 1);
                l++;
            }

            // everytime calc the max len : 
            ans = Math.max(ans, r - l + 1); // window here will be always in valid state
        }

        return ans;
    }
}
