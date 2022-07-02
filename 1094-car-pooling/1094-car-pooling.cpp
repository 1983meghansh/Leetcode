class Solution {
public:
    static bool cmp(vector<int>l,vector<int>h)
    {
        if(l[1]<h[1] or (l[1]==h[1] and l[2]<h[2]))
            return true;
        return false;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),cmp);
        int n=trips.size();
        //create a min heap
       int curr=0; priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            
            while(!pq.empty() and trips[i][1]>=pq.top().first)
            {
                curr-=pq.top().second;
                pq.pop();
            }
            curr+=trips[i][0];
            if(curr>capacity)
                return false;
            pq.push({trips[i][2],trips[i][0]});
        }
        return true;
        
    }
};