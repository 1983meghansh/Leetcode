class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        long long low=1;
        long long hi=*max_element(position.begin(),position.end());
        int ans=0;
        
        while(low<=hi)
        {
            int mid=(low+hi)/2;
            if(ispossible(position,m,mid)==true)
            {
                low=mid+1;
                ans=mid;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
    bool ispossible(vector<int>& position,int m,int mid)
    {
        int pos=position[0];
        int cnt=1;
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-pos>=mid)
            {
                cnt++;
                pos=position[i];
            }
            if(cnt==m)
                return true;
        }
        return false;
    }
    
};