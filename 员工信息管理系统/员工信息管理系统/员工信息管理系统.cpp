#include <iostream>
#include <iomanip>
#define I 0 
using namespace std;
typedef struct Data {
    string name;//姓名
    string post;//岗位
    int stuffid;//工号
    float salary; //工资
    Data* next;

}Data;
void swap(Data* A, Data* B);
class  Company//公司
{
public:
    Company();
    Company(string);//公司名称
    ~Company();
    /*创建员工列表*/
    void Setup(int);
    void print(); //打印员工列表   
    void Insertdata();//插入新的员工信息  
    int Searchdata();//查找。输入姓名和工号    
    void Deletedata();//删除，输入姓名和工号  
    void Sequence();//排序

    int Functionselection();//功能选择
private:
    Data* head;//头节点
    string Companyname;//公司名称
    int stuffnum;//公司员工数
};
Company::Company()
{
    head = new Data;
    head->next = NULL;
    this->stuffnum = 0;
    this->Companyname = "育碧蒙特利尔工作室";
}
Company::~Company()
{
    delete head;
}
void Company::Setup(int n)//共插入i个员工
{
    Data* s, * p = head;
    for (int i = 0; i < n; i++)
    {
        //对单个员工进行录入信息
        s = new Data;
        cout << "请输入第" << i + 1 << "个员工的姓名:";
        cin >> s->name;

        cout << "请输入第" << i + 1 << "个员工的工号:";
        cin >> s->stuffid;

        cout << "请输入第" << i + 1 << "个员工的岗位:";
        cin >> s->post;

        cout << "请输入第" << i + 1 << "个员工的工资:";
        cin >> s->salary;
        cout << "第" << i + 1 << "个员工输入完成\a" << endl << endl;
        s->next = p->next;
        p->next = s; Companyname;
        p = s;
        this->stuffnum++; //员工人数+1
    }
}
void Company::print()
{
    cout << endl;
    cout << "          " << "公司名称：" << this->Companyname << endl;
    cout << "          " << "编号" << "          " << "姓名" << "           " << "工号" << "        " << "工资" << "            " << "岗位" << endl;
    Data* p = this->head->next;
    int i = 1;
    while (p)
    {
        cout << "          " << i++ << "            " << p->name << "           " << p->stuffid << "           " << p->salary << "          " << p->post << endl;
        p = p->next;
    }

}
void Company::Insertdata()
{
    string xname;
    int xstuffid;
    float xsalary;
    string xpost;
    cout << "姓名:";
    cin >> xname;
    cout << "工号:";
    cin >> xstuffid;
    cout << "工资:";
    cin >> xsalary;
    cout << "岗位:";
    cin >> xpost;
    Data* s, * p = head;
    s = new Data;
    s->name = xname;
    s->stuffid = xstuffid;
    s->post = xpost;
    s->salary = xsalary;


    s->next = p->next;
    p->next = s;
    p = s;
}
int Company::Searchdata()
{
    string xname;
    int xstuffid;
    cout << "输入员工姓名:";
    cin >> xname;
    cout << "输入工号:";
    cin >> xstuffid;
    Data* p = head->next;
    while (p)
    {
        if (xstuffid == p->stuffid)
        {
            if (xname == p->name)
            {
                return 1; //成功找到
            }

            return -1;  //错误，工号重复
        }
        p = p->next;
    }
    return 0; //没有查询到该员工信息
}

void Company::Deletedata()
{
    string xname;
    int xstuffid;
    cout << "输入要删除的员工姓名:";
    cin >> xname;
    cout << "输入工号:";
    cin >> xstuffid;
    Data* p = head, * s = p->next;
    while (s)
    {
        if (xstuffid == s->stuffid)
        {
            if (xname == s->name)
            {
                p->next = s->next;
                delete s;
                return;
            }
            cout << endl << "出错，工号与姓名不匹配" << endl;
            return;
        }
        p = s;
        s = p->next;
    }
    cout << "没有查找到相关员工信息,可能已离职" << endl;
    this->stuffnum - 1;
}

void Company::Sequence()
{
    for (Data* a1 = this->head; a1 != NULL; a1 = a1->next)
    {
        for (Data* a2 = this->head; a2->next != NULL; a2 = a2->next)
        {
            if (a2->salary > a2->next->salary) {
                swap(a2, a2->next);
            }
        }
    }
}
int Company::Functionselection()      //功能选择
{
    char k;
    do {
        system("cls");
        cout << "    欢迎使用 育碧蒙特利尔工作室员工管理系统\n";
        cout << "            功能选择\n";
        cout << "         1.录入员工信息\n";
        cout << "         2.浏览员工信息\n";
        cout << "         3.插入员工信息\n";
        cout << "         4.删除员工信息\n";
        cout << "         5.查询员工信息\n";
        cout << "         6.按照工资额排序\n";
        cout << "         7.退出管理系统\n";
        cout << "         你要选择的功能是(请按数字键（1~7）):";
        k = getchar();
    } while (k < '1' || k>'7');
    return(k - '0');
}
void swap(Data* A, Data* B)
{
    Data temp;
    temp.name = A->name;
    A->name = B->name;
    B->name = temp.name;
    temp.post = A->post;
    A->post = B->post;
    B->post = temp.post;
    temp.salary = A->salary;
    A->salary = B->salary;
    B->salary = temp.salary;
    temp.stuffid = A->stuffid;
    A->stuffid = B->stuffid;
    B->stuffid = temp.stuffid;
}
int main()
{
    Company company;
    int n;
    string name;

    for (;;)
    {
        switch (company.Functionselection())
        {
        case 1:
            cout << "1.录入员工信息" << endl;
            company.Setup(5);
            system("pause");
            break;
        case 2:
            cout << "2.浏览员工信息" << endl;
            company.print();
            system("pause");
            break;
        case 3:
            cout << "3.插入员工信息" << endl;
            company.Insertdata();
            system("pause");
            break;
        case 4:
            cout << "4.删除员工信息" << endl;
            company.Deletedata();
            system("pause");
            break;
        case 5:
            cout << "5.查询员工信息:" << endl;
            n = company.Searchdata();
            if (n == 1)
            {
                cout << "确有此人" << endl;
            }
            else
            {
                cout << "查无此人" << endl;
            }
            system("pause");
            break;
        case 6:
            company.Sequence();
            cout << "排序完成" << endl;
            system("pause");
            break;
        case 7:
            cout << "信息已保存,再见" << endl;
            exit(0);
            break;
        }
    }
}

