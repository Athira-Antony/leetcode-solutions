class Solution 
{
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
        {
            int n = mat.size(), m = mat[0].size();
            vector<vector<int>> res (n,vector<int>(m,INT_MAX-1));
            
            //min of left and top
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(mat[i][j] == 0)
                        res[i][j] = 0;
                    else
                    {
                        if(i>0)
                            res[i][j] = min (res[i][j], res[i-1][j]+1);
                        if(j>0)
                            res[i][j] = min (res[i][j], res[i][j-1]+1);
                    }
                }
            }

            //min of right and bottom
            for(int i=n-1; i>=0; i--)
            {
                for(int j=m-1; j>=0; j--)
                {
                    if(mat[i][j] == 0)
                        res[i][j] = 0;
                    else
                    {
                        if(i<n-1)
                            res[i][j] = min (res[i][j], res[i+1][j]+1);
                        if(j<m-1)
                            res[i][j] = min (res[i][j], res[i][j+1]+1);
                    }
                }
            }
            return res;
        }
};
