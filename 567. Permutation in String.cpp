//https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);
        
        int len1 = s1.length();
        int len2 = s2.length();
        
        if (len2 < len1) 
            return false;
        
        for (int i=0; i<s1.length(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        
        if (s1map == s2map) return true;
            
        
        int low = 0, high = len1;
        
        while(high < len2) {                                                                                                                                              
            
            s2map[s2[high] - 'a']++;
            high++;
            
            s2map[s2[low] - 'a']--;
            low++;
            
            if (s1map == s2map) return true;
            
        }
        
        return false;
        
    }
};
