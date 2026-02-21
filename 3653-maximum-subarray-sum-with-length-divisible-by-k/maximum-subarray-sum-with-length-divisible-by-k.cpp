class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> minPrefix(k, LLONG_MAX);
        minPrefix[0] = 0;  
        
        long long prefix = 0;
        long long maxSum = LLONG_MIN;
        
        for (int i = 0; i < n; i++) {
            prefix += nums[i];  
            
            int r = (i + 1) % k;  
            
            if (minPrefix[r] != LLONG_MAX) {
                maxSum = max(maxSum, prefix - minPrefix[r]);
            }
            
            minPrefix[r] = min(minPrefix[r], prefix);
        }
        
        return maxSum;
    }
};