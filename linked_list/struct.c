#include <stdlib.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node * next;
}* first = NULL; //可直接在struct definition 後面接變數宣告

void create_LL(int A[],int n)
{
  int i = 0;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data  = A[0];
  first->next = NULL;
  last = first;

  for(i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t; //link list上的節點先指向新結點
    last = t; // 最後新結點成為list上最後一個節點
  }

}

int Count(struct Node *p) //計算linked list 長度
{
  int l = 0;
  while(p)
  {
    l++;
    p = p->next;
  }
  return l;
}

int Sum(struct Node * p)
{
  int s = 0;
  while(!p)
  {
    s+= p->data;
    p = p->next;
  }
  return s;
}

void Display(struct Node * n)
{
  while(n){
    printf("%d\n", n->data);
    n = n->next;
  }
}

struct Node * Search(struct Node *p, int key){ //linear search
  while(p != NULL)
  {
    if(key == p->data)
    {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

struct Node * Search_Improve(struct Node *p, int key)
{
  //  當某節點被搜尋到時，把此節點移至首節點，讓下次更快被搜尋到
  struct Node *q = NULL;
  while(p != NULL)
  {
    if(key == p->data)
    { 
      q->next = p->next;
      p->next = first;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}

void Insert(struct Node *p, int index, int key)
{
  // insert before first node O(1)
  struct Node * t;
  int i;
  if (index < 0 || index > Count(p))
  {
    return;
  }else
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;

    if(index == 0)
    {
      t->next = first;
      first = t;
    }
    else
    {
      for(i = 0;i < index;i++)
      {
        p = p->next;
      }
      t->next = p->next;
      p->next = t;
    }
  }
}

int main() {
  struct Node * head = NULL,* temp;
  int datas[10] = {1,2,3,4,5,6,7,8,9,10};

  create_LL(datas, 10);
  Insert(first, 0, 22);
  Display(first);

  return 0;
}