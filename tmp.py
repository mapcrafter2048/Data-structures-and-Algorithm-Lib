import os

# Base directory containing the files
base_dir = r"d:\Programming_stuffs\Programing Scripts\C++ and DSA\Data-structures-and-Algorithm-Lib"

# Mapping of file names to LeetCode problem numbers
file_mappings = {
    "Count-Triplets-That-Can-Form-Two-Arrays-of-Equal-XOR.cpp": "1442.cpp",
    "Find-the-Maximum-Sum-of-Node-Values.cpp": "3068.cpp",
    "Minimum-Bit-Flips-to-Convert-Number.cpp": "2220.cpp",
    "single-number-ll.cpp": "137.cpp",
    "Single-Number.cpp": "136.cpp",
    "Sum-of-All-Subset-XOR-Totals.cpp": "1863.cpp",
    "Coin-change.cpp": "322.cpp",
    "Combination-Sum-IV.cpp": "377.cpp",
    "Decode-Ways.cpp": "91.cpp",
    "Delete-Operation-for-Two-Strings.cpp": "583.cpp",
    "Dungeon-Game.cpp": "174.cpp",
    "Edit-distance.cpp": "72.cpp",
    "Integer-Replacement.cpp": "397.cpp",
    "Interleaving-String.cpp": "97.cpp",
    "Jump-Game.cpp": "55.cpp",
    "Knight-Probability-in-Chessboard.cpp": "688.cpp",
    "Longest-Common-Subsequence.cpp": "1143.cpp",
    "Longest-Common-Substring.cpp": "718.cpp",
    "Longest-Increasing-Subsequence.cpp": "300.cpp",
    "Maximum-Score-Words-Formed-by-Letters.cpp": "1255.cpp",
    "Minimum-Falling-Path-Sum-II.cpp": "1289.cpp",
    "Minimum-Falling-Path-Sum.cpp": "931.cpp",
    "Minimum-path-sum.cpp": "64.cpp",
    "Out-of-boundary-Problem.cpp": "576.cpp",
    "Palindrome-Partitioning.cpp": "131.cpp",
    "Reducing-Dishes.cpp": "1402.cpp",
    "ugly-number.cpp": "263.cpp",
    "Word-Search.cpp": "79.cpp",
    "0-1Matrix.cpp": "542.cpp",
    "Bipartite-graph-DFS.cpp": "785.cpp",
    "Cycle-in-directed-graph.cpp": "207.cpp",
    "Cycle-in-Undirected-graph.cpp": "547.cpp",
    "Dijkstra-Algorithm.cpp": "utility_dijkstra.cpp",
    "Island-Perimeter.cpp": "463.cpp",
    "Maximal-Rectangle.cpp": "85.cpp",
    "Number-of-Distinct-Islands.cpp": "694.cpp",
    "Number-of-Enclaves.cpp": "1020.cpp",
    "number-of-islands.cpp": "200.cpp",
    "Path-with-Maximum-Gold.cpp": "1219.cpp",
    "rotten-oranges.cpp": "994.cpp",
    "Surrounded-regions.cpp": "130.cpp",
    "job-scheduling.cpp": "1235.cpp",
    "Subsets.cpp": "78.cpp",
    "Binary-Tree-Level-Order-Traversal.cpp": "102.cpp",
    "Delete-Leaves-With-a-Given-Value.cpp": "1325.cpp",
    "Distribute-Coins-in-Binary-Tree.cpp": "979.cpp",
    "Evaluate-Boolean-Binary-Tree.cpp": "2236.cpp",
    "Path-Sum-II.cpp": "113.cpp",
    "4Sum.cpp": "18.cpp",
    "IPO.cpp": "502.cpp",
    "Longest-Consecutive-Sequence.cpp": "128.cpp",
    "Longest-Substring-Without-Repeating-Characters.cpp": "3.cpp",
    "Merge-Intervals.cpp": "56.cpp",
    "Search-a-2D-Matrix.cpp": "74.cpp",
    "Set Matrix Zeroes.cpp": "73.cpp",
    "Subarray-Sum-Equals-K.cpp": "560.cpp",
    "Capacity-to-Ship-Packages-within-D-Days.cpp": "1011.cpp",
    "Find-Minimum-in-Rotated-Sorted-Array.cpp": "153.cpp",
    "Find-Peak-Element.cpp": "162.cpp",
    "Koko-eating-bananas.cpp": "875.cpp",
    "Minimum-days-to-make-M-bouquets.cpp": "1482.cpp",
    "Search-in-Rotated-Sorted-Array.cpp": "33.cpp",
    "Single-Element-in-a-Sorted-Array.cpp": "540.cpp",
    "Invert-Binary-Tree.cpp": "226.cpp",
    "Diameter-of-Binary-Tree.cpp": "543.cpp",
    "Insert-in-BST.cpp": "701.cpp",
    "Search-in-BST.cpp": "700.cpp",
    "Spiral.cpp": "54.cpp",
    "Width-of-Tree.cpp": "662.cpp",
    "Zig-Zag-Traversal-in-Binary-Tree.cpp": "103.cpp",
}

# Function to recursively rename files
def rename_files_recursively(base_dir, file_mappings):
    for root, _, files in os.walk(base_dir):
        for file in files:
            if file in file_mappings:
                old_path = os.path.join(root, file)
                new_path = os.path.join(root, file_mappings[file])
                os.rename(old_path, new_path)
                print(f"Renamed: {old_path} -> {new_path}")

# Execute the renaming
rename_files_recursively(base_dir, file_mappings)