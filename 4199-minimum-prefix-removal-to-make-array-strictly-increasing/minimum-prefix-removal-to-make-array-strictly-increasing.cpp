class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        stack<int> stk ; 
        stk.push(nums[0]) ; 

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > stk.top()) stk.push(nums[i]) ;
            else{
                while(!stk.empty()){
                    stk.pop() ; 
                }
                stk.push(nums[i]) ; 
            }
        }


        return nums.size() - stk.size() ; 

    }
};