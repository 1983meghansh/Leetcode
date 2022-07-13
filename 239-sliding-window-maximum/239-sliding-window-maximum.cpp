class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //for every window of size k , insert all elemnts into pq and upadte pq , and for every window , push the top of pq into the ans vector
        vector<int>res;
        int i=0,j=0;
        priority_queue<pair<int,int>>pq;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        res.push_back(pq.top().first);
        
        for(int i=k;i<n;i++)
        {
            //push the new element in pq
            pq.push({nums[i],i});
            
            //remove the elements from pq which are not in current window
            while(!(pq.top().second>i-k))
            {
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
        return res;
        
       
    }
};