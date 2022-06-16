class Solution {
public:
    string longestPalindrome(string s) {
        
        //dp table bharo
        
        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int maxi=1;
        for(int i=0;i<n;i++)
            dp[i][i]=1;        //aLL single length strings are palindrome
        
        int st=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;     //for string of len 2 ->if first and second char are same then its palindrome
                maxi=2;
                st=i;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] and dp[i+1][j-1]==1)   //if stirng is of len>=3 then check if boundary charac matches if yes then check if the non boundary string is palindrome
                {
                    dp[i][j]=1;
                    if(k>maxi)
                    {
                        st=i;
                        maxi=k;
                    }
                }
                
            }
        }
        return s.substr(st,maxi);
        
    }
};