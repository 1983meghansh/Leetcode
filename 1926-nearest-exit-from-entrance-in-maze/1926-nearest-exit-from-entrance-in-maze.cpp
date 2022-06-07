class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        int moves=1;
        int r=maze.size();
        int c=maze[0].size();
        maze[e[0]][e[1]]='+';
        int ans=INT_MAX;
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty())
        {
            int l=q.size();
            for(int v=0;v<l;v++)
            {
                auto [i,j]=q.front();
                q.pop();
                for(int s=0;s<4;s++)
                {
                    int x=i+dir[s][0];
                    int y=j+dir[s][1];
                    if(x<0 or y<0 or x>=r or y>=c or maze[x][y]=='+')
                        continue;
                    if(x==0 or y==0 or x==r-1 or y==c-1)
                    {
                        ans=min(moves,ans);
                    }
                    maze[x][y]='+';
                    q.push({x,y});
                }
                
            }
            moves++;
        }
        if(ans==INT_MAX)
        return -1;
        else
            return ans;
    }
};