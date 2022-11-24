
// find maximum path sum of binary tree
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int findMaxUtil(Node *root, int &res) // res is passed by reference
{
    // Base Case
    if (root == NULL)
        return 0;
    // l and r store maximum path sum going through left and
    // right child of root respectively
    int l = findMaxUtil(root->left, res);
    int r = findMaxUtil(root->right, res);
    // Max path for parent call of root. This path must
    // include at-most one child of root
    int max_single = max(max(l, r) + root->data, root->data);
    // Max Top represents the sum when the Node under
    // consideration is the root of the maxsum path and no
    // ancestors of root are there in max sum path
    int max_top = max(max_single, l + r + root->data);
    res = max(res, max_top); // Store the Maximum Result.
    return max_single;
}
int findMaxSum(Node *root) // returns maximum path sum in tree with given root
{
    // Initialize result
    int res = INT_MIN;
    // Compute and return result
    findMaxUtil(root, res);
    return res;
}
int main()
{
    // fast;
    Node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);
    cout << "Max path sum is " << findMaxSum(root);
    return 0;
}