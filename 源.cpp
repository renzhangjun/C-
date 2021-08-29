/*------------------------第5题	电话簿管理1.0-----------------------------*/
#include<fstream>       
#include<conio.h>
#include<iostream>  //凡是没有加 .h 的都是为了适应 visual studio，在其他编译器中得加上
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cstring>
#include<vector>
#include <windows.h>
#include <graphics.h>      // 引用图形库头文件
#include<stdio.h>
#include<math.h>
#include<tchar.h>
#include <atlconv.h>
#include <MMSystem.h>//头文件大小写都可识别;播放音乐mci需要的头文件
#pragma comment(lib,"winmm.lib")//加载winmm.lib库文件
using namespace std;
#pragma warning(disable : 4996)          
//visual studio中使用strcat会报安全错误，此语句用来忽视错误，但在其他编译器中可能会不识别此句话，注意删除

/*******************宏定义***********************/

#define NULL 0    

/******************定义图片**********************/
IMAGE welcome;//欢迎界面
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

/*******************类定义***********************/

/*定义记录类friend_node*/
class  friend_node
{
private:
    int year;//储存录入时间年
    int month; //储存录入时间月
    int day; //储存录入时间天
    int hour; //储存录入时间小时
    int minute; //储存录入时间分钟
    int second;//储存录入时间秒
    wchar_t last_name[20];  //储存姓
    wchar_t first_name[15];  //储存名
    wchar_t phone_num[12];  //储存电话号码
    wchar_t time_num[50];//储存日期
    friend_node* prev;
    friend_node* next;          //表示双链表结构的*prev,*next指针
public:
    void page(); //欢迎界面函数
    void handle_choice();//根据用户选择调用相应功能
    void add_record();              // 增加一个新节点
    void insert_node(friend_node* new_rec_ptr);     //将新节点插入链表
    friend_node* position_insertion_point(wchar_t lastname[20]);       //寻找新节点插入的位置
    void make_node_new_head(friend_node* new_rec_ptr);      //将新节点插入链首
    void add_node_to_end(friend_node* new_rec_ptr);     //将新节点插入链尾
    void move_current_to_end();                     //将当前位置指向链尾
    void display_choose();                 //选择输出模式
    void display_list();                //显示所有电话记录    
    void display_somelist();                //逐屏显示（新添加）
    void display(int position_x, int position_y);  //界面输出（新添加）
    void delete_choose();               //删除功能选择
    void delete_record();              //删除一个节点
    void delete_allrecord();          //删除所有节点（新添加）
    void delete_head_of_list();        //删除链首节点
    void delete_end_of_list(friend_node* previous_ptr);//删除链尾节点
    void delete_from_middle_of_list(friend_node* previous_ptr); //删除中间节点
    int verify_delete();               //确认是否删除
    void delete_node(friend_node* previous_ptr);	//删除*current_ptr所指节点
    void delete_list();                 //删除整个列表  
    void search_choice();//根据用户选择调用相应查找函数
    void search_by_firstname();//根据名（firstname）查找
    void search_by_lastname();//根据姓（lastname）查找
    void search_by_initial_letter(); //根据首字母查找（新添加）
    void search_by_fullname();         //根据姓名查找
    void write_list_to_file();          //将记录保存到文件中
    void load_list_from_file();         //从数据文件FRIENDS.DAT中读取数据重建链表处理
    void help_me();                     //帮助菜单
    void replace();                     //节点修改（新添加）
    void time_note(friend_node* new_rec_ptr);    //将时间传递进记录（新添加）
};

/*定义时间类time_record*/
class  time_record
{
public:
    int year;//表示录入时间年
    int month; //表示录入时间月
    int day; //表示录入时间天
    int hour; //表示录入时间小时
    int minute; //表示录入时间分钟
    int second;//表示录入时间秒
    time_t time_date;//表示录入时间
    tm* CurrentTime;//表示时间类型的指针变量
    time_record* tm_year;//指向时间年的指针
    time_record* tm_mon;//指向时间月的指针
    time_record* tm_mday;//指向时间天的指针
    time_record* tm_hour;//指向时间小时的指针
    time_record* tm_min;//指向时间分钟的指针

    void time_check();//记录时间的函数
};

/*定义用户类*/
class USER
{
private:
    int Num;//编号
    wchar_t name[20];
    wchar_t password1[20];
    wchar_t password2[20];
    wchar_t temp;
public:
    void Register();
    void Login();
    void Display();
}user[100];    //定义用户数量

/********************全局变量***********************/
int UserNum = 0;                       //用户的数量，从0开始
int  usernumber;                      //储存用户的编号
char fname[20];                        //储存用户名
wchar_t pause;                         //用于形成输入阻塞
wchar_t fullname[36];                  //全局变量，用于将姓和名合并
friend_node* head_ptr = NULL;              //全局变量，链头指针，初始化为空
friend_node* current_ptr = NULL;           //全局变量，用于指明当前在链表中的位置

/*******************函数声明***********************/



/*主函数*/
int main()
{
    initgraph(1280, 720);      //定义图形窗口大小
    mciSendString(_T("open bloomofyouth.mp3 alias mymusic"), NULL, 0, NULL);//打开音乐
    mciSendString(_T("play mymusic repeat"), 0, 0, 0);// 重复播放"bloom of youth.mp3"
    USER u;                  //定义一个用户对象
    u.Display();            //显示主页面　　１注册；２登录； 3 退出。
    return 0;
}

