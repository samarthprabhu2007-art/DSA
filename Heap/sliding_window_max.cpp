class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> rm;
        priority_queue<int> pq;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        ans.push_back(pq.top());
        for(int i=k;i<n;i++){
            rm[nums[i-k]]++;
            pq.push(nums[i]);
            while(rm[pq.top()]!=0){
                rm[pq.top()]--;
                pq.pop();
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};