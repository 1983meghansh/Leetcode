class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //Count the occurrence of all numbers in A and B,
//and also the number of domino with two same numbers.

//Try all possibilities from 1 to 6.
//If we can make number i in a whole row,
//it should satisfy that countA[i] + countB[i] - same[i] = n
        vector<int>cnta(7),cntb(7),same(7);
        int n=tops.size();
        for(int i=0;i<n;i++)
        {
            cnta[tops[i]]++;
            cntb[bottoms[i]]++;
            if(tops[i]==bottoms[i])
                same[tops[i]]++;
        }
        
        for(int i=0;i<7;i++)
        {
            if(cnta[i]+cntb[i]-same[i]==n)
            {
                return n-max(cnta[i],cntb[i]);
            }
        }
        return -1;
    }
};