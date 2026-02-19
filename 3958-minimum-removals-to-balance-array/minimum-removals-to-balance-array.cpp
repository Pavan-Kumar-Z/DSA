class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end()) ;
        int i = 0, maxlen = 0 ; 

        for(int j = 0 ; j < nums.size() ; j++){
            while( (long long)nums[j] > (long long)nums[i] * k){
                i++ ;
            }
            maxlen = max(maxlen , j-i+1) ;
        }

        return nums.size() - maxlen ; 
    }
};