/*主页面*/
void USER::Display()
{
    char file_name[128];
    char kb;  //储存键盘信息
    IMAGE image;//播放数组
    //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标键盘信息
    {
        for (int i = 0; i < 1286; i++)
        {
            float ftime;			//记录时间间隔变量
            DWORD startTime = GetTickCount();//记录开始时间

            if (_kbhit())//监听键盘信息
            {
                kb = _getch();
                if (kb == 27)  //esc的ASCII码
                {
                    exit(EXIT_FAILURE); //退出程序
                }
            }
            if (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
            {
                msg = GetMouseMsg();//获取鼠标消息
                if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
                {
                    if (msg.x > 65 && msg.x < 405 && msg.y > 500 && msg.y < 660)//鼠标点击特定区域，即注册按钮所在区域
                    {
                        Register();         //调用register函数
                    }

                    if (msg.x > 870 && msg.x < 1210 && msg.y > 520 && msg.y < 670)//鼠标点击特定区域，即登陆按钮所在区域
                    {
                        Login();            //调用login函数
                    }
                }
            }

            putimage(0, 0, &image);
            sprintf(file_name, "1\\%d.jpg", i + 1); //加载图片
            int num = MultiByteToWideChar(0, 0, file_name, -1, NULL, 0);// 将char*转为LPCTSTR
            wchar_t* wide = new wchar_t[num];
            MultiByteToWideChar(0, 0, file_name, -1, wide, num);
            loadimage(&image, wide);//将属性改为多字符集,则可写变量

            do
            {
                DWORD totalTime = GetTickCount() - startTime;//从开始到现在所经历的时间（毫秒）
                ftime = (float)totalTime;			//转换为浮点数
            } while (ftime < 30);			//为了精确控制播放每一个图片的时间间隔

        }


    }
}

/*注册*/
void USER::Register()
{
    FILE* fp;
    fopen_s(&fp, "user.txt", "a+");//若不存在则新建文件

    //把注册的ID、key保存到user.txt文件当中
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
    //输入用户名
    int i;
    do {
        InputBox(user[UserNum].name, 20, _T("请输入用户名"));//提示用户输入用户名
        //接下来查找用户信息表中的内容，比较新输入的用户名是否存在，如果存在，系统给出提示
        for (i = 0; i < UserNum; i++)
        {
            if (wcscmp(user[i].name, user[UserNum].name) == 0)
            {
                MessageBox(NULL, _T("该用户已经存在，请重新输入"), _T("创建账户"), MB_ICONSTOP | MB_SETFOREGROUND);//输出提示，提醒用户
                break;//跳出for循环
                      //修复了1.0版本用户注册时出现的bug
            }

        }
        if (i >= UserNum)//说明没有找到重复的用户名 
            break;
    } while (1);//如果用户名重复则一直循环，直到不重复时跳出循环 
               //输入用户名函数结束 



      /*下面设置用户密码*/
    do
    {
        InputBox(user[UserNum].password1, 20, _T("请设置密码"));//提示用户输入密码
        InputBox(user[UserNum].password2, 20, _T("请确认密码"));//提示用户确认密码
        if (wcscmp(user[UserNum].password1, user[UserNum].password2) != 0)//两次输入密码不相等 
            MessageBox(NULL, _T("两次输入不一致，请重新输入"), _T("创建账户"), MB_ICONSTOP | MB_SETFOREGROUND);
        else
        {
            MessageBox(NULL, _T("注册成功！"), _T("创建账户"), MB_SETFOREGROUND | MB_ICONASTERISK);
            //参数分别为：消息框拥有的窗口、消息框的内容、消息框的标题、标志集(多个标志用"与"(|)符号连接)
           //最后的参数表示设置消息框为前景窗口

            UserNum++;//代表下一个将要注册的学生用户的编号
            user[UserNum - 1].Num = UserNum;//加一 
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

/*登录*/
void USER::Login()
{
    int i;
    wchar_t username[20];//定义一个临时存储用户名的字符数组 
    wchar_t password[20];//定义一个临时存储密码的字符数组 

    FILE* fp;
    fopen_s(&fp, "user.txt", "a");
    fclose(fp);   //若不存在则新建文件

    fopen_s(&fp, "user.txt", "r");
    //把注册的ID、key保存到user.txt文件当中
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

    InputBox(username, 10, _T("请输入用户名"));//提示用户输入用户名，输入给临时存储用户名的字符数组

    for (i = 0; i < UserNum; i++)
    {
        if (wcscmp(username, user[i].name) == 0)//找到了 
        {
            usernumber = i;
            break;//跳出for循环
        }
    }

    if (i >= UserNum)//说明没有找到对应用户名 
    {
        MessageBox(NULL, _T("该用户不存在"), _T("用户登录"), MB_ICONSTOP | MB_SETFOREGROUND);
    }
    else  //找到用户名，输入密码
    {
        USES_CONVERSION;//宏
        char* pa = W2A(username);//返回一个 ASNI标准的多字节字符
        strcpy(fname, pa);  //将文件名用用户名表示
        strcat(fname, ".txt");
        do
        {
            InputBox(password, 10, _T("请输入密码"));//提示用户输入密码，输入给临时存储密码的字符数组

            if (wcscmp(password, user[usernumber].password1) == 0)         //如果密码正确，登录成功
            {
                MessageBox(NULL, _T("登录成功！"), _T("用户登录"), MB_SETFOREGROUND);

                friend_node object;             //定义一个对象

                object.load_list_from_file(); //将数据保存在文件中
                object.handle_choice(); //调用函数执行用户的选择
                break;


            }
            else
            {
                int result = MessageBox(NULL, _T("密码错误"), _T("学生登录"), MB_ICONWARNING | MB_SETFOREGROUND | MB_RETRYCANCEL);

                if (result == IDCANCEL)
                    break;   //取消输入密码，退出循环
            }
        } while (1);
    }
}


/*主选择界面*/
void friend_node::handle_choice()
{
    loadimage(&welcome, L"welcome.png");//导入欢迎界面
    putimage(0, 0, &welcome);//显示欢迎界面

    //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 135 && msg.x < 350 && msg.y > 120 && msg.y < 200)//鼠标点击特定区域，即新建记录按钮所在区域
                {
                    loadimage(&add, L"add.png");//导入add图片
                    putimage(0, 0, &add);//显示add图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    add_record(); //调用函数增加节点
                }

                if (msg.x > 135 && msg.x < 350 && msg.y > 525 && msg.y < 600)//鼠标点击特定区域，即查找记录按钮所在区域
                {
                    loadimage(&search, L"search.png");//导入search图片
                    putimage(0, 0, &search);//显示search图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_choice(); //调用查找函数
                }

                if (msg.x > 135 && msg.x < 350 && msg.y > 320 && msg.y < 395)//鼠标点击特定区域，即显示记录按钮所在区域
                {
                    loadimage(&display_png, L"display.png");//导入search图片
                    putimage(0, 0, &display_png);//显示display图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    display_choose(); //调用显示函数
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 120 && msg.y < 195)//鼠标点击特定区域，即删除记录按钮所在区域
                {
                    loadimage(&delete_png, L"delete.png");//导入图片
                    putimage(0, 0, &delete_png);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    delete_choose(); //调用函数
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 325 && msg.y < 395)//鼠标点击特定区域，即修改记录按钮所在区域
                {
                    loadimage(&replace_png, L"replace.png");//导入图片
                    putimage(0, 0, &replace_png);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    replace(); //调用函数
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 525 && msg.y < 600)//鼠标点击特定区域，即修改记录按钮所在区域
                {
                    loadimage(&help, L"help.png");//导入图片
                    putimage(0, 0, &help);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    help_me(); //调用函数
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即退出按钮所在区域
                {
                    write_list_to_file();
                    USER u;                  //定义一个用户对象
                    u.Display();
                }
            }
        }
    }
}

/* 在链表中增加一个新节点*/
void friend_node::add_record()
{
    friend_node* new_rec_ptr;                // 定义一个指向新节点的指针
    new_rec_ptr = new friend_node;           // 申请新的内存空间，使指针指向该内存空间

    if (new_rec_ptr != NULL)                  // 如果*new_rec_ptr所指空间不为空
    {                                              //储存用户输入的名字和电话号码    
        InputBox(new_rec_ptr->last_name, 20, _T("Last Name(姓): "));// _T为了与unicode兼容
        while (wcscmp(new_rec_ptr->last_name, _T("")) == 0)//wcscmp类似于strcmp
        {                  //避免输入空字符后影响文件读取（文件读取函数将空字符与“end”设为结束的标志）
            MessageBox(NULL, _T("输入无效，请重新输入"), _T("Last Name(姓): "), MB_ICONSTOP | MB_SETFOREGROUND);
            //参数分别为：消息框拥有的窗口、消息框的内容、消息框的标题、标志集(多个标志用"与"(|)符号连接)
           //最后的参数表示设置消息框为前景窗口
            InputBox(new_rec_ptr->last_name, 20, _T("Last Name(姓): "));
        }
        InputBox(new_rec_ptr->first_name, 20, _T("First Name(名): "));
        InputBox(new_rec_ptr->phone_num, 15, _T("Phone Number(电话号码): "));
        time_note(new_rec_ptr);    //调用函数将时间传递进记录

        friend_node* search_mate_ptr = head_ptr; //定义一个用于寻找的指针

        while ((search_mate_ptr != NULL) && wcscmp(search_mate_ptr->phone_num, new_rec_ptr->phone_num) != 0)
            //向后查找相匹配的记录直到找到或已到链尾
        {
            search_mate_ptr = search_mate_ptr->next;
        }

        if (search_mate_ptr != NULL)        // 原记录有相同手机号码的，提示覆盖原记录或取消操作
        {
            loadimage(&add_display, L"add_display.png");
            putimage(0, 0, &add_display);
            friend_node* persent_ptr;      //定义一个临时指针存放current_ptr
            persent_ptr = current_ptr;
            current_ptr = search_mate_ptr;

            setbkmode(TRANSPARENT);//设置字体背景为透明
            settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
            settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体
            display(780, 80);   //展示函数，此函数中要用到指针变量current_ptr，还要提初始位置
            outtextxy(780, 60, _T(" 姓名         电话号码          日期"));//显示表格第一行表头          
            current_ptr = persent_ptr;
            int result = MessageBox(NULL, _T("该号码已存在，是否选择覆盖原有记录？"), _T("添加记录"), MB_SETFOREGROUND | MB_ICONASTERISK | MB_YESNO);

            if (result == IDYES)     //覆盖原有记录     
            {
                delete search_mate_ptr;         //释放原空间，将新节点插入链表
                insert_node(new_rec_ptr);       //调用插入函数                  
                MessageBox(NULL, _T("修改成功！"), _T("添加记录"), MB_SETFOREGROUND);
            }
        }
        else                                        //原记录中没有同名的，则继续添加
        {
            insert_node(new_rec_ptr);            //将建立的新节点插入到链表中
        }
    }
    else                                     // 如果开辟空间失败，新记录不能添加，并警告提示
    {
        MessageBox(NULL, _T("警告：存储过程中有错，新的记录不能添加！\n"), _T("添加记录"), MB_SETFOREGROUND);
    }
    handle_choice();
}                                          // 结束 add_record函数

/*将时间传递进新记录*/
void friend_node::time_note(friend_node* new_rec_ptr)
{
    time_record tmnote;//定义time_record类对象
    tmnote.time_check();//调用函数获取当前时间
    new_rec_ptr->year = tmnote.year;//表示录入时间年
    new_rec_ptr->month = tmnote.month; //表示录入时间月
    new_rec_ptr->day = tmnote.day; //表示录入时间天
    new_rec_ptr->hour = tmnote.hour; //表示录入时间小时
    new_rec_ptr->minute = tmnote.minute; //表示录入时间分钟
    new_rec_ptr->second = tmnote.second;//表示录入时间秒
    //在我程序中无法正确输出整型数，网上提供的方法x.str()等方法对我不管用，于是我采用了最原始的int-- > string-- > char[]-- > LPCTSTR转换。
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

/*记录时间*/
void time_record::time_check()
{
    time_date = time(NULL);//time( )函数是取得自格林威治时间1970年1月1日00：00所经过的秒数
    CurrentTime = localtime(&time_date);//localtime( )函数是将类型为time_t的时间值，放入结构类型为tm的结构中
    year = CurrentTime->tm_year + 1900;//将当前时间变为标准形式
    month = CurrentTime->tm_mon + 1;//取出月份赋给类中的私有数据Month,tm_mon是从0开始，表示12月份依次为0～11，故真实月份需加一
    day = CurrentTime->tm_mday;//取出当前时间的天数
    hour = CurrentTime->tm_hour;//取出当前时间的小时数
    minute = CurrentTime->tm_min;//取出当前时间的分钟数
    second = CurrentTime->tm_sec;//取出当前时间的秒数
}

/*输出current指针所指内容*/
void friend_node::display(int position_x, int position_y)
{
    wcscpy(fullname, _T(""));              // 清空全局变量fullname数组
    wcscat(fullname, current_ptr->last_name);
    wcscat(fullname, _T(" "));
    wcscat(fullname, current_ptr->first_name);    //将姓和名连接到fullname中
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体
    outtextxy(position_x, position_y, fullname);
    outtextxy(position_x + 130, position_y, current_ptr->phone_num);
    outtextxy(position_x + 280, position_y, current_ptr->time_num);
}									      // 结束 display() 函数

/*将一个由new_rec_ptr 指向的新节点插入链表中*/
void friend_node::insert_node(friend_node* new_rec_ptr)
{
    friend_node* before_ptr;
    friend_node* after_ptr;                  //定义两个指针，用于指向新节点的前一节点与后一节点

    if (head_ptr == NULL)                     // 如果原链表为空，即无记录
    {
        new_rec_ptr->next = NULL;              // 如果链表为空，将记录添加到链首
        new_rec_ptr->prev = NULL;
        head_ptr = new_rec_ptr;
    }
    else                                     // 原链表不为空
    {
        if (wcscmp(new_rec_ptr->last_name, head_ptr->last_name) < 0)
        {                                      // 如果要插入的新记录的姓在链首的姓之前
            make_node_new_head(new_rec_ptr);   // 调用函数插入到链首
        }
        else
        {
            current_ptr = position_insertion_point(new_rec_ptr->last_name);   //调用函数找出应插入的位置，将应该断开的前一个节点赋给*current
            before_ptr = current_ptr;
            after_ptr = current_ptr->next;

            if (after_ptr == NULL)               // 如果要插入的新记录的姓在链尾的姓之后
            {
                add_node_to_end(new_rec_ptr);     //调用函数插入到链尾
            }
            else                  // 如果要插入的新记录的姓在链表中间
            {
                before_ptr->next = new_rec_ptr;        //改变指向，将新节点加入链表
                new_rec_ptr->prev = before_ptr;
                new_rec_ptr->next = after_ptr;
                after_ptr->prev = new_rec_ptr;
            }
        }
    }
}                            // 结束 insert_node 函数

/*根据用户选择调用相应查找函数*/
void friend_node::search_choice()
{
    loadimage(&search_choose, L"search_choose.png");//导入search图片
    putimage(0, 0, &search_choose);//显示search图片

     //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 135 && msg.x < 350 && msg.y > 120 && msg.y < 200)//鼠标点击特定区域，即全名查找按钮所在区域
                {
                    loadimage(&search_fullname, L"search_fullname.png");//导入图片
                    putimage(0, 0, &search_fullname);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_by_fullname(); //调用全名查找函数
                }

                if (msg.x > 135 && msg.x < 350 && msg.y > 525 && msg.y < 600)//鼠标点击特定区域，即姓查找记录按钮所在区域
                {
                    loadimage(&search_lastname, L"search_lastname.png");//导入图片
                    putimage(0, 0, &search_lastname);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_by_lastname(); //调用姓查找函数
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 120 && msg.y < 200)//鼠标点击特定区域，即首字母查找记录按钮所在区域
                {
                    loadimage(&search_str, L"search_str.png");//导入图片
                    putimage(0, 0, &search_str);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_by_initial_letter(); //调用首字母查找函数
                }

                if (msg.x > 960 && msg.x < 1170 && msg.y > 525 && msg.y < 600)//鼠标点击特定区域，即名查找记录按钮所在区域
                {
                    loadimage(&search_firstname, L"search_firstname.png");//导入图片
                    putimage(0, 0, &search_firstname);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_by_firstname(); //调用名查找函数
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&search_back, L"search_back.png");//导入图片
                    putimage(0, 0, &search_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    handle_choice(); //调用主菜单函数
                }
            }
        }
    }
}

