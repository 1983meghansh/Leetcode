class Solution {
public:
    bool isPossible(vector<int>& target) {
        //GOOD QUESTION WITH A LOT OF CORNER CASES
        priority_queue<int>pq;
        long tot=0;
        for(int el:target)
        {
            pq.push(el);
            tot+=el;
        }
        
        while(!pq.empty())
        {
            int maxel=pq.top();
            pq.pop();
            long remsum=tot-maxel;
            if(maxel==1 or remsum==1)
                return true;
            if(remsum==0 or maxel<remsum)
                return false;
            int replacemax=(int)(maxel%remsum);  //mod more efficient than subtraction so did it to remove TLE;
            if(replacemax==0)
                return false;
            
            pq.push(replacemax);
            tot=remsum+replacemax;
            
        }
        return true;
    }
};