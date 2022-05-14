class Solution {
public:
    int f(int i,int j,int m,vector<vector<int>>& t,vector<vector<int>>&dp)
    {
        //base case
        if(i==m-1)
            return t[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down= t[i][j]+f(i+1,j,m,t,dp);
        int diag=t[i][j]+f(i+1,j+1,m,t,dp);
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return f(0,0,m,triangle,dp);
    }
};