// exam4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

struct rb_node
{
	rb_node *p;
	rb_node *lchild;
	rb_node *rchild;
	bool red;
	char s[8];
};

rb_node *tree = (rb_node *)malloc(sizeof(struct rb_node));
int cnt = 0, length = 0;

bool greater(char a[], char b[])
{
	for (int i = 0; i < length; i++)
	{
		if (0 < a[i] - b[i]) return 1;
		if (0 > a[i] - b[i]) return 0;
	}
	return 0;
}

bool equal(char a[], char b[])
{
	for (int i = 0; i < length; i++)
	{
		if (0 != a[i] - b[i]) return 0;
	}
	return 1;
}

void left_rotate(rb_node *pos)
{
	rb_node *tmp = (rb_node *)malloc(sizeof(struct rb_node));
	tmp = pos->rchild;
	pos->rchild = tmp->lchild;
	if (tmp->lchild != NULL)
	{
		tmp->lchild->p = pos;
	}
	tmp->p = pos->p;
	if (pos->p == NULL)
	{
		tree = tmp;
	}
	else if (pos = pos->p->lchild)
	{
		pos->p->lchild = tmp;
	}
	else pos->p->rchild = tmp;
	tmp->lchild = pos;
	pos->p = tmp;
}

void right_rotate(rb_node *pos)
{
	rb_node *tmp = (rb_node *)malloc(sizeof(struct rb_node));
	tmp = pos->lchild;
	pos->lchild = tmp->rchild;
	if (tmp->rchild != NULL)
	{
		tmp->rchild->p = pos;
	}
	tmp->p = pos->p;
	if (pos->p == NULL)
	{
		tree = tmp;
	}
	else if (pos = pos->p->rchild)
	{
		pos->p->rchild = tmp;
	}
	else pos->p->lchild = tmp;
	tmp->rchild = pos;
	pos->p = tmp;
}

void fixup(rb_node *pos)
{
	while (pos->p->red == 1)
	{
		if (pos->p->p != NULL)
		{
			if (pos->p == pos->p->p->lchild)
			{
				rb_node *tmp = (rb_node *)malloc(sizeof(struct rb_node));
				tmp = pos->p->p->rchild;
				if (tmp->red == 1)
				{
					pos->p->red = 0;
					tmp->red = 0;
					pos->p->p->red = 1;
					pos = pos->p->p;
				}
				else 
				{
					if (pos == pos->p->rchild)
					{
						pos = pos->p;
						left_rotate(pos);
					}
					pos->p->red = 0;
					pos->p->p->red = 1;
					right_rotate(pos->p->p);
				}

			}
			else
			{
				rb_node *tmp = (rb_node *)malloc(sizeof(struct rb_node));
				tmp = pos->p->p->lchild;
				if (tmp->red == 1)
				{
					pos->p->red = 0;
					tmp->red = 0;
					pos->p->p->red = 1;
					pos = pos->p->p;
				}
				else
				{
					if (pos == pos->p->lchild)
					{
						pos = pos->p;
						right_rotate(pos);
					}
					pos->p->red = 0;
					pos->p->p->red = 1;
					left_rotate(pos->p->p);
				}
			}
			if (pos->p == NULL) break;
		}
		
		
	}
	tree->red = 0;
}

void insertion(char given[])
{
	rb_node *tmp = (rb_node *)malloc(sizeof(struct rb_node));
	tmp->p = NULL;
	tmp->lchild = NULL;
	tmp->rchild = NULL;
	for (int i = 0; i < length; i++)
	{
		tmp->s[i] = given[i];
	}

	if (tree == NULL)
	{
		tree = tmp;
		tree->red = 0;
	}
	else
	{
		rb_node *pos = (rb_node *)malloc(sizeof(struct rb_node));
		pos = tree;
		while (true)
		{
			if (greater(tmp->s, pos->s))
			{
				if (pos->rchild == NULL)
				{
					pos->rchild = tmp;
					tmp->p = pos;
					break;
				}
				else pos = pos->rchild;
			}
			else
			{
				if (pos->lchild == NULL)
				{
					pos->lchild = tmp;
					tmp->p = pos;
					break;
				}
				else pos = pos->lchild;
			}
		}
		tmp->red = 1;
		fixup(tmp);
	}
}

void preorder_output(rb_node *pos)
{
	
	if (pos == NULL) return;
	for (int i = 0; i < length; i++)
	{
		std::cout << pos->s[i];
	}
	std::cout << ":";
	if (pos->red)
	{
		std::cout << "red";
	}
	else std::cout << "black";
	std::cout << std::endl;

	preorder_output(pos->lchild);
	preorder_output(pos->rchild);
}

void search(char target[])
{

	cnt = 0;
	rb_node *pos = (rb_node *)malloc(sizeof(struct rb_node));
	pos = tree;
	while (pos != NULL)
	{
		cnt++;
		if (equal(target, pos->s))
		{
			cnt--;
			break;
		}
		else if (greater(target, pos->s))
		{
			pos = pos->rchild;
		}
		else
		{
			pos = pos->lchild;
		}
	}
	std::cout << cnt << std::endl;
}

int main()
{
	int n, m;
	char given[8];
	char target[8];
	std::cin >> n >> m;
	tree = NULL;
	for (int i = 0; i < n; i++)
	{
		std::cin >> given;
		length = strlen(given);
		insertion(given);
	}
	preorder_output(tree);

	for (int i = 0; i < m; i++)
	{
		std::cin >> target;
		search(target);

	}

	return 0;
}