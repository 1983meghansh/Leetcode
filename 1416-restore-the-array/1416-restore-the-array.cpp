class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int>dp(n,-1);
      return helper(0,s,k,dp);
    }
    
    int helper(int idx,string &s,int k,vector<int>&dp)
    {
        
        if(idx==s.size())
            return 1;
        if(s[idx]=='0')
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=0;
        long long temp=0;
        for(int i=idx;i<s.size();i++)
        {
            temp=temp*10+s[i]-'0';
            if(temp>k)
                break;
           ans+= helper(i+1,s,k,dp);
             ans %= 1000000007;
                
        }
        return dp[idx]=ans;
    }
};