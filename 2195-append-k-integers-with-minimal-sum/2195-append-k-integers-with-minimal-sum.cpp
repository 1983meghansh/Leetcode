class Solution {
public:
    long long minimalKSum(vector<int>& nums, long k) {
        long ans=k*(k+1)/2;
        unordered_set<int>s(nums.begin(),nums.end());
        nums.clear();
        for(auto i:s)
            nums.push_back(i);
        sort(nums.begin(),nums.end());
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=k)
            {
                ans-=nums[i];
                ans+=k+1;
                k++;
            }
        }
        return ans;
    }
};