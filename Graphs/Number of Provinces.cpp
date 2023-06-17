class Solution {
public:
    void dfs(int node,unordered_map<int,bool> &visited,vector<vector<int>>& adj){
        visited[node]=true;
        for(int i=1;i<=adj[node-1].size();i++){
            if(!visited[i] && adj[node-1][i-1]){
                dfs(i,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int vertices = adj.size();
        int cnt=0;
        unordered_map<int,bool> visited;
        for(int i = 1; i <= vertices; i++){
            // cout<<i<<"->"<<visited[i]<<endl;
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adj);
            }
        }
        return cnt;
    }
};
