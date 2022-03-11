//https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adjList[n];
        //vector<vector<int>> adjList -- Slow
        
        vector<int> visited(n, 0);
        
        for (auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        dfs(source, adjList, visited);
        
        return visited[destination];
    }
    
//     void dfs(int source, vector<vector<int>> adjList, vector<int>& visited) {
        
//         visited[source] = 1;
        
//         cout<<source<<endl;
    
//         for (auto n : adjList[source]) {
//             if (!visited[n] && source != n) 
//                 dfs(n, adjList, visited);
//         }
//     }
    
    void dfs(int start, vector<int> graph[], vector<int>& vis) {
        
        vis[start] = true;
        
        for(auto neighbour : graph[start]){
            if(!vis[neighbour])
                dfs(neighbour, graph, vis);
        }
    }
    
};
