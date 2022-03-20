class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
      int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                int temp=nums[i-1]-nums[i]+1;
                ans+=temp;
                nums[i]+=temp;
        }
        }
        return ans;
    }
};