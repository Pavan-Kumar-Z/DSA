class Solution {
public:

    vector<int> djikstra(int n, int src, auto & graph, auto & dis){
       
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;

        dis[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();

            if(temp.first > dis[temp.second]) continue;

            for(auto & adj : graph[temp.second]){
                int nextnode = adj.first;
                int weight = adj.second;

                if(weight + temp.first < dis[nextnode]){
                    dis[nextnode] = weight + temp.first;
                    pq.push({dis[nextnode],nextnode});
                }
            }
        }

        return dis;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int Thres) {
        
        vector<vector<pair<int,int>>> graph(n);

        for(int i = 0 ; i < edges.size() ; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];

            graph[x].push_back({y,w});
            graph[y].push_back({x,w});
        }

        int count = INT_MAX;
        int ans = -1;

        for(int i = 0 ; i < graph.size() ; i++){
            vector<int> dis(n,INT_MAX);

            dis = djikstra(n,i,graph,dis);

            int temp = 0;
            for(int j = 0 ; j < dis.size() ; j++){
                if(dis[j] <= Thres) temp++;
            }

            if(temp < count || (temp == count && i > ans)){
                count = temp;
                ans = i;
            }
        }

        return ans;
    }
};
