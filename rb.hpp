#include <iostream>

struct redblacktree
{
    int data;
    std::string color;
    redblacktree *left;
    redblacktree *right;
    redblacktree *parent;
};

bool isEmpty(const redblacktree *root)
{
    return root == nullptr;
}

redblacktree *createleaf(int key)
{

    redblacktree *n = new redblacktree;
    n->data = key;
    n->right = nullptr;
    n->left = nullptr;
    return n;
}

void insert(redblacktree *&ptr, int item)
{
    if (isEmpty(ptr))
    {
        ptr = createleaf(item);
    }

    else
    {

        if (ptr->data >= item)

            insert(ptr->left, item);

        else if (ptr->data < item)

            insert(ptr->right, item);
    }
}

void rotateright(redblacktree *&Z)
{
    if (!isEmpty(Z))
    {
        Z->parent->right = Z->parent;

        rotateright(Z->parent);
    }
}

void rotateleft(redblacktree *&Z)
{
    if (!isEmpty(Z))
    {
        Z->parent->left = Z->parent;

        rotateleft(Z->parent);
    }
}

void recolor(redblacktree *&Z)
{
    redblacktree *grandparent = new redblacktree;
    grandparent = Z->parent->parent;

    if (Z->left == nullptr && Z->right == nullptr)
    {
        Z->color = "black";
    }

    else if (Z->color == "red" && grandparent->left->color == "red")
    {

        grandparent->left->color = grandparent->right->color = "black";
        Z = grandparent;
        recolor(Z);
    }

    else if (Z->color == "red" && Z->parent->color == "red" && grandparent->color == "black" && grandparent->left->color == "black")
    {
        rotateright(Z);
        Z->parent = Z;
        Z->right = Z->parent->right;
    }

    else if (Z->color == "red" && Z->parent->color == "red" && grandparent->color == "black")
    {
        rotateleft(grandparent);
        grandparent = Z->parent;
        Z->parent->left = grandparent->right;
    }
}
