
#include<iostream>
#include<cstring>
#include<math.h>
#include <fstream>
#include<cstdlib>
#define INITLISTSIZE 5
#define LISTINCREMENT 5
#define M 1000007

typedef struct forestry          //林业信息存储结构
{
    char city[256];
    char animal[256];
    int num[256];
    int sum;
    int order;                  //按森林总覆盖率排序
} forestry;

typedef struct SqList           //顺序表存储结构
{
    forestry *elem;
    int listsize;
    int length;
} SqList;

forestry HashTable[M];           //哈希表

void Init(SqList &L);           //初始化
int Menu_select();              //菜单
void Create(SqList &L);         //顺序表建立
void Print(SqList L);           //数据打印
void Compute(SqList &L);        //数据计算
void Append(SqList &L);         //数据追加
void Del(SqList &L);            //数据删除
void Insert(SqList &L);         //数据插入
void Search(SqList L);          //数据查找
void Sort(SqList &L);           //数据排序
void Save(SqList L);            //保存文件
void Load(SqList &L);           //读取文件
void Insert_Sort(SqList &L);    //插入排序
void Select_Sort(SqList &L);    //选择排序
void quick_sort(int l, int r,SqList &L);//快速排序
void Number_Sort(SqList &L);    //按学号排序
void Binary_Search(SqList &L);  //折半查找
void Hash_search(SqList L);     //哈希查找
void Squence_Search(SqList L);  //顺序查找
void Creathashtable(SqList L);  //建立哈希表




bool switchchioce(){
	SqList L;
	switch(Menu_select())
        {
        case 0:
            Init(L);
            break;
        case 1:
            Create(L);
            break;
        case 2:
            Print(L);
            break;
        case 3:
            Search(L);
            break;
        case 4:
            Compute(L);
            break;
        case 5:
            Del(L);
            break;
        case 6:
            Append(L);
            break;
        case 7:
            Insert(L);
            break;
        case 8:
            Save(L);
            break;
        case 9:
            Load(L);
            break;
        case 10:
            Sort(L);
            break;
        case 11:
            exit(0);
        }
    
    return true;
}
        


