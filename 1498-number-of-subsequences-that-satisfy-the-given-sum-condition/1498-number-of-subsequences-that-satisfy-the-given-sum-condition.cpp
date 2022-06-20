class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        //good question
        const int mod=1e9+7;
        int n=nums.size();
        vector<int>expo(n,1);
        for(int i=1;i<n;i++)
        {
            expo[i]=(2*expo[i-1])%mod;
        }
        int right=n-1,left=0,ans=0;
        sort(nums.begin(),nums.end());
        while(left<=right)
        {
            if(nums[left]+nums[right]>target)
                right--;
            else{
                ans=(ans+expo[right-left])%mod;
                left++;
            }
        }
        return ans;
    }
};