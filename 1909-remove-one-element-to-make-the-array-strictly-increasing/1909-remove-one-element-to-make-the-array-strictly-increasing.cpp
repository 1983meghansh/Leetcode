class Solution {
public:
    
    int LIS(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] and dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
    
    bool canBeIncreasing(vector<int>& nums) {
        int n=nums.size();
        int lis=LIS(nums);
        if(n-lis<=1)
            return true;
        return false;
    }
};