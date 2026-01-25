class Solution{
public:
    int minimumDifference(vector<int>& nums, int k) {

        if(k == 0 || k == 1) return 0 ; 
        sort(nums.begin() , nums.end()) ; 
        int diff = INT_MAX ; 

        int left = 0 , right = k - 1 ;

        while(right < nums.size()){
            diff = min(diff, nums[right] - nums[left]) ; 

            right++ ; 
            left++ ; 
        } 

        return diff ; 
    }
};