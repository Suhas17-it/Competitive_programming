#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> subtreeSums;

    // 👉 FILL THIS FUNCTION
    int dfs(Node* root) {
        
        if(!root) return 0;
        int res = root->val;
        res += dfs(root->left);
        res += dfs(root->right);

        subtreeSums.push_back(res);
        return res;
    }

    vector<int> getAllSubtreeSums(Node* root) {
        dfs(root);
        return subtreeSums;
    }
};

int main() {
    /*
        Constructing the tree:

                1
               / \
              2   3
             / \   \
            4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> ans = sol.getAllSubtreeSums(root);

    cout << "Subtree sums:\n";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
