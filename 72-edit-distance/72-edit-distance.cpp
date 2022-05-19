class Solution {
public:
    
    int helper(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
        //base case
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        //travel all possible cases , explore everything
        
        
        if(s1[i]==s2[j])
            return dp[i][j]=0+helper(i-1,j-1,s1,s2,dp);
        return dp[i][j]=1+min(helper(i,j-1,s1,s2,dp),min(helper(i-1,j,s1,s2,dp),helper(i-1,j-1,s1,s2,dp)));
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,word1,word2,dp);
    }
};