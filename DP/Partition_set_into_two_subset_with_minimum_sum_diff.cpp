class Solution{

  public:
	int minDifference(vector<int>&arr, int n)  {
        int sum = 0 ;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
        }
        vector<bool> temp(sum+1,false);
        temp[0]=true;
        temp[sum]=true;
        for(int i=0;i<arr.size();i++){
            for(int j=sum;j>=0;j--){
                if(temp[j]==true){
                    int x = j + arr[i];
                    if(x<=sum) temp[x]=true;
                }
            }
        }
        int ans = sum;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==true) ans=min(ans,abs(sum-2*i));
        }
        return ans;
	} 
};
