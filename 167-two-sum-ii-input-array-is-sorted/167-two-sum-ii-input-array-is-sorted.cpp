class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        int s=0,e=n-1;
        while(s<=e)
        {
            if(nums[s]+nums[e]>target)
                e--;
            else if(nums[s]+nums[e]<target)
                s++;
            else{
                ans.push_back(s+1);
                ans.push_back(e+1);
                break;
            }
        }
        return ans;
    }
};