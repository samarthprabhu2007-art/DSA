class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  pq;
        for(int i = 0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int cnt  = 0;
        int x = INT_MAX;
        while(pq.size() != 0){
            int y = pq.top().first;
            int z = pq.top().second;
            if(x != y) {
               x = y;
               cnt++; 
            }
            pq.pop();
            arr[z] = cnt;
        }
        return arr;
    }
};