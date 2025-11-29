class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        int res = 1 , curr = 1 ;
        unordered_set<int> sets ; 

        while(curr % k){
            if(sets.find(curr) != sets.end()){
                return -1 ;
            }else{
                sets.insert(curr) ; 
                curr = (curr % k) * 10 + 1;
                res++ ; 
            }
        } 

        return res ; 
    }
};