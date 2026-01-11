class Solution {
public:

    vector<pair<int,int>> dirs ; 

    void dfs(auto & grid, auto & temp, auto & visited , int m , int n){
        visited[m][n] = true ;

        temp[0] = min(temp[0], m);
        temp[1] = min(temp[1], n);
        temp[2] = max(temp[2], m);
        temp[3] = max(temp[3], n);


        for(int i = 0 ; i < dirs.size() ; i++){
            int x = m + dirs[i].first ; 
            int y = n + dirs[i].second ; 

            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1 && !visited[x][y]){
                dfs(grid,temp,visited,x,y) ; 
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<int>temp = {INT_MAX,INT_MAX, INT_MIN,INT_MIN} ; 
        int m = land.size() , n = land[0].size() ; 
        vector<vector<bool>> visited(m, vector<bool>(n, false)) ;
        vector<vector<int>> res; 

        dirs.push_back({1,0}) ; 
        dirs.push_back({-1,0}) ; 
        dirs.push_back({0,1}) ; 
        dirs.push_back({0,-1}) ; 


        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j] && land[i][j] == 1){
                    dfs(land,temp,visited,i,j) ; 
                    res.push_back(temp) ;
                    temp = {INT_MAX,INT_MAX, INT_MIN,INT_MIN} ;
                }
            }
        }
        return res ;
    }
};