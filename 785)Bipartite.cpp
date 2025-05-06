class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) 
        {
            int n = graph.size();
            vector<int>clr(n,-1);
    
            for(int i=0; i<n; i++)
            {
                if(clr[i]==-1)
                {
                    queue<int>q;
                    clr[i]=0;
                    q.push(i);
    
                    while(!q.empty())
                    {
                        int curr = q.front();
                        q.pop();
    
                        for(int x: graph[curr])
                        {
                            if(clr[x] == -1)
                            {
                                clr[x] = 1 - clr[curr];
                                q.push(x);
                            }
                            else if(clr[x] == clr[curr])
                                return false;
                        }
                    }
                }
            }
    
            return true;
        }
    };