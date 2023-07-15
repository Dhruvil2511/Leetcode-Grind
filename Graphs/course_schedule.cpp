// topo sort
class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& graph) {
        unordered_map<int,int> indegree;
        unordered_map<int,set<int>> adjList;

        // creating adj list
        for(int i=0;i<graph.size();i++){
            adjList[graph[i][0]].insert(graph[i][1]);
            indegree[graph[i][1]]++;
        }

        // bfs topo kahn algo

        queue<int> q;
        int coursesDone=0;

        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            coursesDone++;
            for(const auto node: adjList[front]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }
        return coursesDone==V;
    }
};
