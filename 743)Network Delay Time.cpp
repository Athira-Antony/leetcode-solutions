class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
      vector<vector<pair<int,int>>>adj(n+1); // 1-based
      for(auto t: times)
      {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v,w});
      }

      priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>>pq;
      vector<int>dist(n+1,INT_MAX);
      dist[k] = 0;
      pq.push({0,k});

      while(!pq.empty())
      {
        auto [d,u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v,w] : adj[u])
        {
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
      }
      int res = -1;
      for(int i=1; i<=n; i++)
      {
        if(dist[i] == INT_MAX)  return -1;
        res = max(res,dist[i]);
      }
      return res;
    }
};
