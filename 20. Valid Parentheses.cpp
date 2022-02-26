class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        unordered_map<char,char> map;
        
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        
        for (auto ch : s) {
            
            if (( ch == ')' || ch == '}' || ch == ']') && !st.empty() && st.top() == map[ch]) {
                st.pop();
            } else {
                st.push(ch);
            }
            
        }
        
        return st.size() == 0;
    }
};
