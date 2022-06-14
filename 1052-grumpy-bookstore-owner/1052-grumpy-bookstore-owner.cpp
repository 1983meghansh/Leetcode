class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        //simple sliding window
       int sat=0,msat=0,res=0;
        
        for(int i=0;i<c.size();i++)
        {
            sat+=!g[i]*c[i];
            msat+=c[i]*g[i];
            if(i>=m)
            {
                msat-=c[i-m]*g[i-m];
            }
                res=max(res,msat);
            
        }
        return res+sat;
    }
};