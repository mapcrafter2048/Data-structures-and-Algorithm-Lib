#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
You have information about n different recipes. You are given a string array
recipes and a 2D string array ingredients. The ith recipe has the name
recipes[i], and you can create it if you have all the needed ingredients from
ingredients[i]. A recipe can also be an ingredient for other recipes, i.e.,
ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that
you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer
in any order.

Note that two recipes may contain each other in their ingredients.
*/

/*
Detailed Solution Logic and Steps of Implementation:

The problem is to determine which recipes can be created given a list of
recipes, their required ingredients, and an initial set of supplies. The
solution involves using a topological sorting approach to process dependencies
between recipes and ingredients.

Steps of Implementation:

1. **Input Parsing and Initialization**:
    - Convert the `supplies` list into an unordered set (`set1`) for quick
lookup of available ingredients.
    - Convert the `recipes` list into another unordered set (`set2`) for quick
lookup of recipe names.
    - Initialize two unordered maps:
      - `indegree`: Tracks the number of dependencies (ingredients) each recipe
has.
      - `adj`: Represents the adjacency list for the dependency graph, where an
edge from ingredient `A` to recipe `B` means `B` depends on `A`.

2. **Build the Dependency Graph**:
    - Iterate through each recipe and its corresponding ingredients.
    - For each ingredient:
      - If the ingredient is already in `supplies` (`set1`), skip it since it's
readily available.
      - If the ingredient is another recipe (`set2`), add an edge in the
adjacency list from the ingredient to the current recipe and increment the
indegree of the current recipe.
      - Otherwise, increment the indegree of the current recipe, as it depends
on an unavailable ingredient.

3. **Topological Sorting Using Kahn's Algorithm**:
    - Initialize a queue to store recipes with an indegree of 0 (i.e., recipes
that can be created immediately).
    - Add all such recipes to the queue.

4. **Process Recipes in Topological Order**:
    - While the queue is not empty:
      - Dequeue a recipe and add it to the result list.
      - Mark the recipe as available by adding it to `set1`.
      - For each recipe dependent on the current recipe (from the adjacency
list):
         - Decrement its indegree.
         - If its indegree becomes 0, enqueue it.

5. **Return the Result**:
    - The result list contains all the recipes that can be created in
topological order.

Key Points:
- The use of `indegree` ensures that recipes are only processed when all their
dependencies are satisfied.
- The adjacency list (`adj`) captures the dependency relationships between
recipes and ingredients.
- The unordered sets (`set1` and `set2`) allow for efficient lookups to
distinguish between available ingredients and recipes.

This approach ensures that all recipes that can be created are identified, and
the algorithm handles cyclic dependencies gracefully by not processing recipes
with unresolved dependencies.
*/
/*
// Example input
vector<string> recipes = {"bread", "sandwich", "burger"};
vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"},
{"sandwich", "meat", "bread"}}; vector<string> supplies = {"yeast", "flour",
"meat"};

// Adjacency list
// bread -> sandwich
// sandwich -> burger
// bread -> burger
unordered_map<string, vector<string>> adj = {
    {"bread", {"sandwich", "burger"}},
    {"sandwich", {"burger"}}
};

// Indegree map
// bread: 0
// sandwich: 1
// burger: 2
unordered_map<string, int> indegree = {
    {"bread", 0},
    {"sandwich", 1},
    {"burger", 2}
};
*/

class Solution {
  public:
    vector<string> findAllRecipes(vector<string> &recipes,
                                  vector<vector<string>> &ingredients,
                                  vector<string> &supplies) {
        // Convert supplies and recipes to sets for quick lookup
        // Use a set for recipes to avoid duplicates
        unordered_set<string> set1(supplies.begin(), supplies.end());
        unordered_set<string> set2(recipes.begin(), recipes.end());

        // Maps to track indegrees and adjacency list
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> adj;

        // Initialize indegree for all recipes
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = 0;
        }

        // Build the graph
        for (int i = 0; i < recipes.size(); i++) {
            // For each ingredient in the recipe
            for (auto ing : ingredients[i]) {
                // If the ingredient is already available, skip it
                if (set1.count(ing) != 0) {
                    continue;
                }
                // If the ingredient is a recipe, add an edge
                // Otherwise, just increment the indegree
                if (set2.count(ing) != 0) {
                    adj[ing].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                } else {
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for (auto recipe : recipes) {
            if (indegree[recipe] == 0) {
                q.push(recipe);
            }
        }

        vector<string> result;

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            result.push_back(current);
            set1.insert(current);

            for (auto intrecipe : adj[current]) {
                indegree[intrecipe]--;
                if (indegree[intrecipe] == 0) {
                    q.push(intrecipe);
                }
            }
        }

        return result;
    }
};
