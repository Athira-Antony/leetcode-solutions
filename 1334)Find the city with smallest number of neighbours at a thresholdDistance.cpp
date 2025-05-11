class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>>mat(n,vector(n,INT_MAX));
        for(auto e: edges)
        {
            mat[e[0]][e[1]] = e[2];
            mat[e[1]][e[0]] = e[2];
        }
        for(int i=0; i<n; i++) 
            mat[i][i] = 0; //diagonal elements
    
        for(int k =0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(mat[i][k] == INT_MAX || mat[k][j] == INT_MAX)
                        continue;
                    mat[i][j] = min (mat[i][j] , mat[i][k]+mat[k][j]);
                }
            }
        }
        int mincnt = n, city = -1;
        for(int i=0; i<n; i++)
        {
            int cnt = 0;
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt <= mincnt)
                {
                    mincnt = cnt;
                    city = i;
                }
        }
        return city;
    }
};
