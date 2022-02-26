class Solution {
public:
//     int climbStairs(int n) {
    
//         if (n < 0) return 0;
        
//         if (n == 0) return 1;
        
//         return climbStairs(n-1) + climbStairs(n-2);
        
//     }
    
//     int climbStairs(int n) {
        
//         int dp[46];
        
//         for (int i=0; i<=45; i++) dp[i] = 0;
        
//         dp[1] = 1;
//         dp[2] = 2;
//         dp[3] = 3;
    
//         for (int i=4; i<=n; i++) {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
        
//         return dp[n];
        
//     }
    
    int climbStairs(int n) {
        
        if (n <= 3) return n;
        
        int t1 = 1;
        int t2 = 2;
        int t3 = 3;
        
        
        for (int i=3; i<=n; i++) {
            t3 = t2 + t1;
            t1 = t2;
            t2 = t3;
        }
        
        return t3;;
        
    }
};
