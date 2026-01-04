
class Solution {
public:

    int count(int num){
        vector<int> divs;
        int sum = 1 + num;

        for(int i = 2 ; i * i <= num ; i++){
            if(num % i == 0){
                int j = num / i;

                divs.push_back(i);
                if(i != j) divs.push_back(j);

                if(divs.size() > 2) return 0;
            }
        }

        if(divs.size() == 2) return sum + divs[0] + divs[1];
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        
        int sum = 0 ;
        for(int num : nums){
            sum = sum + count(num) ;
        }
        return sum ; 
    }
};