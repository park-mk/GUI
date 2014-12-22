#include <cstdlib>
#include "window.h"
//using namespace std;

///////////////////////////////////////////////////////////file//////////////////////////////////////////////////////////////////////

//��ʼ���ڴ�
//����ռ��root
void Initnode()
{
	AvailableMemory = MAXNODE;
	for (int i = 0; i < MAXNODE; i++)
	{
		memory[i].name = 0;
		memory[i].type = UNCERTAIN;
		memory[i].childrenNum = 0;
		memory[i].Parent = 0;
		memory[i].FirstChild = 0;
		memory[i].Brother = 0;
	}

	AvailableMemory--;
	memory[0].name = "Root";
	memory[0].type = FOLDER;

	root = &memory[0];
}

//����һ���������ΪnodeType���ļ������ļ���
//����ָ���������ڴ�ռ��ָ��
node* Newnode(int nodeType)
{
	if (AvailableMemory == 0 || (nodeType != 1 && nodeType != 2))
		return 0;

	int i = 0;
	while (memory[i].type != UNCERTAIN)
		i++;
	memory[i].type = nodeType;
	AvailableMemory--;

	node* p = &memory[i];
	return p;
}

//�ͷ�rָ����ڴ�ռ�
//AvailableMemory++
void Freenode(node* r)
{
	r->name = 0;
	r->type = UNCERTAIN;
	r->childrenNum = 0;
	r->Parent = 0;
	r->FirstChild = 0;
	r->Brother = 0;
	AvailableMemory++;
}

//��parentĿ¼���½��ļ������ļ���
//����Ϊch����Ϊparent�ĵ�location������
int Addnode(node* parent, char* ch, int location, int nodeType)
{
	if (parent->type != FOLDER)
		return -1;

	if (parent->childrenNum < location - 1)
		return -2;

	if (nodeType != FILE && nodeType != FOLDER)
		return -3;

	node* r = Newnode(nodeType);
	if (!r)
		return -4;

	r->name = ch;
	r->Parent = parent;
	
	node* t = parent->FirstChild;
	for (int i = 1; i < location; i++)
		t = t->Brother;
	r->Brother = t;

	parent->childrenNum++;
	if (location == 1)
		parent->FirstChild = r;
	else
	{
		t = parent->FirstChild;
		for (int i = 1; i < location - 1; i++)
			t = t->Brother;
		t->Brother = r;
	}
	return 0;
}

//ɾ��parentĿ¼�µĵ�location������
//����ó����쳣����-1��-2�����򷵻�0
int Deletenode(node* parent, int location)
{
	if (parent->type != FOLDER)
		return -1;
	if (location > parent->childrenNum || location < 1)
		return -2;

	node* t = parent->FirstChild;
	for (int i = 1; i < location; i++)
		t = t->Brother;
	
	if (location > 1)
	{
		node* r = parent->FirstChild;
		for (int i = 1; i < location - 1; i++)
			r = r->Brother;
		r->Brother = t->Brother;
	}
	else //location = 1
	{
		parent->FirstChild = t->Brother;
	}
	parent->childrenNum--;

	Freenode(t);
	return 0;
}

//�����r��name��Ϊname
void Renamenode(node* r, char* name)
{
	r->name = name;
}

//�õ�parent�ĵ�location�����
//����ָ��ý���ָ��
node* Getnode(node* parent, int location)
{
	if (parent->childrenNum < location)
		return 0;

	node* t = parent->FirstChild;
	for (int i = 1; i < location; i++)
		t = t->Brother;

	return t;
}

//��r���Ƶ�parentĿ¼��,����Ϊparent�ĵ�һ�����
//�������쳣������-1�����򷵻�0
int Removenode(node* parent, node* r)
{
	if (parent->type != FOLDER)
		return -1;

	node* t = Newnode(r->type);
	t->name = r->name;
	t->childrenNum = r->childrenNum;
	t->Parent = parent;
	t->FirstChild = r->FirstChild;

	parent->childrenNum++;
	if (parent->FirstChild == 0)
	{
		parent->FirstChild = t;
		t->Brother = 0;
	}
	else
	{
		t->Brother = parent->FirstChild;
		parent->FirstChild = t;
	}

	if (t->type == FILE)
		return 0;
	else
	{
		node* ptr = r->FirstChild;
		while (ptr != 0)
		{
			Removenode(t, ptr);
			ptr = ptr->Brother;
		}
	}
	return 0;
}

///////////////////////////////////////////////////window/////////////////////////////////////////////////////////////////////////////
//��ʼ���ڴ�
//Ϊ���ڶ��е�ͷָ�����һ���ڴ�
void InitWindow()
{
	for (int i = 0; i < MAXWINDOW; i++)
	{
		windowMemory[i].wType = -1;
		windowMemory[i].xPos = 0;
		windowMemory[i].yPos = 0;
		windowMemory[i].content = 0;
		windowMemory[i].contentNum = 0;
		windowMemory[i].focusIndex = 0;
		windowMemory[i].pre = 0;
		windowMemory[i].next = 0;
	}
	AvailableWindowMemory = MAXWINDOW;

	windowHead = NewWindow(0);
}

