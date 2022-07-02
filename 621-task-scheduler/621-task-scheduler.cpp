class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto i:tasks)
        {
            // if(mp.find(i)==mp.end())
            //     mp[i]=0;
            mp[i]++;
        }
        priority_queue<int>pq;
        for(auto i:mp)
            pq.push(i.second);
        int ans=0;
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=0;i<=n;i++)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            for(int i:temp)
            {
                if(--i>0)
                    pq.push(i);
            }
            ans+=(pq.empty()==true)?temp.size():n+1;
        }
        return ans;
    }
};