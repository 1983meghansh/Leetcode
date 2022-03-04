class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        //https://www.youtube.com/watch?v=PbdeSn67Kfs
        double quantity[101][101]={0.0};
        quantity[0][0]=poured;
        
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(quantity[i][j]>1)
                {
                    quantity[i+1][j]+=(quantity[i][j]-1)/2.0;
                quantity[i+1][j+1]+=(quantity[i][j]-1)/2.0;
                quantity[i][j]=1;    
            }}
        }
        return quantity[query_row][query_glass];
    }
};