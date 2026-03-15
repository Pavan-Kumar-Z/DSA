class Solution {
public:
    long long countCommas(long long n) {
        
        long long count = 0 ; 

        for(long long k = 0 ;  ; k++){
            long long start = pow(10,3 * k) ; 

            if(n < start) break ; 

            long long end = min(n, (long long)pow(10, 3 * k + 3) - 1 ) ; 

            count += (end - start + 1) * k ; 
        }

        return count ; 
    }
};