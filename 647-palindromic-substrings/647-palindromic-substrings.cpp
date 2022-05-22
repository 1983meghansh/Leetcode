class Solution {
public:
    int countSubstrings(string s) {
        //refer pepcoding
        int n=s.length();
        bool dp[n][n];
        int cnt=0;
        
        for(int diag=0;diag<n;diag++)
        {
            for(int i=0,j=diag;j<n;i++,j++)
            {
                if(diag==0)
                dp[i][j]=true;
                
                else if(diag==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]==true)
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j]==true)
                    cnt++;
            }
        }
        return cnt;
    }
};