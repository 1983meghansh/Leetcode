class Solution {
public:
//     int f(int ind,int buy,vector<int>&prices,int n,vector<vector<int>>&dp)
//     {
//         if(ind==n)
//             return 0;
//         if(dp[ind][buy]!=-1)
//             return dp[ind][buy];
        
//         int profit=0;
//         if(buy)
//         profit=max(-prices[ind]+f(ind+1,0,prices,n,dp),0+f(ind+1,1,prices,n,dp));
//         else
//             profit=max(prices[ind]+f(ind+1,1,prices,n,dp),f(ind+1,0,prices,n,dp));
//         return dp[ind][buy]=profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n,vector<int>(2,-1));
//         return f(0,1,prices,n,dp);
//     }
    
     int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        
        dp[n][0]=0;
         dp[n][1]=0;
         for(int i=n-1;i>=0;i--)
         {
             for(int b=0;b<=1;b++)
             {
                 int profit=0;
                 if(b)
                 {
                     profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                 }
                 else
                     profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                 dp[i][b]=profit;
             }
         }
         return dp[0][1];
    }
    
};