class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //relate with LIS 
        vector<pair<int,int>>players;
        int n=scores.size();
        for(int i=0;i<n;i++)
        {
            players.push_back({ages[i],scores[i]});
            
        }
        sort(players.begin(),players.end());
        vector<int>dp(n);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int score=players[i].second;
            dp[i]=players[i].second;
            for(int j=0;j<i;j++)
            {
                if(players[i].second>=players[j].second and dp[i]<dp[j]+score)
                    dp[i]=dp[j]+score;
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};