class Solution {
public:

    vector<pair<int,int>> dirs ; 
    
    void dfs(auto & grid, auto & visited, int m , int n){
        visited[m][n] = true ; 

        for(int i = 0 ; i < dirs.size() ; i++){
            int x = m + dirs[i].first ; 
            int y = n + dirs[i].second ; 

            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && !visited[x][y] && grid[x][y] == 'X'){
                dfs(grid,visited,x,y) ;
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size() , n = board[0].size() ; 
        vector<vector<bool>> visited(m, vector<bool>(n,false)) ;
        int count = 0 ; 

        dirs.push_back({1,0}) ;
        dirs.push_back({-1,0}) ;
        dirs.push_back({0,1}) ;
        dirs.push_back({0,-1}) ;


        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j] && board[i][j] == 'X'){
                    dfs(board,visited,i,j) ;
                    count++ ;
                }
            }
        }

        return count ; 

    }
};