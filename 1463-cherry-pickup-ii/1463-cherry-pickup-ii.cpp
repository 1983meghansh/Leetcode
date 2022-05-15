class Solution {
public:
    
    int helper(int i,int j1,int j2,int m,int n,vector<vector<int>>& grid,vector < vector < vector < int >>> & dp)
    {
        //base case
        //1st is out of bound case and second will be reaching destination case
        if(j1>=n or j1<0 or j2>=n or j2<0)
            return INT_MIN;
        
        if(i==m-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        
        //explore all possible paths 
        //for every 1 step alice takes,BOB has three options steps to take
        
        int maxi=INT_MIN;
        
        for(int d1=-1;d1<=1;d1++)
        {
            for(int d2=-1;d2<=1;d2++)
            {
                int ans;
                if(j1==j2)
                    ans=grid[i][j1]+helper(i+1,j1+d1,j2+d2,m,n,grid,dp);
                else
                    ans=grid[i][j1]+grid[i][j2]+helper(i+1,j1+d1,j2+d2,m,n,grid,dp);
                
                maxi=max(maxi,ans);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n, -1)));
        return helper(0,0,n-1,m,n,grid,dp);
    }
};