class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        
        map<char,vector<int>>m;
        int i=0;
        for(auto it:s)
            m[it].push_back(i++);
        int cnt=0;
        
        for(int i=0;i<words.size();i++)
        {
            int last=-1;
            string curr=words[i];
            for(int j=0;j<curr.size();j++)
            {
                auto it=upper_bound(m[curr[j]].begin(),m[curr[j]].end(),last);
                if(it==m[curr[j]].end())
                    break;
                last=*it;
                if(j==curr.size()-1)cnt++;
            }
        }
        return cnt;
    }
};