class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //observe the dp table for a sample test case in the image
        //https://www.youtube.com/watch?v=rSi4MpGEz1M
        int n=nums.size();
        if(n<3)
            return 0;
        vector<int>dp(n+2);
        int res=0;
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            {
                dp[i]=dp[i-1]+1;
                res+=dp[i];
            }
        }
        return res;
    }
};