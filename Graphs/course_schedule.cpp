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

// course schedule 2
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // creating adjList or creating graph
        unordered_map<int,set<int>> adjList;
        unordered_map<int,int> indegree;

        for(auto prerequisite: prerequisites){
            adjList[prerequisite[1]].insert(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        // bfs kahans algo
        vector<int> ordering;

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            ordering.push_back(front);

            for(auto node : adjList[front]){
                indegree[node]--;
                if(indegree[node]==0)q.push(node);
            }
        }

        if(ordering.size()==numCourses)return ordering;
        return {};

    }
};



// course schedule 4


class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // creating graph

        unordered_map<int,set<int>> adjList;
        unordered_map<int,int> indegree;
        vector<vector<bool>> table(numCourses,vector<bool>(numCourses,false));

        for(const auto prerequisite: prerequisites){
            adjList[prerequisite[0]].insert(prerequisite[1]);
            indegree[prerequisite[1]]++;
        }

        queue<int> q;
        vector<bool> ans;
        // kahns bfs

        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto node: adjList[front]){

                table[front][node]=true;
                for(int i=0;i<numCourses;i++)if(table[i][front]) table[i][node]=true;

                indegree[node]--;
                if(indegree[node]==0) q.push(node);
            }
        }

        for(int i=0;i<queries.size();i++){
            ans.push_back(table[queries[i][0]][queries[i][1]]);
        }
        return ans;
    }
};
