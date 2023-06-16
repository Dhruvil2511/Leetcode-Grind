class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        priority_queue<pair<int,int>> pq;
        for(const auto num: arr){
            pq.push({abs(num-x),num});
            if(pq.size()>k)pq.pop();   
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
