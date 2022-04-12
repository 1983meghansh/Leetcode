class Solution {
public:
    int R,C;
    int getlivenbr(int row,int col,vector<vector<int>>& board)
    {
        int cnt=0;
        cnt += row - 1 >= 0 && board[row - 1][col] ? 1 : 0;
        cnt += row + 1 < R && board[row + 1][col] ? 1 : 0;
        cnt += col - 1 >= 0 && board[row][col - 1] ? 1 : 0;
        cnt += col + 1 < C && board[row][col + 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col + 1 < C && board[row - 1][col + 1] ? 1 : 0;
        cnt += row + 1 < R && col - 1 >= 0 && board[row + 1][col - 1] ? 1 : 0;
        cnt += row + 1 < R && col + 1 < C && board[row + 1][col + 1] ? 1 : 0;
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        //pretty simple algo
    //just store the original board in some other vector and then calculate the number of live neighbours and according to the conditions update the original board.
        R=board.size();
        C=board[0].size();
        int livnebr=0;
        vector<vector<int>>temp=board;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
               livnebr=getlivenbr(i,j,temp);
            if(board[i][j]==1)
            {
                if(livnebr<2 || livnebr>3)
                    board[i][j]=0;
            }
                else{
                    if(livnebr==3)
                        board[i][j]=1;
                }
            }
        }
        
    }
};