class Solution {
public:
    int minDeletions(string s) {
        vector<int>f(26,0);
        for(auto i:s)
            f[i-'a']++;
        sort(f.begin(),f.end());
        int ans=0;
        for(int i=24;i>=0;i--)
        {
            if(f[i]==0)
                break;
            
            if(f[i]>=f[i+1])
            {
                int temp=f[i];
                f[i]=max(0,f[i+1]-1);
                ans+=temp-f[i];
            }
        }
        return ans;
    }
};