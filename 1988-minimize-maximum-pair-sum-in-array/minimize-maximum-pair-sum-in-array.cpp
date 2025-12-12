class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;

        int maxi = INT_MIN ; 
        for(int i = 0 ; i < nums.size()/2 ; i++){
            maxi = max( nums[i] + nums[nums.size()-1-i] , maxi ) ; 
        }
        return maxi ;
    }
};