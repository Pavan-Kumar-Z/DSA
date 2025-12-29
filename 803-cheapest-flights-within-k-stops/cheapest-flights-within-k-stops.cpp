class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n) ;

        for(int i = 0; i < flights.size() ; i++){
            int x = flights[i][0] ;
            int y = flights[i][1] ;
            int w = flights[i][2] ;

            graph[x].push_back({y,w}) ;
        }

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq ;

        pq.push({0, {src, k + 1}}) ;
        dist[src][k+1] = 0;

        while(!pq.empty()){
            auto [price , d] = pq.top() ;
            pq.pop() ;

            int node = d.first;
            int stops = d.second;

            if(node == dst) return price;
            if(stops == 0) continue;

            for(auto adj : graph[node]){
                int newnode = adj.first ;
                int weight  = adj.second ;

                if(price + weight < dist[newnode][stops-1]){
                    dist[newnode][stops-1] = price + weight;
                    pq.push({price + weight, {newnode, stops-1}});
                }
            }
        }

        return -1; 
    }
};