/*根据姓名查找记录*/
void friend_node::search_by_fullname()
{
    int count = 0;
    loadimage(&search_fullname_display, L"search_fullname_display.png");//导入search图片
    putimage(0, 0, &search_fullname_display);//显示search图片
    wchar_t search_last_string[20];           // 储存想要查找的姓
    wchar_t search_first_string[15];              // 储存想要查找的名
    current_ptr = head_ptr;                   // 将current指针指向链首
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体


    InputBox(search_first_string, 15, _T("请输入您要查找内容的名: "));
    InputBox(search_last_string, 20, _T("请输入您要查找内容的姓: "));

    while ((current_ptr != NULL) &&
        ((wcscmp(current_ptr->last_name, search_last_string) != 0) ||
            (wcscmp(current_ptr->first_name, search_first_string) != 0)))
        //向后查找相匹配的记录直到找到或已到链尾
    {
        current_ptr = current_ptr->next;
    }
    if (current_ptr != NULL)        // 找到相匹配的记录
    {
        outtextxy(780, 60, _T(" 姓名         电话号码          日期"));
        count++;

        display(780, 80);                  //调用展示函数


        while (current_ptr != NULL)             //继续查找剩下的节点（当同名时可以全部查出）
        {
            current_ptr = current_ptr->next;
            if (current_ptr != NULL && (wcscmp(current_ptr->last_name, search_last_string) == 0) &&
                (wcscmp(current_ptr->first_name, search_first_string) == 0))
            {
                display(780, 80 + count * 20);             //调用展示函数
                count++;
            }
        }
    }
    else                            //没有找到所查找的记录
    {
        outtextxy(780, 60, _T("对不起，没有找到您所查找的记录"));
    }

    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 135 && msg.x < 350 && msg.y > 525 && msg.y < 600)//鼠标点击特定区域，即姓查找按钮所在区域
                {
                    loadimage(&search_fullname_display_lastname, L"search_fullname_display_lastname.png");//导入图片
                    putimage(0, 0, &search_fullname_display_lastname);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_by_lastname(); //调用姓查找函数
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&search_fullname_display_back, L"search_fullname_display_back.png");//导入图片
                    putimage(0, 0, &search_fullname_display_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_choice(); //调用上级菜单函数
                }
            }
        }
    }

}                                                   //结束 search_by_lastname 函数

