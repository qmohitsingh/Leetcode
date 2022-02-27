//https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) 
            return false;
        
        int first[26];
        for (int i=0; i<26; i++) first[i] = 0;
        
        int second[26];
        for (int i=0; i<26; i++) second[i] = 0;
        
        for (int i=0; i<s.length(); i++){
            first[s[i] - 'a']++;
            second[t[i] - 'a']++;
        }
        
        for (int i=0; i<26; i++) {
            if (first[i] != second[i]) return false;
        }
        
        return true;
        
    }
};
