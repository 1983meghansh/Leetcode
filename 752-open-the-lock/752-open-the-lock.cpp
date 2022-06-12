class Solution {
public:
    
    unordered_set<string>vis;
    int openLock(vector<string>& deadends, string target) {
        
        
        for(auto it:deadends)
            vis.insert(it); 
        
        if(vis.count("0000") or vis.count(target)) 	//base cases when begin is a deadend or target is a deadend
            return -1;
        if(target=="0000")      	//start itself is target
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
                    //s1 -- > cur with one step clockwise 
				//s2 -- > cur with one step anti clockwise
                    s1[i]='0'+(curr[i]-'0'+1)%10;
                    s2[i]='0'+(curr[i]-'0'+9)%10;
                    //if s1 or s2 is target return steps
                    if(s1==target or s2==target)
                        return depth+1;
                    	//else push s1 and s2 into queue and list of deadends 
				//if they are not present in dead ends already
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