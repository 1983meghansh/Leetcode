class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
         int n = people.size();
        vector<vector<int>> ans(n,vector<int>(2,-1));
        sort(people.begin(),people.end());
        
        for(int i=0;i<n;i++)
        {
            int need = people[i][1];
            int got = 0;
            int ind = 0;
            while(ind<n and got<need){
                if(ans[ind][0] == -1 or ans[ind][0]>=people[i][0])
                got++;
                
                ind++;
            }
            while(ind<n)
            {
                if(ans[ind][0] == -1)break;
                ind++;
            }
            ans[ind] = people[i];
            
        }
        return ans;
    }
};