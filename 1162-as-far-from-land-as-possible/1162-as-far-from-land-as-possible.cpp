class Solution {
public:
    int maxDistance(vector<vector<int>>& mat) {
        //Do 01 matrix problem first
        
        //bfs is a level wise algorithm 
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        // using queue to store position of elements whose answer we know, to use it to derive others' distances
        queue<pair<int,int>>q;
        int cnt=0;
        // distance of 0 from nearest 0 will be 0 (itself)
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    cnt++;
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        if(cnt==m*n)return -1;
        if(cnt==0)return -1;
        
        // right, bottom, left, top - directions in which we can move
        vector<pair<int,int>>dirs{{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!q.empty())
        {
            // position of element whose result is known
            int curx=q.front().first;
            int cury=q.front().second;
            q.pop();
            //traversing in all directions
            for(auto dir:dirs)
            {
                int x=curx+dir.first;
                int y=cury+dir.second;
                // if the new position is valid
                if(x>=0 and x<m and y>=0 and y<n)
                {
                    // update the distance if previous distance is more than distance of current element + 1 (bcoz. we can move only 1 step at a time)
                    if(ans[x][y]>ans[curx][cury]+1)
                    {
                        ans[x][y]=ans[curx][cury]+1;
                        q.push({x,y}); // adding result to queue to use to derive other distances
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]>maxi)
                    maxi=ans[i][j];
            }
        }
       
        return maxi;
    }
};