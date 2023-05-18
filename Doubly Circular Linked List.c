/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  School of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
//<stdio.h>�� <stdlib.h>�� ������ ���� �ҽ��� Ȯ���ϵ��� ����
/* �ʿ��� ������� �߰� */

//listNode ����ü ����
typedef struct Node {
	int key;	//�ش� node�� key��
	struct Node* llink;	//�ش� node�� llink
	struct Node* rlink;	//�ش� node�� rlink
} listNode;

/* �Լ� ����Ʈ */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);

//Circular Double ���Ḯ��Ʈ�� �����Լ�
int main()
{
	char command;	//����ڷκ��� �Է¹��� command�� ������ ����
	int key;	//����ڷκ��� �Է¹��� key���� ������ ����
	int count = 0;	//Initialize�� ����ǵ��� �ϴ� ����
	listNode* headnode=NULL;
	//listNode �����ͺ��� headnode����


	do{//command�� q or Q�� �Էµɶ����� �ݺ��ϴ� do-while��
		//�޴� ���
		printf("------------------[Byeun jaeyun] [2021041023]-------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//����ڷκ��� command�� �Է¹���

		switch(command) {	//command�� �������� �����ϴ� switch��
		case 'z': case 'Z':	//command�� z or Z �϶�
			initialize(&headnode);
			count++;	//count�� ���� (���� �ٸ� �޴� ���డ��)
			break;
		case 'p': case 'P':	//command�� p or P �϶�
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}

			printList(headnode);
			break;
		case 'i': case 'I':	//command�� i or I �϶�
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':	//command�� d or D �϶�
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':	//command�� n or N �϶�
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':	//command�� e or E �϶�
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			deleteLast(headnode);
			break;
		case 'f': case 'F':	//command�� f or F �϶�
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':	//command�� t or T �϶�
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			deleteFirst(headnode);
			break;
		case 'r': case 'R':	//command�� r or R �϶�
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			invertList(headnode);
			break;
		case 'q': case 'Q':	//command�� q or Q �϶�
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;	//0 ��ȯ
}

//���Ḯ��Ʈ�� �����ϴ� �Լ�
int initialize(listNode** h) 
{

	/* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	if(*h != NULL)	
		freeList(*h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	*h = (listNode*)malloc(sizeof(listNode));
	//h�� �����Ҵ�
	(*h)->rlink = *h;
	(*h)->llink = *h;
	//h�� rlink�� llink�� ��� �ڽ��� ����Ű�� ����
	(*h)->key = -9999;
	//h�� key���� -9999 ����
	return 0;	//0 ��ȯ
}

/* �޸� ���� */
//���Ḯ��Ʈ�� �޸𸮸� ������Ű�� �Լ�
int freeList(listNode* h)
{
	listNode *p = h->rlink;
	//listNode ������ ���� p ������ h�� rlink ����
	listNode *prev = NULL;
	//listNode ������ ���� prev ����

	while(p!=NULL&&p!=h)	//p�� NULL�� �ƴϰ�, h�� �ƴҶ� �ݺ��ϴ� while��
	{
		prev = p;
		p = p->rlink;	//p�� rlink�������� �̵���Ű�� 
		free(prev);		//�ϳ��� free
	}
	free(h);	//���������� h�� free

	return 0;	//0 ��ȯ
}

//���Ḯ��Ʈ�� ����ϴ� �Լ�
void printList(listNode* h) 
{
	int i = 0;	
	listNode* p = NULL;
	//listNode ������ ���� p ����

	printf("\n---PRINT\n");

	if(h == NULL)
	{	//���Ḯ��Ʈ�� ���������
		printf("Nothing to print....\n");	//���� �޼��� ���
		return;
	}

	p = h->rlink;	//p�� h�� rlink�� ����

	while(p != NULL && p != h) {	//p�� NULL�� �ƴϰ�, h�� �ƴҶ� ���� �ݺ��ϴ� while��
		printf("[ [%d]=%d ] ", i, p->key);	//index�� �ش� ����� key�� ���
		p = p->rlink;	//p�� rlink�� �̵�
		i++;	//i�� ����
	}
	printf("  items = %d\n", i);	//�� ������ ���� ���


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);
	//headnode�� llink,rlink ���� �ּҰ� ���

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {	//p�� NULL�� �ƴϰ�, h�� �ƴҶ� ���� �ݺ��ϴ� while��
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		//�ش� node�� llink,rlink ���� �ּҰ� ���
		p = p->rlink;	//rlink�� p�� �̵�
		i++;	//i�� ����
	}

}



//���Ḯ��Ʈ�� �������� ��带 �߰��ϴ� �Լ�
int insertLast(listNode* h, int key) 
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	//listNode �����ͺ��� node���� �� �����Ҵ�
	node->key = key;	//node�� key���� ����ڷκ��� �Է¹��� key�� ����
	node->rlink = NULL;
	node->llink = NULL;
	//node�� rlink�� llink��� NULL�� �ʱ�ȭ

	if(h->rlink==h)	//���Ḯ��Ʈ�� ���������
	{
		h->rlink = node;	//h�� rlink�� node�� ����
		h->llink = node;	//h�� llink�� node�� ����
		node->rlink = h;	//node�� rlink�� h�� ����
		node->llink = h;	//node�� llink�� h�� ����
		return 0;	//0 ��ȯ
	}

	listNode *n = h->llink;
	//listNode ������ ���� n�� ���� �� h->llink ����

	n->rlink = node;	//n�� rlink�� node�� ����
	h->llink = node;	//h�� llink�� node�� ����
	node->rlink = h;	//node�� rlink�� h ����
	node->llink = n;	//node�� llink�� n ����
	return 0;	//0 ��ȯ
}


//���Ḯ��Ʈ ���������� ��带 �����ϴ� �Լ�
int deleteLast(listNode* h) 
{
	if(h->rlink == h) {	//���Ḯ��Ʈ�� ���������
		printf("Nothing to delete....\n");	//���� �޼��� ���
		return 1;	//1 ��ȯ
	}
	
	listNode* n = h;
	listNode* trail = NULL;
	//listNode ������ ���� n,trail ���� �� �ʱ�ȭ

	if(n->rlink->rlink == n)//���Ḯ��Ʈ�� ���� �Ѱ��϶�
	{
		trail = n->rlink;	//trail�� n�� rlink ����
		free(trail);	//trail free
		n->rlink = n;	//n�� rlink�� n����
		n->llink = n;	//n�� llink�� n����
		
		return 0;	//0 ��ȯ
	}

	n = n->llink;	//n�� n�� llink ����
	trail = n->llink;	//trail�� n�� llink ����
	trail->rlink = h;	//trail�� rlink�� h ����
	h->llink = trail;	//h�� llink�� trail ����
	free(n);	//n free

	return 0;	//0 ��ȯ
}


//���Ḯ��Ʈ�� ó���� ��带 �߰��ϴ� �Լ�
int insertFirst(listNode* h, int key) 
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	//listNode ������ ���� node ������ ���� �Ҵ�
	node->key = key;	//node�� key�� ����ڷκ��� �Է¹��� key�� ����
	node->rlink = NULL;
	node->llink = NULL;
	//node�� rlink�� llink �ʱ�ȭ

	if(h->rlink==h)	//���Ḯ��Ʈ�� ���������
	{
		h->rlink = node;
		h->llink = node;
		node->rlink = h;
		node->llink = h;
		return 0;
	}

	listNode *n = h;
	//listNode �����ͺ��� n ���� �� h ����

	n = n->rlink;

	n->llink = node;
	h->rlink = node;
	node->rlink = n;
	node->llink = h;
	return 0; // 0 ��ȯ
}