/* 根据名（firstname）查找记录*/
void friend_node::search_by_firstname()
{
    loadimage(&search_firstname_display, L"search_firstname_display.png");//导入search图片
    putimage(0, 0, &search_firstname_display);//显示search图片
    int count = 0;
    wchar_t search_first_string[20];  // 存放查找的内容
    current_ptr = head_ptr;  //current指针指向头节点
    InputBox(search_first_string, 20, _T("请输入您要查找内容的名: "));
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体

    while ((current_ptr != NULL) &&
        (wcscmp(current_ptr->first_name, search_first_string) != 0))
        //向后查找相匹配的记录直到找到或已到链尾
    {
        current_ptr = current_ptr->next;
    }

    if (current_ptr != NULL)        // 找到相匹配的记录
    {
        outtextxy(30, 60, _T(" 姓名         电话号码          日期"));
        count++;

        display(30, 80);                  //调用展示函数

        while (current_ptr != NULL)             //继续查找剩下的节点（当同名时可以全部查出）
        {
            current_ptr = current_ptr->next;
            if (current_ptr != NULL && wcscmp(current_ptr->first_name, search_first_string) == 0)
            {
                display(30, 80 + count * 20);             //调用展示函数
                count++;
            }
        }
    }
    else                            //没有找到所查找的记录
    {
        outtextxy(30, 60, _T("对不起，没有找到您所查找的记录"));
    }

    //鼠标交互//
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 960 && msg.x < 1170 && msg.y > 120 && msg.y < 200)//鼠标点击特定区域，即首字母查找记录按钮所在区域
                {
                    loadimage(&search_firstname_display_str, L"search_firstname_display_str.png");//导入图片
                    putimage(0, 0, &search_firstname_display_str);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_by_initial_letter(); //调用首字母查找函数
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&search_firstname_display_back, L"search_firstname_display_back.png");//导入图片
                    putimage(0, 0, &search_firstname_display_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_choice(); //调用上级菜单函数
                }
            }
        }
    }
} // 结束search_by_firstname函数

/* 根据姓（lastname）查找记录*/
void friend_node::search_by_lastname()
{
    loadimage(&search_lastname_display, L"search_lastname_display.png");//导入search图片
    putimage(0, 0, &search_lastname_display);//显示search图片
    int count = 0;
    wchar_t search_last_string[20];  // 存放查找的内容
    current_ptr = head_ptr;  //current指针指向头节点
    InputBox(search_last_string, 20, _T("请输入您要查找内容的姓: "));
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体

    while ((current_ptr != NULL) &&
        (wcscmp(current_ptr->last_name, search_last_string) != 0))
        //向后查找相匹配的记录直到找到或已到链尾
    {
        current_ptr = current_ptr->next;
    }

    if (current_ptr != NULL)        // 找到相匹配的记录
    {
        outtextxy(780, 60, _T(" 姓名         电话号码          日期"));
        count++;
        display(780, 80);                  //调用展示函数

        while (current_ptr != NULL)             //继续查找剩下的节点（当同名时可以全部查出）
        {
            current_ptr = current_ptr->next;
            if (current_ptr != NULL && wcscmp(current_ptr->last_name, search_last_string) == 0)
            {
                display(780, 80 + count * 20);             //调用展示函数
                count++;
            }
        }
    }
    else                            //没有找到所查找的记录
    {
        outtextxy(780, 60, _T("对不起，没有找到您所查找的记录"));
    }

    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 135 && msg.x < 350 && msg.y > 120 && msg.y < 200)//鼠标点击特定区域，即全名查找按钮所在区域
                {
                    loadimage(&search_lastname_display_fullname, L"search_lastname_display_fullname.png");//导入图片
                    putimage(0, 0, &search_lastname_display_fullname);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_by_fullname(); //调用全名查找函数
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&search_lastname_display_back, L"search_lastname_display_back.png");//导入图片
                    putimage(0, 0, &search_lastname_display_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_choice(); //调用上级菜单函数
                }
            }
        }
    }
} // 结束search_by_firstname函数

/* 根据首字母查找记录*/
void friend_node::search_by_initial_letter()
{
    loadimage(&search_str_display, L"search_str_display.png");//导入search图片
    putimage(0, 0, &search_str_display);//显示search图片
    wchar_t szlast_name[2];// 定义一字符用来存放首字母
    int count = 0;
    current_ptr = head_ptr;  // 移current_ptr指针至链首
    InputBox(szlast_name, 20, _T("请输入你想查询者的姓的首字母: "));
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体

    while ((current_ptr != NULL) &&
        (current_ptr->last_name[0] != szlast_name[0]))
        //向后查找相匹配的记录直到找到或已到链尾
    {
        current_ptr = current_ptr->next;
    }

    if (current_ptr != NULL)        // 找到相匹配的记录
    {
        outtextxy(30, 60, _T(" 姓名         电话号码          日期"));
        count++;

        display(30, 80);                  //调用展示函数

        while (current_ptr != NULL)             //继续查找剩下的节点（当同名时可以全部查出）
        {
            current_ptr = current_ptr->next;
            if (current_ptr != NULL && current_ptr->last_name[0] == szlast_name[0])
            {
                display(30, 80 + count * 20);             //调用展示函数
                count++;
            }
        }
    }
    else                            //没有找到所查找的记录
    {
        outtextxy(30, 60, _T("对不起，没有找到您所查找的记录"));
    }

    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 960 && msg.x < 1170 && msg.y > 525 && msg.y < 600)//鼠标点击特定区域，即名查找记录按钮所在区域
                {
                    loadimage(&search_str_display_firstname, L"search_str_display_firstname.png");//导入图片
                    putimage(0, 0, &search_str_display_firstname);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_by_firstname(); //调用名查找函数
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&search_str_display_back, L"search_str_display_back.png");//导入图片
                    putimage(0, 0, &search_str_display_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    search_choice(); //调用上级菜单函数
                }
            }
        }
    }
} // 结束search_by_initial_letter函数

