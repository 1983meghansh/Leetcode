class Solution {
public:
    //  int helper(vector<int>&dp,int i,int k,vector<int>& nums)
    // {
    //     if(dp[i]!=INT_MIN)
    //         return dp[i];
    //     for(int j=1;j<=k;j++)
    //     {
    //         if(i+j<nums.size())
    //         {
    //             dp[i]=max(dp[i],nums[i]+helper(dp,i+j,k,nums));
    //         }
    //     }
    //     return dp[i];
    // }
    // int maxResult(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int>dp(n,INT_MIN);
    //     //dp[i] denotes maximum points we can get if we start at this index
    //     dp[n-1]=nums[n-1];
    //     return helper(dp,0,k,nums);
    // }
    
    //lets tabulate it
    // int maxResult(vector<int>& nums, int k) {
    //      int n=nums.size();
    //      vector<int>dp(n,INT_MIN);
    //     dp[0]=nums[0];
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=1;j<=k and i-j>=0;j++)
    //         {
    //             dp[i]=max(dp[i],nums[i]+dp[i-j]);
    //         }
    //     }
    //     return dp.back();
    // }
    //now to further optimize it , we can see that each time we r storing the max of i-1,i-2,i-k values , so instead of iterating k times every time , we can store the max of last i-k value and use them directly
    //we store pair in set as there can be same numberws too
     int maxResult(vector<int>& nums, int k) {
         int n=nums.size();
         vector<int>dp(n,INT_MIN);
        dp[0]=nums[0];
         set<pair<int,int>>s;
         s.insert({nums[0],0});
        for(int i=1;i<n;i++)
        {
            if(i>k)
                s.erase({dp[i-k-1],i-k-1});
            pair<int,int> it=*rbegin(s);
            dp[i]=it.first+nums[i];
            s.insert({dp[i],i});
        }
        return dp.back();
    }
};