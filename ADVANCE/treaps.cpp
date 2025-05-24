#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

struct TreapNode {
    int key, priority, size, sum, minVal, maxVal;
    bool lazyReverse, lazyPaint;
    int paintValue, lazyAdd;
    TreapNode *left, *right;

    TreapNode(int k) {
        key = k;
        priority = rand();
        size = 1;
        sum = minVal = maxVal = k;
        lazyReverse = lazyPaint = false;
        paintValue = lazyAdd = 0;
        left = right = nullptr;
    }
};

// Get size of a node
int getSize(TreapNode* node) {
    return node ? node->size : 0;
}

// Update size, sum, min, max values
void updateNode(TreapNode* node) {
    if (!node) return;

    node->size = 1 + getSize(node->left) + getSize(node->right);
    node->sum = node->minVal = node->maxVal = node->key;

    if (node->left) {
        node->size += node->left->size;
        node->sum += node->left->sum;
        node->minVal = min(node->minVal, node->left->minVal);
        node->maxVal = max(node->maxVal, node->left->maxVal);
    }
    if (node->right) {
        node->size += node->right->size;
        node->sum += node->right->sum;
        node->minVal = min(node->minVal, node->right->minVal);
        node->maxVal = max(node->maxVal, node->right->maxVal);
    }
}

// Push lazy propagation updates
void propagate(TreapNode* node) {
    if (!node) return;

    // Apply painting
    if (node->lazyPaint) {
        node->key = node->paintValue;
        node->sum = node->size * node->paintValue;
        node->minVal = node->maxVal = node->paintValue;
        if (node->left) {
            node->left->lazyPaint = true;
            node->left->paintValue = node->paintValue;
        }
        if (node->right) {
            node->right->lazyPaint = true;
            node->right->paintValue = node->paintValue;
        }
        node->lazyPaint = false;
    }

    // Apply addition
    if (node->lazyAdd) {
        node->key += node->lazyAdd;
        node->sum += node->size * node->lazyAdd;
        node->minVal += node->lazyAdd;
        node->maxVal += node->lazyAdd;
        if (node->left) node->left->lazyAdd += node->lazyAdd;
        if (node->right) node->right->lazyAdd += node->lazyAdd;
        node->lazyAdd = 0;
    }

    // Apply reversal
    if (node->lazyReverse) {
        swap(node->left, node->right);
        if (node->left) node->left->lazyReverse ^= true;
        if (node->right) node->right->lazyReverse ^= true;
        node->lazyReverse = false;
    }
}

// Split treap into two parts
void split(TreapNode* root, int key, TreapNode*& left, TreapNode*& right) {
    if (!root) {
        left = right = nullptr;
        return;
    }
    propagate(root);

    int leftSize = getSize(root->left);
    if (key <= leftSize) {
        split(root->left, key, left, root->left);
        right = root;
    } else {
        split(root->right, key - leftSize - 1, root->right, right);
        left = root;
    }
    updateNode(root);
}

// Merge two treaps
TreapNode* merge(TreapNode* left, TreapNode* right) {
    propagate(left);
    propagate(right);

    if (!left || !right) return left ? left : right;

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        updateNode(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        updateNode(right);
        return right;
    }
}

// Insert at a specific position
TreapNode* insertAt(TreapNode* root, int pos, int key) {
    TreapNode *left, *right;
    split(root, pos, left, right);
    return merge(merge(left, new TreapNode(key)), right);
}

// Delete at a specific position
TreapNode* deleteAt(TreapNode* root, int pos) {
    TreapNode *left, *mid, *right;
    split(root, pos, mid, right);
    split(mid, pos - 1, left, mid);

    delete mid;
    return merge(left, right);
}

// Query sum in range [L, R]
int rangeSum(TreapNode* root, int L, int R) {
    TreapNode *left, *mid, *right;
    split(root, R, mid, right);
    split(mid, L - 1, left, mid);

    int sum = mid ? mid->sum : 0;
    root = merge(merge(left, mid), right);
    return sum;
}

// Reverse a range
TreapNode* reverseRange(TreapNode* root, int L, int R) {
    TreapNode *left, *mid, *right;
    split(root, R, mid, right);
    split(mid, L - 1, left, mid);

    if (mid) mid->lazyReverse ^= true;

    return merge(merge(left, mid), right);
}

// Paint a range with a new value
TreapNode* updateRange(TreapNode* root, int L, int R, int value) {
    TreapNode *left, *mid, *right;
    split(root, R, mid, right);
    split(mid, L - 1, left, mid);

    if (mid) {
        mid->lazyPaint = true;
        mid->paintValue = value;
    }

    return merge(merge(left, mid), right);
}

// Add a value to a range
TreapNode* addRange(TreapNode* root, int L, int R, int value) {
    TreapNode *left, *mid, *right;
    split(root, R, mid, right);
    split(mid, L - 1, left, mid);

    if (mid) mid->lazyAdd += value;

    return merge(merge(left, mid), right);
}

// Inorder traversal
void inorder(TreapNode* root) {
    if (!root) return;
    propagate(root);
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Main function
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TreapNode* root = nullptr;
    root = insertAt(root, 0, 10);
    root = insertAt(root, 1, 20);
    root = insertAt(root, 2, 30);
    root = insertAt(root, 3, 40);

    cout << "Before operations: ";
    inorder(root);
    cout << "\n";

    root = reverseRange(root, 1, 3);
    cout << "After reversing [1,3]: ";
    inorder(root);
    cout << "\n";

    root = updateRange(root, 2, 3, 100);
    cout << "After painting [2,3] with 100: ";
    inorder(root);
    cout << "\n";

    cout << "Sum of range [1,3]: " << rangeSum(root, 1, 3) << "\n";

    return 0;
}
