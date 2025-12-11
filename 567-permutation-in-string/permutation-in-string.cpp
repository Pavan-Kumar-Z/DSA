class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>hash1(26,0) ,hash2(26,0) ; 
        
        if(s1.size() > s2.size()) return false ; 

        for(char c : s1){
            hash1[c - 'a']++ ;
        }

        for(int i = 0 ; i < s1.size() ; i++){
            hash2[s2[i] - 'a']++ ;
        }

        if(hash1 == hash2) return true ; 

        for(int i = s1.size() ; i < s2.size() ; i++){
            hash2[s2[i] - 'a']++ ; 
            hash2[s2[i - s1.size()] - 'a']-- ;

            if(hash1 == hash2) return true ;  
        }

        return false;
    }
};