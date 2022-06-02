class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y,int n,int m)
    {
        if(x>=n or x<0 or y>=m or y<0 or grid[x][y]!=0)
            return;
        grid[x][y]=1;
        dfs(grid,x+1,y,n,m);
                dfs(grid,x-1,y,n,m);
        dfs(grid,x,y+1,n,m);
        dfs(grid,x,y-1,n,m);

    }
    int closedIsland(vector<vector<int>>& grid) {
        //a verry good video on boundary dfs concept 
        //https://www.youtube.com/watch?v=JJ5FxoLckMw
        //first make all boundaries as 1
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i*j==0 or i==n-1 or j==m-1)
                {
                    if(grid[i][j]==0)
                    dfs(grid,i,j,n,m);
            }}
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(grid,i,j,n,m);
                }
            }}
        return ans;
    }
};