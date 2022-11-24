
// check for balanced binary tree
// if height of left subtree and right subtree is not more than 1
// then it is balanced binary tree
struct Node // creating node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) // constructor
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int height(Node *root) // calculating height of tree
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}
bool isBalanced(Node *root) //
{
    if (root == NULL)
        return true;
    if (isBalanced(root->left) == false)
        return false;
    if (isBalanced(root->right) == false)
        return false;
    int lh = height(root->left);  // calculating height of left subtree
    int rh = height(root->right); // calculating height of right subtree
    if (abs(lh - rh) <= 1)        // checking if height of left subtree and right subtree is not more than 1
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}