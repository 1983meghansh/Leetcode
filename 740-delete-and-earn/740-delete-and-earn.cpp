class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>freq(10001);
        for(auto i:nums)
            freq[i]++;
        int include=0;
        int exclude=0;
        for(int i=0;i<=10000;i++)
        {
            int newinc=freq[i]*i+exclude;
            int newex=max(include,exclude);
            include=newinc;
            exclude=newex;
        }
        return max(include,exclude);
    }
};