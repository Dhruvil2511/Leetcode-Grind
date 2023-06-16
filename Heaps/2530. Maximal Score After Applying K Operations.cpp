class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(const auto num: nums){
            pq.push(num);
        }
        while(k--){
            long long top=pq.top();
            score=score+top;
            pq.pop();
            pq.push(ceil(top/3.0));
        }
        return score;
    }
};
