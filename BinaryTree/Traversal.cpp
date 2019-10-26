/*****二叉树的递归遍历*****/
//前序遍历
void PreOrder(BTnode *pnode)
{
    if (pnode)
    {
        visit(pnode);
        PreOrder(bnode->left);
        PreOrder(bnode->right);
    }
}
//中序遍历
void InOrder(BTnode *pnode)
{
    if (pnode)
    {
        InOrder(pnode->left);
        visit(pnode);
        InOrder(pnode->right);
    }
}
//后序遍历
void PostOrder(BTnode *pnode)
{
    if (pnode)
    {
        PostOrder(pnode->left);
        PostOrder(pnode->right);
        visit(pnode);
    }
}

/*****二叉树的非递归遍历*****/
//前序遍历
void PreOrder1(BTnode *pnode)
{
    stack<*BTnode> s;
    BTnode *p = pnode;
    while (p || !s.empty())
    {
        while (p)
        {
            visit(p); //先访问根节点,再入栈
            s.push(p);
            p = p->left; //遍历到左子树最下面
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right; //进入右子树，开始新的遍历
        }
    }
}
void PreOrder2(BTnode *pnode)
{
    stack<*BTnode> s;
    BTnode *p = pnode;
    while (p || !s.empty())
    {
        if (p)
        {
            visit(p);
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}
void PreOrder3(BTnode *pnode)
{
    stack < *BTnod入栈
                BTnode *p = pnode;
    while (p || !s.empty())
    {
        visit(p);
        if (p->right)
            s.push(p->right);
        if (p->left)
            s.push(p->left);
        else
        {
            p = s.top();
            s.pop();
            p = p->right; //左子树访问完了，访问右子树
        }
    }
}
//中序遍历
void InOrder1(BTnode *pnode)
{
    stack<*Bnode> s;
    BTnode *p = pnode;
    while (p || !s.empty())
    {
        //先找到左子树的最下边的节点
        while (!p)
        {
            s.push(p); //边遍历边保存根节点到栈中
            p = p->left;
        }
        //p为空时，说明已经到达左子树最下边，这时需要出栈
        if (!s.empty())
        {
            p = s.top();
            visit(p);
            s.pop();
            p = p->right; //进入右子树，开始新的一轮左子树遍历
        }
    }
}
vodi InOrder2(BTnode *pnode)
{
    stack<*BTnode> s;
    BTnode *p = pnode;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            visit(p);
            p = p->right;
        }
    }
}
