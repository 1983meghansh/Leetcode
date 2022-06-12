class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>s;
        int curr_sum=0,ans=0;
        int l=0;
        for(int i=0;i<nums.size();i++)
        {
            while(s.find(nums[i])!=s.end())
            {
                curr_sum-=nums[l];
                s.erase(nums[l]);
                l++;
            }
            curr_sum+=nums[i];
            s.insert(nums[i]);
            ans=max(ans,curr_sum);
        }
        return ans;
    }
};