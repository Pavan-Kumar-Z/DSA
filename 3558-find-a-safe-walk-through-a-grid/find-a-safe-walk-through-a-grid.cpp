class Solution {
public:
    bool bfs(auto & grid, int m, int n, auto & visited, int health){
        queue<pair<int,pair<int,int>>> q ; 
        int start = (grid[0][0] == 1 ? health-1 : health);
        q.push({start,{0,0}}) ;
        visited[0][0] = start ;

        vector<pair<int,int>> dirs ; 
        dirs.push_back({1,0}) ;
        dirs.push_back({-1,0}) ;
        dirs.push_back({0,1}) ;
        dirs.push_back({0,-1}) ;

        while(!q.empty()){
            auto[h,l] = q.front() ;
            q.pop() ;

            if(l.first == m-1 && l.second == n-1 && h >= 1){
                return true ; 
            }

            if(h < 1) continue ;

            for(int i = 0;  i < dirs.size() ; i++){
                int x = dirs[i].first + l.first ;
                int y = dirs[i].second + l.second ;

                if(x >= 0 && y >= 0 && x < m && y < n){
                    int nh = (grid[x][y] == 0 ? h : h-1);
                    if(nh >= 0 && visited[x][y] < nh){
                        visited[x][y] = nh ;
                        q.push({nh,{x,y}}) ;
                    }
                }
            }
        }
        return false ;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() , n = grid[0].size() ;
        vector<vector<int>> visited(m, vector<int>(n,-1)) ;
        return bfs(grid,m,n,visited,health) ;
    }
};
