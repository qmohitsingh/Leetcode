//https://leetcode.com/problems/permutation-sequence/



// Naive Solution
class Solution {
public:
    
    string getPermutation(int n, int k) {
        
        string src="";
        string ans="";
        
        unordered_map<char, int> map;
        
        for (int i=1; i<=n; i++) {
            src += to_string(i);
        }
        
        permutation(src, "", k, ans, map);
        
        return ans;
    }
    
    void permutation(string src, string result, int& k, string& ans, unordered_map<char, int> & map) {
        
        if (result.length() == src.length()) {
            
            if (!--k)
                ans = result;
            
            return;
        }
        
        for (int i=0; i < src.length(); i++) {
            
            if (map[src[i]] != 1 && k) {
                map[src[i]] = 1;
                permutation(src, result+src[i], k, ans, map);
                map[src[i]] = 0;
            }
            
        }
    }
    
};


// 1 2 3 4 5

