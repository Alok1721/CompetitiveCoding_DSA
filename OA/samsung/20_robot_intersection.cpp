#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    long long x1, y1, x2, y2;
};

bool overlap(long long a1, long long a2, long long b1, long long b2) {
    if(a1 > a2) swap(a1, a2);
    if(b1 > b2) swap(b1, b2);
    return max(a1, b1) <= min(a2, b2);
}

bool intersect(const Segment &A, const Segment &B) {
    bool Avert = (A.x1 == A.x2);
    bool Bvert = (B.x1 == B.x2);

    if (Avert && !Bvert) {
        // A vertical, B horizontal
        long long vx = A.x1;
        long long hy = B.y1;
        return (min(A.y1, A.y2) <= hy && hy <= max(A.y1, A.y2) &&
                min(B.x1, B.x2) <= vx && vx <= max(B.x1, B.x2));
    }
    if (!Avert && Bvert) {
        // A horizontal, B vertical
        long long hy = A.y1;
        long long vx = B.x1;
        return (min(B.y1, B.y2) <= hy && hy <= max(B.y1, B.y2) &&
                min(A.x1, A.x2) <= vx && vx <= max(A.x1, A.x2));
    }
    if (Avert && Bvert) {
        // both vertical
        if (A.x1 != B.x1) return false;
        return overlap(A.y1, A.y2, B.y1, B.y2);
    }
    // both horizontal
    if (A.y1 != B.y1) return false;
    return overlap(A.x1, A.x2, B.x1, B.x2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        long long x = 0, y = 0;
        vector<Segment> segs;

        int result = -1;

        for (int i = 1; i <= N; i++) {
            int dir;
            long long dist;
            cin >> dir >> dist;

            long long nx = x, ny = y;
            if (dir == 1) ny += dist;    // North
            if (dir == 2) ny -= dist;    // South
            if (dir == 3) nx += dist;    // East
            if (dir == 4) nx -= dist;    // West

            Segment cur = {x, y, nx, ny};

            // Check intersection with all earlier segments except immediate previous
            for (int j = 0; j + 1 < (int)segs.size(); j++) {
                if (intersect(cur, segs[j])) {
                    if (result == -1) result = i;
                }
            }

            segs.push_back(cur);
            x = nx;
            y = ny;
        }

        cout << "Case #" << tc << "\n";
        cout << result << "\n";
    }

    return 0;
}
