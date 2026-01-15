class Solution {
public:
    int djikstra(auto& graph, int n,int src, int dest) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int mod = 1e9+7 ;

        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node])
                continue;

            for (auto adj : graph[node]) {
                int nextnode = adj.first;
                long long weight = adj.second;
                long long newDist = dis + weight;

                if (newDist == dist[nextnode]) {
                    ways[nextnode] = (ways[nextnode] + ways[node]) % mod;
                } else if (newDist < dist[nextnode]) {
                    dist[nextnode] = newDist;
                    ways[nextnode] = ways[node];
                    pq.push({newDist, nextnode});
                }
            }
        }

        return static_cast<int>(ways[n - 1] % mod);
    }
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < roads.size(); i++) {
            int x = roads[i][0];
            int y = roads[i][1];
            int w = roads[i][2];

            graph[x].push_back({y, w});
            graph[y].push_back({x, w});
        }

        vector<int> dist(n, INT_MAX);

        return djikstra(graph, n, 0, n - 1);
    }
};