/*查找新节点插入位置*/
friend_node* friend_node::position_insertion_point(wchar_t lastname[20])
{                          // 根据姓氏大小，返回其在链表中的正确位置的前一节点。新节点即将插入此点之后。
    wchar_t temp_name[20];               //从链表中提取已有记录lastname的数组
    friend_node* temp_ptr;
    int tempint;                      //用于进行比较的整型变量

    if (head_ptr->next != NULL)             // 如果链表中有多个节点时，查找添加的正确位置
    {
        current_ptr = head_ptr;
        temp_ptr = current_ptr->next;
        wcscpy(temp_name, temp_ptr->last_name);//将链表中已有记录的lastname赋给temp_name  
        tempint = wcscmp(lastname, temp_name);                  //从头开始比较查找        
        while ((tempint > 0) && (current_ptr->next != NULL))   //进行循环一直向下比较查找（升序排列，且仅限姓）
        {
            current_ptr = temp_ptr;
            if (current_ptr->next != NULL)                       //确认将添加的位置不是链尾
            {
                temp_ptr = current_ptr->next;                   //继续往下比较
                wcscpy(temp_name, temp_ptr->last_name);
                tempint = wcscmp(lastname, temp_name);
            }
        }
    }
    else                                              // 如果链表中只有链首一个节点
    {
        current_ptr = head_ptr;                         //将当前位置指向链首
    }
    return(current_ptr);		//函数返回值为current_ptr
}                             // 结束 position_insertion_point 函数

/*将新记录添加在链首*/
void friend_node::make_node_new_head(friend_node* new_rec_ptr)
{
    friend_node* temp_ptr;                      //临时指针用于跟踪链表头
    temp_ptr = head_ptr;                      //将临时指针指向原链首
    temp_ptr->prev = new_rec_ptr;             //搭建新的双链
    new_rec_ptr->next = temp_ptr;
    new_rec_ptr->prev = NULL;                   //新节点prev指针为空
    head_ptr = new_rec_ptr;
}                             // 结束 make_node_new_head 函数

/*将新记录添加到链尾*/
void friend_node::add_node_to_end(friend_node* new_rec_ptr)
{
    new_rec_ptr->next = NULL;     //新节点next指针为空
    move_current_to_end();         //调用函数将全局指针current指向链尾
    current_ptr->next = new_rec_ptr;  // 搭建新的双链
    new_rec_ptr->prev = current_ptr;
}                                        // 结束 add_node_to_end 函数

/*将全局指针current指向链尾*/
void friend_node::move_current_to_end()
{
    current_ptr = head_ptr;           // 将current指针指到链首

    while (current_ptr->next != NULL)
    {                                 // 将current指针向后移直到链尾
        current_ptr = current_ptr->next;
    }
}                                         //结束 move_current_to_end 函数

/*选择输出显示模式*/
void friend_node::display_choose()
{
    loadimage(&display_choise, L"display_choise.png");//导入欢迎界面
    putimage(0, 0, &display_choise);//显示欢迎界面\

     //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 140 && msg.x < 210 && msg.y > 135 && msg.y < 375)//鼠标点击特定区域，即显示所有记录按钮所在区域
                {
                    loadimage(&display_choise_alllist, L"display_choise_alllist.png");//导入图片
                    putimage(0, 0, &display_choise_alllist);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    display_list(); //调用显示所有函数
                }

                if (msg.x > 1045 && msg.x < 1117 && msg.y > 135 && msg.y < 375)//鼠标点击特定区域，即逐屏显示按钮所在区域
                {
                    loadimage(&display_choise_somelist, L"display_choise_somelist.png");//导入图片
                    putimage(0, 0, &display_choise_somelist);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    display_somelist(); //调用逐屏显示函数
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&display_choise_back, L"display_choise_back.png");//导入图片
                    putimage(0, 0, &display_choise_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    handle_choice(); //调用主菜单函数
                }
            }
        }
    }
}

/*显示所有电话记录*/
void friend_node::display_list()
{
    int count = 0;
    loadimage(&display_list_all, L"display_list_all.png");//导入图片
    putimage(0, 0, &display_list_all);//显示图片
    current_ptr = head_ptr;           // 将current指针指到链首
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体


    if (current_ptr != NULL)            //如果有记录
    {
        outtextxy(400, 60, _T(" 姓名         电话号码          日期"));
        do
        {
            count++;
            display(400, 60 + 20 * count);                          //调用界面输出函数
            current_ptr = current_ptr->next;     //将current指针后移一个
        } while (current_ptr != NULL);            //直到链尾
    }
    else                              // 如果没有记录，提示无记录显示
    {
        outtextxy(400, 60, _T("    您还没有记录哦，赶快去创建一个吧!"));
    }

    //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 1045 && msg.x < 1117 && msg.y > 135 && msg.y < 375)//鼠标点击特定区域，即逐屏显示按钮所在区域
                {
                    loadimage(&display_list_all_somelist, L"display_list_all_somelist.png");//导入图片
                    putimage(0, 0, &display_list_all_somelist);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    display_somelist(); //调用逐屏显示函数
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&display_list_all_back, L"display_list_all_back.png");//导入图片
                    putimage(0, 0, &display_list_all_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    display_choose(); //调用上级菜单函数
                }
            }
        }
    }
}                                    //结束 display_list 函数

