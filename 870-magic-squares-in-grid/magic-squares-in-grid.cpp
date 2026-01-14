class Solution {
public:
    int solve(auto & grid, int x, int y, int m , int n){
        unordered_set<int> hashmap;
        int magic = 15;

        for(int i = x; i <= m; i++){           
            for(int j = y; j <= n; j++){
                int val = grid[i][j];
                if(val < 1 || val > 9 || hashmap.find(val) != hashmap.end()){
                    return 0;
                }
                hashmap.insert(val);
            }
        }
        if(hashmap.size() != 9) return 0;

        for(int i = x; i <= m; i++){
            int rowsum_now = grid[i][y] + grid[i][y+1] + grid[i][y+2];
            if(rowsum_now != magic) return 0;
        }

        vector<int> colsum(3, 0);
        for(int j = 0; j < 3; j++){
            colsum[j] = grid[x][y+j] + grid[x+1][y+j] + grid[x+2][y+j];
            if(colsum[j] != magic) return 0;
        }

        int d1 = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        int d2 = grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y];
        if(d1 != magic || d2 != magic) return 0;

        return 1;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {

        if(grid.size() < 3) return 0;
        int m = grid.size() , n = grid[0].size() ;
        if(n < 3) return 0;

        int count = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i + 2 < m && j + 2 < n){
                    count += solve(grid, i, j, i+2, j+2);
                }
            }
        }
        return count ;
    }
};