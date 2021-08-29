/*------------------------��5��	�绰������1.0-----------------------------*/
#include<fstream>       
#include<conio.h>
#include<iostream>  //����û�м� .h �Ķ���Ϊ����Ӧ visual studio���������������еü���
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cstring>
#include<vector>
#include <windows.h>
#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include<stdio.h>
#include<math.h>
#include<tchar.h>
#include <atlconv.h>
#include <MMSystem.h>//ͷ�ļ���Сд����ʶ��;��������mci��Ҫ��ͷ�ļ�
#pragma comment(lib,"winmm.lib")//����winmm.lib���ļ�
using namespace std;
#pragma warning(disable : 4996)          
//visual studio��ʹ��strcat�ᱨ��ȫ���󣬴�����������Ӵ��󣬵��������������п��ܻ᲻ʶ��˾仰��ע��ɾ��

/*******************�궨��***********************/

#define NULL 0    

/******************����ͼƬ**********************/
IMAGE welcome;//��ӭ����
IMAGE add;
IMAGE add_display;
IMAGE search;
IMAGE search_choose;
IMAGE search_fullname;
IMAGE search_lastname;
IMAGE search_firstname;
IMAGE search_back;
IMAGE search_str;
IMAGE search_firstname_display;
IMAGE search_firstname_display_back;
IMAGE search_firstname_display_str;
IMAGE search_lastname_display_back;
IMAGE search_lastname_display;
IMAGE search_lastname_display_fullname;
IMAGE search_str_display_firstname;
IMAGE search_str_display_back;
IMAGE search_str_display;
IMAGE display_png;
IMAGE display_choise_alllist;
IMAGE display_choise_back;
IMAGE display_choise_somelist;
IMAGE display_choise;
IMAGE display_list_all_back;
IMAGE display_list_all_somelist;
IMAGE display_list_all;
IMAGE display_list_some_all;
IMAGE display_list_some_back;
IMAGE display_list_some;
IMAGE search_fullname_display;
IMAGE search_fullname_display_lastname;
IMAGE search_fullname_display_back;
IMAGE replace_list_back;
IMAGE replace_list;
IMAGE help_png;
IMAGE help_back;
IMAGE help;
IMAGE delete_png;
IMAGE replace_png;
IMAGE delete_choise;
IMAGE delete_choise_fullname;
IMAGE delete_choise_fullname_display_back;
IMAGE delete_choise_all;
IMAGE delete_choise_fullname_display;
IMAGE delete_choise_back;

/*******************�ඨ��***********************/

/*�����¼��friend_node*/
class  friend_node
{
private:
    int year;//����¼��ʱ����
    int month; //����¼��ʱ����
    int day; //����¼��ʱ����
    int hour; //����¼��ʱ��Сʱ
    int minute; //����¼��ʱ�����
    int second;//����¼��ʱ����
    wchar_t last_name[20];  //������
    wchar_t first_name[15];  //������
    wchar_t phone_num[12];  //����绰����
    wchar_t time_num[50];//��������
    friend_node* prev;
    friend_node* next;          //��ʾ˫����ṹ��*prev,*nextָ��
public:
    void page(); //��ӭ���溯��
    void handle_choice();//�����û�ѡ�������Ӧ����
    void add_record();              // ����һ���½ڵ�
    void insert_node(friend_node* new_rec_ptr);     //���½ڵ��������
    friend_node* position_insertion_point(wchar_t lastname[20]);       //Ѱ���½ڵ�����λ��
    void make_node_new_head(friend_node* new_rec_ptr);      //���½ڵ��������
    void add_node_to_end(friend_node* new_rec_ptr);     //���½ڵ������β
    void move_current_to_end();                     //����ǰλ��ָ����β
    void display_choose();                 //ѡ�����ģʽ
    void display_list();                //��ʾ���е绰��¼    
    void display_somelist();                //������ʾ������ӣ�
    void display(int position_x, int position_y);  //�������������ӣ�
    void delete_choose();               //ɾ������ѡ��
    void delete_record();              //ɾ��һ���ڵ�
    void delete_allrecord();          //ɾ�����нڵ㣨����ӣ�
    void delete_head_of_list();        //ɾ�����׽ڵ�
    void delete_end_of_list(friend_node* previous_ptr);//ɾ����β�ڵ�
    void delete_from_middle_of_list(friend_node* previous_ptr); //ɾ���м�ڵ�
    int verify_delete();               //ȷ���Ƿ�ɾ��
    void delete_node(friend_node* previous_ptr);	//ɾ��*current_ptr��ָ�ڵ�
    void delete_list();                 //ɾ�������б�  
    void search_choice();//�����û�ѡ�������Ӧ���Һ���
    void search_by_firstname();//��������firstname������
    void search_by_lastname();//�����գ�lastname������
    void search_by_initial_letter(); //��������ĸ���ң�����ӣ�
    void search_by_fullname();         //������������
    void write_list_to_file();          //����¼���浽�ļ���
    void load_list_from_file();         //�������ļ�FRIENDS.DAT�ж�ȡ�����ؽ�������
    void help_me();                     //�����˵�
    void replace();                     //�ڵ��޸ģ�����ӣ�
    void time_note(friend_node* new_rec_ptr);    //��ʱ�䴫�ݽ���¼������ӣ�
};

/*����ʱ����time_record*/
class  time_record
{
public:
    int year;//��ʾ¼��ʱ����
    int month; //��ʾ¼��ʱ����
    int day; //��ʾ¼��ʱ����
    int hour; //��ʾ¼��ʱ��Сʱ
    int minute; //��ʾ¼��ʱ�����
    int second;//��ʾ¼��ʱ����
    time_t time_date;//��ʾ¼��ʱ��
    tm* CurrentTime;//��ʾʱ�����͵�ָ�����
    time_record* tm_year;//ָ��ʱ�����ָ��
    time_record* tm_mon;//ָ��ʱ���µ�ָ��
    time_record* tm_mday;//ָ��ʱ�����ָ��
    time_record* tm_hour;//ָ��ʱ��Сʱ��ָ��
    time_record* tm_min;//ָ��ʱ����ӵ�ָ��

    void time_check();//��¼ʱ��ĺ���
};

/*�����û���*/
class USER
{
private:
    int Num;//���
    wchar_t name[20];
    wchar_t password1[20];
    wchar_t password2[20];
    wchar_t temp;
public:
    void Register();
    void Login();
    void Display();
}user[100];    //�����û�����

/********************ȫ�ֱ���***********************/
int UserNum = 0;                       //�û�����������0��ʼ
int  usernumber;                      //�����û��ı��
char fname[20];                        //�����û���
wchar_t pause;                         //�����γ���������
wchar_t fullname[36];                  //ȫ�ֱ��������ڽ��պ����ϲ�
friend_node* head_ptr = NULL;              //ȫ�ֱ�������ͷָ�룬��ʼ��Ϊ��
friend_node* current_ptr = NULL;           //ȫ�ֱ���������ָ����ǰ�������е�λ��

/*******************��������***********************/



/*������*/
int main()
{
    initgraph(1280, 720);      //����ͼ�δ��ڴ�С
    mciSendString(_T("open bloomofyouth.mp3 alias mymusic"), NULL, 0, NULL);//������
    mciSendString(_T("play mymusic repeat"), 0, 0, 0);// �ظ�����"bloom of youth.mp3"
    USER u;                  //����һ���û�����
    u.Display();            //��ʾ��ҳ�桡����ע�᣻����¼�� 3 �˳���
    return 0;
}

