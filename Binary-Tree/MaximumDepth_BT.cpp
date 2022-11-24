
// find maximum depth of binary tree
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data) // O(1)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int maxDepth(Node *node) // recursive // O(n)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int main()
{
    O_O;
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Height of tree is " << maxDepth(root);
    return 0;
}
