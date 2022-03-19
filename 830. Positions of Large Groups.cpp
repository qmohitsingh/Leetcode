//https://leetcode.com/problems/positions-of-large-groups/


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        
        int start=0, end=0;
        
        vector<vector<int>> ans;
        while (end < s.length()) {
            
            if(s[end] != s[start]) {
                
                if (end - start >= 3 )
                    ans.push_back({start, end-1});
                
                start = end;
            }
            
            end++;
        }
        
        //last case
        if (end - start >= 3 )
                    ans.push_back({start, end-1});
        
        return ans;
        
    }
};


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        
        int start=0, end=0;
        
        vector<vector<int>> ans;
        
        int j = 0;
        for (int i=0; i<s.length(); i=j) {
            while(j < s.length() && s[j] == s[i]) j++;
            
            if (j - i >= 3)
                ans.push_back({i, j-1});
        } 
        
//         while (end < s.length()) {
            
//             if(s[end] != s[start]) {
                
//                 if (end - start >= 3 )
//                     ans.push_back({start, end-1});
                
//                 start = end;
//             }
            
//             end++;
//         }
        
//         //last case
//         if (end - start >= 3 )
//                     ans.push_back({start, end-1});
        
        return ans;
        
    }
};
