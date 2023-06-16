const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i)matrix[i][j]=matrix[i-1][j]^matrix[i][j];
                if(j)matrix[i][j]=matrix[i][j-1]^matrix[i][j];
                if(i&&j)matrix[i][j]=matrix[i-1][j-1]^matrix[i][j];
               ans.push_back(matrix[i][j]);
            }
        }
//        for(int i=0;i<rows;i++){
//            for(int j=0;j<cols;j++)
// //            cout<<matrix[i][j]<<" ";
//            cout<<endl;
//        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-k];
    }
};
