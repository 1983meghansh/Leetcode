class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        int islands=0;
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    int area=1;
                    islands++;
                    grid[i][j]=0;
                    while(!q.empty())
                    {   
                         int k=q.front().first;
                         int l=q.front().second;
                         q.pop();
                        //mark visited
                        //grid[k][l]=0;
                        if(k-1>=0 and grid[k-1][l]==1)
                        {
                            grid[k-1][l]=0;
                            q.push({k-1,l});
                            area++;
                        }
                         if(l-1>=0 and grid[k][l-1]==1)
                        {
                            grid[k][l-1]=0;
                            q.push({k,l-1});
                             area++;

                        }
                         if(k+1<m and grid[k+1][l]==1)

                        {
                           grid[k+1][l]=0;

                            q.push({k+1,l});
                             area++;
                             }

                         if(l+1<n and grid[k][l+1]==1)

                        {

                            grid[k][l+1]=0;

                            q.push({k,l+1});
                             area++;

                        }
                    }
                    maxi=max(area,maxi);
                }

            }

        }
        cout<<islands;

        return maxi;
    }
};