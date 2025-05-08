class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        //reverse the graph and do topological sort
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> indeg(n,0);
        vector<int>topo;
        queue<int>q;

        for(int i=0; i<n; i++)
        {
            for(int x: graph[i])
            {
                rev[x].push_back(i);
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int x: rev[i])
                indeg[x]++;
        }
        
        for(int i=0; i<n; i++)
        {
            if(indeg[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for(int x: rev[node])
            {
                indeg[x]--;
                if(indeg[x] == 0)
                    q.push(x);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};
