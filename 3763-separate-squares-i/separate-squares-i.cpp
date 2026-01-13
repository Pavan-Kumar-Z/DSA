class Solution {
public:
    double total;

    double areaBelow(vector<vector<int>>& squares, double mid) {
        double area = 0.0;

        for(int i = 0; i < squares.size(); i++) {
            double y = squares[i][1];
            double side = squares[i][2];
            double top = y + side;

            if(top <= mid) {
                area += side * side;
            }
            else if(y < mid) {
                area += side * (mid - y);
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        total = 0.0;

        for(int i = 0; i < squares.size(); i++) {
            double y = squares[i][1];
            double side = squares[i][2];
            low = min(low, y);
            high = max(high, y + side);
            total += side * side;
        }

        double half = total / 2.0;

        for(int it = 0; it < 100; it++) {
            double mid = (low + high) / 2.0;
            double below = areaBelow(squares, mid);

            if(below < half) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
