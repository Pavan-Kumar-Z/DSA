class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char> hashset ; 
        hashset.insert('a') ;
        hashset.insert('e') ;
        hashset.insert('i') ;
        hashset.insert('o') ;
        hashset.insert('u') ;
         
        while(s.size() > 0 && hashset.find(s[s.size()-1]) != hashset.end()){
            s.pop_back() ;
        }

        return s ;
    }
};