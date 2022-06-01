class Solution {
public:
//     int numIslands(vector<vector<char>>& grid) {
//         several connected components
//         so perform bfs inside for loop
        
//         queue<pair<int,int>>q;
//         int m=grid.size();
//         int n=grid[0].size();
//         int islands=0;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==1)
//                 {
//                     q.push({i,j});
//                     islands++;
//                     grid[i][j]=0;
//                     while(!q.empty())
//                     {
                        
//                          int k=q.front().first;
//                          int l=q.front().second;
//                          q.pop();
//                         mark visited
//                         grid[k][l]=0;
//                         if(k-1>=0 and grid[k-1][l]==1)
//                         {
//                             grid[k-1][l]=0;
//                             q.push({k-1,l});
//                         }
//                          if(l-1>=0 and grid[k][l-1]==1)
//                         {
//                             grid[k][l-1]=0;
//                             q.push({k,l-1});
//                         }
//                          if(k+1<m and grid[k+1][l]==1)
//                         {
//                             grid[k+1][l]=0;
//                             q.push({k+1,l});
//                         }
//                          if(l+1<n and grid[k][l+1]==1)
//                         {
//                             grid[k][l+1]=0;
//                             q.push({k,l+1});
//                         }
//                     }
//                 }
//             }
//         }
//         return islands;
        
//     }
    
    //check out dfs code!!!!!
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int islands=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    islands++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid,int x,int y,int m,int n)
    {
        if(x>=m or x<0 or y>=n or y<0 or grid[x][y]!='1')
            return;
        
        grid[x][y]=2;
        dfs(grid,x+1,y,m,n);
        dfs(grid,x,y+1,m,n);
                dfs(grid,x-1,y,m,n);
                dfs(grid,x,y-1,m,n);


        
    }
};