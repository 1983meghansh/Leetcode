class Solution {
public:
    
//     int helper(int i,int j,string &s,string &t,vector<vector<int>>&dp)
//     {
//         if(j<0)
//             return 1;
//         if(i<0)
//             return 0;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         if(s[i]==t[j])
//             return dp[i][j]=helper(i-1,j-1,s,t,dp)+helper(i-1,j,s,t,dp);
        
//         return dp[i][j]=helper(i-1,j,s,t,dp);
//     }
//     int numDistinct(string s, string t) {
//         int m=s.length();
//         int n=t.length();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return helper(m-1,n-1,s,t,dp);
//     }
    //lets try iterative dp
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<double>>dp(m+1,vector<double>(n+1,0));
        //base case
        //shift indexes to right
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        //now convert recuurences
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};