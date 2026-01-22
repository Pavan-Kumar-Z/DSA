class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        int ops = 0 ;

        while(1){
            bool flag = true ; 
            for(int i = 0; i < nums.size()-1 ; i++){
                if(nums[i] > nums[i+1]){
                    flag = false ;
                    break ; 
                }
            }

            if(flag) break ;

            int ind = -1 ; 
            int mini = INT_MAX ;

            for(int i = 0 ;  i < nums.size()-1 ; i++){
                if(nums[i] + nums[i+1] < mini){
                    mini = nums[i] + nums[i+1] ;
                    ind = i ;
                }
            }

            nums[ind] = nums[ind] + nums[ind+1] ;
            nums.erase(nums.begin()+ind+1) ;

            ops++ ;
        }

        return ops ;
        
    }
};