/*��ҳ��*/
void USER::Display()
{
    char file_name[128];
    char kb;  //���������Ϣ
    IMAGE image;//��������
    //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ��������������Ϣ
    {
        for (int i = 0; i < 1286; i++)
        {
            float ftime;			//��¼ʱ��������
            DWORD startTime = GetTickCount();//��¼��ʼʱ��

            if (_kbhit())//����������Ϣ
            {
                kb = _getch();
                if (kb == 27)  //esc��ASCII��
                {
                    exit(EXIT_FAILURE); //�˳�����
                }
            }
            if (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
            {
                msg = GetMouseMsg();//��ȡ�����Ϣ
                if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
                {
                    if (msg.x > 65 && msg.x < 405 && msg.y > 500 && msg.y < 660)//������ض����򣬼�ע�ᰴť��������
                    {
                        Register();         //����register����
                    }

                    if (msg.x > 870 && msg.x < 1210 && msg.y > 520 && msg.y < 670)//������ض����򣬼���½��ť��������
                    {
                        Login();            //����login����
                    }
                }
            }

            putimage(0, 0, &image);
            sprintf(file_name, "1\\%d.jpg", i + 1); //����ͼƬ
            int num = MultiByteToWideChar(0, 0, file_name, -1, NULL, 0);// ��char*תΪLPCTSTR
            wchar_t* wide = new wchar_t[num];
            MultiByteToWideChar(0, 0, file_name, -1, wide, num);
            loadimage(&image, wide);//�����Ը�Ϊ���ַ���,���д����

            do
            {
                DWORD totalTime = GetTickCount() - startTime;//�ӿ�ʼ��������������ʱ�䣨���룩
                ftime = (float)totalTime;			//ת��Ϊ������
            } while (ftime < 30);			//Ϊ�˾�ȷ���Ʋ���ÿһ��ͼƬ��ʱ����

        }


    }
}

/*ע��*/
void USER::Register()
{
    FILE* fp;
    fopen_s(&fp, "user.txt", "a+");//�����������½��ļ�

    //��ע���ID��key���浽user.txt�ļ�����
    fread(&UserNum, 4, 1, fp);
    for (int i = 0; i < UserNum; i++)
    {
        fread(&user[i].Num, sizeof(Num), 1, fp);
        fread(&user[i].name, sizeof(name), 1, fp);
        fread(&user[i].password1, sizeof(password1), 1, fp);
        fread(&user[i].password2, sizeof(password2), 1, fp);
        fread(&user[i].temp, sizeof(temp), 1, fp);
    }
    fclose(fp);
    //�����û���
    int i;
    do {
        InputBox(user[UserNum].name, 20, _T("�������û���"));//��ʾ�û������û���
        //�����������û���Ϣ���е����ݣ��Ƚ���������û����Ƿ���ڣ�������ڣ�ϵͳ������ʾ
        for (i = 0; i < UserNum; i++)
        {
            if (wcscmp(user[i].name, user[UserNum].name) == 0)
            {
                MessageBox(NULL, _T("���û��Ѿ����ڣ�����������"), _T("�����˻�"), MB_ICONSTOP | MB_SETFOREGROUND);//�����ʾ�������û�
                break;//����forѭ��
                      //�޸���1.0�汾�û�ע��ʱ���ֵ�bug
            }

        }
        if (i >= UserNum)//˵��û���ҵ��ظ����û��� 
            break;
    } while (1);//����û����ظ���һֱѭ����ֱ�����ظ�ʱ����ѭ�� 
               //�����û����������� 



      /*���������û�����*/
    do
    {
        InputBox(user[UserNum].password1, 20, _T("����������"));//��ʾ�û���������
        InputBox(user[UserNum].password2, 20, _T("��ȷ������"));//��ʾ�û�ȷ������
        if (wcscmp(user[UserNum].password1, user[UserNum].password2) != 0)//�����������벻��� 
            MessageBox(NULL, _T("�������벻һ�£�����������"), _T("�����˻�"), MB_ICONSTOP | MB_SETFOREGROUND);
        else
        {
            MessageBox(NULL, _T("ע��ɹ���"), _T("�����˻�"), MB_SETFOREGROUND | MB_ICONASTERISK);
            //�����ֱ�Ϊ����Ϣ��ӵ�еĴ��ڡ���Ϣ������ݡ���Ϣ��ı��⡢��־��(�����־��"��"(|)��������)
           //���Ĳ�����ʾ������Ϣ��Ϊǰ������

            UserNum++;//������һ����Ҫע���ѧ���û��ı��
            user[UserNum - 1].Num = UserNum;//��һ 
            break;
        }
    } while (1);

    fopen_s(&fp, "user.txt", "w+");
    fwrite(&UserNum, 4, 1, fp);
    for (int i = 0; i < UserNum; i++)
    {
        fwrite(&user[i].Num, sizeof(Num), 1, fp);
        fwrite(&user[i].name, sizeof(name), 1, fp);
        fwrite(&user[i].password1, sizeof(password1), 1, fp);
        fwrite(&user[i].password2, sizeof(password2), 1, fp);
        fwrite(&user[i].temp, sizeof(temp), 1, fp);
    }
    fclose(fp);
}

/*��¼*/
void USER::Login()
{
    int i;
    wchar_t username[20];//����һ����ʱ�洢�û������ַ����� 
    wchar_t password[20];//����һ����ʱ�洢������ַ����� 

    FILE* fp;
    fopen_s(&fp, "user.txt", "a");
    fclose(fp);   //�����������½��ļ�

    fopen_s(&fp, "user.txt", "r");
    //��ע���ID��key���浽user.txt�ļ�����
    fread(&UserNum, 4, 1, fp);
    for (int i = 0; i < UserNum; i++)
    {
        fread(&user[i].Num, sizeof(Num), 1, fp);
        fread(&user[i].name, sizeof(name), 1, fp);
        fread(&user[i].password1, sizeof(password1), 1, fp);
        fread(&user[i].password2, sizeof(password2), 1, fp);
        fread(&user[i].temp, sizeof(temp), 1, fp);
    }
    fclose(fp);

    InputBox(username, 10, _T("�������û���"));//��ʾ�û������û������������ʱ�洢�û������ַ�����

    for (i = 0; i < UserNum; i++)
    {
        if (wcscmp(username, user[i].name) == 0)//�ҵ��� 
        {
            usernumber = i;
            break;//����forѭ��
        }
    }

    if (i >= UserNum)//˵��û���ҵ���Ӧ�û��� 
    {
        MessageBox(NULL, _T("���û�������"), _T("�û���¼"), MB_ICONSTOP | MB_SETFOREGROUND);
    }
    else  //�ҵ��û�������������
    {
        USES_CONVERSION;//��
        char* pa = W2A(username);//����һ�� ASNI��׼�Ķ��ֽ��ַ�
        strcpy(fname, pa);  //���ļ������û�����ʾ
        strcat(fname, ".txt");
        do
        {
            InputBox(password, 10, _T("����������"));//��ʾ�û��������룬�������ʱ�洢������ַ�����

            if (wcscmp(password, user[usernumber].password1) == 0)         //���������ȷ����¼�ɹ�
            {
                MessageBox(NULL, _T("��¼�ɹ���"), _T("�û���¼"), MB_SETFOREGROUND);

                friend_node object;             //����һ������

                object.load_list_from_file(); //�����ݱ������ļ���
                object.handle_choice(); //���ú���ִ���û���ѡ��
                break;


            }
            else
            {
                int result = MessageBox(NULL, _T("�������"), _T("ѧ����¼"), MB_ICONWARNING | MB_SETFOREGROUND | MB_RETRYCANCEL);

                if (result == IDCANCEL)
                    break;   //ȡ���������룬�˳�ѭ��
            }
        } while (1);
    }
}


/*��ѡ�����*/
void friend_node::handle_choice()
{
    loadimage(&welcome, L"welcome.png");//���뻶ӭ����
    putimage(0, 0, &welcome);//��ʾ��ӭ����

    //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 135 && msg.x < 350 && msg.y > 120 && msg.y < 200)//������ض����򣬼��½���¼��ť��������
                {
                    loadimage(&add, L"add.png");//����addͼƬ
                    putimage(0, 0, &add);//��ʾaddͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    add_record(); //���ú������ӽڵ�
                }

                if (msg.x > 135 && msg.x < 350 && msg.y > 525 && msg.y < 600)//������ض����򣬼����Ҽ�¼��ť��������
                {
                    loadimage(&search, L"search.png");//����searchͼƬ
                    putimage(0, 0, &search);//��ʾsearchͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_choice(); //���ò��Һ���
                }

                if (msg.x > 135 && msg.x < 350 && msg.y > 320 && msg.y < 395)//������ض����򣬼���ʾ��¼��ť��������
                {
                    loadimage(&display_png, L"display.png");//����searchͼƬ
                    putimage(0, 0, &display_png);//��ʾdisplayͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    display_choose(); //������ʾ����
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 120 && msg.y < 195)//������ض����򣬼�ɾ����¼��ť��������
                {
                    loadimage(&delete_png, L"delete.png");//����ͼƬ
                    putimage(0, 0, &delete_png);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    delete_choose(); //���ú���
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 325 && msg.y < 395)//������ض����򣬼��޸ļ�¼��ť��������
                {
                    loadimage(&replace_png, L"replace.png");//����ͼƬ
                    putimage(0, 0, &replace_png);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    replace(); //���ú���
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 525 && msg.y < 600)//������ض����򣬼��޸ļ�¼��ť��������
                {
                    loadimage(&help, L"help.png");//����ͼƬ
                    putimage(0, 0, &help);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    help_me(); //���ú���
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼��˳���ť��������
                {
                    write_list_to_file();
                    USER u;                  //����һ���û�����
                    u.Display();
                }
            }
        }
    }
}

