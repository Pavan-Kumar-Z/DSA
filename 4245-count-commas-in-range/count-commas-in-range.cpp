class Solution {
public:

    int counts(int n){ 
        int count = 0 ;
        while(n > 0){
            count++ ; 
            n /= 10 ; 
        }
        return count ; 
    }

    int power10(int k){
        int ten = 1 ; 
        while(k > 0){
            ten *= 10 ; 
            k-- ;
        } 

        return ten ;
    }
    int countCommas(int n) {
        long long count = 0 ; 

        while(n > 999){
            int digits = counts(n) ; 

            int commas = (digits-1) / 3 ; 

            int lower = power10(digits-1) ;

            long long numbers = n - lower + 1 ; 

            count += numbers * commas ;

            n = lower - 1; 
        }

        return count ;
    }
};