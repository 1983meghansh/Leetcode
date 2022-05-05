class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            int temp=-a;
            int st=i+1,end=n-1;
            while(st<end)
            {
                
                if(nums[st]+nums[end]==temp)
                {
                    while(st<end and nums[st]==nums[st+1])st++;
                    while(st<end and nums[end]==nums[end-1])end--;
                    ans.push_back({nums[i],nums[st],nums[end]});
                    end--;
                    st++;
                }
                else if(nums[st]+nums[end]<temp)
                    st++;
                else
                    end--;
            }
            while(i+1<n and nums[i+1]==nums[i])i++;
            
            
        }
        return ans;
    }
};