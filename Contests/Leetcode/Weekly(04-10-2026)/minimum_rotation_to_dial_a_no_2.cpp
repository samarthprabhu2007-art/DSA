class Solution {
public:
    // shortest way around the circular dial from digit a to digit b
    int dist(int a, int b) {
        int d = abs(a - b);
        return min(d, 10 - d);
    }

    int minRotations(int n, string s) {
        // pre[i] = cost to dial the first i digits, starting from 0
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int prev;
            if (i == 0) prev = 0;
            else prev = s[i - 1] - '0';
            pre[i + 1] = pre[i] + dist(prev, s[i] - '0');
        }

        // suf[i] = cost of moving between neighbours inside s[i..n-1]
        vector<int> suf(n + 1, 0);
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + dist(s[i] - '0', s[i + 1] - '0');
        }

        int best = pre[n];             // option 1: no reversal
        int last = s[n - 1] - '0';

        for (int k = 0; k < n; k++) {  // option 2: reverse s[k..n-1]
            int prev = (k == 0) ? 0 : s[k - 1] - '0';
            int cost = pre[k] + dist(prev, last) + suf[k];
            best = min(best, cost);
        }
        return best;
    }
};