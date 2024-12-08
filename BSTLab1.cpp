#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public:
		// the Node should contain
		// 	- an integer "key" that holds the value of the Node
		int key;
		// 	- a pointer to each child possible child node ("right" and "left")
		Node* left;
		Node* right;

		// Write a constructor for the Node
		// input: only an integer value for "key", no pointer arguments
		// 		right and left pointers should be null
		Node(int input){
			key = input;
			left = nullptr;
			right = nullptr;
		}

};


// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
	// root
	Node *root = new Node(13);

	// level 1 (children of root)
	root->left = new Node(0);
	root->right = new Node(21);
	// level 2 (children of 0)
	root->left->left = new Node(-2);
	root->left->right = new Node (7);
	// level 2 (children of 21)
	root->right->left = new Node(15);
	root->right->right = new Node(99);
	// level 3 (children of -2)
	root->left->left->right = new Node(-1);
	// level 3 (children of 7)
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(12);
	// level 3 (children of 15)
	root->right->left->right = new Node(18);
	// level 3 (children of 99)
	// level 4 (children of 18)
	root->right->left->right->right = new Node(19);

	return root;
}

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {
	bool leftExists, rightExists;
	leftExists = (root->left != nullptr) ? true : false;
	rightExists = (root->right != nullptr) ? true : false;

	// Base cases
	if(root->key == target){
		return true;
	}
	
	if(leftExists == false and rightExists == false){
		return false;
	}
	
	// General case
	if(leftExists and rightExists){
		if(target < root->key){
			return searchTree(target, root->left);
		} else {
			return searchTree(target, root->right);
		}
	}

	if(leftExists){
		return searchTree(target, root->left);
	}

	if(rightExists){
		return searchTree(target, root->right);
	}
	
	//This should never happen
	return false;
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
	if(root == nullptr){
		return 0;
	}

	int output = 1;
	// base case
	if(root->left == nullptr and root->right == nullptr){
		return output;
	}

	// General case
	if(root->left != nullptr){
		output += treeSize(root->left);
	}

	if(root->right != nullptr){
		output += treeSize(root->right);
	}

	return output;

}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {

	if(root == nullptr){
		return 0;
	}

	int output = 0;
	int leftLength = 0;
	int rightLength = 0;
	// base case
	if(root->left == nullptr and root->right == nullptr){
		return output;
	} else {
		output++;
	}

	if(root->right != nullptr){
		rightLength = treeHeight(root->right) + output;
	}if(root->left != nullptr){
		leftLength = treeHeight(root->left) + output;
	}

	return (leftLength >= rightLength) ? leftLength : rightLength;
}
