#pragma once
#include "DataUtil.h"

typedef struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	Student* info;
}TreeNode;

TreeNode* createTreeNode(Student* info) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->info = info;
	node->right = node->left = NULL;
	return node;
}

void insertTreeNode(TreeNode** root, Student* info) {
	if (*root == NULL) {
		*root = createTreeNode(info);
	}
	else {
		if ((*root)->info->income > info->income)
			insertTreeNode(&(*root)->left, info);
		else if ((*root)->info->income < info->income)
			insertTreeNode(&(*root)->right, info);
	}
}

Student* getMax(TreeNode* root) {
	while (root->right)
		root = root->right;
	return root->info;
}

void postOrderPrint(TreeNode* root) {
	if (root == NULL) return;

	postOrderPrint(root->left);
	postOrderPrint(root->right);
	printf("Student: %s, income: %f\n", root->info->name, root->info->income);
}

void preOrderPrint(TreeNode* root) {
	if (root == NULL) return;

	printf("Student: %s, income: %f\n", root->info->name, root->info->income);
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}

void inOrderPrint(TreeNode* root) {
	if (root == NULL) return;

	inOrderPrint(root->left);
	printf("Student: %s, income: %f\n", root->info->name, root->info->income);
	inOrderPrint(root->right);
}

void DisplayTree(TreeNode* root, int level) {
	if (root != NULL) {
		for (int i = 1; i <= level; i++)
			printf("\t");
		printf("Student: %s, income: %f\n", root->info->name, root->info->income);
		level++;
		DisplayTree(root->left, level);
		DisplayTree(root->right, level);
	}
}

void deleteFullNode(TreeNode** root, TreeNode** rsubtree) {
	if ((*rsubtree)->left)
		deleteFullNode(root, &(*rsubtree)->left);
	else {
		TreeNode* tmp = (*rsubtree);
		(*root)->info = (*rsubtree)->info;
		(*rsubtree) = tmp->right;
		free(tmp);
	}
}

 void deleteNodeByKey(TreeNode** root, float key) { // income
	if (*root == NULL) return;

	if ((*root)->info->income > key)
		deleteNodeByKey(&(*root)->left, key);
	else if ((*root)->info->income < key)
		deleteNodeByKey(&(*root)->right, key);
	else {
		if ((*root)->left == NULL && (*root)->right == NULL) {
			deleteStudent((*root)->info);
			free((*root));
			*root = NULL;
		}
		else if ((*root)->left == NULL || (*root)->right == NULL){
			TreeNode* tmp = *root;
			*root = (*root)->left ? (*root)->left : (*root)->right;
			deleteStudent(tmp->info);
			free(tmp);
		}
		else {
			deleteFullNode(root, &(*root)->right);
		}
	}
}