//���Ḯ��Ʈ�� ó������ ��带 �����ϴ� �Լ�
int deleteFirst(listNode* h) 
{
	if(h->rlink == h) {	//���Ḯ��Ʈ�� ���������
		printf("Nothing to delete....\n");	//���� �޼��� ���
		return 1;	//1 ��ȯ
	}
	
	listNode* n = h;
	listNode* trail = NULL;
	//listNode �����ͺ��� n�� trail ���� �� �ʱ�ȭ

	if(n->rlink->rlink == n)	//���Ḯ��Ʈ�ȿ� ���� �ϳ��϶�
	{
		trail = n->rlink;
		free(trail);
		n->rlink = n;
		n->llink = n;
		
		return 0;
	}

	n = n->rlink;
	trail = n->rlink;
	trail->llink = h;
	h->rlink = trail;
	free(n);

	return 0;	// 0 ��ȯ
}


//���Ḯ��Ʈ�� �������� ��ġ�ϴ� �Լ�
int invertList(listNode* h) 
{
	if(h->rlink == h) {	//���Ḯ��Ʈ�� ���������
		printf("Nothing to invert....\n");	//���� �޼��� ���
		return 1;	//1 ��ȯ
	}

	listNode* temp = h;
	listNode* front = NULL;
	listNode* back = NULL;
	//listNode ������ ���� temp,front,back ����

	do{//temp�� h���ɶ����� �ݺ��ϴ� do-while��
		front = temp->rlink;	//front�� temp�� rlink ����
		back = temp->llink;		//back�� temp�� llink ����

		temp->rlink = back;		//temp�� rlink�� back�� ����
		temp->llink	= front;	//temp�� llink�� front�� ����

		temp = temp->llink;		//temp�� llink�� �̵�
	}while(temp != h);

	return 0;	//0 ��ȯ
}



