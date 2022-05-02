class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int prefixsum=0;
        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i];
            ans.push_back(prefixsum);
        }
        return ans;
    }
};