class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int x,int y,int m,int n,int &flag)
    {
        //we pass flag as reference so that its value does not change with recursive calls
        if(x<0 or x>=m or y<0 or y>=n or grid2[x][y]!=1)
            return;
        if(grid1[x][y]==0)
            flag=0;
        grid2[x][y]=0;  //mark visited
        dfs(grid1,grid2,x-1,y,m,n,flag);
        dfs(grid1,grid2,x,y-1,m,n,flag);
        dfs(grid1,grid2,x+1,y,m,n,flag);
        dfs(grid1,grid2,x,y+1,m,n,flag);

    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int subisland=0;
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j]==1)
                {
                    int flag=1;
                    dfs(grid1,grid2,i,j,m,n,flag);
                    subisland+=flag;
            }
        }}
        return subisland;
    }
};