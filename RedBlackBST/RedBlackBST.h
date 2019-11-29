#pragma once

enum class Color
{
	RED,
	BLACK
};

template<typename Key, typename Value>
class RedBlackBST
{
private:
	class Node
	{
	public:
		Node(Key const& k, Value const& v)
			: key(k), value(v),left(nullptr), 
			right(nullptr), N(1), color(Color::BLACK) {}
		Key key;
		Value value;
		Node* left;
		Node* right;
		Color color;
		int N;
	};
	Node* root;
public:
	RedBlackBST() :root(nullptr) {}

	// 存在该key则更新节点，否则插入节点
	void put(Key const& k, Value const& v)
	{
		root = put(root, k, v);
		root->color = Color::BLACK;
	}


private:
	// 判断节点颜色是否为红色
	bool isRed(Node const* const& h)
	{
		if (!h)
			return false;
		else
			return h->color == Color::RED;
	}

	// 左旋
	Node* rotateLeft(Node* const& h)
	{
		Node* x = h->right;
		h->right = x->left;
		x->left = h;
		x->N = h->N;
		x->color = h->color;
		h->color = Color::RED;
		h->N = size(h->left) + size(h->right) + 1;
		return x;
	}

	// 右旋
	Node* rotateRight(Node* const& h)
	{
		Node* x = h->left;
		h->left = x->right;
		x->right = h;
		x->N = h->N;
		x->color = h->color;
		h->color = Color::RED;
		h->N = size(h->left) + size(h->right) + 1;
		return x;
	}

	// 以该节点为根的树的大小
	int size(Node* h)
	{
		if (!h) return 0;
		return h->N;
	}

	// 节点左右子女均为红色，需转换颜色
	void flipColors(Node* h)
	{
		h->color		= Color::RED;
		h->left->color	= Color::BLACK;
		h->right->color = Color::BLACK;
	}
	Node* put(Node* h, Key const& k, Value const& v)
	{
		if (!h)
			return new Node(k, v);
		if (k < h->key)
		{
			put(h->left, k, v);
		}
		else if (k > h->key)
		{
			put(h->right, k, v);
		}
		else
		{
			h->value = v;
		}

		// 判断是否需要旋转

		// 该节点右子女为红色，左子女为黑色，需左旋
		if (isRed(h->right) && !isRed(h->left))
			h = rotateLeft(h);

		// 该节点左子女为红色，左子女的左子女也为红色，需右旋
		if (isRed(h->left) && isRed(h->left->left))
			h = rotateRight(h);

		// 该节点左右子女都为红色，则需转换颜色
		if (isRed(h->left) && isRed(h->right))
			flipColors(h);

		h->N = size(h->left) + size(h->right) + 1;
		return h;
	}


};

