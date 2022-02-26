
// Time - O(n), Space - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        
        vector<int> ans;
        
        for (int i=0; i<nums.size(); i++) {
            map[nums[i]] = i;
        }
        
        for (int i=0; i<nums.size(); i++) {
            
            int compliment = target-nums[i];
            
            if (map.find(compliment) != map.end() && map[compliment] != i) {
                ans.push_back(i);
                ans.push_back(map[compliment]);
                
                break;
            }
        }
        
        return ans;
        
    }
};

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
