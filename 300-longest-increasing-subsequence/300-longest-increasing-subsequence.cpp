class Solution {
public:
//     int f(int idx,int previdx,int n,vector<int>& nums,vector<vector<int>>&dp)
//     {
//         //base case
//         if(idx==n)
//             return 0;
        
//         if(dp[idx][previdx+1]!=-1)
//             return dp[idx][previdx+1];
//         //not take case
//         int len=0+f(idx+1,previdx,n,nums,dp);
        
//         //take case
//         if(previdx==-1 or nums[idx]>nums[previdx])
//             len=max(len,1+f(idx+1,idx,n,nums,dp));
        
//         return dp[idx][previdx+1]=len;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         return f(0,-1,n,nums,dp);
//     } 
    // tabulated code
     int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
         for(int i=n-1;i>=0;i--)
         {
             for(int prev_idx=i-1;prev_idx>=-1;prev_idx--)
             {
                 int len=dp[i+1][prev_idx+1];
                  if(prev_idx==-1 or nums[i]>nums[prev_idx])
            len=max(len,1+dp[i+1][i+1]);
                    dp[i][prev_idx+1]=len;
             }
         }
         return dp[0][0];
    }
                    
    
};