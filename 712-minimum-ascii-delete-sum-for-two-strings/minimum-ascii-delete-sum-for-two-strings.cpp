class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size() , n = s2.size() ; 
        vector<vector<int>> dp(m+1, vector<int>(n+1,0)) ; 

        for(int i = m-1 ; i >= 0 ; i--){
            dp[i][n] = (int)s1[i] + dp[i+1][n] ; 
        }
        for(int i = n-1 ; i >= 0 ; i--){
            dp[m][i] = (int)s2[i] + dp[m][i+1] ;
        } 

        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                int cost = 0 ;
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1] ; 
                }
                else{
                    cost = min( ((int)s1[i] + dp[i+1][j]) , ((int)s2[j] + dp[i][j+1]) ) ;
                }
                dp[i][j] = cost ; 
            }
        }

        return dp[0][0] ; 
        
    }
};