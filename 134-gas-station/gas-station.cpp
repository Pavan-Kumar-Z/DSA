#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n == 0) return -1;

        int total = 0;   
        int tank = 0;    
        int start = 0;   

        for (int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return (total >= 0) ? (start % n) : -1;
    }
};
