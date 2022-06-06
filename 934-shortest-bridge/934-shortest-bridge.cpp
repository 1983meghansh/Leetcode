class Solution {
public:
    //Algo of this wonderful yet simple question
    //mark a complete island visited
    //add each (1) of that island into the queue
    //through bfs from each (1) in the queue , keep track of level
    //if anyone reaches 1 , return the level if its minimum
    
    queue<pair<int,int>>q;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==2 or grid[i][j]==0)
            return;
        grid[i][j]=2;   //mark visited
        q.push({i,j});   
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    
    int bfs(vector<vector<int>>& grid)
    {
        int level=0;
        int ans=INT_MAX;
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        while(!q.empty())
        {
            int n=q.size();
            while(n-->0)
            {
                auto a=q.front();
                q.pop();
                for (int h=0; h<4; h++) {
                    int x = dir[h][0] + a.first;
                    int y = dir[h][1] + a.second;
                    if (x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y] == 1)
                    {
                        ans=min(ans,level);
                    }
                  else if (x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y] == 0)
                  {
                      q.push({x, y});
                      grid[x][y] = 2;
                  }
            }
        }
            level++;     // increasing each level by distance + 1
    }
        return ans;
        }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and flag==0)// found 1st '1' in the matrix
                {
                    flag=1;
                    q.push({i,j});
                    dfs(grid,i,j);      // dfs for marking the whole island visited
                    break;
                }
            }
            if(flag!=0)
                break;
        }
        return bfs(grid); // bfs for getting min dist and returning it
        
    }
};