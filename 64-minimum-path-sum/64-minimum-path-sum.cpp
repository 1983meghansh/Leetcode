class Solution {
public:
    int helper(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(m==0 && n==0)
            return grid[0][0];
        if(m<0 || n<0)
            return INT_MAX;
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int up=helper(m-1,n,grid,dp);
        int left=helper(m,n-1,grid,dp);
        
        return dp[m][n]=min(up,left)+grid[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
       return helper(m-1,n-1,grid,dp);
    }
//     int calculate(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
//     if(row == 0 && col == 0) 
//         return grid[0][0];
//     if(row < 0 || col < 0)
//         return INT_MAX;
//     if(dp[row][col] != -1)
//         return dp[row][col];
    
//     int left = calculate(row, col - 1, grid, dp);
//     int up = calculate(row - 1, col, grid, dp);
//     return dp[row][col] = min(left, up) + grid[row][col];
// }

// int minPathSum(vector<vector<int>>& grid) {
//     int row = grid.size(), col = grid[0].size();
//     vector<vector<int>> dp(row, vector<int> (col, -1));
//     return calculate(row - 1, col - 1, grid, dp);
// }
};