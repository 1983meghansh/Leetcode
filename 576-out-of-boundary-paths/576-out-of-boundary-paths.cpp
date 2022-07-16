class Solution {
public:
    long long int M=1000000007;
    
    int helper(int m,int n,int limit,int r,int c,vector<vector<vector<int>>>&dp)
    {
        if(r<0 or r>=m or c<0 or c>=n)
            return 1;
        if(limit<=0)
            return 0;
        if(dp[r][c][limit]!=-1)
            return (dp[r][c][limit])%M;
        int down=helper(m,n,limit-1,r+1,c,dp)%M;
                int up=helper(m,n,limit-1,r-1,c,dp)%M;
                int left=helper(m,n,limit-1,r,c-1,dp)%M;
                int right=helper(m,n,limit-1,r,c+1,dp)%M;
        dp[r][c][limit]=(down%M+up%M+left%M+right%M)%M;
        return (dp[r][c][limit])%M;



    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
       
        
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return helper(m,n,maxMove,startRow,startColumn,dp);
        
    }
};