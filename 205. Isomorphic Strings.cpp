// Reference : https://www.youtube.com/watch?v=6Qkail843d8

class Solution {
public:
    
    // Time O(n), Space O(n)
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> map;
        
        unordered_map<char, int> map2;
        for (int i=0; i<s.length(); i++) {
            
            if(map.find(s[i]) == map.end() && !map2[t[i]]) {
                map[s[i]] = t[i];
                map2[t[i]] = 1;
            }
            
            if (map[s[i]] != t[i]) return false;
            
        }
        
        return true;
        
    }
}
