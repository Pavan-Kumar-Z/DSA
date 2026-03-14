class Solution {
public:

    string res = "" ;
    int count = 0 ; 

    void generate(auto & curr, int n , int k){
        if(!res.empty()) return ; 

        if(curr.size() == n){
            count++ ; 
            if(count == k) res = curr ;

            return ; 
        }

        for(char ch : {'a' , 'b' , 'c'}){
            if(!curr.empty() && curr.back() == ch) continue  ;

            curr.push_back(ch) ; 
            generate(curr,n,k) ; 
            curr.pop_back() ; 
        }
    }
    string getHappyString(int n, int k) {
        string curr = "" ;
        generate(curr,n,k) ;
        return res; 
    }
};