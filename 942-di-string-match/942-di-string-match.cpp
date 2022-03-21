class Solution {
public:
    vector<int> diStringMatch(string s) {
        //IDID
        //0,2,1,3,
        //pretty straightforwward observation
        int len=s.size();
        int low=0;
        int high=len;
        vector<int>res(len+1,0);
        for(int i=0;i<len;i++)
        {
            if(s[i]=='I')
                res[i]=low++;
            else
                res[i]=high--;
        }
        res[len]=high;
        return res;
        
        
    }
};