class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int  n = grid.size(), m = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0)
            return -1;
        
        queue<pair<int,int>>q;
        q.push({0,0});//top left node
        grid[0][0] = 1; //distance

        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty())
        {
            int row = q.front().first, col = q.front().second;
            q.pop();

            if(row == n-1 && col == m-1)
                return grid[n-1][m-1];
            
            for(int i=0; i<8; i++)
            {
                int nx = row + dx[i], ny = col + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny<m && grid[nx][ny] == 0)
                {
                    q.push({nx,ny});
                    grid[nx][ny] = grid[row][col] + 1;
                }
            }
        }
        return -1;
        
    }
};
