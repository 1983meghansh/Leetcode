class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        vector<int>ans(houses.size(),INT_MAX);
        
        for(int i=0,h=0;i<houses.size() and h<heaters.size();)
        {
            if(houses[i]<=heaters[h])
            {
                ans[i]=heaters[h]-houses[i];
                i++;
            }
            else
                h++;
        }
        for(int i=houses.size()-1,h=heaters.size()-1;i>=0 and h>=0;)
        {
            if(houses[i]>=heaters[h])
            {
                ans[i]=min(ans[i],houses[i]-heaters[h]);
                    i--;
            }
            else{
                h--;
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};