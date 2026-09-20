class Solution {
  public:
    // so my state is, imagine iam landing on this 
    // i ,j point, then what is max i can get
    // mat[i][j]+ max(element not from same j from prev row)
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==1){
            return max(mat[0][0],max(mat[0][1],mat[0][2]));
        }
        int x=mat[0][0];
        int y=mat[0][1];
        int z=mat[0][2];
        for(int i=1;i<n;i++){
            int a=mat[i][0]+max(y,z);
            int b=mat[i][1]+max(x,z);
            int c=mat[i][2]+max(x,y);
            x=a;
            y=b;
            z=c;
        }
        return max(x,max(y,z));
    }
};