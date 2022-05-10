class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int hi=*max_element(quantities.begin(),quantities.end());
        int low=1;
        int ans=0;
        
        while(low<=hi)
        {
            int mid=(low+hi)/2;
            if(ispossible(quantities,mid,n)==true)
            {
                ans=mid;
                hi=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool ispossible(vector<int>& quantities,int maxallow,int n)
    {
        int shops=0;
        for(int i=0;i<quantities.size();i++)
        {
            if(quantities[i]<=maxallow)
                shops++;
            else{
                int temp=quantities[i];
                while(temp>0)
                {
                    temp-=maxallow;
                    shops++;
                }
            }
        }
        if(shops<=n)
            return true;
        else
            return false;
    }
};