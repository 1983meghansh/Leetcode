class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),cmp);
        int ans=0;
        for(auto i:b)
        {
            int a=min(t,i[0]);
            ans+=a*i[1];
            t-=a;
            if(t==0)
                break;
        }
        return ans;
        
    }
};