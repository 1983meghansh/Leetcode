class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        bool pres=false;
        for(auto it:wordList)
        {
            if(it==endWord)
                pres=true;
            s.insert(it);
        }
        if(pres==false)
            return false;
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        
        while(!q.empty())
        {
            int lsize=q.size();
            depth++;
            while(lsize--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++)
                {
                    string temp=curr;
                    for(char c='a';c<='z';c++)
                    {
                        temp[i]=c;
                        if(curr.compare(temp)==0)
                            continue;          //skip if its the same curr word
                        if(temp.compare(endWord)==0)
                            return depth+1;
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};