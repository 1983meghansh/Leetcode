class Solution {
public:
     vector<pair<int,int>> v;
     int dp[601][101][101];
    int helper(int idx,int m,int n,vector<string>& strs)
    {
        // if(m<0 or n<0)
        //    return -1;
         if((m==0 && n==0) || idx==0) 
            return dp[idx][m][n]= 0;
        // if(idx==0)
        // {
        //     int cnt0=0,cnt1=0;
        //     string s=strs[0];
        //     for(int i=0;i<s.length();i++)
        //     {
        //         if(s[i]==0)
        //             cnt0++;
        //         else
        //             cnt1++;
        //     }
        //     if(cnt0<=m and cnt1<=n)
        //         return 1;
        //     else
        //         return 0;
        // }
        if(dp[idx][m][n]!=-1)
            return dp[idx][m][n];
       
        if(v[idx-1].first>m or v[idx-1].second>n)
           return dp[idx][m][n]=helper(idx-1,m,n,strs);
        else
           return  dp[idx][m][n]= max(1+helper(idx-1,m-v[idx-1].first,n-v[idx-1].second,strs),0+helper(idx-1,m,n,strs));
            
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        for(int k=0; k<strs.size(); k++)
        {
            int i=0;
            for(int j=0; j<strs[k].length(); j++)
            {
                if(strs[k][j]=='0')
                    i++;
            }
            v.push_back({i,strs[k].length()-i});
        }
        memset(dp,-1,sizeof(dp)); 
       
        
        return helper(strs.size(),m,n,strs);
        
    }
};