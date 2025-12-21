class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int count = 0 ;
        vector<bool> sort(strs.size(), false) ;

        for(int i = 0 ; i < strs[0].size() ; i++){
            
            bool deletecol = false ; 
            for(int j = 0 ; j < strs.size()-1 ; j++){
                if(!sort[j] && strs[j][i] > strs[j+1][i]){
                    deletecol = true; 
                    break ; 
                }
            }

            if(deletecol){
                count++ ;
                continue ;
            }
        
            bool allsort = true ;     
            for(int j = 0 ; j < strs.size()-1 ; j++){
                if(!sort[j] && strs[j][i] < strs[j+1][i]){
                    sort[j] = true ; 
                }
                if(!sort[j]) allsort = false ;

            }

            if(allsort) break ;
            

        }

        return count; 

    }
};