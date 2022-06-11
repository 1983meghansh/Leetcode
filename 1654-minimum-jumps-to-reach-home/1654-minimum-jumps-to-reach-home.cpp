class Solution {
public:
    
    unordered_map<int,int>mp;
    int dp[6009][2];  //2 states of dp 
    //first is indexes and 2nd parameter is that we dont go back consecutively
    
    int helper(int i,bool back,int a, int b, int x)
    {
        
        if(i==x)
            return 0;
        
        if(i<0 or i>6000 or back>=2 or mp.find(i)!=mp.end())
            return 1e9+7;
        if(dp[i][back]!=-1)
            return dp[i][back];
        
        dp[i][back]=helper(i+a,0,a,b,x)+1;
        if(back==0)
            dp[i][back]=min(dp[i][back],helper(i-b,1,a,b,x)+1);
        return dp[i][back];
        
    }
    
   
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
         for(auto i:forbidden)
             mp[i]=1;
        memset(dp,-1,sizeof(dp));
        int ans= helper(0,0,a,b,x);
        if(ans>1e9)
            return -1;
        return ans;
        
    }
};