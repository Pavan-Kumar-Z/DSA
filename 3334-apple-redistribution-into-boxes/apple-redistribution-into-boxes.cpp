class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(),apple.end(),0) ; 

        priority_queue<int> pq ; 
        for(int i = 0 ; i < capacity.size() ; i++){
            pq.push(capacity[i]) ; 
        }
        
        int count = 0 ; 
        while(sum > 0){
            sum -= pq.top() ; 
            pq.pop() ;
            count++ ; 
        }

        return count ;
    }
};