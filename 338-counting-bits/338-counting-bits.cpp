class Solution {
public:
    vector<int> countBits(int n) {
        //The key thing to observe here is that if there is a number x and if its even , then the number of set bits(no if 1's) in it will be equal to number of set bits in x/2.
//If number x is odd then then number of set bits in it will be equal to 1+no of set bits in x/2.
//So we fill a 1d dp table by storing dp[0]=0 .
//So for 1 , its odd , so 1/2=0 so for 1 its 1, and similarly we store for others using precomputed values.
//This solution is O(n) time.
        vector<int>dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i/2]+i%2;
        }
        return dp;
    }
};