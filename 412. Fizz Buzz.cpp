//https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> ans;
        
        for (int i=1; i<=n; i++) {
            
            int a = i%3;
            int b = i%5;
            
            if (!a && !b) {
                ans.push_back("FizzBuzz");
            } else if (!a){
                ans.push_back("Fizz");
            } else if(!b) {
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(i));
            }
        }
        
        return ans;
    }
};
