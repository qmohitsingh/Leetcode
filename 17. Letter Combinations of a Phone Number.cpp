//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    
    void letterCombinationsRecursion(vector<string>& res, vector<string> map, string digits, string current, int index) {
        
        if (current.length() == digits.length()){
            res.push_back(current);
            return;
        }
        
        //cout<<"index: "<<digits[index] - '0'<<endl;
        string letters = map[digits[index] - '0'];
        
        for (int i=0; i<letters.length(); i++) {
            letterCombinationsRecursion(res, map, digits, current+letters[i], index+1);
        }
        
        
    }
    
    
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        
         if (!digits.length()) return res;
        
        vector<string> map(10);
        map[0] = "0";
        map[1] = "1";
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        
        letterCombinationsRecursion(res, map, digits, "", 0);
        return res;
            
        
    }
};
