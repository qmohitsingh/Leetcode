//https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        
        int low = 0;
        
        int high = 1;
        while(high < nums.size()) {
            if (nums[high-1] + 1 == nums[high]) {
                high++;
                continue;
            }
            else {
                if (high - low > 1 && high < nums.size()) {
                    ans.push_back(to_string(nums[low])+"->"+to_string(nums[high-1]));
                } else {
                    ans.push_back(to_string(nums[low]));
                }
                low = high;
                high++;
            }
        }
        
        if (high - low > 1 && high <= nums.size()) {
            ans.push_back(to_string(nums[low])+"->"+to_string(nums[high-1]));
        }
        else if (low < nums.size()) {
            ans.push_back(to_string(nums[low]));
        }
        
        return ans;
        
    }
};
