class Solution {
public:
    int dp[1001];
    int helper(int i,vector<int>& cost)
    {
        if(i<0)
            return 0;
        if(i==0 or i==1)
            return cost[i];
        if(dp[i]!=-1)
            return dp[i];
        dp[i]=cost[i]+min(helper(i-1,cost),helper(i-2,cost));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        return min(helper(n-1,cost),helper(n-2,cost));
    }
};