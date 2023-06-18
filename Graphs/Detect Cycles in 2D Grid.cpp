class Solution {
public:
    bool isCycle(vector<vector<char>>& grid,char chr,int row,int col,int lrow,int lcol,vector<vector<bool>> &visited){
        if(row<0||row>grid.size()-1 || col<0 || col>grid[0].size()-1|| grid[row][col]!=chr) return false;

        if(visited[row][col]) return true;
        visited[row][col]=true;

        if((row+1!=lrow||col!=lcol) && isCycle(grid,chr,row+1,col,row,col,visited)) return true;
        if((row-1!=lrow||col!=lcol) && isCycle(grid,chr,row-1,col,row,col,visited)) return true;
        if((row!=lrow||col+1!=lcol) && isCycle(grid,chr,row,col+1,row,col,visited)) return true;
        if((row!=lrow||col-1!=lcol) && isCycle(grid,chr,row,col-1,row,col,visited)) return true;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(!vis[i][j] && isCycle(grid,grid[i][j],i,j,-1,-1,vis)) return true;
            }
        }
        return false;
    }
};
