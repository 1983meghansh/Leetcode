class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
                nums[i]=0;
            else
                nums[i]=1;
        }
        unordered_map<int,int>mp{{0,1}};
        int psum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            psum+=nums[i];
            ans+=mp[psum-k];
            mp[psum]++;
        }
        return ans;
    }
};