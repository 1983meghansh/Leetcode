class Solution {
public:
    //either take or nottake
    //i is pizza index and n is total slice taken by me
    int dp[501][180];
    int helper(int i,int n,vector<int>&slices)
    {
        if(n==0 or i>=slices.size())
            return 0;
        if(dp[i][n]!=-1)
            return dp[i][n];
        return dp[i][n]=max(helper(i+2,n-1,slices)+slices[i],helper(i+1,n,slices));
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        memset(dp,-1,sizeof(dp));
        int ans1=helper(1,n/3,slices);
         memset(dp,-1,sizeof(dp));      //set the dp again
        slices[n-1]=0;
        int ans2=helper(0,n/3,slices);
        return max(ans1,ans2);
    }
};