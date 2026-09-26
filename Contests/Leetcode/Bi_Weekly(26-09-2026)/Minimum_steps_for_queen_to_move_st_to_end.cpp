class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int x = source[0];
        int y =source[1];
        int p = target[0];
        int q = target[1];
        if(x==p && y==q) return 0;
        if(x==p) return 1;
        if(y==q) return 1;
        if(x+y == p+q) return 1;
        if(x-y == p-q) return 1;
        return 2;
    }
};