//https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        int sum = 0;

        sort(cost.begin(), cost.end(), greater<>());

        for (int i=0; i<cost.size(); i++) {
            if ((i+1)%3 == 0) continue;
            sum += cost[i];
        }
        
        return sum;
    }
};
