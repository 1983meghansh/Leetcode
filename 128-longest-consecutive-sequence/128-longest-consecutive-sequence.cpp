class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int ans=0;
        
        for(auto i:nums)
            s.insert(i);
        
        for(int i:nums)
        {
            if(!s.count(i-1))
            {
                int temp=1;
                int curr=i;
                while(s.count(curr+1))
                {
                    temp++;
                    curr=curr+1;
                }
                ans=max(temp,ans);
            }
            
        }
        return ans;
    }
};