/* ������������һ���½ڵ�*/
void friend_node::add_record()
{
    friend_node* new_rec_ptr;                // ����һ��ָ���½ڵ��ָ��
    new_rec_ptr = new friend_node;           // �����µ��ڴ�ռ䣬ʹָ��ָ����ڴ�ռ�

    if (new_rec_ptr != NULL)                  // ���*new_rec_ptr��ָ�ռ䲻Ϊ��
    {                                              //�����û���������ֺ͵绰����    
        InputBox(new_rec_ptr->last_name, 20, _T("Last Name(��): "));// _TΪ����unicode����
        while (wcscmp(new_rec_ptr->last_name, _T("")) == 0)//wcscmp������strcmp
        {                  //����������ַ���Ӱ���ļ���ȡ���ļ���ȡ���������ַ��롰end����Ϊ�����ı�־��
            MessageBox(NULL, _T("������Ч������������"), _T("Last Name(��): "), MB_ICONSTOP | MB_SETFOREGROUND);
            //�����ֱ�Ϊ����Ϣ��ӵ�еĴ��ڡ���Ϣ������ݡ���Ϣ��ı��⡢��־��(�����־��"��"(|)��������)
           //���Ĳ�����ʾ������Ϣ��Ϊǰ������
            InputBox(new_rec_ptr->last_name, 20, _T("Last Name(��): "));
        }
        InputBox(new_rec_ptr->first_name, 20, _T("First Name(��): "));
        InputBox(new_rec_ptr->phone_num, 15, _T("Phone Number(�绰����): "));
        time_note(new_rec_ptr);    //���ú�����ʱ�䴫�ݽ���¼

        friend_node* search_mate_ptr = head_ptr; //����һ������Ѱ�ҵ�ָ��

        while ((search_mate_ptr != NULL) && wcscmp(search_mate_ptr->phone_num, new_rec_ptr->phone_num) != 0)
            //��������ƥ��ļ�¼ֱ���ҵ����ѵ���β
        {
            search_mate_ptr = search_mate_ptr->next;
        }

        if (search_mate_ptr != NULL)        // ԭ��¼����ͬ�ֻ�����ģ���ʾ����ԭ��¼��ȡ������
        {
            loadimage(&add_display, L"add_display.png");
            putimage(0, 0, &add_display);
            friend_node* persent_ptr;      //����һ����ʱָ����current_ptr
            persent_ptr = current_ptr;
            current_ptr = search_mate_ptr;

            setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
            settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
            settextstyle(20, 0, _T("����"));//���������С20����ʽ����
            display(780, 80);   //չʾ�������˺�����Ҫ�õ�ָ�����current_ptr����Ҫ���ʼλ��
            outtextxy(780, 60, _T(" ����         �绰����          ����"));//��ʾ����һ�б�ͷ          
            current_ptr = persent_ptr;
            int result = MessageBox(NULL, _T("�ú����Ѵ��ڣ��Ƿ�ѡ�񸲸�ԭ�м�¼��"), _T("��Ӽ�¼"), MB_SETFOREGROUND | MB_ICONASTERISK | MB_YESNO);

            if (result == IDYES)     //����ԭ�м�¼     
            {
                delete search_mate_ptr;         //�ͷ�ԭ�ռ䣬���½ڵ��������
                insert_node(new_rec_ptr);       //���ò��뺯��                  
                MessageBox(NULL, _T("�޸ĳɹ���"), _T("��Ӽ�¼"), MB_SETFOREGROUND);
            }
        }
        else                                        //ԭ��¼��û��ͬ���ģ���������
        {
            insert_node(new_rec_ptr);            //���������½ڵ���뵽������
        }
    }
    else                                     // ������ٿռ�ʧ�ܣ��¼�¼������ӣ���������ʾ
    {
        MessageBox(NULL, _T("���棺�洢�������д��µļ�¼������ӣ�\n"), _T("��Ӽ�¼"), MB_SETFOREGROUND);
    }
    handle_choice();
}                                          // ���� add_record����

/*��ʱ�䴫�ݽ��¼�¼*/
void friend_node::time_note(friend_node* new_rec_ptr)
{
    time_record tmnote;//����time_record�����
    tmnote.time_check();//���ú�����ȡ��ǰʱ��
    new_rec_ptr->year = tmnote.year;//��ʾ¼��ʱ����
    new_rec_ptr->month = tmnote.month; //��ʾ¼��ʱ����
    new_rec_ptr->day = tmnote.day; //��ʾ¼��ʱ����
    new_rec_ptr->hour = tmnote.hour; //��ʾ¼��ʱ��Сʱ
    new_rec_ptr->minute = tmnote.minute; //��ʾ¼��ʱ�����
    new_rec_ptr->second = tmnote.second;//��ʾ¼��ʱ����
    //���ҳ������޷���ȷ����������������ṩ�ķ���x.str()�ȷ������Ҳ����ã������Ҳ�������ԭʼ��int-- > string-- > char[]-- > LPCTSTRת����
    string temp = to_string(_ULONGLONG_(new_rec_ptr->year));
    char s[100];
    unsigned int i;
    for (i = 0; i < temp.length(); i++)
        s[i] = temp[i];
    s[i] = '\0';
    int n = MultiByteToWideChar(0, 0, s, -1, NULL, 0);
    wchar_t* wide = new wchar_t[n];
    MultiByteToWideChar(0, 0, s, -1, wide, n);
    wcscpy(new_rec_ptr->time_num, wide);
    wcscat(new_rec_ptr->time_num, _T("-"));

    temp = to_string(_ULONGLONG_(new_rec_ptr->month));

    for (i = 0; i < temp.length(); i++)
        s[i] = temp[i];
    s[i] = '\0';
    n = MultiByteToWideChar(0, 0, s, -1, NULL, 0);
    wide = new wchar_t[n];
    MultiByteToWideChar(0, 0, s, -1, wide, n);
    wcscat(new_rec_ptr->time_num, wide);
    wcscat(new_rec_ptr->time_num, _T("-"));

    temp = to_string(_ULONGLONG_(new_rec_ptr->day));


    for (i = 0; i < temp.length(); i++)
        s[i] = temp[i];
    s[i] = '\0';
    n = MultiByteToWideChar(0, 0, s, -1, NULL, 0);
    wide = new wchar_t[n];
    MultiByteToWideChar(0, 0, s, -1, wide, n);
    wcscat(new_rec_ptr->time_num, wide);
    wcscat(new_rec_ptr->time_num, _T(" "));

    temp = to_string(_ULONGLONG_(new_rec_ptr->hour));


    for (i = 0; i < temp.length(); i++)
        s[i] = temp[i];
    s[i] = '\0';
    n = MultiByteToWideChar(0, 0, s, -1, NULL, 0);
    wide = new wchar_t[n];
    MultiByteToWideChar(0, 0, s, -1, wide, n);
    wcscat(new_rec_ptr->time_num, wide);
    wcscat(new_rec_ptr->time_num, _T(":"));

    temp = to_string(_ULONGLONG_(new_rec_ptr->minute));

    for (i = 0; i < temp.length(); i++)
        s[i] = temp[i];
    s[i] = '\0';
    n = MultiByteToWideChar(0, 0, s, -1, NULL, 0);
    wide = new wchar_t[n];
    MultiByteToWideChar(0, 0, s, -1, wide, n);
    wcscat(new_rec_ptr->time_num, wide);
    wcscat(new_rec_ptr->time_num, _T(":"));

    temp = to_string(_ULONGLONG_(new_rec_ptr->second));

    for (i = 0; i < temp.length(); i++)
        s[i] = temp[i];
    s[i] = '\0';
    n = MultiByteToWideChar(0, 0, s, -1, NULL, 0);
    wide = new wchar_t[n];
    MultiByteToWideChar(0, 0, s, -1, wide, n);
    wcscat(new_rec_ptr->time_num, wide);
}

/*��¼ʱ��*/
void time_record::time_check()
{
    time_date = time(NULL);//time( )������ȡ���Ը�������ʱ��1970��1��1��00��00������������
    CurrentTime = localtime(&time_date);//localtime( )�����ǽ�����Ϊtime_t��ʱ��ֵ������ṹ����Ϊtm�Ľṹ��
    year = CurrentTime->tm_year + 1900;//����ǰʱ���Ϊ��׼��ʽ
    month = CurrentTime->tm_mon + 1;//ȡ���·ݸ������е�˽������Month,tm_mon�Ǵ�0��ʼ����ʾ12�·�����Ϊ0��11������ʵ�·����һ
    day = CurrentTime->tm_mday;//ȡ����ǰʱ�������
    hour = CurrentTime->tm_hour;//ȡ����ǰʱ���Сʱ��
    minute = CurrentTime->tm_min;//ȡ����ǰʱ��ķ�����
    second = CurrentTime->tm_sec;//ȡ����ǰʱ�������
}

/*���currentָ����ָ����*/
void friend_node::display(int position_x, int position_y)
{
    wcscpy(fullname, _T(""));              // ���ȫ�ֱ���fullname����
    wcscat(fullname, current_ptr->last_name);
    wcscat(fullname, _T(" "));
    wcscat(fullname, current_ptr->first_name);    //���պ������ӵ�fullname��
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����
    outtextxy(position_x, position_y, fullname);
    outtextxy(position_x + 130, position_y, current_ptr->phone_num);
    outtextxy(position_x + 280, position_y, current_ptr->time_num);
}									      // ���� display() ����

