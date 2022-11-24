
// diameter of binary tree
struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{ // creating a new node
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int height(Node *root)
{ // calculating height of tree
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int diameter(Node *root)
{ // calculating diameter of tree
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);                             // calculating height of left subtree
    int rheight = height(root->right);                            // calculating height of right subtree
    int ldiameter = diameter(root->left);                         // diameter of left subtree
    int rdiameter = diameter(root->right);                        // diameter of right subtree
    return max(lheight + rheight + 1, max(ldiameter, rdiameter)); // returning maximum of all
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Diameter of the given binary tree is " << diameter(root);
    return 0;
}