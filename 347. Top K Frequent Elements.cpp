//https://leetcode.com/problems/top-k-frequent-elements/submissions/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>
            > pq;
        
        vector<int> result;
        
        for (auto num : nums) {
            map[num]++;
        }
        
        for (auto m : map) {
            
            pq.push({m.second, m.first});
            
            if (pq.size() > k) 
                pq.pop();
        }
        
        while(pq.size() > 0) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
  
    }
    
};
