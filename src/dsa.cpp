#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

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

/*
2. Hash Map:

    insert(HashMap* map, int key, int value): Insert a key-value pair.
    delete(HashMap* map, int key): Remove a key-value pair.
    search(HashMap* map, int key): Retrieve a value based on a key.
    resize(HashMap* map): Resize the hash table, typically doubling its size.

3. Queue:

    enqueue(Queue* queue, int item): Add an item to the end of the queue.
    dequeue(Queue* queue): Remove and return the item at the front of the queue.
    front(Queue* queue): Peek at the front item without removing it.
    isEmpty(Queue* queue): Check if the queue is empty.
    isFull(Queue* queue): Check if the queue is full.

5. Set (using Binary Search Tree):

    insert(BSTNode** root, int data): Insert a node.
    delete(BSTNode** root, int key): Delete a node.
    search(BSTNode* root, int key): Search for a node.
    inorderTraversal(BSTNode* root): Inorder traversal (gives elements in sorted order).
    findMin(BSTNode* root): Find minimum value node.
    findMax(BSTNode* root): Find maximum value node.

6. Graph (using Adjacency List):

    addEdge(Graph* graph, int src, int dest): Add an edge between two vertices.
    printGraph(Graph* graph): Display the graph.
    breadthFirstSearch(Graph* graph, int startVertex): BFS traversal.
    depthFirstSearch(Graph* graph, int startVertex): DFS traversal.

7. Tree (Generic Tree):

    addChild(TreeNode* node, int data): Add a child node.
    printTree(TreeNode* root): Display the tree (e.g., level-order traversal).


*/