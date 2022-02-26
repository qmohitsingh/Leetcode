
// Time - O(n), Space - O(n)
class Solution {
    
    public int[] twoSum(int[] nums, int target) {
        
        int[] result = new int[2];
        
        Map<Integer, Integer> hashMap = new HashMap<>();
        
        for (int i=0; i<nums.length; i++) {
            
            if (hashMap.containsKey(target-nums[i])) {
                result[0] = i;
                result[1] = hashMap.get(target-nums[i]);
                break;
            }
            
            hashMap.put(nums[i], i);
        }
    
        return result;
        
    }
}

/*

Solution: 1 using two loop
Solution: 3 using hashmap(n + n)

[2,7,11,15]
9
[5, 2, -2, ]

[3,2,4]
6
[3, 4, 2]


**/
