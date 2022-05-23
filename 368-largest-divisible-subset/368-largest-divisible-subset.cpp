class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //after u sort the array the problem becomes similar to LIS just that
        //here we need to find longestdivisiblesubsequence not increasing
        //so just need to sort and make 1 change in the if condition
        //inside j loop
        //code similar to that used for printing the lis
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        int maxi=0,lastindex=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
               //here is the change in if condition from printing the lis code
                if(nums[i]%nums[prev]==0 and 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastindex=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex)
        {
            lastindex=hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        return ans;
        
    }
};