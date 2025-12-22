class Solution {
public:

    int solve(int index, int prev, auto & strs, auto & dp){
        if(index == strs[0].size()) return  0 ;

        if(dp[index][prev+1] != -1) return dp[index][prev+1] ;

        int pick = 0 ;
        int skip = solve(index+1,prev,strs,dp) ;  

        if(prev == -1) pick = 1 + solve(index+1,index,strs,dp) ;
        else {
            bool flag = true ; 
            
            for(int i = 0 ; i < strs.size() ; i++){
                if(strs[i][index] < strs[i][prev]){
                    flag = false ; 
                    break ;
                }
            }

            if(flag) pick = 1 + solve(index+1,index,strs,dp) ; 

        }

        return dp[index][prev+1] = max(pick,skip) ;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size() ; 
        int m = strs[0].size() ;

        vector<vector<int>> dp(m,vector<int>(m+1,-1)) ;

        return m - solve(0,-1,strs,dp) ;
    }
};