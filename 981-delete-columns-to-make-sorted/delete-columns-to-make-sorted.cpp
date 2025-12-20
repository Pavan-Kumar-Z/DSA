class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int count = 0 ; 
        for(int i = 0 ; i < strs[0].size() ; i++){
            char c = strs[0][i] ; 
            for(int j = 1 ; j < strs.size() ; j++){
                char p = strs[j][i] ; 
                if(c > p){
                    count++ ;
                    break ;
                }
                c = p ;  
            }
        }

        return count ; 
    }
};