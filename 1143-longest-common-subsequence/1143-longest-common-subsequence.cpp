class Solution {
public:
//     int dp[1000 + 1][1000 + 1];
//     int helper(int idx1,int idx2,string s1,string s2)
//     {
//         if(idx1==0 or idx2==0)
//             return 0;
        
//         if(dp[idx1][idx2]!=-1)
//             return dp[idx1][idx2];
//         //take all comparisons
        
//         if(s1[idx1-1]==s2[idx2-1])
//             return dp[idx1][idx2]= 1+helper(idx1-1,idx2-1,s1,s2);
//         else
//         return dp[idx1][idx2]= max(helper(idx1-1,idx2,s1,s2),helper(idx1,idx2-1,s1,s2)); 
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int l1=text1.length();
//         int l2=text2.length();
//        memset(dp, -1, sizeof(dp));   
       
//         return helper(l1,l2,text1,text2);
//    }
    //below is iterative dp
    int longestCommonSubsequence(string s1, string s2) {
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
//      int dp[1000 + 1][1000 + 1];
    
//     int maxLen(string& s1, string& s2, int n, int m)
//     {
//         if (n == 0 || m == 0)
//             return 0;
        
//         if (dp[n][m] != -1)
//             return dp[n][m];

//         if (s1[n - 1] == s2[m - 1])
//             return dp[n][m] = 1 + maxLen(s1, s2, n - 1, m - 1);
//         else
//             return dp[n][m] = max(0 + maxLen(s1, s2, n - 0, m - 1), 0 + maxLen(s1, s2, n - 1, m - 0));
//     }
        
//     int longestCommonSubsequence(string s1, string s2) 
//     {
//         memset(dp, -1, sizeof(dp));        
//         return maxLen(s1, s2, s1.length(), s2.length());
//     }
};