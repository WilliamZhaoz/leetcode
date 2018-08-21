class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = abs((A - C) * (B - D)) + abs((E - G) * (F - H));
        if (E >= C || A >= G || B >= H || F >= D) {
            return sum;
        }
        return sum - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F)));
    }
};