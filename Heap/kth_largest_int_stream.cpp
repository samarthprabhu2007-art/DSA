class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size ;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        size = 0;
        cap = k;
        for(int i = 0 ; i<nums.size();i++){
            pq.push(nums[i]);
            size++;
            if(size > cap) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        size++;
        if(size > cap) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */