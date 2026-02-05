class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size()-1  ;
        return max(nums[0] , nums[n]) ;
    }
};