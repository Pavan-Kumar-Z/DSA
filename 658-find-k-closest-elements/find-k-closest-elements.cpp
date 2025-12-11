class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap ; 
        vector<int> res ;

        for(int num : arr){
            minheap.push({abs(num-x),num}) ; 
        }

        while(k > 0){
            res.push_back(minheap.top().second) ;
            minheap.pop() ; 
            k-- ;
        }

        sort(res.begin(),res.end()) ;

        return res;

    }
};