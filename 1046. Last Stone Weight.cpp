//https://leetcode.com/problems/last-stone-weight/


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        
        int ans = 0;
        for (auto n : stones)
            pq.push(n);
        
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            if (x == y) 
                continue;
            
            pq.push(x-y);
        }
        
        
        return pq.size() ? pq.top() : 0;
    }
};
