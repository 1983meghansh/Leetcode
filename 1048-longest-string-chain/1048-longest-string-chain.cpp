class Solution {
public:
    
    bool  isPossible(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1)
            return false;
        
        int p1=0,p2=0;
        while(p1<s1.size())
        {
            if(p2<s2.size() and s1[p1]==s2[p2])
            {
                p1++;
                p2++;
            }
            else{
                p1++;
            }
        }
        if(p1==s1.size() and p2==s2.size())
            return true;
        return false;
    }
  static  bool compare(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        //now this question is similar to LIS but its not a subsequence , 
        //so it can be in any order, sort it by length to make it a subsequence
        sort(words.begin(),words.end(),compare);
        int n=words.size();
        int ans=1;
        vector<int>dp(n+1,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isPossible(words[i],words[j]) and 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>ans)
                ans=dp[i];
        }
        return ans;
    }
};