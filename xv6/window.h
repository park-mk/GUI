////////////////////////////////////////////////////File////////////////////////////////////////////////////////////////////////
#define UNCERTAIN 0
#define FILE 1
#define FOLDER 2
#define MAXNODE 100

struct node
{
	char* name;                   //�ļ������ļ��е�����
	int type;                     //FILE or FOLDER
	int childrenNum;              //����ڵ�Ϊ�ļ��У���¼�ļ������ļ������ļ��еĸ���

	node* Parent;                 //���ڵ㣬��ʾ���ڵ��ļ���
	node* FirstChild;             //�����ĵ�һ���ļ������ļ���
	node* Brother;                //�ֵܽڵ㣬����һ���ļ������ļ���
};

node* root;	                      //ȫ��ָ�룬��״�����ͷָ��
node memory[MAXNODE];             //�ɹ�������ڴ棬���ΪMAXNODE
int AvailableMemory;              //ʣ��ɹ�������ڴ���

void Initnode();
node* Newnode(int nodeType);
void Freenode(node* r);
int Addnode(node* parent, char* ch, int location, int nodeType);
int Deletenode(node* parent, int location);
void Renamenode(node* r, char* name);
node* Getnode(node* parent, int location);
int Removenode(node* parent, node* r);

////////////////////////////////////////////////window//////////////////////////////////////////////////////////////////////////////
#define MAXWINDOW 20
#define WINDOWWIDTH 600
#define WINDOWHEIGHT 400
#define ICON 0
#define LIST 1

struct window
{
	int wType;					         //�������ͣ�ͼ�����ͻ��б�����,��ʼʱΪ-1
	int xPos;                            //�������Ͻǵ�x����
	int yPos;                            //�������Ͻǵ�y����

	node* content;                       //�������ļ����ļ��������ͷָ��,content->FirstChildΪ��һ������
	int contentNum;                      //����ĳ��ȣ����������ļ����ļ��е��ܸ���
	int focusIndex;                      //λ�ڽ�����ļ����ļ��еĴ��򣬴�1��ʼ����

	window* pre;                         //���ڶ����е�ǰһ������
	window* next;                        //���ڶ����еĺ�һ������
};

window* windowHead;                      //���ڶ��е�ͷָ��,windowHead->nextΪ��һ������
window windowMemory[MAXWINDOW];          //�ɹ�����Ĵ������ͱ������ڴ棬����ͬʱ����MAXWINDOW��
int AvailableWindowMemory;               //ʣ��ɹ�����Ĵ��ڱ�������

void InitWindow();
window* NewWindow(int type);
void FreeWindow(window* w);
int AddWindow(int type);
int CloseWindow();
window* GetWindow(int location);
window* get_window_by_icon(int icon);
int FocusWindow(window* w);
int MoveWindow(window* w, int dx, int dy);
window* ClickWindow(int x, int y);
int setWindowType(window* w, int type);
int setWindowContent(window* w, node* r);



