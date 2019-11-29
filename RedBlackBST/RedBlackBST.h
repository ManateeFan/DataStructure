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

	// ���ڸ�key����½ڵ㣬�������ڵ�
	void put(Key const& k, Value const& v)
	{
		root = put(root, k, v);
		root->color = Color::BLACK;
	}


private:
	// �жϽڵ���ɫ�Ƿ�Ϊ��ɫ
	bool isRed(Node const* const& h)
	{
		if (!h)
			return false;
		else
			return h->color == Color::RED;
	}

	// ����
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

	// ����
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

	// �Ըýڵ�Ϊ�������Ĵ�С
	int size(Node* h)
	{
		if (!h) return 0;
		return h->N;
	}

	// �ڵ�������Ů��Ϊ��ɫ����ת����ɫ
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

		// �ж��Ƿ���Ҫ��ת

		// �ýڵ�����ŮΪ��ɫ������ŮΪ��ɫ��������
		if (isRed(h->right) && !isRed(h->left))
			h = rotateLeft(h);

		// �ýڵ�����ŮΪ��ɫ������Ů������ŮҲΪ��ɫ��������
		if (isRed(h->left) && isRed(h->left->left))
			h = rotateRight(h);

		// �ýڵ�������Ů��Ϊ��ɫ������ת����ɫ
		if (isRed(h->left) && isRed(h->right))
			flipColors(h);

		h->N = size(h->left) + size(h->right) + 1;
		return h;
	}


};

