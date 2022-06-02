class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        int i,j;
          vector<vector<int>> T(n, vector<int>(m, 0));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            T[j][i] = A[i][j];
        }
        return T;
    }
};