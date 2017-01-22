/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
struct Node {
int data;
Node* left;
Node* right;
}
*/
bool reallyCheckBST(Node *node, int min, int max) {
	if (node == nullptr)
		return true;
	if (node->data <= min || node->data >= max)
		return false; //Not a Binary Search Tree
	return reallyCheckBST(node->left, min, node->data) && reallyCheckBST(node->right, node->data, max);
}

bool checkBST(Node* root) {
	return reallyCheckBST(root, -32767, 32768);
}
