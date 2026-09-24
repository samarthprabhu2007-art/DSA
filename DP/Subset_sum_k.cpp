class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n= arr.size();
        vector<bool> temp(sum+1,false);
        temp[0] = true;
        if(arr[0] <= sum) temp[arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=sum;j>=0;j--){
                if(temp[j] == true){
                    int x=j+arr[i];
                    if(x<=sum) temp[x]=true;
                }
            }
        }-
        return temp[sum];
        // no recursion stakc space 
        //sc is o(k)
        // tc is o(nk)
    }
};