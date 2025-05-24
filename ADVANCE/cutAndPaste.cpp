#include <iostream>
#include <cstdlib>
using namespace std;

struct TreapNode {
    char val;
    int priority, size;
    TreapNode *left, *right;

    TreapNode(char v) {
        val = v;
        priority = rand();
        size = 1;
        left = right = nullptr;
    }
};

// Update the size of the subtree
int getSize(TreapNode* node) {
    return node ? node->size : 0;
}

// Recalculate size after modifications
void updateSize(TreapNode* node) {
    if (node) node->size = 1 + getSize(node->left) + getSize(node->right);
}

// Split treap at position key into two treaps
void split(TreapNode* root, int key, TreapNode*& left, TreapNode*& right) {
    if (!root) {
        left = right = nullptr;
        return;
    }

    int leftSize = getSize(root->left);
    if (key <= leftSize) { 
        split(root->left, key, left, root->left);
        right = root;
    } else {
        split(root->right, key - leftSize - 1, root->right, right);
        left = root;
    }

    updateSize(root);
}

// Merge two treaps
TreapNode* merge(TreapNode* left, TreapNode* right) {
    if (!left || !right) return left ? left : right;

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        updateSize(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        updateSize(right);
        return right;
    }
}

// Insert character at the end
TreapNode* insertEnd(TreapNode* root, char c) {
    return merge(root, new TreapNode(c));
}

// Build a treap from string
TreapNode* buildTreap(const string& s) {
    TreapNode* root = nullptr;
    for (char c : s)
        root = insertEnd(root, c);
    return root;
}

// Inorder traversal to collect the final string
void inorder(TreapNode* root, string& result) {
    if (!root) return;
    inorder(root->left, result);
    result += root->val;
    inorder(root->right, result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    TreapNode* root = buildTreap(s);

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;  // Convert 1-based to 0-based index

        TreapNode *left, *mid, *right;
        split(root, a, left, mid);
        split(mid, b - a + 1, mid, right);

        root = merge(left, right);  // Remove the middle part
        root = merge(root, mid);    // Append the middle part to the end
    }

    string result;
    inorder(root, result);
    cout << result << "\n";

    return 0;
}