/****************菜单函数*******************/
int Menu_select()
{
    int choice;
    printf("****************************菜单*******************************\n");
    printf("                        0  初始化             \n");
    printf("                        1  输入               \n");
    printf("                        2  打印               \n");
    printf("                        3  查找               \n");
    printf("                        4  计算               \n");
    printf("                        5  删除               \n");
    printf("                        6  追加               \n");
    printf("                        7  插入               \n");
    printf("                        8  保存               \n");
    printf("                        9  读入               \n");
    printf("                        10 排序               \n");
    printf("                        11 退出               \n");
    printf("Enter your choice(0-11):");
    scanf("%d",&choice);
    return choice;
}
/****************初始化*********************/
void Init(SqList &L)
{
    L.elem=(forestry *)malloc(INITLISTSIZE*sizeof(forestry));
    L.length=0;
}
/****************顺序表的建立***************/
void Create(SqList &L)
{
    int i=0;
    while(1)
    {
        printf("请输入城市名:");
        scanf("%s",L.elem[i].city);
        if(L.elem[i].city[0]=='@')
            break;
        printf("请输入特有珍稀生物名:");
        scanf("%s",L.elem[i].animal);
        printf("请输入林地、疏林地与灌木林总覆盖率:");
        scanf("%d",&L.elem[i].num[0]);
        printf("请输入无林地覆盖率:");
        scanf("%d",&L.elem[i].num[1]);
        printf("请输入未成林造林地:");
        scanf("%d",&L.elem[i].num[2]);
        L.elem[i].sum=0;
        L.elem[i].order=0;
        L.length++;
        i++;
        char n;
        scanf("%d",n);
    }
}
/****************信息打印*******************/
void Print(SqList L)
{
	system("cls");
    int i;
    for(i=0; i<L.length; i++)
    {
        printf("城市名:%s 特有珍稀生物名:%s 林地、疏林地与灌木林总覆盖率:%d 无林地覆盖率:%d 未成林造林地：%d 总分:%d 排名:%d\n",L.elem[i].city,L.elem[i].animal,L.elem[i].num[0],L.elem[i].num[1],L.elem[i].num[2],L.elem[i].sum,L.elem[i],L.elem[i].order);
    }
}
/****************数据删除*******************/
void Del(SqList &L)
{
	system("cls");
    printf("输入要删除的城市名:");
    char number[11];
    scanf("%s",number);
    int i=0;
    while(i<L.length&&strcmp(number,L.elem[i].city))
        i++;
    while(i<L.length-1)
    {
        L.elem[i]=L.elem[i+1];
        i++;
    }
    L.length-=1;
}
/****************数据追加*******************/
void Append(SqList &L)
{
	system("cls");
    printf("请输入要增加的城市林业信息:");
    char city[11];
    printf("请输入城市名:");
    scanf("%s",city);
    char animal[15];
    printf("请输入特有珍稀生物名:");
    scanf("%s",animal);
    int num[3];
    printf("请输入林地、疏林地与灌木林总覆盖率:");
    scanf("%d",&num[0]);
    printf("请输入无林地覆盖率:");
    scanf("%d",&num[1]);
    printf("请输入未成林造林地");
    scanf("%d",&num[2]);
    float sum=0;
    float average=0;
    strcpy(L.elem[L.length].city,city);
    strcpy(L.elem[L.length].animal,animal);
    memcpy(L.elem[L.length].num,num,sizeof(num));
    L.elem[L.length].sum=sum;
    L.elem[L.length].order=0;
    L.length+=1;
}
/****************数据插入*******************/
void Insert(SqList &L)
{
	system("cls");
    printf("请输入指定的城市名:");
    char city[11];
    scanf("%s",city);
    forestry *p;
    p=L.elem;
    while(p&&strcmp(p->city,city))
        p++;
    if(!p)
        printf("没有此地！\n");
    else
    {
        forestry *q;
        for(q=L.elem+L.length; q>=p; q--)
        {
            *(q+1)=*q;
        }
    }
    printf("请输入城市名：");
    scanf("%s",p->city);
    printf("请输入特有珍稀生物名：");
    scanf("%s",p->animal);
    printf("请输入林地、疏林地与灌木林总覆盖率");
    scanf("%d",&p->num[0]);
    printf("请输入无林地覆盖率:");
    scanf("%d",&p->num[1]);
    printf("请输入未成林造林地");
    scanf("%d",&p->num[2]);
    L.length++;
}
/****************数据计算*******************/
void Compute(SqList &L)
{
	system("cls");
    forestry *p;
    for(p=L.elem; p<L.elem+L.length; p++)
    {
        p->sum=p->num[0]+p->num[1]+p->num[2];
    }
}
/****************文件保存*******************/
void Save(SqList L)
{

    FILE *fp;
    if((fp=fopen("student.txt","w"))==NULL)
    {
        printf("文件打开失败\n");
        getchar();
        exit(1);
    }

    forestry *p;
    for(p=L.elem; p<L.elem+L.length; p++)
    {
        fprintf(fp,"%s %s %d %d %d %d %f %d\n",p->city,p->animal,p->num[0],p->num[1],p->num[2],p->sum,p->order);
    }
    fclose(fp);
}
/****************文件读取*******************/
void Load(SqList &L)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("student.txt","r"))==NULL)
    {
        printf("文件打开失败\n");
        getchar();
        exit(1);
    }
    forestry *p;
    p=L.elem;
    while(fscanf(fp,"%s%s%d%d%d%d%f%d",p->city,p->animal,&p->num[0],&p->num[1],&p->num[2],&p->sum,&p->order)==8)
    {
        p++;
        i++;
    }
    L.length=i;
    fclose(fp);
}
/****************插入排序*******************/
void Insert_Sort(SqList &L)
{
	system("cls");
    forestry p;
    int i, j;
    for (i = 1; i < L.length; i++)
        if (L.elem[i].sum > L.elem[i - 1].sum)
        {
            p = L.elem[i];
            for (j = i - 1; j >= 0 && L.elem[j].sum < p.sum; j--)
                L.elem[j + 1] = L.elem[j];
            L.elem[j + 1] = p;
        }
    forestry *t;
    i=0;
    for(t=L.elem; t<L.elem+L.length; t++)
    {
        L.elem[i].order=i+1;
        i++;
    }
}
/****************选择排序*******************/
void Select_Sort(SqList &L)
{
	system("cls");
    for (int i = 0; i <L.length - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < L.length; j++)
        {
            if (L.elem[index].sum <L.elem[j].sum)
            {
                index = j;
            }
        }
        forestry p;
        p = L.elem[index];
        L.elem[index] = L.elem[i];
        L.elem[i] = p;
    }
    forestry *t;
    int i=0;
    for(t=L.elem; t<L.elem+L.length; t++)
    {
        L.elem[i].order=i+1;
        i++;
    }
}
/****************快速排序*******************/
void Quick_sort(int s,int t,SqList &L)
{
	system("cls");
    int i=s,j=t,x=L.elem[(i+j)/2].sum;
    forestry y;
    do
    {
        while(L.elem[i].sum>x)
            i++;
        while(L.elem[j].sum<x)
            j--;
        if(i<=j)
        {
            y=L.elem[j];
            L.elem[j]=L.elem[i];
            L.elem[i]=y;
            i++;
            j--;
        }
    }
    while(i<j);
    if(j>s)
        Quick_sort(s,j,L);
    if(i<t)
        Quick_sort(i,t,L);
    forestry *p;
    i=0;
    for(p=L.elem; p<L.elem+L.length; p++)
    {
        L.elem[i].order=i+1;
        i++;
    }
}
/****************顺序查找*******************/
void Squence_Search(SqList L)
{
	system("cls");
    int i;
    char search_number[11];
    printf("输入要查找的城市名:");
    scanf("%s",search_number);
    for( i=0; i<L.length; i++)
    {
        if(strcmp(search_number,L.elem[i].city)==0)
        {
            printf("%s %s %d %d %d %d %.2f %d\n",L.elem[i].city,L.elem[i].animal,L.elem[i].num[0],L.elem[i].num[0],L.elem[1].num[2],L.elem[i].sum,L.elem[i].order);
            break;
        }
    }
    if(i==L.length)
        printf("错误!!!没有此地信息!\n");
}
/****************二分查找*******************/
void Binary_Search(SqList &L)
{
	system("cls");
    Number_Sort(L);
    char search_number[11];
    printf("输入要查找的城市名:");
    scanf("%s",search_number);
    int low=0,high=L.length-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(strcmp(L.elem[mid].city,search_number)==0)
        {
            printf("%s %s %d %d %d %d %.2f %d\n",L.elem[mid].city,L.elem[mid].animal,L.elem[mid].num[0],L.elem[mid].num[0],L.elem[mid].num[2],L.elem[mid].sum,L.elem[mid].order);
            return;
        }
        else if(strcmp(L.elem[mid].city,search_number)<0)
            low=mid+1;
        else if(strcmp(L.elem[mid].city,search_number)>0)
            high=mid-1;
    }
    printf("错误!!!没有此地信息!\n");
}
/****************建立哈希表*****************/
void Creathashtable(SqList L)
{
    int i=0;
    while(i<L.length)
    {
        int len=strlen(L.elem[i].city);
        int j=0;
        int sum=0;
        while(j<4&&len)
        {
            sum+=(L.elem[i].city[len-1]-'0')*pow(10,j);
            j++;
            len--;
        }
        if(strlen(HashTable[sum].city)==0)
            HashTable[sum]=L.elem[i];
        else
        {
            while(strlen(HashTable[sum].city)!=0)
            {
                sum++;
            }
            HashTable[sum]=L.elem[i];
        }
        i++;
    }
}
/****************哈希查找*******************/
void Hash_search(SqList L)
{
	system("cls");
    Creathashtable(L);
    char search_number[11];
    printf("输入要查找的城市名:");
    scanf("%s",search_number);
    int len=strlen(search_number);
    int j=0;
    int sum=0;
    while(j<4&&len)
    {
        sum+=(search_number[len-1]-'0')*pow(10,j);
        j++;
        len--;
    }
    forestry *p=&HashTable[sum];
    while(strcmp(p->city,search_number)!=0)
    {
        p++;
    }
    printf("%s %s %d %d %d %d %.2f %d\n",p->city,p->animal,p->num[0],p->num[1],p->num[2],p->sum,p->order);
}
/****************按学号排序*****************/
void Number_Sort(SqList &L)
{
    for (int i = 0; i <L.length - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < L.length; j++)
        {
            if (strcmp(L.elem[index].city,L.elem[j].city)>0)
            {
                index = j;
            }
        }
        forestry p;
        p = L.elem[index];
        L.elem[index] = L.elem[i];
        L.elem[i] = p;
    }
}
/****************排序函数*******************/
void Sort(SqList &L)
{
	system("cls");
    int select;
    printf("1：插入排序\n2: 选择排序\n3: 快速排序\n4: 学号排序\n");
    scanf("%d",&select);
    if(select==1) Insert_Sort(L);
    else if(select==2) Select_Sort(L);
    else if(select==3) Quick_sort(0,L.length-1,L);
    else if(select==4) Number_Sort(L);
}
/****************查找函数*******************/
void Search(SqList L)
{
	system("cls");
    int opt;
    printf("1:顺序查找\n2:二分查找\n3:哈希查找\n");
    scanf("%d",&opt);
    if(opt==1)
        Squence_Search(L);
    else if(opt==2)
        Binary_Search(L);
    else if(opt==3)
        Hash_search(L);
}
/****************主程序*********************/

int main()
{
    SqList L;
    Init(L); 
    while(switchchioce());
	
}
