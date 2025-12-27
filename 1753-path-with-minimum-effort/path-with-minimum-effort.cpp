class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq ; 

        int m = heights.size(), n = heights[0].size() ; 
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX)) ;

        dist[0][0] = 0 ; 
        pq.push({0,{0,0}}) ;
         
        vector<pair<int,int>> dirs ; 
        dirs.push_back({1,0}) ;
        dirs.push_back({-1,0}) ;
        dirs.push_back({0,1}) ;
        dirs.push_back({0,-1}) ;


        while(!pq.empty()){
            auto it = pq.top() ; 
            int diff = it.first ;
            int row = it.second.first ;
            int col = it.second.second ;

            pq.pop() ;

            if(row == m-1 && col == n-1) return diff; 

            for(int i = 0; i < 4 ; i++){
                int x = row + dirs[i].first ; 
                int y = col + dirs[i].second ;

                if(x >= 0 && x < m && y >= 0 && y < n){
                    int currdif = max(abs(heights[row][col] - heights[x][y]) , diff) ; 

                    if(currdif < dist[x][y]){
                        dist[x][y] = currdif ; 
                        pq.push({currdif,{x,y}}) ; 
                    }
                }
            }
        }
        return -1 ; 

    }
};