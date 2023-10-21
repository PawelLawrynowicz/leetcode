#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

/* ARRAY */
// raw implementation
int arr[5] = {1, 2, 3, 4, 5};
// stl
std::array<int, 5> stl_arr = {1, 2, 3, 4, 5};

/* HASH MAP */
// raw implementation
struct HashNode {
  int              key;
  int              value;
  struct HashNode* next;
};

struct HashMap {
  int               size;
  struct HashNode** list;  // An array of pointers to HashNodes
};
// stl
std::map<char, int> stl_map = {
    {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5},
};

/* Queue */
// raw implementation
struct Queue {
  int      front, rear, size;
  unsigned capacity;
  int*     array;
};
// stl
std::queue<int> stl_queue;

/* Stack */
// raw implementation
struct Stack {
  int      top;
  unsigned capacity;
  int*     array;
};
// stl
std::stack<int> stl_stack;

/* Set */
// raw implementation
// stl
std::set<int> stl_set = {1, 2, 3, 4, 5};

/* Graph */
// raw implementation
struct Graph {
  int             V;
  std::list<int>* adj;
};
// stl
// C++ STL doesn't have a dedicated graph structure. Graphs are typically represented using vectors or lists.
std::vector<std::list<int>> stl_graph_representation;

/* Tree */
// raw implementation
// stl
struct TreeNode {
  int                    data;
  std::vector<TreeNode*> children;
};

/* Binary search tree */
// raw implementation
// stl
struct BSTNode {
  int      data;
  BSTNode* left;
  BSTNode* right;
};
