//https://leetcode.com/problems/minimum-time-to-complete-trips/submissions/

class Solution {
public:    
    long long minimumTime(vector<int>& time, int totalTrips) {
           
        long long low = 1, high = 1e14;
        
        while(low < high) {
            long long mid = low + (high-low)/2;
            
            long long tempTrips = getTotalTrips(time, mid);
            
            if (tempTrips < totalTrips ) low = mid + 1;
            else high = mid;
            
        }
        
        return low;
        
    }
    
    long long getTotalTrips(vector<int>& time, long long currentTime) {
        
        long long sum = 0;
        for (auto n : time) {
            sum += currentTime/n;
        }
        
        return sum;
        
    }
    
};
