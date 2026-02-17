class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxlen = 0 ; 

        for(int i = 0 ; i < nums.size() ; i++){
            unordered_set<int> even , odd; 
            for(int j = i  ; j < nums.size() ; j++){
                if(nums[j] % 2 == 0 && even.find(nums[j]) == even.end()) even.insert(nums[j]) ; 
                else if(nums[j] % 2 == 1 && odd.find(nums[j]) == odd.end()) odd.insert(nums[j]) ;

                if(odd.size() == even.size()) maxlen = max(maxlen , j-i+1) ; 
            }
        }

        return maxlen ;
    }
};