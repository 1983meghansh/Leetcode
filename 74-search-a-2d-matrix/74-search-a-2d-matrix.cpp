class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // #1 simple approach
        // acc to properties , elements increase if we go down and decrease if we go left
        //keep a pointer at last element of first row
        int i=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int j=m-1;
        while(i<n and j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
        return false;
    }
};