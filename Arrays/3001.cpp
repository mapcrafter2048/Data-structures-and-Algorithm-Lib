#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

/*
There is a 1-indexed 8 x 8 chessboard containing 3 pieces.

You are given 6 integers a, b, c, d, e, and f where:

    (a, b) denotes the position of the white rook.
    (c, d) denotes the position of the white bishop.
    (e, f) denotes the position of the black queen.

Given that you can only move the white pieces, return the minimum number of
moves required to capture the black queen.

Note that:

    Rooks can move any number of squares either vertically or horizontally, but
cannot jump over other pieces. Bishops can move any number of squares
diagonally, but cannot jump over other pieces. A rook or a bishop can capture
the queen if it is located in a square that they can move to. The queen does not
move.
*/

/*
Solution Logic:

The problem involves determining the minimum number of moves required for a
white rook and a white bishop to capture a black queen on a chessboard. The
solution involves simulating the movement of the rook and bishop while
considering the constraints of their movement and the positions of the other
pieces.

Steps of Implementation:

1. **Input Normalization**:
    - Convert the 1-indexed positions of the pieces into 0-indexed positions for
easier array-based calculations.

2. **Rook Movement**:
    - The rook can move horizontally or vertically to capture the queen.
    - Check if the rook and queen are on the same row or column.
    - Ensure that the bishop is not blocking the rook's path to the queen. This
is done by verifying that the bishop is not between the rook and the queen on
the same row or column.

3. **Bishop Movement**:
    - The bishop can move diagonally to capture the queen.
    - Check if the bishop and queen are on the same diagonal. This is determined
by the condition `abs(br - qr) == abs(bc - qc)`.
    - Ensure that the rook is not blocking the bishop's path to the queen. This
is done by verifying that the rook is not between the bishop and the queen on
the same diagonal.

4. **Return the Result**:
    - If either the rook or the bishop can capture the queen in one move, return
`1`.
    - Otherwise, return `2`, as it will take at least two moves to capture the
queen.

5. **Edge Cases**:
    - Consider scenarios where the rook or bishop is already in a position to
capture the queen.
    - Handle cases where one piece blocks the other from capturing the queen
directly.

The implementation ensures that all constraints are respected and calculates the
minimum number of moves efficiently.
*/

class Solution {
  public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int rr = a - 1, rc = b - 1;
        int br = c - 1, bc = d - 1;
        int qr = e - 1, qc = f - 1;

        if (rr == qr) {
            if (!(br == rr && min(rc, qc) < bc && bc < max(rc, qc))) {
                return 1;
            }
        }
        if (rc == qc) {
            if (!(bc == rc && min(rr, qr) < br && br < max(rr, qr))) {
                return 1;
            }
        }

        if (abs(br - qr) == abs(bc - qc)) {

            bool rookOnDiag = (abs(br - rr) == abs(bc - rc));
            bool betweenRows = min(br, qr) < rr && rr < max(br, qr);
            bool betweenCols = min(bc, qc) < rc && rc < max(bc, qc);
            if (!rookOnDiag || !(betweenRows && betweenCols)) {
                return 1;
            }
        }

        return 2;
    }
};