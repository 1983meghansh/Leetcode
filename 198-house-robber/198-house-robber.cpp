class Solution {
public:
    //recursion+memoization=dp soln
   //  int rob(vector<int>& nums) {
   //      int n=nums.size();
   //      vector<int>dp(n,-1);
   //      return helper(n-1,nums,dp);
   //  }
   // int helper(int ind,vector<int>&nums,vector<int>&dp)
   //  {
   //      if(ind==0)
   //          return nums[0];
   //      if(ind<0)
   //          return 0;
   //      if(dp[ind]!=-1)
   //          return dp[ind];
   //     int pick=nums[ind]+helper(ind-2,nums,dp);
   //     int notpik=0+helper(ind-1,nums,dp);
   //     return dp[ind]=max(pick,notpik);
   //  }
    //tabulated dp(iterative dp) soln
    //TC->O(n), SC->O(n)
    //  int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n,-1);
    //     return helper(n,nums,dp);
    // }
    // int helper(int ind,vector<int>&nums,vector<int>&dp){
    //     dp[0]=nums[0];
    //     for(int i=1;i<ind;i++)
    //     {
    //         int pick=nums[i];
    //         if(i>1)
    //             pick+=dp[i-2];                
    //         int notpick=0+dp[i-1];
    //         dp[i]=max(pick,notpick);
    //     }
    //     return dp[ind-1];
    // }
    
    //space optimization soln
    //TC->O(n),SC->O(1)
    int rob(vector<int>& nums) {
        int n=nums.size();
        return helper(n,nums);
    }
    int helper(int ind,vector<int>&nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<ind;i++)
        {
            int pick=nums[i];
            if(i>1)
                pick+=prev2;                
            int notpick=0+prev;
          int  curri=max(pick,notpick);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};