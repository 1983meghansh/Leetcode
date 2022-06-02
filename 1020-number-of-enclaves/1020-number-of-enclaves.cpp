class Solution {
public:
    int cnt=0;
     void dfs(vector<vector<int>>& grid,int x,int y,int n,int m)
    {
        if(x>=n or x<0 or y>=m or y<0 or grid[x][y]!=1)
            return;
        grid[x][y]=0;
         cnt++;
        dfs(grid,x+1,y,n,m);
        dfs(grid,x-1,y,n,m);
        dfs(grid,x,y+1,n,m);
        dfs(grid,x,y-1,n,m);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        //boundary dfs concept
        //do no of islands problem first
         int n=grid.size();
        int m=grid[0].size();
        //dfs call to mark all boundary islands as 0 as they dont count
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i*j==0 or i==n-1 or j==m-1)
                {
                    if(grid[i][j]==1)
                    dfs(grid,i,j,n,m);
            }}
        }
        cnt=0;   //important because the unwanted islands may also get counted due to previous dfs calls
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    
                    dfs(grid,i,j,n,m);
                }
            }}
        return cnt;
        
    }
};