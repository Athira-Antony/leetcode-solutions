class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size(), time = 0, cnt = 0, tot = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]!=0)
                    tot++;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty())
        {
            int k = q.size();
            cnt += k;
            while(k--)
            {
                int row = q.front().first, col = q.front().second;
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(nrow >=0 && ncol >=0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({nrow,ncol});}
                }
            }

            if(!q.empty())
                time++;
        }
        return tot == cnt ? time: -1;
    }

    
};