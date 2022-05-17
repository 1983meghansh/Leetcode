class Solution {
public:
    
//     int helper(int idx,int target,vector<int>&coins,vector<vector<int>>&dp)
//     {
//         //memoization
//         //base case
//         if(idx==0)
//             return (target%coins[0]==0);
        
//         if(dp[idx][target]!=-1)
//             return dp[idx][target];
        
        
//         int nottake=helper(idx-1,target,coins,dp);
//         int take=0;
//            if(coins[idx]<=target)
//                 take=helper(idx,target-coins[idx],coins,dp);
//         return dp[idx][target]=take+nottake;   
//     }
//     int change(int amount, vector<int>& coins) {
//         int idx=coins.size();
//         vector<vector<int>>dp(idx+1,vector<int>(amount+1,-1));
//         return helper(idx-1,amount,coins,dp);
//     }
    
    int helper(int n,int target,vector<int>&coins)
    {
        //tabulation , iterative dp
        //base case
         vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i=0;i<=target;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=1;
        }
        
        for(int ind=1;ind<n;ind++)
        {
            
            for(int amount=0;amount<=target;amount++)
            {
                int nottake=dp[ind-1][amount];
                int take=0;
                if(coins[ind]<=amount)
                    take=dp[ind][amount-coins[ind]];
                dp[ind][amount]=take+nottake;
            }
        }
        return dp[n-1][target];
        
    }
    
    
    int change(int amount, vector<int>& coins) {
        int idx=coins.size();
       
        return helper(idx,amount,coins);
    }
};