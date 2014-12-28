#define WindowWidth 660
#define WindowHeight 400
#define MaxNode 60
#define MaxWindow 20

///////////////////////////////////////////////////////////////Node//////////////////////////////////////////////////////////////////////////////
typedef struct Node
{
	int type;																    //1��ʾ�ļ���0��ʾ�ļ���
	struct Node* Parent;													    //�����
	struct Node* Firstchild;                                                    //��һ������
	struct Node* Lastchild;                                                     //���һ������
	struct Node* Brother;                                                       //�ֵܽ��
	char Name[30];                                                              //�������
} Node;

char* strcpy(char *s, char *t);                                                 //��tָ����ַ���������s�У����ؿ�������ַ���ָ��
void InitNode();																//��ʼ�����ռ�
struct Node* RequireNode();														//�����ڴ�ռ�
void ReleaseNode(struct Node* n);												//�ͷŽ��nָ����ڴ�ռ�  
int Add_Node(struct Node* currentNode, char* newName, int newType);				//���ָ�����ƺ����͵Ľ�㵽��ǰ��㴦
int Delete_Node(struct Node* p, int n);											//ɾ�����p�ĵ�n������
void Rename_Node(struct Node* p, char* newname);								//�����p�����Ƹ���Ϊnewname
struct Node* GetNode(struct Node* p, int n);                                    //��ý��p�ĵ�n������
int Remove_Node(struct Node* content, struct Node* old);                        //����old��contentĿ¼�£�����contentΪfolder

//////////////////////////////////////////////////////////////Window//////////////////////////////////////////////////////////////////////////////
typedef struct Window
{
	int Cur_icon;																  //��������
	int ChoosenOne;																  //�ں�����б�ѡ�����±�
	struct Node* Cur_Node;														  //�ں����ĸ����
	struct Window* next;														  //��һ������
	struct Window* pre;															  //��һ������
	int Pos_x;																	  //�������Ͻǵĺ�����
	int Pos_y;																	  //�������Ͻǵ�������
} Window;

void InitWindow();                                                 //��ʼ�������ڴ�ռ�           
struct Window* RequireWindow();									   //����һ�鴰���ڴ�ռ�
void ReleaseWindow(struct Window* w);                              //�ͷ�wָ����ڴ�ռ�  
struct Window* Add_Window(int icon);                               //���Ӵ�������Ϊicon�Ĵ���
void Close_Window();                                               //�رմ���
void Move_Window(struct Window* aim, int px, int py);              //�ƶ�aim���ڣ�����ֱ�Ϊpx.py
void Focus(struct Window* aim);                                    //��aimָ��Ĵ�������Ϊ��ǰ    
struct Window* Get_LastWindow();								   //�������һ������
struct Window* Click_Get_Window(int px, int py);				   //�����px,py)���ش���
struct Window* get_window_by_icon(int type);                       //���ص�һ����������Ϊtype�Ĵ���
void Set_Window_Node(struct Window* w, struct Node* node);        //��node����Ϊw���ں����
void Set_Window_Icon(struct Window* w, int type);                 //����w�Ĵ�������Ϊtype


////////////////////////////////////////////////////////////ȫ�ֱ���/////////////////////////////////////////////////////////////////////////////////
int NumOfNode;                                //������Ľ����
int NumOfWindow;                              //������Ĵ�����
struct Window window[MaxWindow];              //ģ��Ĵ����ڴ��
struct Node node[MaxNode];                    //ģ��Ľ���ڴ��
struct Window* WindowLine;                    //���ڶ���
struct Node* Root;                            //�����
struct Node* User_folder;                     //�û��ļ���
struct Node* Readme_file;                     //�ļ�



