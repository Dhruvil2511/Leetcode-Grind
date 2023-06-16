class Solution {
public:

    void heapify(vector<int>&arr,int size,int i){
        int largest=i;
        int left=(2*i)+1;
        int right=(2*i)+2;
        if(left<size && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<size && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,size,largest);
        }
    }
    void heapSort(vector<int> & arr){
        int size=arr.size();
        // creating heap 
        for(int i=size/2 - 1;i>=0;i--){
            heapify(arr,size,i);
        }
        // swapping first ele (maximum)->max heap with last  and making heap(heapify) remaining and 
        // do same for all elements until sorted
        for (int i = size - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
