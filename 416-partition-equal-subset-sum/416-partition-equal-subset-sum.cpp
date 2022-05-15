class Solution {
public:
    
    int helper(int idx,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target==0)
            return true;
        
        if(idx==0)
            return nums[0]==target;
        
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        
        bool nottake=helper(idx-1,target,nums,dp);
        
        bool take=false;
        if(nums[idx]<=target)
            take=helper(idx-1,target-nums[idx],nums,dp);
        
        return dp[idx][target]=take or nottake;
        
    }
    
    
    bool canPartition(vector<int>& nums) {
        //we just need to find a subarray with sum = totsum/2;
        
        int totsum=0;
        for(int i=0;i<nums.size();i++)
            totsum+=nums[i];
        if(totsum%2!=0)
            return false;
        
        int target=totsum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        
        return helper(n-1,target,nums,dp);
    }
};