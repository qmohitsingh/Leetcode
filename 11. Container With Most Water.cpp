//https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    
    int maxArea(vector<int>& height) {
        
        int ans = 0;
        
        int low = 0, high = height.size()-1;
        while(low < high) {
            
            int minH = 0;
            if (height[low] < height[high]) {
                minH = height[low];
                low++;
            } else {
                minH = height[high];
                high--;
            }
            
            ans = max(ans, minH*(high-low+1));
            
        }
        
        return ans;
    }
};
