class Solution {
private:
    bool checkBipartite(int start, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i=0;i<graph[node].size();i++){

                if(color[graph[node][i]]==-1){
                    if(color[node]==0)color[graph[node][i]]=1;
                    else if(color[node]==1) color[graph[node][i]]=0;
                    q.push(graph[node][i]);
                }
                
                else if(color[node]==color[graph[node][i]]) return false;  
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> color(nodes,-1);
        for(int vertex=0;vertex<nodes;vertex++){
            if(color[vertex]==-1){
                if(!checkBipartite(vertex,color,graph))return false;
            }
        }
        return true;
    }
};
