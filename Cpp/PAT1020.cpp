#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* lchild=NULL;
	Node* rchild=NULL;
};
int post[30] = {0};
int in[30] = {0};
Node* dfs(int prel,int prer,int inl,int inr) {
	int i;                                                                                                                     
	Node* T=new Node;
	T->data = post[prer];
	for (i = inl; i<=inr; ++i) {
		if (in[i]==post[prer])
			break;
	}
	if(i>inl)
		T->lchild=dfs(prel, i-1-inl+prel, inl, i - 1);
	if(i<inr)
		T->rchild=dfs(i-inl+prel,prer-1,i+1,inr);
	return T;
}
void bfs(Node* T) {
	queue<Node*> q;
	q.push(T);
	printf("%d",T->data);
	while(!q.empty()) {
		Node* temp=q.front();
		q.pop();
		if (temp->lchild != NULL) {
			q.push(temp->lchild);
			printf(" %d", temp->lchild->data);
		}
		if (temp->rchild != NULL) {
			q.push(temp->rchild);
			printf(" %d", temp->rchild->data);
		}
	}
}
int main() {
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i<n; ++i)
		scanf("%d", &post[i]);
	for (i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	Node* root = dfs(0, n - 1, 0, n - 1);
	bfs(root);
	return 0;
}
