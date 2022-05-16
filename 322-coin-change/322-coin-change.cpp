class Solution {
public:
    int helper(int index,int target,vector<int>& coins,vector<vector<int>>&dp)
    {   
        if(index==0)
        {
            if(target%coins[0]==0)
                return target/coins[0];
        
            return 1e9;
        }
        
        if(dp[index][target]!=-1)
            return dp[index][target];
        
        int nottake=0+helper(index-1,target,coins,dp);
        
        int take=1e9;
        if(coins[index]<=target)
            take=1+helper(index,target-coins[index],coins,dp);
        
        return dp[index][target]=min(nottake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=helper(n-1,amount,coins,dp);
        return ans==1e9?-1:ans;
    }
};