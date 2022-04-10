//https://leetcode.com/problems/baseball-game/


class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> stk;
        
        int sum = 0;
        for(auto ch : ops) {
            
            if (ch == "C") 
                stk.pop();
            else if (ch  == "D") {
                stk.push(stk.top()*2);
            } else if (ch == "+") {
                
                int val1 = stk.top(); 
                stk.pop();
                int val2 = stk.top(); 
                
                stk.push(val1);
                stk.push(val1+val2);
            } else{
                stk.push(stoi(ch));
            }
        }
        
        while(!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        
        return sum;
    }
};
