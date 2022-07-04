class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int ans=1,i=0,j=0;
        long sum=0;
        while(j<nums.size())
        {
             sum=sum+nums[j];
            while(k+sum<(long)nums[j]*(j-i+1))
            {
                sum-=nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};