class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        //similar to house robber problem
        long long dp[2000001]={0};
        long long n=questions.size();
        for(int i=questions.size()-1;i>=0;--i)
        {
            dp[i]=max(dp[i+1],questions[i][0]+dp[questions[i][1]+i+1]);
        }
        return dp[0];
    }
};