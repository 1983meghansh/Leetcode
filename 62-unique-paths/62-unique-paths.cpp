class Solution {
public:
    
//     int helper(int m,int n,vector<vector<int> > &dp)
//     {
//         //base case
//         //top down dp
//         //step 1 ->indexes
//         if(m==0 and n==0)
//             return 1;
//         if(m<0 or n<0)
//             return 0;
//         if(dp[m][n]!=-1)
//             return dp[m][n];
//         //step 2-> take all appraches
//         int left=helper(m,n-1,dp);
//         int up=helper(m-1,n,dp);
//         return dp[m][n]=left+up;
        
//     }
    int helper(int m,int n,vector<vector<int> > &dp)
    {
        //bottom up iterative dp
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               
                if(i==0 and j==0){
                    dp[i][j]=1;
                    continue;
                }
                
                 int right=0,down=0;
                if(i>0)
                 down=dp[i-1][j];
                if(j>0)
                 right=dp[i][j-1];
                dp[i][j]=down+right;
            }
        }
        return dp[m-1][n-1];
      
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m,n,dp);
    }
};