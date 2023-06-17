//using  DFS Algorithm to solve this problem
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&grid){
        if(row<0 || row>grid.size()-1 || col<0 || col>grid[row].size()-1 || grid[row][col]=='0'){
            return;
        }
        grid[row][col]='0';
        dfs(row+1,col,grid);
        dfs(row-1,col,grid);
        dfs(row,col+1,grid);
        dfs(row,col-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int numOfIslands=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    numOfIslands++;
                    dfs(i,j,grid);
                }
            }
        }   
        return numOfIslands;
    }
};

