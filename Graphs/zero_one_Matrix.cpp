class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> ans(rows,vector<int>(cols));
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        queue<pair<pair<int,int>,int>> q;
                 // row,col,distance
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }

        int nRows[]={-1,0,1,0};
        int nCols[]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            ans[row][col]=dis;

            for(int i=0;i<4;i++){
                int newRow=nRows[i]+row;
                int newCol=nCols[i]+col;
                if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && !visited[newRow][newCol]){
                    q.push({{newRow,newCol},dis+1});
                    visited[newRow][newCol]=true;
                }
            }
        }
        return ans;
    }
};
