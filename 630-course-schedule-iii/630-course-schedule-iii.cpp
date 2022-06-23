 // bool sortbylastday(vector<int>a,vector<int>b)
 //    {
 //        if(a[1]==b[1])
 //            return a[0]<b[0];
 //        return a[1]<b[1];
 //    }

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        // sort(c.begin(),c.end(),sortbylastday);
        sort(c.begin(), c.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int>pq;
        int days=0,ans=0;
        int n=c.size();
        for(int i=0;i<n;i++)
        {
            if(days+c[i][0]<=c[i][1])
            {
                ans++;
                pq.push(c[i][0]);
                days+=c[i][0];
            }
            else{
                if(!pq.empty() and pq.top()>c[i][0])
                {
                    days-=pq.top();
                    pq.pop();
                    pq.push(c[i][0]);
                    days+=c[i][0];
                }
            }
        }
        return ans;
    }
};