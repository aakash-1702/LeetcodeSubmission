class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for(auto &x : invocations){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
        }    

        vector<int> mal(n , 0 );
        dfs(k , adj , mal);   

        int flag = false; 

        for(auto &x : invocations){
            int u = x[0];
            int v = x[1];
            if(mal[v] && (mal[u] == 0)){
                flag = 1;
            }
        }

        vector<int> ans;
        
        if(flag){
            for(int i = 0 ;i < n ;i++) ans.push_back(i);
        }else {
            for(int i = 0 ; i < n ;i++){
                if(mal[i] == 0) ans.push_back(i);
            }
        }



        return ans;
    }
    private:
    void dfs(int node , vector<int> adj[] , vector<int> &mal){
        mal[node] = 1;

        for(auto &x : adj[node]){
            if(mal[x]) continue;
            else dfs(x , adj , mal);
        }

        return;
    }
};