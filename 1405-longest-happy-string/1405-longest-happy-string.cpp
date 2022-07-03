class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)
            pq.push({a,'a'});
        if(b>0)
            pq.push({b,'b'});
        if(c>0)
            pq.push({c,'c'});
        string ans="";
        int size=0;
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            if(size>1 and ans[size-1]==it.second and ans[size-2]==it.second)
            {
                if(pq.empty())
                    return ans;
                auto temp=pq.top();
                ans+=pq.top().second;
                size++;
                pq.pop();
                if(temp.first>1)
                {
                    pq.push({temp.first-1,temp.second});
                }
                pq.push({it.first,it.second});
            }
            else{
                ans+=it.second;
                if(it.first>1)
                {
                    pq.push({it.first-1,it.second});
                }
                size++;
            }
        }
        return ans;
    }
};