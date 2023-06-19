class Solution {
public:
    void dfs(int row,int col,vector<vector<bool>>& visited,vector<vector<char>>& board){
        if(row<0 || row>board.size()-1|| col<0|| col>board[0].size()-1 || board[row][col]=='X'|| visited[row][col]==true)return;
        

        visited[row][col]=true;

        dfs(row+1,col,visited,board);
        dfs(row-1,col,visited,board);
        dfs(row,col-1,visited,board);
        dfs(row,col+1,visited,board);

    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<cols;i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(0,i,visited,board);
            }
            if(!visited[rows-1][i] && board[rows-1][i]=='O'){
                dfs(rows-1,i,visited,board);
            }
        }
        for(int i=0;i<rows;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,visited,board);
            }
            if(!visited[i][cols-1] && board[i][cols-1]=='O'){
                dfs(i,cols-1,visited,board);
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};
