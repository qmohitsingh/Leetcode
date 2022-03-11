//https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    
    vector<int> graph[20001];
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
           
        vector<int> ans;
        
        if (n < 2){
            ans.push_back(0);
            return ans;
        }
            
        
        vector<int> degree(n);
        for (int i=0; i<edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        queue<int> q;
        for (int i=0; i<n; i++) {
            
            degree[i] = graph[i].size();
            
            if (degree[i]==1)
                q.push(i);
            
        }
        
        //Revisit
        while(n > 2) {
            int size = q.size();
            n -= size;
            
            while(size--) {
                int i = q.front();
                q.pop();
                for(auto n : graph[i]) {
                    degree[n]--;
                    if (degree[n] == 1)
                        q.push(n);
                }
            }
            
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
            
         
        return ans;
        
    }
    
//     vector<int> graph[20001];
//     vector<int> visited;
//     int minHeight;
    
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
           
//         vector<int> ans;
//         visited.resize(20001);
        
//         vector<pair<int, int>> temp;
//         for (int i=0; i<edges.size(); i++) {
            
//             int u = edges[i][0];
//             int v = edges[i][1];
            
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }
        
        
//         minHeight = INT_MAX;
        
//         // Total T : O(n*(V+E))
//         for(int i=0; i<n; i++) {
            
//            if(graph[i].size() != 1) {
//                 int maxHeight = 0;
//                 fill(visited.begin(), visited.end(), 0);

//                 dfs(graph, i, 0, maxHeight); // T : O(V+E)

//                 minHeight = min(maxHeight, minHeight);

//                 temp.push_back({maxHeight, i});
//            }
//         }
        
//         for (auto t : temp) {
//             if (t.first == minHeight)
//                 ans.push_back(t.second);
//         }
        
//         return ans;
        
//     }
    
//     //DFS algo to calculate maxHeight T: O(V+E)
//     void dfs(vector<int> graph[], int source, int level, int& maxHeight) {

//         visited[source] = 1;
        
//         // Pruning
//         if (maxHeight > minHeight){
//             maxHeight = INT_MAX;
//             return;
//         }

//         maxHeight = max(level, maxHeight);
        
//         for(auto n : graph[source]) {
//             if (!visited[n])
//                 dfs(graph, n, level+1, maxHeight);
//         }
//     }
};
