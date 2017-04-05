# include <iostream>

using namespace std;

struct  BinaryTreeNode
{
	int value;
	BinaryTreeNode * pLeft;
	BinaryTreeNode * pRight;
};

BinaryTreeNode * ConstructCore(int * startPreorder, int * endPreorder,
	int * startInorder, int * endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode * root = new BinaryTreeNode();
	root->value = rootValue;
	root->pLeft = root->pRight = NULL;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder &&
			*startPreorder == *startInorder)
			return root;
		else
			throw new exception("Invaild input");
	}

	int * rootInorder = startInorder;
	while (rootInorder < endInorder && *rootInorder != rootValue)
	{
		++rootInorder;
	}

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw new exception("Invaild input");

	int leftLength = rootInorder - startInorder;
	int * leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0)
		root->pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, 
		startInorder, rootInorder - 1);

	if (leftLength < endPreorder - startPreorder)
		root->pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, 
		rootInorder + 1, endInorder);

	return root;
}

BinaryTreeNode * Construct(int * preorder, int * inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void Preorder(BinaryTreeNode * root)
{
	if (root)
	{
		cout << root->value << endl;
		Preorder(root->pLeft);
		Preorder(root->pRight);
	}
}

int main()
{
	int preorder[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode * root = Construct(preorder, inorder, 8);
	Preorder(root);
	return 0;
}