/*��һ����new_rec_ptr ָ����½ڵ����������*/
void friend_node::insert_node(friend_node* new_rec_ptr)
{
    friend_node* before_ptr;
    friend_node* after_ptr;                  //��������ָ�룬����ָ���½ڵ��ǰһ�ڵ����һ�ڵ�

    if (head_ptr == NULL)                     // ���ԭ����Ϊ�գ����޼�¼
    {
        new_rec_ptr->next = NULL;              // �������Ϊ�գ�����¼��ӵ�����
        new_rec_ptr->prev = NULL;
        head_ptr = new_rec_ptr;
    }
    else                                     // ԭ����Ϊ��
    {
        if (wcscmp(new_rec_ptr->last_name, head_ptr->last_name) < 0)
        {                                      // ���Ҫ������¼�¼���������׵���֮ǰ
            make_node_new_head(new_rec_ptr);   // ���ú������뵽����
        }
        else
        {
            current_ptr = position_insertion_point(new_rec_ptr->last_name);   //���ú����ҳ�Ӧ�����λ�ã���Ӧ�öϿ���ǰһ���ڵ㸳��*current
            before_ptr = current_ptr;
            after_ptr = current_ptr->next;

            if (after_ptr == NULL)               // ���Ҫ������¼�¼��������β����֮��
            {
                add_node_to_end(new_rec_ptr);     //���ú������뵽��β
            }
            else                  // ���Ҫ������¼�¼�����������м�
            {
                before_ptr->next = new_rec_ptr;        //�ı�ָ�򣬽��½ڵ��������
                new_rec_ptr->prev = before_ptr;
                new_rec_ptr->next = after_ptr;
                after_ptr->prev = new_rec_ptr;
            }
        }
    }
}                            // ���� insert_node ����

/*�����û�ѡ�������Ӧ���Һ���*/
void friend_node::search_choice()
{
    loadimage(&search_choose, L"search_choose.png");//����searchͼƬ
    putimage(0, 0, &search_choose);//��ʾsearchͼƬ

     //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 135 && msg.x < 350 && msg.y > 120 && msg.y < 200)//������ض����򣬼�ȫ�����Ұ�ť��������
                {
                    loadimage(&search_fullname, L"search_fullname.png");//����ͼƬ
                    putimage(0, 0, &search_fullname);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_by_fullname(); //����ȫ�����Һ���
                }

                if (msg.x > 135 && msg.x < 350 && msg.y > 525 && msg.y < 600)//������ض����򣬼��ղ��Ҽ�¼��ť��������
                {
                    loadimage(&search_lastname, L"search_lastname.png");//����ͼƬ
                    putimage(0, 0, &search_lastname);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_by_lastname(); //�����ղ��Һ���
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 120 && msg.y < 200)//������ض����򣬼�����ĸ���Ҽ�¼��ť��������
                {
                    loadimage(&search_str, L"search_str.png");//����ͼƬ
                    putimage(0, 0, &search_str);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_by_initial_letter(); //��������ĸ���Һ���
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 525 && msg.y < 600)//������ض����򣬼������Ҽ�¼��ť��������
                {
                    loadimage(&search_firstname, L"search_firstname.png");//����ͼƬ
                    putimage(0, 0, &search_firstname);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_by_firstname(); //���������Һ���
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&search_back, L"search_back.png");//����ͼƬ
                    putimage(0, 0, &search_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    handle_choice(); //�������˵�����
                }
            }
        }
    }
}

/*�����������Ҽ�¼*/
void friend_node::search_by_fullname()
{
    int count = 0;
    loadimage(&search_fullname_display, L"search_fullname_display.png");//����searchͼƬ
    putimage(0, 0, &search_fullname_display);//��ʾsearchͼƬ
    wchar_t search_last_string[20];           // ������Ҫ���ҵ���
    wchar_t search_first_string[15];              // ������Ҫ���ҵ���
    current_ptr = head_ptr;                   // ��currentָ��ָ������
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����


    InputBox(search_first_string, 15, _T("��������Ҫ�������ݵ���: "));
    InputBox(search_last_string, 20, _T("��������Ҫ�������ݵ���: "));

    while ((current_ptr != NULL) &&
        ((wcscmp(current_ptr->last_name, search_last_string) != 0) ||
            (wcscmp(current_ptr->first_name, search_first_string) != 0)))
        //��������ƥ��ļ�¼ֱ���ҵ����ѵ���β
    {
        current_ptr = current_ptr->next;
    }
    if (current_ptr != NULL)        // �ҵ���ƥ��ļ�¼
    {
        outtextxy(780, 60, _T(" ����         �绰����          ����"));
        count++;

        display(780, 80);                  //����չʾ����


        while (current_ptr != NULL)             //��������ʣ�µĽڵ㣨��ͬ��ʱ����ȫ�������
        {
            current_ptr = current_ptr->next;
            if (current_ptr != NULL && (wcscmp(current_ptr->last_name, search_last_string) == 0) &&
                (wcscmp(current_ptr->first_name, search_first_string) == 0))
            {
                display(780, 80 + count * 20);             //����չʾ����
                count++;
            }
        }
    }
    else                            //û���ҵ������ҵļ�¼
    {
        outtextxy(780, 60, _T("�Բ���û���ҵ��������ҵļ�¼"));
    }

    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 135 && msg.x < 350 && msg.y > 525 && msg.y < 600)//������ض����򣬼��ղ��Ұ�ť��������
                {
                    loadimage(&search_fullname_display_lastname, L"search_fullname_display_lastname.png");//����ͼƬ
                    putimage(0, 0, &search_fullname_display_lastname);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_by_lastname(); //�����ղ��Һ���
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&search_fullname_display_back, L"search_fullname_display_back.png");//����ͼƬ
                    putimage(0, 0, &search_fullname_display_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_choice(); //�����ϼ��˵�����
                }
            }
        }
    }

}                                                   //���� search_by_lastname ����

/* ��������firstname�����Ҽ�¼*/
void friend_node::search_by_firstname()
{
    loadimage(&search_firstname_display, L"search_firstname_display.png");//����searchͼƬ
    putimage(0, 0, &search_firstname_display);//��ʾsearchͼƬ
    int count = 0;
    wchar_t search_first_string[20];  // ��Ų��ҵ�����
    current_ptr = head_ptr;  //currentָ��ָ��ͷ�ڵ�
    InputBox(search_first_string, 20, _T("��������Ҫ�������ݵ���: "));
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����

    while ((current_ptr != NULL) &&
        (wcscmp(current_ptr->first_name, search_first_string) != 0))
        //��������ƥ��ļ�¼ֱ���ҵ����ѵ���β
    {
        current_ptr = current_ptr->next;
    }

    if (current_ptr != NULL)        // �ҵ���ƥ��ļ�¼
    {
        outtextxy(30, 60, _T(" ����         �绰����          ����"));
        count++;

        display(30, 80);                  //����չʾ����

        while (current_ptr != NULL)             //��������ʣ�µĽڵ㣨��ͬ��ʱ����ȫ�������
        {
            current_ptr = current_ptr->next;
            if (current_ptr != NULL && wcscmp(current_ptr->first_name, search_first_string) == 0)
            {
                display(30, 80 + count * 20);             //����չʾ����
                count++;
            }
        }
    }
    else                            //û���ҵ������ҵļ�¼
    {
        outtextxy(30, 60, _T("�Բ���û���ҵ��������ҵļ�¼"));
    }

    //��꽻��//
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 960 && msg.x < 1170 && msg.y > 120 && msg.y < 200)//������ض����򣬼�����ĸ���Ҽ�¼��ť��������
                {
                    loadimage(&search_firstname_display_str, L"search_firstname_display_str.png");//����ͼƬ
                    putimage(0, 0, &search_firstname_display_str);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_by_initial_letter(); //��������ĸ���Һ���
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&search_firstname_display_back, L"search_firstname_display_back.png");//����ͼƬ
                    putimage(0, 0, &search_firstname_display_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_choice(); //�����ϼ��˵�����
                }
            }
        }
    }
} // ����search_by_firstname����

/* �����գ�lastname�����Ҽ�¼*/
void friend_node::search_by_lastname()
{
    loadimage(&search_lastname_display, L"search_lastname_display.png");//����searchͼƬ
    putimage(0, 0, &search_lastname_display);//��ʾsearchͼƬ
    int count = 0;
    wchar_t search_last_string[20];  // ��Ų��ҵ�����
    current_ptr = head_ptr;  //currentָ��ָ��ͷ�ڵ�
    InputBox(search_last_string, 20, _T("��������Ҫ�������ݵ���: "));
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����

    while ((current_ptr != NULL) &&
        (wcscmp(current_ptr->last_name, search_last_string) != 0))
        //��������ƥ��ļ�¼ֱ���ҵ����ѵ���β
    {
        current_ptr = current_ptr->next;
    }

    if (current_ptr != NULL)        // �ҵ���ƥ��ļ�¼
    {
        outtextxy(780, 60, _T(" ����         �绰����          ����"));
        count++;
        display(780, 80);                  //����չʾ����

        while (current_ptr != NULL)             //��������ʣ�µĽڵ㣨��ͬ��ʱ����ȫ�������
        {
            current_ptr = current_ptr->next;
            if (current_ptr != NULL && wcscmp(current_ptr->last_name, search_last_string) == 0)
            {
                display(780, 80 + count * 20);             //����չʾ����
                count++;
            }
        }
    }
    else                            //û���ҵ������ҵļ�¼
    {
        outtextxy(780, 60, _T("�Բ���û���ҵ��������ҵļ�¼"));
    }

    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 135 && msg.x < 350 && msg.y > 120 && msg.y < 200)//������ض����򣬼�ȫ�����Ұ�ť��������
                {
                    loadimage(&search_lastname_display_fullname, L"search_lastname_display_fullname.png");//����ͼƬ
                    putimage(0, 0, &search_lastname_display_fullname);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_by_fullname(); //����ȫ�����Һ���
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&search_lastname_display_back, L"search_lastname_display_back.png");//����ͼƬ
                    putimage(0, 0, &search_lastname_display_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_choice(); //�����ϼ��˵�����
                }
            }
        }
    }
} // ����search_by_firstname����

