class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
        {
            int n = image.size(), m = image[0].size(), sclr = image[sr][sc];
            if (sclr == color) 
                return image;
    
            queue<pair <int,int>>clr;
            image[sr][sc] = color;
            clr.push({sr,sc});
    
            int dx[4] = {-1,0,1,0};
            int dy[4] = {0,1,0,-1};
    
            while(!clr.empty())
            {
                int row = clr.front().first, col = clr.front().second;
                clr.pop();
                for(int i=0; i<4; i++)
                {
                    int nrow = row + dx[i] , ncol = col + dy[i];
                    if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && image[nrow][ncol] == sclr){
                        image[nrow][ncol] = color;
                        clr.push({nrow,ncol});
                    }
                }
            }
            return image;
        }
    };