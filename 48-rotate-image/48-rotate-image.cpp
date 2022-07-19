class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //step1->transpose
        //step2->reverse every row
        
        //transpose
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //reverse every row
        for(int i=0;i<matrix.size();i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};