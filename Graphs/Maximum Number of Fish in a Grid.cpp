class Solution {
private:
    void bfs(int i,int j,int &fishCaught,vector<vector<bool>>& visited,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int newRows[]={-1,0,1,0};
        int newCols[]={0,1,0,-1};
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            int row = q.front().first;
            int col= q.front().second;
            q.pop();
            fishCaught=fishCaught+grid[row][col];
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
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxFish=0;
        int fishCaught=0;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && grid[i][j]>0){
                    bfs(i,j,fishCaught,visited,grid);
                    maxFish=max(fishCaught,maxFish);
                    fishCaught=0;
                }
            }
        }
        return maxFish;
    }
};
