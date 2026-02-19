class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> before(n,0), after(n,0); 

        for(int i = 1; i < n; i++){
            before[i] = before[i-1] + ((s[i-1] == 'b') ? 1 : 0);
        }

        for(int i = n-2; i >= 0; i--){
            after[i] = after[i+1] + ((s[i+1] == 'a') ? 1 : 0);
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, before[i] + after[i]);
        }

        return ans;
    }
};
