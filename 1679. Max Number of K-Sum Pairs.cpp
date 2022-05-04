//https://leetcode.com/problems/max-number-of-k-sum-pairs/


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        
        for (auto n : nums) {
            map[n]++;
        }
        
        int ans = 0;
        for (auto n : nums) {
            
            if (n == k-n && map[n] >= 2) {
                ans++;
                map[n]--;
                map[k-n]--;
            }
            else if (n != k-n && map[n] && map[k-n]) {
                ans++;
                map[n]--;
                map[k-n]--;
            }
        }
        
        return ans;
    }
};
