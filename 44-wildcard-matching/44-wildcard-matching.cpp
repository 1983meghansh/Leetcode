class Solution {
public:
    
    bool helper(int i,int j,string &s,string &p,vector<vector<int>>&dp)
    {
        //base cases
        if(i<0 and j<0)
            return true;
        if(i<0 and j>=0)
            return false;
        if(i>=0 and j<0)
        {
            for(int t=0;t<=i;t++)
            {
                if(s[t]!='*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
       //explore all possibilities
        if(s[i]==p[j] or s[i]=='?')
            return dp[i][j]=helper(i-1,j-1,s,p,dp);
        
        if(s[i]=='*')
        {
            return dp[i][j]=helper(i-1,j,s,p,dp) or helper(i,j-1,s,p,dp);
        }
        
        return dp[i][j]=false;
        
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,p,s,dp);
    }
};