/* ��������ĸ���Ҽ�¼*/
void friend_node::search_by_initial_letter()
{
    loadimage(&search_str_display, L"search_str_display.png");//����searchͼƬ
    putimage(0, 0, &search_str_display);//��ʾsearchͼƬ
    wchar_t szlast_name[2];// ����һ�ַ������������ĸ
    int count = 0;
    current_ptr = head_ptr;  // ��current_ptrָ��������
    InputBox(szlast_name, 20, _T("�����������ѯ�ߵ��յ�����ĸ: "));
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����

    while ((current_ptr != NULL) &&
        (current_ptr->last_name[0] != szlast_name[0]))
        //��������ƥ��ļ�¼ֱ���ҵ����ѵ���β
    {
        current_ptr = current_ptr->next;
    }

    if (current_ptr != NULL)        // �ҵ���ƥ��ļ�¼
    {
        outtextxy(30, 60, _T(" ����         �绰����          ����"));
        count++;

        display(30, 80);                  //����չʾ����

        while (current_ptr != NULL)             //��������ʣ�µĽڵ㣨��ͬ��ʱ����ȫ�������
        {
            current_ptr = current_ptr->next;
            if (current_ptr != NULL && current_ptr->last_name[0] == szlast_name[0])
            {
                display(30, 80 + count * 20);             //����չʾ����
                count++;
            }
        }
    }
    else                            //û���ҵ������ҵļ�¼
    {
        outtextxy(30, 60, _T("�Բ���û���ҵ��������ҵļ�¼"));
    }

    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 960 && msg.x < 1170 && msg.y > 525 && msg.y < 600)//������ض����򣬼������Ҽ�¼��ť��������
                {
                    loadimage(&search_str_display_firstname, L"search_str_display_firstname.png");//����ͼƬ
                    putimage(0, 0, &search_str_display_firstname);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_by_firstname(); //���������Һ���
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&search_str_display_back, L"search_str_display_back.png");//����ͼƬ
                    putimage(0, 0, &search_str_display_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    search_choice(); //�����ϼ��˵�����
                }
            }
        }
    }
} // ����search_by_initial_letter����

/*�����½ڵ����λ��*/
friend_node* friend_node::position_insertion_point(wchar_t lastname[20])
{                          // �������ϴ�С���������������е���ȷλ�õ�ǰһ�ڵ㡣�½ڵ㼴������˵�֮��
    wchar_t temp_name[20];               //����������ȡ���м�¼lastname������
    friend_node* temp_ptr;
    int tempint;                      //���ڽ��бȽϵ����ͱ���

    if (head_ptr->next != NULL)             // ����������ж���ڵ�ʱ��������ӵ���ȷλ��
    {
        current_ptr = head_ptr;
        temp_ptr = current_ptr->next;
        wcscpy(temp_name, temp_ptr->last_name);//�����������м�¼��lastname����temp_name  
        tempint = wcscmp(lastname, temp_name);                  //��ͷ��ʼ�Ƚϲ���        
        while ((tempint > 0) && (current_ptr->next != NULL))   //����ѭ��һֱ���±Ƚϲ��ң��������У��ҽ����գ�
        {
            current_ptr = temp_ptr;
            if (current_ptr->next != NULL)                       //ȷ�Ͻ���ӵ�λ�ò�����β
            {
                temp_ptr = current_ptr->next;                   //�������±Ƚ�
                wcscpy(temp_name, temp_ptr->last_name);
                tempint = wcscmp(lastname, temp_name);
            }
        }
    }
    else                                              // ���������ֻ������һ���ڵ�
    {
        current_ptr = head_ptr;                         //����ǰλ��ָ������
    }
    return(current_ptr);		//��������ֵΪcurrent_ptr
}                             // ���� position_insertion_point ����

/*���¼�¼���������*/
void friend_node::make_node_new_head(friend_node* new_rec_ptr)
{
    friend_node* temp_ptr;                      //��ʱָ�����ڸ�������ͷ
    temp_ptr = head_ptr;                      //����ʱָ��ָ��ԭ����
    temp_ptr->prev = new_rec_ptr;             //��µ�˫��
    new_rec_ptr->next = temp_ptr;
    new_rec_ptr->prev = NULL;                   //�½ڵ�prevָ��Ϊ��
    head_ptr = new_rec_ptr;
}                             // ���� make_node_new_head ����

/*���¼�¼��ӵ���β*/
void friend_node::add_node_to_end(friend_node* new_rec_ptr)
{
    new_rec_ptr->next = NULL;     //�½ڵ�nextָ��Ϊ��
    move_current_to_end();         //���ú�����ȫ��ָ��currentָ����β
    current_ptr->next = new_rec_ptr;  // ��µ�˫��
    new_rec_ptr->prev = current_ptr;
}                                        // ���� add_node_to_end ����

/*��ȫ��ָ��currentָ����β*/
void friend_node::move_current_to_end()
{
    current_ptr = head_ptr;           // ��currentָ��ָ������

    while (current_ptr->next != NULL)
    {                                 // ��currentָ�������ֱ����β
        current_ptr = current_ptr->next;
    }
}                                         //���� move_current_to_end ����

/*ѡ�������ʾģʽ*/
void friend_node::display_choose()
{
    loadimage(&display_choise, L"display_choise.png");//���뻶ӭ����
    putimage(0, 0, &display_choise);//��ʾ��ӭ����\

     //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 140 && msg.x < 210 && msg.y > 135 && msg.y < 375)//������ض����򣬼���ʾ���м�¼��ť��������
                {
                    loadimage(&display_choise_alllist, L"display_choise_alllist.png");//����ͼƬ
                    putimage(0, 0, &display_choise_alllist);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    display_list(); //������ʾ���к���
                }

                if (msg.x > 1045 && msg.x < 1117 && msg.y > 135 && msg.y < 375)//������ض����򣬼�������ʾ��ť��������
                {
                    loadimage(&display_choise_somelist, L"display_choise_somelist.png");//����ͼƬ
                    putimage(0, 0, &display_choise_somelist);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    display_somelist(); //����������ʾ����
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&display_choise_back, L"display_choise_back.png");//����ͼƬ
                    putimage(0, 0, &display_choise_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    handle_choice(); //�������˵�����
                }
            }
        }
    }
}

/*��ʾ���е绰��¼*/
void friend_node::display_list()
{
    int count = 0;
    loadimage(&display_list_all, L"display_list_all.png");//����ͼƬ
    putimage(0, 0, &display_list_all);//��ʾͼƬ
    current_ptr = head_ptr;           // ��currentָ��ָ������
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����


    if (current_ptr != NULL)            //����м�¼
    {
        outtextxy(400, 60, _T(" ����         �绰����          ����"));
        do
        {
            count++;
            display(400, 60 + 20 * count);                          //���ý����������
            current_ptr = current_ptr->next;     //��currentָ�����һ��
        } while (current_ptr != NULL);            //ֱ����β
    }
    else                              // ���û�м�¼����ʾ�޼�¼��ʾ
    {
        outtextxy(400, 60, _T("    ����û�м�¼Ŷ���Ͽ�ȥ����һ����!"));
    }

    //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 1045 && msg.x < 1117 && msg.y > 135 && msg.y < 375)//������ض����򣬼�������ʾ��ť��������
                {
                    loadimage(&display_list_all_somelist, L"display_list_all_somelist.png");//����ͼƬ
                    putimage(0, 0, &display_list_all_somelist);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    display_somelist(); //����������ʾ����
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&display_list_all_back, L"display_list_all_back.png");//����ͼƬ
                    putimage(0, 0, &display_list_all_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    display_choose(); //�����ϼ��˵�����
                }
            }
        }
    }
}                                    //���� display_list ����

/*������ʾ�绰��¼*/
void friend_node::display_somelist()
{
    loadimage(&display_list_some, L"display_list_some.png");//����ͼƬ
    putimage(0, 0, &display_list_some);//��ʾͼƬ
    wchar_t a[2];    //���������ַ�
    int n = 0;//���ͱ����������¼����
    current_ptr = head_ptr;                     //��currentָ��ָ������
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����
    friend_node* temp_ptr;//������ʱָ��
    int flag = 0;

    if (current_ptr != NULL)                    //����м�¼
    {
        //���������꽻����
        MOUSEMSG msg;//������������������Ϣ
        FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
        while (true) // ��ѭ��,ѭ�����������Ϣ
        {
            while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
            {
                msg = GetMouseMsg();//��ȡ�����Ϣ
                if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
                {
                    if (msg.x > 575 && msg.x < 705 && msg.y > 585 && msg.y < 615)//������ض����򣬼�ѡ����Ŀ��ť��������
                    {
                        InputBox(a, 10, _T("������ȷ��ÿ����ʾ�ļ�¼������1-9��"));//UnicodeתASCII�����ѣ���ȡ���취
                        if (wcscmp(a, _T("1")) == 0)
                            n = 1;
                        else if (wcscmp(a, _T("2")) == 0)
                            n = 2;
                        else if (wcscmp(a, _T("3")) == 0)
                            n = 3;
                        else if (wcscmp(a, _T("4")) == 0)
                            n = 4;
                        else if (wcscmp(a, _T("5")) == 0)
                            n = 5;
                        else if (wcscmp(a, _T("6")) == 0)
                            n = 6;
                        else if (wcscmp(a, _T("7")) == 0)
                            n = 7;
                        else if (wcscmp(a, _T("8")) == 0)
                            n = 8;
                        else if (wcscmp(a, _T("9")) == 0)
                            n = 9;
                        else
                            MessageBox(NULL, _T("������1-9���ڵ�����"), _T("��¼��ʾ"), MB_SETFOREGROUND | MB_ICONEXCLAMATION);

                        loadimage(&display_list_some, L"display_list_some.png");//����ͼƬ
                        putimage(0, 0, &display_list_some);//��ʾͼƬ
                        outtextxy(400, 60, _T(" ����         �绰����          ����"));
                        current_ptr = head_ptr;
                        for (int i = 0; i < n; i++)  //������ʾ
                        {

                            display(400, 80 + i * 20);                           //����չʾ����
                            if (current_ptr->next == NULL)
                                break;                         //��ʾ�������
                            current_ptr = current_ptr->next;
                        }
                        if (current_ptr->next == NULL)  //��n̫��������
                        {
                            flag = 1;
                        }
                    }

                    if (msg.x > 455 && msg.x < 533 && msg.y > 585 && msg.y < 621)//������ض����򣬼����ͷ��ť��������
                    {
                        loadimage(&display_list_some, L"display_list_some.png");//����ͼƬ
                        putimage(0, 0, &display_list_some);//��ʾͼƬ
                        outtextxy(400, 60, _T(" ����         �绰����          ����"));

                        int a = 0;
                        friend_node* t_ptr;
                        t_ptr = head_ptr;
                        while (t_ptr != NULL)    //�����ܽ����
                        {
                            a++;
                            t_ptr = t_ptr->next;
                        }

                        if (current_ptr->next == NULL && flag == 1)
                        {

                            if (current_ptr->prev == NULL)
                                break;
                            for (int i = 0; i < a % n - 1; i++)
                            {

                                current_ptr = current_ptr->prev;
                            }
                        }
                        if (flag == 0)
                        {
                            for (int i = 0; i < n; i++)
                            {
                                if (current_ptr->prev == NULL)
                                {

                                    break;   //��ֹc��������
                                }
                                current_ptr = current_ptr->prev;
                            }
                        }
                        flag = 0;
                        if (current_ptr->prev == NULL)
                        {
                            for (int i = 0; i < n; i++)  //������ʾ
                            {
                                if (current_ptr->next == NULL)
                                    break;
                                current_ptr = current_ptr->next;
                            }//��ʾ�������

                        }

                        temp_ptr = current_ptr;
                        for (int i = 0; i < n; i++)
                        {

                            if (temp_ptr->prev == NULL)
                                break;
                            temp_ptr = temp_ptr->prev;
                        }
                        for (int i = 0, j = 0; i < n; i++, j++)
                        {
                            if (temp_ptr == NULL)
                                break;                         //��ʾ�������
                            if (current_ptr->prev == NULL)
                            {
                                display(400, 80);
                                j++;
                            }
                            wcscpy(fullname, _T(""));              // ���ȫ�ֱ���fullname����
                            wcscat(fullname, temp_ptr->last_name);
                            wcscat(fullname, _T(" "));
                            wcscat(fullname, temp_ptr->first_name);    //���պ������ӵ�fullname��
                            setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
                            settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
                            settextstyle(20, 0, _T("����"));//���������С20����ʽ����
                            outtextxy(400, 80 + j * 20, fullname);
                            outtextxy(400 + 130, 80 + j * 20, temp_ptr->phone_num);
                            outtextxy(400 + 280, 80 + j * 20, temp_ptr->time_num);
                            temp_ptr = temp_ptr->next;    //��currentָ�����һ��
                        }
                    }

                    if (msg.x > 765 && msg.x < 845 && msg.y > 585 && msg.y < 621)//������ض����򣬼��Ҽ�ͷ��ť��������
                    {

                        if (flag == 0)
                        {
                            loadimage(&display_list_some, L"display_list_some.png");//����ͼƬ
                            putimage(0, 0, &display_list_some);//��ʾͼƬ
                            outtextxy(400, 60, _T(" ����         �绰����          ����"));


                            for (int i = 0; i < n; i++)
                            {
                                if (current_ptr->next == NULL)
                                {
                                    display(400, 80 + i * 20);
                                    flag = 1;
                                    break;
                                }//��ʾ�������

                                display(400, 80 + i * 20);                           //����չʾ����
                                current_ptr = current_ptr->next;    //��currentָ�����һ��
                            }

                        }
                    }

                    if (msg.x > 140 && msg.x < 210 && msg.y > 135 && msg.y < 375)//������ض����򣬼���ʾ���м�¼��ť��������
                    {
                        loadimage(&display_list_some_all, L"display_list_some_all.png");//����ͼƬ
                        putimage(0, 0, &display_list_some_all);//��ʾͼƬ
                        Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                        display_list(); //������ʾ���к���
                    }

                    if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                    {
                        loadimage(&display_list_some_back, L"display_list_some_back.png");//����ͼƬ
                        putimage(0, 0, &display_list_some_back);//��ʾͼƬ
                        Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                        display_choose(); //�����ϼ��˵�����
                    }
                }
            }

        }
    }
    else                                   // ���û�м�¼����ʾ�޼�¼��ʾ
    {
        outtextxy(400, 60, _T("����û�м�¼Ŷ���Ͽ�ȥ����һ���ɣ�"));
        //���������꽻����
        MOUSEMSG msg;//������������������Ϣ
        FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
        while (true) // ��ѭ��,ѭ�����������Ϣ
        {
            while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
            {
                msg = GetMouseMsg();//��ȡ�����Ϣ
                if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
                {
                    if (msg.x > 140 && msg.x < 210 && msg.y > 135 && msg.y < 375)//������ض����򣬼���ʾ���м�¼��ť��������
                    {
                        loadimage(&display_list_some_all, L"display_list_some_all.png");//����ͼƬ
                        putimage(0, 0, &display_list_some_all);//��ʾͼƬ
                        Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                        display_list(); //������ʾ���к���
                    }

                    if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                    {
                        loadimage(&display_list_some_back, L"display_list_some_back.png");//����ͼƬ
                        putimage(0, 0, &display_list_some_back);//��ʾͼƬ
                        Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                        display_choose(); //�����ϼ��˵�����
                    }
                }
            }
        }
    }

}                                   //���� display_somelist ����

/*�޸Ľڵ�����*/
void friend_node::replace()
{
    loadimage(&replace_list, L"replace_list.png");//����ͼƬ
    putimage(0, 0, &replace_list);//��ʾͼƬ
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����

    if (head_ptr == NULL)
    {
        outtextxy(400, 60, _T("����û�м�¼Ŷ���Ͽ�ȥ����һ���ɣ�"));
    }
    else
    {
        int count = 0;                  //ͳ���ҵ���¼��������
        friend_node* new_rec_ptr;
        wchar_t search_last_string[20];           // ������Ҫ���ҵ���
        wchar_t search_first_string[15];              // ������Ҫ���ҵ���
        new_rec_ptr = new friend_node;           // �����µ��ڴ�ռ䣬ʹָ��ָ����ڴ�ռ�
        current_ptr = head_ptr;                   // ��currentָ��ָ������

        InputBox(search_first_string, 15, _T("��������Ҫ�޸����ݵ���: "));
        InputBox(search_last_string, 20, _T("��������Ҫ�޸����ݵ���: "));

        while ((current_ptr != NULL) &&
            ((wcscmp(current_ptr->last_name, search_last_string) != 0) ||
                (wcscmp(current_ptr->first_name, search_first_string) != 0)))
            //��������ƥ��ļ�¼ֱ���ҵ����ѵ���β
        {
            current_ptr = current_ptr->next;
        }

        do
        {

            if (current_ptr != NULL)                     //���ڸü�¼
            {

                count++;
                outtextxy(400, 60, _T(" ����         �绰����          ����"));
                display(400, 80);                  //����չʾ����

                int result = MessageBox(NULL, _T("��ȷʵҪ�޸�ԭ�м�¼��"), _T("�޸ļ�¼"), MB_SETFOREGROUND | MB_ICONASTERISK | MB_YESNO);



                if (result == IDYES)   //Ҫ�޸ļ�¼
                {
                    InputBox(new_rec_ptr->last_name, 20, _T("Last Name(��): "));// _TΪ����unicode����
                    while (wcscmp(new_rec_ptr->last_name, _T("")) == 0)//wcscmp������strcmp
                    {                  //����������ַ���Ӱ���ļ���ȡ���ļ���ȡ���������ַ��롰end����Ϊ�����ı�־��
                        MessageBox(NULL, _T("������Ч������������"), _T("Last Name(��): "), MB_ICONSTOP | MB_SETFOREGROUND);
                        //�����ֱ�Ϊ����Ϣ��ӵ�еĴ��ڡ���Ϣ������ݡ���Ϣ��ı��⡢��־��(�����־��"��"(|)��������)
                       //���Ĳ�����ʾ������Ϣ��Ϊǰ������
                        InputBox(new_rec_ptr->last_name, 20, _T("Last Name(��): "));
                    }
                    InputBox(new_rec_ptr->first_name, 20, _T("First Name(��): "));
                    InputBox(new_rec_ptr->phone_num, 15, _T("Phone Number(�绰����): "));
                    time_note(new_rec_ptr);    //���ú�����ʱ�䴫�ݽ���¼

                    friend_node* search_mate_ptr = head_ptr; //����һ������Ѱ�ҵ�ָ��

                    while ((search_mate_ptr != NULL) && wcscmp(search_mate_ptr->phone_num, new_rec_ptr->phone_num) != 0)
                        //��������ƥ��ļ�¼ֱ���ҵ����ѵ���β
                    {
                        search_mate_ptr = search_mate_ptr->next;
                    }

                    if (search_mate_ptr != NULL)        // ԭ��¼����ͬ�ֻ�����ģ���ʾ����ԭ��¼��ȡ������
                    {
                        loadimage(&replace_list, L"replace_list.png");
                        putimage(0, 0, &replace_list);
                        friend_node* persent_ptr;      //����һ����ʱָ����current_ptr
                        persent_ptr = current_ptr;
                        current_ptr = search_mate_ptr;
                        display(400, 80);                  //����չʾ����
                        current_ptr = persent_ptr;
                        MessageBox(NULL, _T("�ú����Ѵ��ڣ��޸�ʧ��"), _T("�޸ļ�¼"), MB_SETFOREGROUND | MB_ICONASTERISK);
                        break;
                    }
                    else
                    {
                        wcscpy(current_ptr->first_name, new_rec_ptr->first_name);
                        wcscpy(current_ptr->last_name, new_rec_ptr->last_name);
                        wcscpy(current_ptr->phone_num, new_rec_ptr->phone_num);
                        MessageBox(NULL, _T("���ѳɹ��޸ļ�¼��"), _T("�޸ļ�¼"), MB_SETFOREGROUND);
                        break;
                    }
                }
                else
                    break;
            }
            else                            //û���ҵ������ҵļ�¼
            {
                if (count == 0)
                {
                    outtextxy(400, 60, _T("�Բ���û�в�ѯ����ؼ�¼"));
                }
                else
                {
                    outtextxy(400, 60, _T("������ϣ�"));
                }
            }
            if (current_ptr != NULL)
            {
                current_ptr = current_ptr->next;
            }
        } while (current_ptr != NULL);  //��֤ͬ��ʱ�����޸�
    }

    //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 535 && msg.x < 745 && msg.y > 555 && msg.y < 627)//������ض����򣬼��޸İ�ť��������
                {
                    replace();   //�޸ĺ���
                }
                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&replace_list_back, L"replace_list_back.png");//����ͼƬ
                    putimage(0, 0, &replace_list_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    handle_choice(); //�����ϼ��˵�����
                }
            }
        }
    }
}                                    //���� display_list ����

/*����*/
void friend_node::help_me()
{
    loadimage(&help_png, L"help_png.png");//����ͼƬ
    putimage(0, 0, &help_png);//��ʾͼƬ

        //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&help_back, L"help_back.png");//����ͼƬ
                    putimage(0, 0, &help_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    handle_choice(); //�����ϼ��˵�����
                }
            }
        }
    }
}                                    //���� help_me ����

/*����¼���浽�ļ���*/
void friend_node::write_list_to_file()
{
    FILE* fp;
    fopen_s(&fp, fname, "wb");
    current_ptr = head_ptr;                          // ��current_ptrָ������

    if (head_ptr != NULL)                       // �������Ϊ�գ���ʼ���ļ�д����
    {
        do
        {                                            // �ѽڵ�����д���ļ�
            fwrite(current_ptr->last_name, sizeof(last_name), 1, fp);
            fwrite(current_ptr->first_name, sizeof(first_name), 1, fp);
            fwrite(current_ptr->phone_num, sizeof(phone_num), 1, fp);
            fwrite(current_ptr->time_num, sizeof(time_num), 1, fp);


            current_ptr = current_ptr->next;          //��current_ptrָ����һ���ڵ�
        } while (current_ptr != NULL);                             // ѭ��ֱ����β
    }

    fwrite(_T("END OF FILE"), sizeof(last_name), 1, fp);
    // "END OF FILE"����ʹ���ļ��ж�������ʱ�ж��Ƿ񵽴��ļ�β��
    fclose(fp);                                       // �ر��ļ�
    delete_list();
}                                                  //���� write_list_to_file ����

/*���û��ļ��ж�ȡ�����ؽ�����*/
void friend_node::load_list_from_file()
{
    friend_node* new_rec_ptr;               //����һ�����ٿռ��ָ��


    FILE* fp;
    int end_loop = 0;           //����һ���ж��Ƿ������ȡ�ļ������ݵı���
    fopen_s(&fp, fname, "ab");
    fwrite(_T("END OF FILE"), sizeof(last_name), 1, fp);
    fclose(fp);
    //���ļ�ĩβ��ӱ�־���������򴴽��ļ�
    fopen_s(&fp, fname, "rb");
    do
    {
        new_rec_ptr = new friend_node;           // Ϊ�ڵ�����ռ�

        if (new_rec_ptr != NULL)                     // �������ռ��Ƿ�ɹ�
        {
            fread(new_rec_ptr->last_name, sizeof(last_name), 1, fp);    // ���ļ��ж���'��'��Ϣ
            if ((wcscmp(new_rec_ptr->last_name, _T("                    ")) != 0) && (wcscmp(new_rec_ptr->last_name, _T("END OF FILE")) != 0))  //���û���ļ�β�����������ļ��ж�ȡ����
            {

                fread(new_rec_ptr->first_name, sizeof(first_name), 1, fp);  //���ļ��ж���'��'��Ϣ

                fread(new_rec_ptr->phone_num, sizeof(phone_num), 1, fp);   //���ļ��ж���'�绰����'��Ϣ
                fread(new_rec_ptr->time_num, sizeof(time_num), 1, fp);

                insert_node(new_rec_ptr);                     //���ú�������¼����ڵ�
            }
            else       // ��������ļ�β�����ͷ��������Ŀռ䣬�����end_loop����
            {
                delete new_rec_ptr;
                end_loop = 1;
            }
        }
        else            // �������ռ�����������棬�����end_loop����
        {
            cout << "����: ����ռ����. ��Ӳ�̶������ݲ��ɹ���\n";
            end_loop = 1;
        }
    } while (end_loop == 0);                   // ѭ��ֱ��end_loopΪ1���˳�
    fclose(fp);                                // �ر��ļ�.

}                                                     // ���� load_list_from_file ����

/*ɾ������ѡ��*/
void friend_node::delete_choose()
{
    loadimage(&delete_choise, L"delete_choise.png");//����ͼƬ
    putimage(0, 0, &delete_choise);//��ʾͼƬ

        //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 505 && msg.x < 810 && msg.y > 250 && msg.y < 325)//������ض����򣬼�����ȫ��ɾ��¼��ť��������
                {
                    loadimage(&delete_choise_fullname, L"delete_choise_fullname.png");//����ͼƬ
                    putimage(0, 0, &delete_choise_fullname);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    delete_record(); //���ø���ȫ��ɾ������
                }
                if (msg.x > 520 && msg.x < 790 && msg.y > 395 && msg.y < 465)//������ض����򣬼�ȫɾ��¼��ť��������
                {
                    loadimage(&delete_choise_all, L"delete_choise_all.png");//����ͼƬ
                    putimage(0, 0, &delete_choise_all);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    delete_allrecord(); //����ȫɾ������
                    loadimage(&delete_choise, L"delete_choise.png");//����ͼƬ
                    putimage(0, 0, &delete_choise);//��ʾͼƬ
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&delete_choise_back, L"delete_choise_back.png");//����ͼƬ
                    putimage(0, 0, &delete_choise_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    handle_choice(); //�����ϼ��˵�����
                }
            }
        }
    }
}


