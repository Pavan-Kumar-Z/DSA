class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long,long long> freq, freqP;

        for (long long x : nums) freq[x]++;

        const long long mod = 1000000007;
        long long ans = 0;

        for (long long x : nums) {
            long long total = freq[2*x];
            long long prev  = freqP[2*x];
            long long right = total - prev;

            if (x == 0) right--;

            freqP[x]++;

            long long add = (prev % mod) * (right % mod);
            add %= mod;
            ans += add;
            ans %= mod;
        }

        return (int)ans;
    }
};