/*逐屏显示电话记录*/
void friend_node::display_somelist()
{
    loadimage(&display_list_some, L"display_list_some.png");//导入图片
    putimage(0, 0, &display_list_some);//显示图片
    wchar_t a[2];    //接收数字字符
    int n = 0;//整型变量，储存记录个数
    current_ptr = head_ptr;                     //将current指针指向链首
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体
    friend_node* temp_ptr;//定义临时指针
    int flag = 0;

    if (current_ptr != NULL)                    //如果有记录
    {
        //下面进行鼠标交互：
        MOUSEMSG msg;//定义变量，保存鼠标消息
        FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
        while (true) // 主循环,循环监听鼠标信息
        {
            while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
            {
                msg = GetMouseMsg();//获取鼠标消息
                if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
                {
                    if (msg.x > 575 && msg.x < 705 && msg.y > 585 && msg.y < 615)//鼠标点击特定区域，即选择数目按钮所在区域
                    {
                        InputBox(a, 10, _T("请输入确定每屏显示的记录个数（1-9）"));//Unicode转ASCII较困难，采取笨办法
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
                            MessageBox(NULL, _T("请输入1-9以内的数字"), _T("记录显示"), MB_SETFOREGROUND | MB_ICONEXCLAMATION);

                        loadimage(&display_list_some, L"display_list_some.png");//导入图片
                        putimage(0, 0, &display_list_some);//显示图片
                        outtextxy(400, 60, _T(" 姓名         电话号码          日期"));
                        current_ptr = head_ptr;
                        for (int i = 0; i < n; i++)  //初步显示
                        {

                            display(400, 80 + i * 20);                           //调用展示函数
                            if (current_ptr->next == NULL)
                                break;                         //显示完后跳出
                            current_ptr = current_ptr->next;
                        }
                        if (current_ptr->next == NULL)  //若n太大则有异
                        {
                            flag = 1;
                        }
                    }

                    if (msg.x > 455 && msg.x < 533 && msg.y > 585 && msg.y < 621)//鼠标点击特定区域，即左箭头按钮所在区域
                    {
                        loadimage(&display_list_some, L"display_list_some.png");//导入图片
                        putimage(0, 0, &display_list_some);//显示图片
                        outtextxy(400, 60, _T(" 姓名         电话号码          日期"));

                        int a = 0;
                        friend_node* t_ptr;
                        t_ptr = head_ptr;
                        while (t_ptr != NULL)    //计算总结点数
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

                                    break;   //防止c进入链首
                                }
                                current_ptr = current_ptr->prev;
                            }
                        }
                        flag = 0;
                        if (current_ptr->prev == NULL)
                        {
                            for (int i = 0; i < n; i++)  //初步显示
                            {
                                if (current_ptr->next == NULL)
                                    break;
                                current_ptr = current_ptr->next;
                            }//显示完后跳出

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
                                break;                         //显示完后跳出
                            if (current_ptr->prev == NULL)
                            {
                                display(400, 80);
                                j++;
                            }
                            wcscpy(fullname, _T(""));              // 清空全局变量fullname数组
                            wcscat(fullname, temp_ptr->last_name);
                            wcscat(fullname, _T(" "));
                            wcscat(fullname, temp_ptr->first_name);    //将姓和名连接到fullname中
                            setbkmode(TRANSPARENT);//设置字体背景为透明
                            settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
                            settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体
                            outtextxy(400, 80 + j * 20, fullname);
                            outtextxy(400 + 130, 80 + j * 20, temp_ptr->phone_num);
                            outtextxy(400 + 280, 80 + j * 20, temp_ptr->time_num);
                            temp_ptr = temp_ptr->next;    //将current指针后移一个
                        }
                    }

                    if (msg.x > 765 && msg.x < 845 && msg.y > 585 && msg.y < 621)//鼠标点击特定区域，即右箭头按钮所在区域
                    {

                        if (flag == 0)
                        {
                            loadimage(&display_list_some, L"display_list_some.png");//导入图片
                            putimage(0, 0, &display_list_some);//显示图片
                            outtextxy(400, 60, _T(" 姓名         电话号码          日期"));


                            for (int i = 0; i < n; i++)
                            {
                                if (current_ptr->next == NULL)
                                {
                                    display(400, 80 + i * 20);
                                    flag = 1;
                                    break;
                                }//显示完后跳出

                                display(400, 80 + i * 20);                           //调用展示函数
                                current_ptr = current_ptr->next;    //将current指针后移一个
                            }

                        }
                    }

                    if (msg.x > 140 && msg.x < 210 && msg.y > 135 && msg.y < 375)//鼠标点击特定区域，即显示所有记录按钮所在区域
                    {
                        loadimage(&display_list_some_all, L"display_list_some_all.png");//导入图片
                        putimage(0, 0, &display_list_some_all);//显示图片
                        Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                        display_list(); //调用显示所有函数
                    }

                    if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                    {
                        loadimage(&display_list_some_back, L"display_list_some_back.png");//导入图片
                        putimage(0, 0, &display_list_some_back);//显示图片
                        Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                        display_choose(); //调用上级菜单函数
                    }
                }
            }

        }
    }
    else                                   // 如果没有记录，提示无记录显示
    {
        outtextxy(400, 60, _T("您还没有记录哦，赶快去创建一个吧！"));
        //下面进行鼠标交互：
        MOUSEMSG msg;//定义变量，保存鼠标消息
        FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
        while (true) // 主循环,循环监听鼠标信息
        {
            while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
            {
                msg = GetMouseMsg();//获取鼠标消息
                if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
                {
                    if (msg.x > 140 && msg.x < 210 && msg.y > 135 && msg.y < 375)//鼠标点击特定区域，即显示所有记录按钮所在区域
                    {
                        loadimage(&display_list_some_all, L"display_list_some_all.png");//导入图片
                        putimage(0, 0, &display_list_some_all);//显示图片
                        Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                        display_list(); //调用显示所有函数
                    }

                    if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                    {
                        loadimage(&display_list_some_back, L"display_list_some_back.png");//导入图片
                        putimage(0, 0, &display_list_some_back);//显示图片
                        Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                        display_choose(); //调用上级菜单函数
                    }
                }
            }
        }
    }

}                                   //结束 display_somelist 函数

/*修改节点内容*/
void friend_node::replace()
{
    loadimage(&replace_list, L"replace_list.png");//导入图片
    putimage(0, 0, &replace_list);//显示图片
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体

    if (head_ptr == NULL)
    {
        outtextxy(400, 60, _T("您还没有记录哦，赶快去创建一个吧！"));
    }
    else
    {
        int count = 0;                  //统计找到记录个数变量
        friend_node* new_rec_ptr;
        wchar_t search_last_string[20];           // 储存想要查找的姓
        wchar_t search_first_string[15];              // 储存想要查找的名
        new_rec_ptr = new friend_node;           // 申请新的内存空间，使指针指向该内存空间
        current_ptr = head_ptr;                   // 将current指针指向链首

        InputBox(search_first_string, 15, _T("请输入您要修改内容的名: "));
        InputBox(search_last_string, 20, _T("请输入您要修改内容的姓: "));

        while ((current_ptr != NULL) &&
            ((wcscmp(current_ptr->last_name, search_last_string) != 0) ||
                (wcscmp(current_ptr->first_name, search_first_string) != 0)))
            //向后查找相匹配的记录直到找到或已到链尾
        {
            current_ptr = current_ptr->next;
        }

        do
        {

            if (current_ptr != NULL)                     //存在该记录
            {

                count++;
                outtextxy(400, 60, _T(" 姓名         电话号码          日期"));
                display(400, 80);                  //调用展示函数

                int result = MessageBox(NULL, _T("您确实要修改原有记录吗？"), _T("修改记录"), MB_SETFOREGROUND | MB_ICONASTERISK | MB_YESNO);



                if (result == IDYES)   //要修改记录
                {
                    InputBox(new_rec_ptr->last_name, 20, _T("Last Name(姓): "));// _T为了与unicode兼容
                    while (wcscmp(new_rec_ptr->last_name, _T("")) == 0)//wcscmp类似于strcmp
                    {                  //避免输入空字符后影响文件读取（文件读取函数将空字符与“end”设为结束的标志）
                        MessageBox(NULL, _T("输入无效，请重新输入"), _T("Last Name(姓): "), MB_ICONSTOP | MB_SETFOREGROUND);
                        //参数分别为：消息框拥有的窗口、消息框的内容、消息框的标题、标志集(多个标志用"与"(|)符号连接)
                       //最后的参数表示设置消息框为前景窗口
                        InputBox(new_rec_ptr->last_name, 20, _T("Last Name(姓): "));
                    }
                    InputBox(new_rec_ptr->first_name, 20, _T("First Name(名): "));
                    InputBox(new_rec_ptr->phone_num, 15, _T("Phone Number(电话号码): "));
                    time_note(new_rec_ptr);    //调用函数将时间传递进记录

                    friend_node* search_mate_ptr = head_ptr; //定义一个用于寻找的指针

                    while ((search_mate_ptr != NULL) && wcscmp(search_mate_ptr->phone_num, new_rec_ptr->phone_num) != 0)
                        //向后查找相匹配的记录直到找到或已到链尾
                    {
                        search_mate_ptr = search_mate_ptr->next;
                    }

                    if (search_mate_ptr != NULL)        // 原记录有相同手机号码的，提示覆盖原记录或取消操作
                    {
                        loadimage(&replace_list, L"replace_list.png");
                        putimage(0, 0, &replace_list);
                        friend_node* persent_ptr;      //定义一个临时指针存放current_ptr
                        persent_ptr = current_ptr;
                        current_ptr = search_mate_ptr;
                        display(400, 80);                  //调用展示函数
                        current_ptr = persent_ptr;
                        MessageBox(NULL, _T("该号码已存在，修改失败"), _T("修改记录"), MB_SETFOREGROUND | MB_ICONASTERISK);
                        break;
                    }
                    else
                    {
                        wcscpy(current_ptr->first_name, new_rec_ptr->first_name);
                        wcscpy(current_ptr->last_name, new_rec_ptr->last_name);
                        wcscpy(current_ptr->phone_num, new_rec_ptr->phone_num);
                        MessageBox(NULL, _T("您已成功修改记录！"), _T("修改记录"), MB_SETFOREGROUND);
                        break;
                    }
                }
                else
                    break;
            }
            else                            //没有找到所查找的记录
            {
                if (count == 0)
                {
                    outtextxy(400, 60, _T("对不起，没有查询到相关记录"));
                }
                else
                {
                    outtextxy(400, 60, _T("搜索完毕！"));
                }
            }
            if (current_ptr != NULL)
            {
                current_ptr = current_ptr->next;
            }
        } while (current_ptr != NULL);  //保证同名时正常修改
    }

    //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 535 && msg.x < 745 && msg.y > 555 && msg.y < 627)//鼠标点击特定区域，即修改按钮所在区域
                {
                    replace();   //修改函数
                }
                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&replace_list_back, L"replace_list_back.png");//导入图片
                    putimage(0, 0, &replace_list_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    handle_choice(); //调用上级菜单函数
                }
            }
        }
    }
}                                    //结束 display_list 函数

