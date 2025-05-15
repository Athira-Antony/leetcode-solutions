class Disjointset{
    public:
    vector<int>rank,par;
    Disjointset(int n)
    {
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0; i<n; i++)
            par[i] = i;
    }

    int findpar(int u)
    {
        if(par[u] == u)
            return u;
        return par[u] = findpar(par[u]);
    }

    void unionByRank(int u, int v)
    {
        int par_u = findpar(u), par_v = findpar(v);
        if(rank[par_u] < rank[par_v])
        {
            par[par_u] = par_v;
        }
        else if(rank[par_u] > rank[par_v])
        {
            par[par_v] = par_u;
        }
        else
        {
            par[par_v] = par_u;
            rank[par_u] ++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int row = 0, col = 0;
        for(auto s: stones)
        {
            row = max (row, s[0]);
            col = max (col, s[1]);
        }

        int n = row+col+2;
        Disjointset ds(n);
        unordered_set<int>useNodes;

        for(auto s: stones)
        {
            int nodeRow = s[0];
            int nodeCol = s[1] + row + 1;
            ds.unionByRank(nodeRow, nodeCol);
            useNodes.insert(nodeRow);
            useNodes.insert(nodeCol);
        }

        int cnt = 0;
        for (auto i: useNodes)
        {
            if(ds.par[i] == i )
                cnt++;
        }
        return stones.size() - cnt;
    }
};
