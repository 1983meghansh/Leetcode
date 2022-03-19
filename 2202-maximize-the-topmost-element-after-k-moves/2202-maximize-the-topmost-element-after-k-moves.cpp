class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1 and k%2)
            return -1;
        if(nums.size()==1)
            return nums[0];
        //case if k>size
        
        if(k>nums.size())
        {
            int ans=0;
            for(int i=0;i<nums.size();i++)
                ans=max(ans,nums[i]);
            return ans;
        }
        // case if k=size
        if(k==nums.size())
        {
            int ans=0;
            for(int i=0;i<k-1;i++)
            {
                ans=max(ans,nums[i]);
            }
            return ans;
        }
        // case if k<size
        int ans=0;
        for(int i=0;i<k-1;i++)
        {
            ans=max(ans,nums[i]);
        }
        if(ans<nums[k])
            ans=nums[k];
        return ans;
            
    }
};