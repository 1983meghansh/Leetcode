class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int>mp;
        int ans=INT_MAX;
        vector<string>idx;
        vector<string>ans1;
        for(int i=0;i<list1.size();i++)
        {
            mp[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++)
        {
            if(mp.find(list2[i])!=mp.end())
            {
                if(ans>i+mp[list2[i]])
                {
                   ans=i+mp[list2[i]];
                    idx.clear();
                   idx.push_back(list2[i]);
                }
                else if(ans==i+mp[list2[i]])
                {
                    idx.push_back(list2[i]);
                }
               
            }
        }
       
       
        return idx;
    }
};