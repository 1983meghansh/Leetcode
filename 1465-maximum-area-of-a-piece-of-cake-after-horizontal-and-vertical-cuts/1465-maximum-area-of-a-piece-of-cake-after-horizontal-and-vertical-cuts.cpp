class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
       hc.push_back(0);
       hc.push_back(h);
       vc.push_back(0);
       vc.push_back(w);
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        long maxh=0,maxw=0;
        for(int i=1;i<hc.size();i++)
        {
            if(maxh<hc[i]-hc[i-1])
                maxh=hc[i]-hc[i-1];
        }
        for(int i=1;i<vc.size();i++)
        {
            if(maxw<vc[i]-vc[i-1])
                maxw=vc[i]-vc[i-1];
        }
        return (maxh*maxw)%1000000007;

    }
};