//��������Ϊtype�Ĵ���
//����ֵΪ���ڵ�ָ��
window* NewWindow(int type)
{
	if (AvailableWindowMemory <= 0 || (type != ICON && type != LIST))
		return 0;

	int i;
	for (i = 0; i < MAXWINDOW; i++)
	{
		if (windowMemory[i].wType == -1)
			break;
	}
	windowMemory[i].wType = type;
	AvailableWindowMemory--;
	return (&windowMemory[i]);
}

//�ͷ�wָ��Ĵ������ڵ��ڴ�ռ�
void FreeWindow(window* w)
{
	w->wType = -1;
	w->xPos = 0;
	w->yPos = 0;
	w->content = 0;
	w->contentNum = 0;
	w->focusIndex = 0;
	w->pre = 0;
	w->next = 0;
	AvailableWindowMemory++;
}

//��Ӵ��ڣ��½����ڵ�����Ϊtype
//���뵽���ڶ��еĶ���
int AddWindow(int type)
{
	if (type != ICON && type != LIST)
		return -1;
	if (AvailableWindowMemory <= 0)
		return -2;

	window* w = NewWindow(type);
	if (!w)
		return -3;

	if (windowHead->next == 0)
	{
		windowHead->next = w;
		w->pre = windowHead;
		w->xPos = 0;
		w->yPos = 0;
	}
	else
	{
		w->next = windowHead->next;
		windowHead->next = w;
		w->pre = windowHead;
		w->next->pre = w;

		w->xPos = w->next->xPos + 20;
		w->yPos = w->next->yPos + 20;
	}
	return 0;
}

//�رն��״���
int CloseWindow()
{
	if (windowHead->next == 0)
		return -1;

	window *w = windowHead->next;
	windowHead->next = w->next;
	if (w->next)
		w->next->pre = windowHead;

	FreeWindow(w);
	return 0;
}

//�õ������е�location�����ڵ�ָ��
window* GetWindow(int location)
{
	int index = 1;
	window* ptr = windowHead->next;
	while(ptr != NULL && index < location)
	{
		ptr = ptr->next;
		index++;
	}
	return ptr;
}

//��w�ŵ����еĶ��ף�����Ϊ�۽�
int FocusWindow(window* w)
{
	if (!w)
		return -1;

	window* pre = w->pre;

	if (!pre)
		return -2;

	pre->next = w->next;
	if (w->next)
	{
		w->next->pre = pre;
	}

	window* t = windowHead->next;
	windowHead->next = w;
	w->next = t;
	t->pre = w;
	w->pre = windowHead;
	return 0;
}

//������w��x�����ƶ�dx����y�����ƶ�dy
int MoveWindow(window* w, int dx, int dy)
{
	if (!w)
		return -1;
	w->xPos += dx;
	w->yPos += dy;
	return 0;
}

//�����������x,y)ʱ���еĴ��ڵ�ָ��
window* ClickWindow(int x, int y)
{
	window* ptr;
	for (ptr = windowHead->next; ptr != 0; ptr = ptr->next)
	{
		if (x >= ptr->xPos && x <= ptr->xPos + WINDOWWIDTH && y >= ptr->yPos && y <= ptr->yPos + WINDOWHEIGHT)
			break;
	}
	return ptr;
}

//���ô���w������Ϊtype
int setWindowType(window* w, int type)
{
	if (!w)
		return -1;
	if (type < 0)
		return -2;

	w->wType = type;
	return 0;
}

//���ô���w������Ϊrָ�������
int setWindowContent(window* w, node* r)
{
	if (!w)
		return -1;
	
	w->content = r;
	return 0;
}

//int main(int argc, char* argv[])
//{
//	////////////////////////test node module///////////////////////////
//	Initnode();
//	Addnode(root, "Folder1", 1, FOLDER);
//	Addnode(root, "Folder2", 2, FOLDER);
//	Addnode(root, "Folder3", 3, FOLDER);
//	Deletenode(root, 3);
//	
//	Addnode(Getnode(root, 2), "File1", 1, FILE);
//	Renamenode(Getnode(root, 1), "Folder3");
//
//	Removenode(Getnode(root, 1), Getnode(Getnode(root, 2), 1));
//
//	///////////////////////test window module///////////////////////////
//	InitWindow();
//	AddWindow(1);
//	AddWindow(2);
//	CloseWindow();
//	AddWindow(3);
//	FocusWindow(GetWindow(2));
//	setWindowContent(GetWindow(1), root);
//
//	system("pause");
//	return 0;
//}