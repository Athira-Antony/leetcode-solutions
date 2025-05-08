class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = numCourses;
        vector<int>topo;
        queue<int>q;
        vector<int>indeg(n,0);

        vector<vector<int>> adj(n);
        for(auto p: prerequisites)
            adj[p[1]].push_back(p[0]);
        
        for(int i=0; i<n; i++)
        {
            for(int x: adj[i])
                indeg[x]++;
        }

        for(int i=0; i<n; i++)
        {
            if(indeg[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int x: adj[node])
            {
                indeg[x]--;
                if(indeg[x] == 0)
                    q.push(x);
            }
        }
        if(topo.size() == n) return topo ;
        else
            return {};
    }
};
