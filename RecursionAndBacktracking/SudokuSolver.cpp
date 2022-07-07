class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i=0;i<9;i++)
        {
            // check row if there exist duplicate equal to 'c'
            if(board[row][i] == c)
                return false;
            // check col if there exist duplicate equal to 'c'
            if(board[i][col] == c)
                return false;
            
            int start_x = 3*(row/3);
            int start_y = 3*(col/3);
            if(board[start_x + i/3][start_y + i%3] == c)
                return false;
        }   
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j]=='.')
                {
                    for(char c ='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j] = c;
                    
                            if(solve(board))
                                return true; 
                            
                            board[i][j] = '.';
                        }
                    }
         
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};