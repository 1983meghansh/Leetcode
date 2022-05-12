class Solution {
public:
    int numDecodings(string s) {
        int dp[101];
        memset(dp,-1,sizeof dp);
       return  helper(0,s,dp);
    }
    int helper(int idx,string s,int *dp)
    {
        int ans=0;
        if(idx>=s.size())
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        int op1=s[idx]-'0';
        int op2=0;
        if(idx<s.size()-1)
             op2=op1*10+s[idx+1]-'0';
        if(op1>0)
           ans+= helper(idx+1,s,dp);
        if(op1>0 and op2>0 and op2<=26)
           ans+= helper(idx+2,s,dp);
        return dp[idx]=ans;
    }
    
    
};