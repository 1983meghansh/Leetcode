class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        if(j<0 or j>=n)
            return INT_MAX;
        if(i==0)
            return matrix[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int up=f(i-1,j,n,matrix,dp);
        int diagleft=f(i-1,j-1,n,matrix,dp);
        int diagright=f(i-1,j+1,n,matrix,dp);
        
        return dp[i][j]=min(up,min(diagleft,diagright))+matrix[i][j];
        
    }
        
        
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int j=0;j<n;j++)
        {
            int ans=f(m-1,j,n,matrix,dp);
            mini=min(ans,mini);
        }
        return mini;
    }
};