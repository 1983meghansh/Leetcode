class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //make a frequency table for nums[i]=0 to nums of end and now if u pick nums[i] then u cant pick nums[i-1] or nums[i+1] ie if from freq table u pick 4 u cant consider 3 and 1 .....make a dp table , dp state ->each dp[i] denoted max points u can earn by picking that index . and return the dp[last]
        int maxe=*max_element(nums.begin(),nums.end());
        int dp[20004];
        vector<int>freq(20004);
        for(auto i:nums)
            freq[i]++;
        dp[0]=0;
        dp[1]=freq[1];
        for(int i=2;i<=maxe;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+freq[i]*i);
        }
        return dp[maxe];
    }
};