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
    int minInsertions(string s) {
        //answer is lengthofstring-longestpossiblesubsequence
         string s2=s;
            reverse(s2.begin(),s2.end());
        int longestpalindrom=lcs(s,s2);
        int len=s.length();
        return len-longestpalindrom;
    }
};