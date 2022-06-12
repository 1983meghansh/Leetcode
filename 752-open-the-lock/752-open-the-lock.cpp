class Solution {
public:
    
    unordered_set<string>vis;
    int openLock(vector<string>& deadends, string target) {
        
        
        for(auto it:deadends)
            vis.insert(it); 
        
        if(vis.count("0000") or vis.count(target))
            return -1;
        if(target=="0000")
            return 0;
        queue<string>q;
        q.push("0000");
        int depth=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            while(sz-->0)
            {
                string curr=q.front();
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    string s1=curr;
                    string s2=curr;
                    s1[i]='0'+(curr[i]-'0'+1)%10;
                    s2[i]='0'+(curr[i]-'0'+9)%10;
                    if(s1==target or s2==target)
                        return depth+1;
                    if(!vis.count(s1))
                    {
                        q.push(s1);
                        vis.insert(s1);
                    }
                    if(!vis.count(s2))
                    {
                        q.push(s2);
                        vis.insert(s2);
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};