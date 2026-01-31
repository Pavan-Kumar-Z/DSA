class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0 , high = letters.size()-1, mid ; 

        while(low < high){
            mid = (low + high)/2 ; 

            if(letters[mid] > target) high = mid ;
            else low = mid + 1 ; 
        }

        return (letters[low] > target) ? letters[low] : letters[0] ; 
    }
};