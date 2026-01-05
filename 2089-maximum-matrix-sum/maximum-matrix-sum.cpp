class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int mr = 0 , mc = 0 , count = 0, mini = INT_MAX; 

        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] < 0){
                    count++ ;
                }
                
                if(mini > abs(matrix[i][j])){
                    mini = abs(matrix[i][j]) ; 
                    mr = i ;
                    mc = j ; 
                }
            }
        }

        long long sum = 0 ;

        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                sum += llabs(matrix[i][j])  ;
            }
        }


        return (count % 2 == 0) ? sum : sum - 2LL * abs(matrix[mr][mc]) ;
    }
};