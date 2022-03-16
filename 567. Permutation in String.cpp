//https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        
        if (s1.length() > s2.length())
            return false;
        
        int low = 0, high = 0;
        vector<int> map(26);
        
        vector<int> s2map(26, 0);
        
        for (auto c : s1)
            map[c-'a']++;
        
        while(high < s2.length()) {
            
            int index = s2[high] - 'a';
            high++;
            
            s2map[index]++;
            
            if (!map[index]) {
                fill(s2map.begin(), s2map.end(), 0);
                low = high;
                continue;
            }
            
            while(map[index] < s2map[index]) {
                int lowIdx = s2[low] - 'a';
                s2map[lowIdx]--;
                low++;
            }
            
            if (map == s2map) 
                return true;
            
        }
    
        return false;
        
    }
};
