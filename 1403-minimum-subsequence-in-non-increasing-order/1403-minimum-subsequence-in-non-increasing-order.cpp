class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        //simple 1st sort in decreasing order then find running sum and subtract nums[i]from total sum and then break from the loop when rsum>tsum
        sort(nums.begin(),nums.end(),std::greater<>());
        int tsum=0,rsum=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            tsum+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            rsum+=nums[i];
            tsum-=nums[i];
            ans.push_back(nums[i]);
            if(rsum>tsum)
                break;
        }
        sort(ans.begin(),ans.end(),std::greater<>());
        return ans;
    }
};