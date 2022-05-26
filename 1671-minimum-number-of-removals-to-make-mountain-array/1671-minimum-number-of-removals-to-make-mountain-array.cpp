class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        //revise longest bitonic subsequence (striver)
        //answer is total length - longest bitonic subsequence
        
        int n=nums.size();
        vector<int>dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] and dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
        }
        
         vector<int>dp2(n,1);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]<nums[i] and dp2[i]<dp2[j]+1)
                    dp2[i]=dp2[j]+1;
            }
        }
        
        int lbs=0;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]>1 and dp2[i]>1)
            lbs=max(lbs,dp[i]+dp2[i]-1);    
        }
        return n-lbs;
    }
};