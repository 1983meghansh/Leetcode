class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // #1 simple approach , beautiful
        // acc to properties , elements increase if we go down and decrease if we go left
        //keep a pointer at last element of first row
        int i=0;
        int n=matrix.size();
        int m=matrix[0].size();
        // int j=m-1;
        // while(i<n and j>=0)
        // {
        //     if(matrix[i][j]==target)
        //         return true;
        //     if(matrix[i][j]>target)
        //         j--;
        //     else
        //         i++;
        // }
        // return false;
        
        //However we can further optimize it 
        //observe that if we place all elements in a 1d array , it will be sorted
        //so we can apply binary search and get the target
        //but we prefer not to use extra space
        //so we give imaginary indexes to the matrix itself and perform bs and we can get the index by the formula index/m and index%m
        int lo=0,hi=n*m-1;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(matrix[mid/m][mid%m]==target)
                return true;
            if(matrix[mid/m][mid%m]>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return false;
    }
};