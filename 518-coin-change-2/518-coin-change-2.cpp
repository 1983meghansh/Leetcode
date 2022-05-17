class Solution {
public:
    
    int helper(int idx,int target,vector<int>&coins,vector<vector<int>>&dp)
    {
        //base case
        if(idx==0)
            return (target%coins[0]==0);
        
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        
        
        int nottake=helper(idx-1,target,coins,dp);
        int take=0;
           if(coins[idx]<=target)
                take=helper(idx,target-coins[idx],coins,dp);
        return dp[idx][target]=take+nottake;
        
    }
    int change(int amount, vector<int>& coins) {
        int idx=coins.size();
        vector<vector<int>>dp(idx+1,vector<int>(amount+1,-1));
        return helper(idx-1,amount,coins,dp);
    }
};