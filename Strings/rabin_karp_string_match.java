class Solution {
    private int base = 1000000;
    public int strStr(String haystack, String needle) {
        int n = haystack.length();
        int m = needle.length();

        if (n == 0 || m == 0)
            return -1;

        // 1. find power :
        int power = 1;
        for (int i = 0; i < m; i++) {
            power = (power * 31) % base;
        }

        // 2. find target code
        int targetcode = 0;
        for (int i = 0; i < m; i++) {
            targetcode = (targetcode * 31 + needle.charAt(i)) % base;
        }

        // 3. find hashcode :
        int hashcode = 0;
        for (int i = 0; i < n; i++) {
            hashcode = (hashcode * 31 + haystack.charAt(i)) % base;

            if (i < m - 1)
                continue;

            if (i >= m) {   /*****VVI*/
                hashcode = (hashcode - haystack.charAt(i - m) * power) % base;
            }
            if (hashcode < 0)
                hashcode += base;

            if (hashcode == targetcode) {
                if (haystack.substring(i - m + 1, i + 1).equals(needle))
                    return i - m + 1;
            }
        }
        return -1;
    }
}
