class node{
    public:
    int val;
    int row;
    int col;
    node(int val,int row,int col){
        this->val=val;
        this->row=row;
        this->col=col;
    }
};
class compare{
    public: 
    bool operator()(node* a,node* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node* ,vector<node*>, compare> pq;
        int initMin=INT_MAX,initMax=INT_MIN;
        int k=nums.size();
        for(int i=0;i<k;i++){
            node* temp=new node(nums[i][0],i,0);
            initMin=min(initMin,nums[i][0]);
            initMax=max(initMax,nums[i][0]);
            pq.push(temp);
        }
       
        int mini=initMin,maxi=initMax;
        while(!pq.empty()){
            node* top=pq.top();
            pq.pop();
            initMin=top->val;
            if(initMax-initMin<maxi-mini){
                mini=initMin;
                maxi=initMax;
            }
            if(top->col+1<nums[top->row].size()){
                initMax=max(initMax,nums[top->row][top->col + 1]);
                node* temp=new node(nums[top->row][top->col + 1],top->row,top->col+1);
                pq.push(temp);
            }
            else{
                break;
            }  
        }
        return {mini,maxi};
        
    }
};
