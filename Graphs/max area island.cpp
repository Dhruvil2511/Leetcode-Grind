class Solution {
private:
    void expand(int i,int j,vector<vector<int>> &visited,vector<vector<int>>& grid,int &area){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
        
            area++;
            int newRows[]={-1,0,1,0};
            int newCols[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nRow = newRows[i] + row;
                int nCol = newCols[i] + col;
                if(nRow>=0 && nRow<grid.size() && nCol>=0 && nCol<grid[0].size() && !visited[nRow][nCol] && grid[nRow][nCol]){
                    q.push({nRow,nCol});
                    visited[nRow][nCol]=true;
                }
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,false));
        int maxArea=0;
        int area=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && grid[i][j]){
                    expand(i,j,visited,grid,area);
                    maxArea=max(maxArea,area);
                    area=0;
                }
            }
        }
        return maxArea;
    }
};
