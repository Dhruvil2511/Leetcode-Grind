class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        for(auto x: arr){
            mp[x]++;
        }
        for(auto x: mp)pq.push(x.second);
        int size=arr.size();
        int newsize=0;
        int cnt=0;
        while(!pq.empty() && newsize<size/2){
            newsize=newsize+pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};
