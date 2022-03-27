//https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        
        for(int i=0; i<nums.size(); i++) {
            
            int val = nums[i];
            
            if (map.find(val) != map.end() && abs(map[val] - i) <= k) 
                return true;
            else {
                map[val] = i;
            }
        }
        
        return false;
        
    }
};
