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

// Reference : https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        
        string ans;
        
        vector<int> factorial(n+1);
        
        factorial[0] = 1;
        for (int i=1; i<=n; i++) {
            factorial[i] = i*factorial[i-1];
        }
        
        vector<int> numbers(n+1);
        for (int i=0; i<=n; i++) numbers[i] = i+1;
        
        k--; // 0 -indexing
        auto itr = numbers.begin();
        for (int i=1; i<=n; i++) {
            
            int index = k/factorial[n-i];
            ans += to_string(numbers[index]);
            
            // remove that element from the list
            numbers.erase(itr+index);
            
            k = k - index*factorial[n-i];
        }
        
        return ans;
        
    }
};