/*帮助*/
void friend_node::help_me()
{
    loadimage(&help_png, L"help_png.png");//导入图片
    putimage(0, 0, &help_png);//显示图片

        //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&help_back, L"help_back.png");//导入图片
                    putimage(0, 0, &help_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    handle_choice(); //调用上级菜单函数
                }
            }
        }
    }
}                                    //结束 help_me 函数

/*将记录保存到文件中*/
void friend_node::write_list_to_file()
{
    FILE* fp;
    fopen_s(&fp, fname, "wb");
    current_ptr = head_ptr;                          // 把current_ptr指向链首

    if (head_ptr != NULL)                       // 如果链表不为空，开始向文件写数据
    {
        do
        {                                            // 把节点数据写入文件
            fwrite(current_ptr->last_name, sizeof(last_name), 1, fp);
            fwrite(current_ptr->first_name, sizeof(first_name), 1, fp);
            fwrite(current_ptr->phone_num, sizeof(phone_num), 1, fp);
            fwrite(current_ptr->time_num, sizeof(time_num), 1, fp);


            current_ptr = current_ptr->next;          //把current_ptr指向下一个节点
        } while (current_ptr != NULL);                             // 循环直到链尾
    }

    fwrite(_T("END OF FILE"), sizeof(last_name), 1, fp);
    // "END OF FILE"用来使从文件中读入数据时判断是否到达文件尾部
    fclose(fp);                                       // 关闭文件
    delete_list();
}                                                  //结束 write_list_to_file 函数

/*从用户文件中读取数据重建链表*/
void friend_node::load_list_from_file()
{
    friend_node* new_rec_ptr;               //定义一个开辟空间的指针


    FILE* fp;
    int end_loop = 0;           //定义一个判断是否结束读取文件中数据的变量
    fopen_s(&fp, fname, "ab");
    fwrite(_T("END OF FILE"), sizeof(last_name), 1, fp);
    fclose(fp);
    //在文件末尾添加标志，不存在则创建文件
    fopen_s(&fp, fname, "rb");
    do
    {
        new_rec_ptr = new friend_node;           // 为节点申请空间

        if (new_rec_ptr != NULL)                     // 检查申请空间是否成功
        {
            fread(new_rec_ptr->last_name, sizeof(last_name), 1, fp);    // 从文件中读入'姓'信息
            if ((wcscmp(new_rec_ptr->last_name, _T("                    ")) != 0) && (wcscmp(new_rec_ptr->last_name, _T("END OF FILE")) != 0))  //如果没到文件尾部，继续从文件中读取数据
            {

                fread(new_rec_ptr->first_name, sizeof(first_name), 1, fp);  //从文件中读入'名'信息

                fread(new_rec_ptr->phone_num, sizeof(phone_num), 1, fp);   //从文件中读入'电话号码'信息
                fread(new_rec_ptr->time_num, sizeof(time_num), 1, fp);

                insert_node(new_rec_ptr);                     //调用函数将记录插入节点
            }
            else       // 如果到达文件尾部，释放最近申请的空间，并标记end_loop变量
            {
                delete new_rec_ptr;
                end_loop = 1;
            }
        }
        else            // 如果申请空间出错，给出警告，并标记end_loop变量
        {
            cout << "警告: 申请空间出错. 从硬盘读入数据不成功！\n";
            end_loop = 1;
        }
    } while (end_loop == 0);                   // 循环直到end_loop为1，退出
    fclose(fp);                                // 关闭文件.

}                                                     // 结束 load_list_from_file 函数

/*删除功能选择*/
void friend_node::delete_choose()
{
    loadimage(&delete_choise, L"delete_choise.png");//导入图片
    putimage(0, 0, &delete_choise);//显示图片

        //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 505 && msg.x < 810 && msg.y > 250 && msg.y < 325)//鼠标点击特定区域，即根据全名删记录按钮所在区域
                {
                    loadimage(&delete_choise_fullname, L"delete_choise_fullname.png");//导入图片
                    putimage(0, 0, &delete_choise_fullname);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    delete_record(); //调用根据全名删除函数
                }
                if (msg.x > 520 && msg.x < 790 && msg.y > 395 && msg.y < 465)//鼠标点击特定区域，即全删记录按钮所在区域
                {
                    loadimage(&delete_choise_all, L"delete_choise_all.png");//导入图片
                    putimage(0, 0, &delete_choise_all);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    delete_allrecord(); //调用全删除函数
                    loadimage(&delete_choise, L"delete_choise.png");//导入图片
                    putimage(0, 0, &delete_choise);//显示图片
                }

                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&delete_choise_back, L"delete_choise_back.png");//导入图片
                    putimage(0, 0, &delete_choise_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    handle_choice(); //调用上级菜单函数
                }
            }
        }
    }
}


