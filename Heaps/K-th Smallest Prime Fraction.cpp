class Solution {
public:
    static bool compare(const pair<pair<int,int>,double> &a,const pair<pair<int,int>,double> &b){
        return a.second<b.second;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // vector<pair<pair<int,int>,double>> p;
        priority_queue<pair<pair<int,int>,double>> pq;
        for(int i=0;i<arr.size();i++){
            pair<pair<int,int>,double> pp;
            for(int j=i+1;j<arr.size();j++){
                pp=make_pair(make_pair(arr[i],arr[j]),double(arr[i])/arr[j]);
                pq.push(pp);
                if(pq.size()<k)pq.pop();
            }
        }
       
        // sort(p.begin(),p.end(),compare);
        return {pq.top().first.first,pq.top().first.second};
    }
};
