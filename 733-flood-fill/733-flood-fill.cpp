class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //bfs code
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(q.size()>0)
        {
            
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0 and vis[i-1][j]==0 and image[i][j]==image[i-1][j])
            {
                vis[i-1][j]=1;
                q.push({i-1,j});
            }
             if(j-1>=0 and vis[i][j-1]==0 and image[i][j]==image[i][j-1])
            {
                vis[i][j-1]=1;
                q.push({i,j-1});
            }
             if(i+1<image.size() and vis[i+1][j]==0 and image[i][j]==image[i+1][j])
            {
                vis[i+1][j]=1;
                q.push({i+1,j});
            }
             if(j+1<image[0].size() and vis[i][j+1]==0 and image[i][j]==image[i][j+1])
            {
                vis[i][j+1]=1;
                q.push({i,j+1});
            }
            image[i][j]=newColor;
        }
        return image;
    }
};