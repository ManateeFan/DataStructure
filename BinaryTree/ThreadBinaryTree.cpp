/*****线索二叉树 *****/

//线索二叉树节点定义
struct BinaryTreeNode
{
    BinaryTreeNode(int x) : data(x), left(nullptr), right(nullptr)
                            ltag(false), rtag(false) {}
    BinaryTreeNode() : left(nullptr), right(nullptr)
                       ltag(false), rtag(false) {}
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    bool ltag; //true表示left指向其直接前驱
    bool rtag; //true表示right指向其直接后继
};

//中序构造二叉树
void CreateBinaryTree(BinaryTreeNode *root)
{
    int data;
    if (std::cin >> data)
    {
        if (root == nullptr)
            root = new BinaryTreeNode;
        CreateBinaryTree(root->left);
        root->data = data;
        CreateBinaryTree(root->right);
    }
    else
        return;
}

//中序线索化
BinaryTreeNode *pre = nullptr; //全局变量，始终指向刚刚访问过的结点
void InOrderTread(BinaryTreeNode *p)
{
    if (p == nullptr)
        return;
    InOrderTread(p->left);  //递归左子树线索化
    if (p->left == nullptr) //若p无左孩子
    {
        p->ltag = true;
        p->left = temp; //p的左孩子指向当前节点的前驱
    }
    if (pre && pre->right == nullptr) //若pre无右孩子
    {
        pre->rtag = true;
        pre->right = p; //从左子树链尾开始
    }
    temp = p;
    InOrderTread(p->right);
}

//线索化后的中序遍历
void InOrder(BinaryTreeNode *root)
{
    BinaryTreeNode *p = root;
    while (p)
    {
        while (p->ltag == false)
            p = p->left;
        std::cout << p->data << " ";
        while (p->rtag == true)
        {
            p = p->right;
            std::cout << p->data << " ";
        }
        p = p->right;
    }
}

//求节点p中序遍历序列中的后继
//若rtag==true，则right指向其后继
//否则，为其右子树的左链尾的节点
BinaryTreeNode *InNext(BinaryTreeNode *p)
{
    if (p->rtag) //rtag为true，则right为其后继
        return p->right;
    else
    {
        p = p->right; //p指向其右子女
        while (p->left)
            p = p->left; //找右子树的左链尾
        return p;
    }
}
