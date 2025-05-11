class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
            >pq;
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>dist(n,vector(m,INT_MAX));
        dist[0][0] = 0;

        pq.push({0,0,0});

        int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

        while(!pq.empty())
        {
            auto [diff,x,y] = pq.top();
            pq.pop();

            if(x == n-1 && y==m-1)
                return diff;

            for(int i=0; i<4; i++)
            {
                int nx = x+dx[i] , ny = y+dy[i];
                if(nx >=0 &&  ny >= 0 && nx<n && ny<m)
                {
                    int difference = max(abs(heights[x][y] - heights[nx][ny]),diff);
                    if(difference < dist[nx][ny])
                    {
                        dist[nx][ny] = difference;
                        pq.push({difference,nx,ny});
                    }
                }
            }
        }
        return 0;
    }
};
