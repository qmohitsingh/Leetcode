//https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int res = 0;
        int alt = 0;
        for (auto g : gain) {
            alt += g;
            res = max(res, alt);
        }
        
        return res;
        
    }
};
