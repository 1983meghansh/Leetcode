class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mp;
        for(auto i:s)
            mp[i]++;
        
        priority_queue<pair<int,char>>pq;
        for(auto i:mp)
            pq.push(make_pair(i.second,i.first));
        
        int i=0;
        auto t1=pq.top();
        pq.pop();
        string ans="";
         ans+=t1.second;
        cout<<ans;
        while(!pq.empty())
        {
            auto t2=pq.top();
            pq.pop();
            ans+=t2.second;
            if(--t1.first)
                pq.push(t1);
            t1=t2;
        }
        if(ans.size()==s.size())
       return ans;
        return "";
    }
};