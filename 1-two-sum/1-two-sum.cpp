class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            int tofind=target-nums[i];
            if(mp.find(tofind)!=mp.end())
            {
                result.push_back(mp[tofind]);
                result.push_back(i);
                return result;
            }
            mp[nums[i]]=i;
        }
        return result;
    }
};