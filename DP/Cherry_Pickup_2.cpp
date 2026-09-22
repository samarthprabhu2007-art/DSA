class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int row = 0;
        vector<vector<int>> dp(n,vector<int> (n,INT_MIN));
        vector<vector<int>> temp(n,vector<int> (n,INT_MIN));
        dp[0][n-1] = grid[0][0]+grid[0][n-1];
        temp=dp;
        for(row=1; row<m; row++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int p=-1;p<=1;p++){
                        for(int q=-1;q<=1;q++){
                            int x=i+p;
                            int y=j+q;
                            int z = grid[row][i];
                            if(i!=j) z+=grid[row][j];
                            if((x>=0 && x<n)&&(y>=0 && y<n)) temp[i][j]=max(temp[i][j],z+dp[x][y]);
                        }
                    }
                }
            }
            dp=temp;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) ans=max(ans,dp[i][j]);
        }
        return ans;
    }
};