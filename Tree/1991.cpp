#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

class Node {
public :
	char leftChild;
	char rightChild;
};

void preOrder(vector<Node>& tree, char cur);
void inOrder(vector<Node>& tree, char cur);
void postOrder(vector<Node>& tree, char cur);

int problem1991() {
	int n;
	cin >> n;

	vector<Node> tree(127);
	for (int i = 0; i < n; ++i) {
		char p, l, r;
		cin >> p >> l >> r;

		if (isalpha(l))
			tree[p].leftChild = l;

		if (isalpha(r))
			tree[p].rightChild = r;

	}

	preOrder(tree, 'A');
	cout << "\n";

	inOrder(tree, 'A');
	cout << "\n";

	postOrder(tree, 'A');

	return 0;
}

void preOrder(vector<Node>& tree, char cur) {
	/* root -> left -> right */

	cout << cur;

	if (tree[cur].leftChild > 0)
		preOrder(tree, tree[cur].leftChild);

	if (tree[cur].rightChild > 0)
		preOrder(tree, tree[cur].rightChild);
}

void inOrder(vector<Node>& tree, char cur) {
	/* left -> root -> right*/

	if (tree[cur].leftChild > 0)
		inOrder(tree, tree[cur].leftChild);

	cout << cur;

	if (tree[cur].rightChild > 0)
		inOrder(tree, tree[cur].rightChild);
}

void postOrder(vector<Node>& tree, char cur) {
	/* left -> right -> root */

	if (tree[cur].leftChild > 0)
		postOrder(tree, tree[cur].leftChild);

	if (tree[cur].rightChild > 0)
		postOrder(tree, tree[cur].rightChild);

	cout << cur;
}