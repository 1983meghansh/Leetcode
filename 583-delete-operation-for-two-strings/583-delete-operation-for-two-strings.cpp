class Solution {
public:
    int lcs(string s1,string s2)
    {
         int n=s1.length();
        int m=s2.length();
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
         for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        //find lcs and answer is length of both strings - lcs
        int lcslen=lcs(word1,word2);
        int len1=word1.length();
        int len2=word2.length();
        int ans=0;
        ans+=len1-lcslen;
        ans+=len2-lcslen;
        return ans;
    }
};