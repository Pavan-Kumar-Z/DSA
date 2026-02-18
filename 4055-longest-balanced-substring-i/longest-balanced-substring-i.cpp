class Solution {
public:
 
    bool check(auto & maps){
        int temp ; 
        for(int num : maps){
            if(num != 0){
                temp = num ; 
                break ; 
            } 
        }

        for(int num : maps){
            if(num == temp || num == 0) continue ;
            
            return false ;
        }

        return true; 

    }
    int longestBalanced(string s) {
        if(s.size() == 0) return 0 ;

        int maxlen = INT_MIN ; 

        for(int i = 0 ; i < s.size() ; i++){
            vector<int> maps(26,0) ; 
            for(int j = i ; j < s.size() ; j++){
                maps[s[j] - 'a']++ ;
                if(check(maps)) maxlen = max(maxlen , j-i+1) ;  
            }
        }

        return maxlen ;
    }
};