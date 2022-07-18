#include <iostream>
using namespace std;

int inorder[100001], postorder[100001], inorder_index[100001];
void getPreorder(int is, int ie, int ps, int pe);

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
		inorder_index[inorder[i]] = i;
	}
	for (int j = 1; j <= n; j++) {
		cin >> postorder[j];
	}

	getPreorder(1, n, 1, n);
	return 0;
}

void getPreorder(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe)
		return;

	int rootIndex = inorder_index[postorder[pe]];
	int leftSize = rootIndex - is;
	int rightSize = ie - rootIndex;

	cout << postorder[pe] << " ";

	getPreorder(is, rootIndex - 1, ps, ps + leftSize - 1);
	getPreorder(rootIndex + 1, ie, ps + leftSize, pe - 1);
}