/*根据全名删除一个节点（修改参照）*/
void friend_node::delete_record()
{
    int flag = 0;
    loadimage(&delete_choise_fullname_display, L"delete_choise_fullname_display.png");//导入图片
    putimage(0, 0, &delete_choise_fullname_display);//显示图片
    setbkmode(TRANSPARENT);//设置字体背景为透明
    settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
    settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体
    if (head_ptr == NULL)
    {
        outtextxy(400, 60, _T("您还没有记录哦，赶快去创建一个吧！"));
    }                                //如果没有记录，显示无记录删除

    else
    {
        friend_node* previous_ptr;       //用于查找被删除节点前一节点的指针
        previous_ptr = NULL;             // 使previous_ptr指针指向NULL.
        current_ptr = head_ptr;          //将current_ptr指针移至待删除list开头
        wchar_t search_last_string[20];
        wchar_t search_first_string[15];     //储存想要删除的姓与名
        InputBox(search_first_string, 15, _T("请输入您要删除的记录者的名: "));
        InputBox(search_last_string, 20, _T("请输入您要删除的记录者的姓: "));

        do
        {
            flag = 0;
            loadimage(&delete_choise_fullname_display, L"delete_choise_fullname_display.png");//导入图片
            putimage(0, 0, &delete_choise_fullname_display);//显示图片
            while ((current_ptr->next != NULL) &&
                ((wcscmp(current_ptr->last_name, search_last_string) != 0) ||
                    (wcscmp(current_ptr->first_name, search_first_string) != 0)))
                //	向后查找相匹配的记录直到找到或已到链尾								
            {  //不能让current越界，所以有了第一个判断
                previous_ptr = current_ptr;      // 在该记录被删除前，用previous_ptr指向它 
                current_ptr = current_ptr->next;
            }
            if ((wcscmp(current_ptr->last_name, search_last_string) == 0) ||
                (wcscmp(current_ptr->first_name, search_first_string) == 0))           // 找到相匹配的记录
            {       //因为上一个限制，所以这个地方不能再把出界作为标准
                outtextxy(400, 60, _T(" 姓名         电话号码          日期"));
                display(400, 80);

                if (verify_delete())            // 确认要删除记录
                {
                    delete_node(previous_ptr);     // 调用 delete_node 函数删除记录
                    MessageBox(NULL, _T("删除成功！"), _T("删除记录"), MB_SETFOREGROUND | MB_ICONASTERISK);
                }
                else  //如果选择否，得继续往下，所以current必须指向下一个
                {
                    if (current_ptr != NULL && current_ptr->next != NULL)
                    {
                        current_ptr = current_ptr->next;
                        flag = 1;                       //为了防止在最后一个节点while循环跳过，所以用flag标记（flag是最好的特效药）
                    }
                    else
                        break;   //当此节点为最后一个节点时自动退出，避免死循环
                }
            }
            else                              // 如果没找到相匹配的记录，提示无记录可删
            {
                outtextxy(400, 60, _T("全部记录已搜寻完毕！"));
            }


        } while ((current_ptr != NULL && current_ptr->next != NULL) || flag == 1);      //当出现记录同名的情况时，可以继续寻找并删除
    }

    loadimage(&delete_choise_fullname_display, L"delete_choise_fullname_display.png");//导入图片
    putimage(0, 0, &delete_choise_fullname_display);//显示图片
    outtextxy(400, 60, _T("全部记录已搜寻完毕！"));//刷新屏幕一刀切
    //下面进行鼠标交互：
    MOUSEMSG msg;//定义变量，保存鼠标消息
    FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
    while (true) // 主循环,循环监听鼠标信息
    {
        while (MouseHit())	//监听鼠标信息;当有鼠标消息的时候执行,可检测连续的鼠标信息
        {
            msg = GetMouseMsg();//获取鼠标消息
            if (WM_LBUTTONDOWN == msg.uMsg)//判断鼠标信息;鼠标左键按下
            {
                if (msg.x > 1096 && msg.x < 1253 && msg.y > 655 && msg.y < 705)//鼠标点击特定区域，即返回按钮所在区域
                {
                    loadimage(&delete_choise_fullname_display_back, L"delete_choise_fullname_display_back.png");//导入图片
                    putimage(0, 0, &delete_choise_fullname_display_back);//显示图片
                    Sleep(100);//延时，降低CPU占用率，并且做到点击效果
                    delete_choose(); //调用上级菜单函数
                }
            }
        }
    }

}                                        //结束 delete_record 函数

/*删除所有记录*/
void friend_node::delete_allrecord()
{
    if (head_ptr == NULL)
    {
        MessageBox(NULL, _T("您还没有记录哦，赶快去创建一个吧！"), _T("删除记录"), MB_SETFOREGROUND | MB_ICONASTERISK);
    }                                     //若没有记录，显示无记录可删除

    else
    {
        if (verify_delete())                                     // 确认要删除记录
        {
            delete_list();                              //调用释放内存空间的函数
            head_ptr = NULL;                                //使头指针指空
            MessageBox(NULL, _T("已删除所有记录！"), _T("删除记录"), MB_SETFOREGROUND | MB_ICONASTERISK);
        }
    }

}                                                      //结束delete_allrecord函数

/*确认是否删除记录*/
int friend_node::verify_delete()
{
    int result = MessageBox(NULL, _T("您确实要删除所选记录吗？"), _T("删除记录"), MB_SETFOREGROUND | MB_ICONQUESTION | MB_YESNO);
    return result == IDYES;
}                                       //结束verify_delete函数

/*删除*current_ptr所指记录*/
void friend_node::delete_node(friend_node* previous_ptr)

{
    if (current_ptr == head_ptr)             // 如果*current_ptr指向链首
    {
        delete_head_of_list();       //调用delete_head_of_list()函数，删除链首
    }
    else
    {
        if (current_ptr->next == NULL)       //如果*current_ptr指向链尾
        {
            delete_end_of_list(previous_ptr);  //调用delete_head_of_list()函数，删除链尾
        }
        else                       // 如果*current_ptr指向链中间
        {
            delete_from_middle_of_list(previous_ptr);
            //调用delete_from_middle_of_list()函数，删除除去链首和链尾的其他链节
        }
    }
}                                   //结束delete_node函数

/*删除链首*/
void friend_node::delete_head_of_list()
{
    current_ptr = head_ptr;                        //将当前位置指向链首
    if (head_ptr->next != NULL)
    {
        head_ptr = current_ptr->next;  //如果链首后的链节不为空，将下一链节作为链首
        head_ptr->prev = NULL;          //链首的前指针为空
    }
    else                            //链首后链节为空，则删除原链首，链表为空
    {
        head_ptr = NULL;
    }
    delete current_ptr;                      //释放current_ptr指针所占空间
    current_ptr = head_ptr;               // 将当前指针指向链首
}                                     //结束delete_head_of_list函数

/*删除链尾的函数*/
void friend_node::delete_end_of_list(friend_node* previous_ptr)

{
    delete current_ptr;                   // 删除current_ptr所指链节，即链尾
    previous_ptr->next = NULL;            // 使倒数第二个链节作为新的链尾
    current_ptr = head_ptr;               // 将当前指针指向链首
}                                   //结束delete_end_of_list函数

/*删除中间链节的函数*/
void friend_node::delete_from_middle_of_list(friend_node* previous_ptr)

{
    previous_ptr->next = current_ptr->next;              //跳过要删除的链节，
    // current_ptr指向要删除的记录，使previous_ptr->next指向current_ptr->next
    current_ptr->next->prev = previous_ptr;         //恢复双链
    delete current_ptr;                            // 删除current_ptr所指链节
    current_ptr = head_ptr;                            //将当前指针指向链首
}                               //结束delete_from_middle_of_list函数

/*释放链表所占空间的函数*/
void friend_node::delete_list()
{
    friend_node* temp_ptr;                 // 定义一个临时中间过渡指针
    current_ptr = head_ptr;                 //将current_ptr指向list的开头
    do                                        // 逐个释放每个链节所占空间
    {
        temp_ptr = current_ptr->next;            //使用临时指针来指向下一个地址，实现逐个删除                         
        delete current_ptr;
        current_ptr = temp_ptr;
    } while (temp_ptr != NULL);
    current_ptr = NULL;
    head_ptr = NULL;
}                                                    //结束delete_list函数
