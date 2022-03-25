class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res=0;
        int n=colors.size();
        int i=n-1;
        int j=0;
        while(colors[0]==colors[i])
            i--;
        while(colors[n-1]==colors[j])
            j++;
        //12-3-1
        res=max(i,n-j-1);
        return res;
    }
};