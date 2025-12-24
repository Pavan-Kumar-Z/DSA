
class Solution {
public:
    int nextEventIndex(const vector<int>& starts, int target) {
        return lower_bound(starts.begin(), starts.end(), target) - starts.begin();
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        if (n == 0) return 0;

        sort(events.begin(), events.end(), [](const auto &a, const auto &b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        vector<int> starts(n);
        for (int i = 0; i < n; ++i) starts[i] = events[i][0];

        vector<int> bestSuffix(n);
        for (int i = n - 1; i >= 0; --i) {
            bestSuffix[i] = events[i][2];
            if (i + 1 < n) bestSuffix[i] = max(bestSuffix[i], bestSuffix[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, events[i][2]);
            int next = nextEventIndex(starts, events[i][1] + 1);
            if (next < n) ans = max(ans, events[i][2] + bestSuffix[next]);
        }

        return ans;
    }
};
