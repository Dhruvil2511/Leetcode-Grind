class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int freshCnt=0;
        pair<pair<int,int>,int> p;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(make_pair(i,j),0));
                    visited[i][j]=2;
                }
                else if(grid[i][j]==1) freshCnt++;
            }
        } 
                    // top,right,bottom,left
        int nRows[]={-1,0,+1,0};
        int nCols[]={0,+1,0,-1};
        int mins=0;
        int cnt=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            mins=max(time,mins);
            q.pop();
            for(int i=0;i<4;i++){
                int newRow=row+nRows[i];
                int newCol=col+nCols[i];
                if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol]!=0 && visited[newRow][newCol]!=2){
                    visited[newRow][newCol]=2;
                    q.push(make_pair(make_pair(newRow,newCol),time+1));
                    cnt++;
                }
            }
        }
        if(cnt!=freshCnt)return -1;
        return mins;
       
    }

};