/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(listNode* h, int key) 
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	//listNode �����ͺ��� node ���� �� �����Ҵ�
	node->key = key;	//node�� key�� ����ڷκ��� �Է¹��� key�� ����
	node->rlink = NULL;
	node->llink = NULL;
	//node�� rlink�� llink �ʱ�ȭ

	if(h->rlink== h)	//���Ḯ��Ʈ�� ���������
	{
		h->rlink = node;
		h->llink = node;
		node->rlink = h;
		node->llink = h;
		return 0;
	}

	listNode *temp = h->rlink;
	//listNode ������ ���� temp ���� �� h->rlink ����

	//���Ḯ��Ʈ�� ������� ������
	while(temp != h)	//temp�� h�� �ɶ����� �ݺ��ϴ� while��
	{
		if(temp->key > node->key)	//temp->key�� node->key ���� Ŭ��
		{
			node->rlink = temp;	//node�� rlink�� temp����
			node->llink = temp->llink;	//node�� llink�� temp�� llink����
			temp->llink->rlink = node;	//temp�� llink�� rlink�� node ����
			temp->llink = node;	//temp�� llink�� node ����
			return 0;	//0 ��ȯ
		}

		temp = temp->rlink;	//temp�� rlink�� �̵�
	}

	node->rlink = temp;	//node�� rlink�� temp ����
	node->llink = temp->llink;	//node�� llink�� temp�� llink ����
	temp->llink->rlink = node;	//temp�� llink�� rlink�� node ����
	temp->llink = node;	//temp�� llink�� node ����
	return 1;	//1 ��ȯ
}


//����ڷκ��� key���� �Է¹޾� �ش� ��带 �����ϴ� �Լ�
int deleteNode(listNode* h, int key) 
{
	if(h->rlink == h) {	//���Ḯ��Ʈ�� ���������
		printf("Nothing to delete....\n");	//���� �޼��� ���
		return 1;	//1 ��ȯ
	}

	listNode* temp = h->rlink;
	listNode* front = NULL;
	listNode* back = NULL;
	//listNode �����ͺ��� temp,front,back ����

	while(temp != h)	//temp�� h�� �ɶ����� �ݺ��ϴ� while��
	{
		back = temp->llink;	//back�� temp�� llink����
		front = temp->rlink;	//front�� temp�� rlink ����

		if(temp->key == key)	//temp�� key�� ����ڰ� �Է��� key�� ���� ������
		{
			back->rlink = front;	//back�� rlink�� front����
			front->llink = back;	//front�� llink�� back����
			free(temp);	//temp free
			return 0;	//0��ȯ
		}

		temp = temp->rlink;	//temp�� rlink�� �̵�
	}

	//key�� ���� ���Ḯ��Ʈ�� ������
	printf("Check the key value.\n");	//���� �޽��� ���
	
	return 1;	//1 ��ȯ
}