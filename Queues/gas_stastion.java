class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int rem_fuel = 0;
        int ans = 0;

        int gas_sum = 0;
        int cost_sum = 0;

        for (int i = 0; i < n; i++) {
            gas_sum += gas[i];
            cost_sum += cost[i];
        }

        if (gas_sum < cost_sum)
            return -1;

        for (int i = 0; i < n; i++) {
            rem_fuel += gas[i] - cost[i];
            if (rem_fuel < 0) {
                // change the ans
                ans = i + 1;
                rem_fuel = 0;
            }
        }

        return ans;
    }
}