/*����ȫ��ɾ��һ���ڵ㣨�޸Ĳ��գ�*/
void friend_node::delete_record()
{
    int flag = 0;
    loadimage(&delete_choise_fullname_display, L"delete_choise_fullname_display.png");//����ͼƬ
    putimage(0, 0, &delete_choise_fullname_display);//��ʾͼƬ
    setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
    settextcolor(COLORREF(RGB(0, 0, 0)));//����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����"));//���������С20����ʽ����
    if (head_ptr == NULL)
    {
        outtextxy(400, 60, _T("����û�м�¼Ŷ���Ͽ�ȥ����һ���ɣ�"));
    }                                //���û�м�¼����ʾ�޼�¼ɾ��

    else
    {
        friend_node* previous_ptr;       //���ڲ��ұ�ɾ���ڵ�ǰһ�ڵ��ָ��
        previous_ptr = NULL;             // ʹprevious_ptrָ��ָ��NULL.
        current_ptr = head_ptr;          //��current_ptrָ��������ɾ��list��ͷ
        wchar_t search_last_string[20];
        wchar_t search_first_string[15];     //������Ҫɾ����������
        InputBox(search_first_string, 15, _T("��������Ҫɾ���ļ�¼�ߵ���: "));
        InputBox(search_last_string, 20, _T("��������Ҫɾ���ļ�¼�ߵ���: "));

        do
        {
            flag = 0;
            loadimage(&delete_choise_fullname_display, L"delete_choise_fullname_display.png");//����ͼƬ
            putimage(0, 0, &delete_choise_fullname_display);//��ʾͼƬ
            while ((current_ptr->next != NULL) &&
                ((wcscmp(current_ptr->last_name, search_last_string) != 0) ||
                    (wcscmp(current_ptr->first_name, search_first_string) != 0)))
                //	��������ƥ��ļ�¼ֱ���ҵ����ѵ���β								
            {  //������currentԽ�磬�������˵�һ���ж�
                previous_ptr = current_ptr;      // �ڸü�¼��ɾ��ǰ����previous_ptrָ���� 
                current_ptr = current_ptr->next;
            }
            if ((wcscmp(current_ptr->last_name, search_last_string) == 0) ||
                (wcscmp(current_ptr->first_name, search_first_string) == 0))           // �ҵ���ƥ��ļ�¼
            {       //��Ϊ��һ�����ƣ���������ط������ٰѳ�����Ϊ��׼
                outtextxy(400, 60, _T(" ����         �绰����          ����"));
                display(400, 80);

                if (verify_delete())            // ȷ��Ҫɾ����¼
                {
                    delete_node(previous_ptr);     // ���� delete_node ����ɾ����¼
                    MessageBox(NULL, _T("ɾ���ɹ���"), _T("ɾ����¼"), MB_SETFOREGROUND | MB_ICONASTERISK);
                }
                else  //���ѡ��񣬵ü������£�����current����ָ����һ��
                {
                    if (current_ptr != NULL && current_ptr->next != NULL)
                    {
                        current_ptr = current_ptr->next;
                        flag = 1;                       //Ϊ�˷�ֹ�����һ���ڵ�whileѭ��������������flag��ǣ�flag����õ���Чҩ��
                    }
                    else
                        break;   //���˽ڵ�Ϊ���һ���ڵ�ʱ�Զ��˳���������ѭ��
                }
            }
            else                              // ���û�ҵ���ƥ��ļ�¼����ʾ�޼�¼��ɾ
            {
                outtextxy(400, 60, _T("ȫ����¼����Ѱ��ϣ�"));
            }


        } while ((current_ptr != NULL && current_ptr->next != NULL) || flag == 1);      //�����ּ�¼ͬ�������ʱ�����Լ���Ѱ�Ҳ�ɾ��
    }

    loadimage(&delete_choise_fullname_display, L"delete_choise_fullname_display.png");//����ͼƬ
    putimage(0, 0, &delete_choise_fullname_display);//��ʾͼƬ
    outtextxy(400, 60, _T("ȫ����¼����Ѱ��ϣ�"));//ˢ����Ļһ����
    //���������꽻����
    MOUSEMSG msg;//������������������Ϣ
    FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
    while (true) // ��ѭ��,ѭ�����������Ϣ
    {
        while (MouseHit())	//���������Ϣ;���������Ϣ��ʱ��ִ��,�ɼ�������������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (WM_LBUTTONDOWN == msg.uMsg)//�ж������Ϣ;����������
            {
                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//������ض����򣬼����ذ�ť��������
                {
                    loadimage(&delete_choise_fullname_display_back, L"delete_choise_fullname_display_back.png");//����ͼƬ
                    putimage(0, 0, &delete_choise_fullname_display_back);//��ʾͼƬ
                    Sleep(100);//��ʱ������CPUռ���ʣ������������Ч��
                    delete_choose(); //�����ϼ��˵�����
                }
            }
        }
    }

}                                        //���� delete_record ����

/*ɾ�����м�¼*/
void friend_node::delete_allrecord()
{
    if (head_ptr == NULL)
    {
        MessageBox(NULL, _T("����û�м�¼Ŷ���Ͽ�ȥ����һ���ɣ�"), _T("ɾ����¼"), MB_SETFOREGROUND | MB_ICONASTERISK);
    }                                     //��û�м�¼����ʾ�޼�¼��ɾ��

    else
    {
        if (verify_delete())                                     // ȷ��Ҫɾ����¼
        {
            delete_list();                              //�����ͷ��ڴ�ռ�ĺ���
            head_ptr = NULL;                                //ʹͷָ��ָ��
            MessageBox(NULL, _T("��ɾ�����м�¼��"), _T("ɾ����¼"), MB_SETFOREGROUND | MB_ICONASTERISK);
        }
    }

}                                                      //����delete_allrecord����

/*ȷ���Ƿ�ɾ����¼*/
int friend_node::verify_delete()
{
    int result = MessageBox(NULL, _T("��ȷʵҪɾ����ѡ��¼��"), _T("ɾ����¼"), MB_SETFOREGROUND | MB_ICONQUESTION | MB_YESNO);
    return result == IDYES;
}                                       //����verify_delete����

/*ɾ��*current_ptr��ָ��¼*/
void friend_node::delete_node(friend_node* previous_ptr)

{
    if (current_ptr == head_ptr)             // ���*current_ptrָ������
    {
        delete_head_of_list();       //����delete_head_of_list()������ɾ������
    }
    else
    {
        if (current_ptr->next == NULL)       //���*current_ptrָ����β
        {
            delete_end_of_list(previous_ptr);  //����delete_head_of_list()������ɾ����β
        }
        else                       // ���*current_ptrָ�����м�
        {
            delete_from_middle_of_list(previous_ptr);
            //����delete_from_middle_of_list()������ɾ����ȥ���׺���β����������
        }
    }
}                                   //����delete_node����

/*ɾ������*/
void friend_node::delete_head_of_list()
{
    current_ptr = head_ptr;                        //����ǰλ��ָ������
    if (head_ptr->next != NULL)
    {
        head_ptr = current_ptr->next;  //������׺�����ڲ�Ϊ�գ�����һ������Ϊ����
        head_ptr->prev = NULL;          //���׵�ǰָ��Ϊ��
    }
    else                            //���׺�����Ϊ�գ���ɾ��ԭ���ף�����Ϊ��
    {
        head_ptr = NULL;
    }
    delete current_ptr;                      //�ͷ�current_ptrָ����ռ�ռ�
    current_ptr = head_ptr;               // ����ǰָ��ָ������
}                                     //����delete_head_of_list����

/*ɾ����β�ĺ���*/
void friend_node::delete_end_of_list(friend_node* previous_ptr)

{
    delete current_ptr;                   // ɾ��current_ptr��ָ���ڣ�����β
    previous_ptr->next = NULL;            // ʹ�����ڶ���������Ϊ�µ���β
    current_ptr = head_ptr;               // ����ǰָ��ָ������
}                                   //����delete_end_of_list����

/*ɾ���м����ڵĺ���*/
void friend_node::delete_from_middle_of_list(friend_node* previous_ptr)

{
    previous_ptr->next = current_ptr->next;              //����Ҫɾ�������ڣ�
    // current_ptrָ��Ҫɾ���ļ�¼��ʹprevious_ptr->nextָ��current_ptr->next
    current_ptr->next->prev = previous_ptr;         //�ָ�˫��
    delete current_ptr;                            // ɾ��current_ptr��ָ����
    current_ptr = head_ptr;                            //����ǰָ��ָ������
}                               //����delete_from_middle_of_list����

/*�ͷ�������ռ�ռ�ĺ���*/
void friend_node::delete_list()
{
    friend_node* temp_ptr;                 // ����һ����ʱ�м����ָ��
    current_ptr = head_ptr;                 //��current_ptrָ��list�Ŀ�ͷ
    do                                        // ����ͷ�ÿ��������ռ�ռ�
    {
        temp_ptr = current_ptr->next;            //ʹ����ʱָ����ָ����һ����ַ��ʵ�����ɾ��                         
        delete current_ptr;
        current_ptr = temp_ptr;
    } while (temp_ptr != NULL);
    current_ptr = NULL;
    head_ptr = NULL;
}                                                    //����delete_list����
