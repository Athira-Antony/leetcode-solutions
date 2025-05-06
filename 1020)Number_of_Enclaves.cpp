class Solution {
    public:
        int numEnclaves(vector<vector<int>>& grid) 
        {
            int tot = 0,cnt = 0;
            int n = grid.size(), m = grid[0].size();
            queue<pair<int,int>>q; // for boundary ones
            vector<vector<int>>vis(n,vector(m,0));
    
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(grid[i][j]==1)
                        tot++;
                    if(i==0 || j==0 || i==n-1 || j==m-1)
                    {
                        if(grid[i][j] == 1)
                        {
                            q.push({i,j});
                            vis[i][j] = 1;
                            cnt++;
                        }
                    }
                }
            }
    
            int dx[4] = {-1,0,1,0}, dy[4]={0,1,0,-1};
    
            while(!q.empty())
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
    
                for(int i=0; i<4; i++)
                {
                    int nx = x + dx[i] , ny = y+dy[i];
                    if(nx<n && ny<m && nx>=0 && ny>=0 && grid[nx][ny]==1 && !vis[nx][ny])
                    {
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                        cnt++;
                    }
                }
            }
    
            return tot - cnt;
        }
    };