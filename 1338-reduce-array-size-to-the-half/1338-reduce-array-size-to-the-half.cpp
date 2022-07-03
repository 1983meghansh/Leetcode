class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size=arr.size();
        size=size/2;
       
        unordered_map<int,int>mp;
        for(auto i:arr)
            mp[i]++;
        vector<int>occr;
        for(int i=0;i<mp.size();i++)
            occr.push_back(mp[i]);
        int ans=0;
        sort(occr.begin(),occr.end(),greater<int>());
        for(int i=0;i<occr.size() and size>0;i++)
        {
            ans++;
            size-=occr[i];
        }
        return ans;
    }
};