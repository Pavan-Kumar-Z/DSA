class Solution {
public:

    void bfs(auto & graph, auto & dist, auto & vis, int src){ 

        queue<pair<int,int>> q ; 
        q.push({0,src}) ; 
        vis[src] = true; 


        while(!q.empty()){
            auto [dis, node] = q.front() ;
            q.pop() ; 

            vis[node] = true; 
            dist[node] = dis ;

            for(int adj : graph[node]){
                if(!vis[adj]){
                    vis[adj] = true; 
                    q.push({dis+1, adj}) ; 
                }
            }
        }

    }

    int p(auto & disx, auto & disy, auto & disz, int x, int y, int z){
        int count = 0 ; 
        vector<long long> temp(3,0) ; 
        for(int i = 0 ; i < disx.size() ; i++){
            temp[0] = disx[i] ;
            temp[1] = disy[i] ;
            temp[2] = disz[i] ; 

            sort(temp.begin() , temp.end()) ;

            if (1LL*temp[0]*temp[0] + 1LL*temp[1]*temp[1] == 1LL*temp[2]*temp[2])  count++;
        }

        return count ; 
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> graph(n) ; 
        for(int i = 0 ; i < edges.size() ; i++){
            graph[edges[i][0]].push_back(edges[i][1]) ;
            graph[edges[i][1]].push_back(edges[i][0]) ; 
        }

        vector<int> disx(n,INT_MAX) ;
        vector<bool> visx(n,false) ; 

        bfs(graph,disx,visx,x) ; 


        vector<int> disy(n,INT_MAX) ;
        vector<bool> visy(n,false) ; 

        bfs(graph,disy,visy,y) ;
        
        vector<int> disz(n,INT_MAX) ;
        vector<bool> visz(n,false) ; 

        bfs(graph,disz,visz,z) ; 

        return p(disx,disy,disz,x,y,z) ; 


    }
};