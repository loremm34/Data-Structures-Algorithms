#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    long value;
    int height;
    int way;

    Node(long v) : left(nullptr), right(nullptr), value(v), height(0), way(0) {}
};

class BST {
private:

    Node* root;

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->value) {
            root->left = insert(root->left, value);
        }
        else if (value > root->value) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    Node* getMinimumKey(Node* curr)
    {
        if (curr->left == nullptr) {
            return curr;
        }
        return getMinimumKey(curr->left);
    }

    Node* deleteNode(Node* n, long v) {
        if (n == nullptr) return nullptr;
        if (v < n->value) {
            n->left = deleteNode(n->left, v);
            return n;
        }
        if (v > n->value) {
            n->right = deleteNode(n->right, v);
            return n;
        }
        if (n->left == nullptr) {
            return n->right;
        }
        if (n->right == nullptr) {
            return n->left;
        } 
        else {
            long min_val = getMinimumKey(n->right)->value;
            n->value = min_val;
            n->right = deleteNode(n->right, min_val);
            return n;
        }
    }

    void findDepth(Node* n) {
        if (n->right == nullptr && n->left == nullptr) {
            n->height = 0;
        }
        else if (n->left == nullptr) {
            n->height = n->right->height + 1;
        }
        else if (n->right == nullptr) {
            n->height = n->left->height + 1;
        }
        else {
            if (n->right->height > n->left->height)
                n->height = n->right->height + 1;
            else n->height = n->left->height + 1;
        }
    }

    void arrangeSemipath(Node* n) {
        if (n->right == nullptr && n->left == nullptr) {
            n->way = 0;
        }
        else if (n->left == nullptr) {
            n->way = n->right->height + 1;
        }
        else if (n->right == nullptr) {
            n->way = n->left->height + 1;
        }
        else n->way = n->right->height + n->left->height + 2;
    }

    void preOrderTraversal(Node* n, vector<long>& result) {
        if (n != nullptr) {
            result.push_back(n->value);
            preOrderTraversal(n->left, result);
            preOrderTraversal(n->right, result);
        }
    }

    void preOrderTraversalPath(Node* n) {
        if (n != nullptr) {
            arrangeSemipath(n);
            preOrderTraversalPath(n->left);
            preOrderTraversalPath(n->right);
        }
    }

    void postOrderTraversal(Node* n, vector<Node*>& nodes) {
        if (n != nullptr) {
            postOrderTraversal(n->left, nodes);
            postOrderTraversal(n->right, nodes);
            findDepth(n);
            nodes.push_back(n);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(long v) {
        root = insert(root, v);
    }

    void remove(long v) {
        root = deleteNode(root, v);
    }

    vector<long> toVectorPrint() {
        vector<long> result;
        preOrderTraversal(root, result);
        return result;
    }

    long toArrayListNode() {
        vector<Node*> nodes;
        postOrderTraversal(root, nodes);
        preOrderTraversalPath(root);

        sort(nodes.begin(), nodes.end(), [](Node* node1, Node* node2    ) {
            if (node1->way - node2->way == 0)
                return node1->height < node2->height;
            return node1->way < node2->way;
            });

        return nodes.back()->value;
    }
};

int main() {
    BST tree;
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    long value;

    while (fin >> value) {
        tree.insert(value);
    }
        
    tree.remove(tree.toArrayListNode());
   
    auto result = tree.toVectorPrint();
    for (const auto& val : result)
        fout << val << endl;

    return 0;
}