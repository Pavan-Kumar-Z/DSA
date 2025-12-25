class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq ; 
        for(int num : happiness){
            pq.push(num) ; 
        }

        int count = 0 ;
        long long sum = 0 ; 
        while(k > 0 && pq.top() > count){
            sum += (pq.top() - count) ; 
            count++ ; 
            pq.pop() ;
            k-- ;
        }

        return sum ;
    }
};