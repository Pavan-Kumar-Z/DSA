class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int sum = 0 ; 
        vector<int> temp = points[0] ; 

        for(int i = 1; i < points.size() ; i++){
            sum += max(abs(points[i][0] - temp[0]) , abs(points[i][1] - temp[1])) ; 
            temp = points[i] ; 
        }

        return sum ; 
    }
};