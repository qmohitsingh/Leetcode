//https://leetcode.com/problems/sort-characters-by-frequency/submissions/

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> map;
        
        string result;
        
        for (auto ch : s) map[ch]++;
        
        priority_queue<pair<int, char>> pq;
        
        for (auto m : map) {
            pq.push({m.second, m.first});
        }
        
        while(!pq.empty()) {
            int num = pq.top().first;
            char ch = pq.top().second;
            
            for(int i=0; i<num; i++)
                result += ch;
            
            pq.pop();
        }
        
        return result;
        
    }
};
