/* Given a target sum, find a pair of 2 ele which sum 
 * gives the target
 */

package two_pointers;

public int[] twoSum(int[] nums, int target) {
    int n = nums.length;
    int s = 0 , e = n-1;
    //Arrays.sort(nums);
    HashMap<Integer, Integer> mp = new HashMap<>();

    for(int i=0; i<n; i++) {
        mp.put(nums[i], i);
    }

    int res[] = new int[2];

    for(int i=0; i<n; i++) {
        int remVal = target - nums[i];
        if(mp.containsKey(remVal)) {
            if(mp.get(remVal) == i) {
                for(Map.Entry<Integer,Integer>entry:mp.entrySet()) {
                    if(entry.getKey()==remVal && entry.getValue()!=i) {
                        res[0] = i;
                        res[1] = entry.getValue();
                    }
                }
            }else {
                res[0] = i;
                res[1] = mp.get(target - nums[i]);
            }
        } 
    }
    return res;
}
