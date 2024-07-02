
#include<iostream>
#include<cstring>
#include<math.h>
#include <fstream>
#include<cstdlib>
#define INITLISTSIZE 5
#define LISTINCREMENT 5
#define M 1000007

typedef struct forestry          //��ҵ��Ϣ�洢�ṹ
{
    char city[256];
    char animal[256];
    int num[256];
    int sum;
    int order;                  //��ɭ���ܸ���������
} forestry;

typedef struct SqList           //˳���洢�ṹ
{
    forestry *elem;
    int listsize;
    int length;
} SqList;

forestry HashTable[M];           //��ϣ��

void Init(SqList &L);           //��ʼ��
int Menu_select();              //�˵�
void Create(SqList &L);         //˳�����
void Print(SqList L);           //���ݴ�ӡ
void Compute(SqList &L);        //���ݼ���
void Append(SqList &L);         //����׷��
void Del(SqList &L);            //����ɾ��
void Insert(SqList &L);         //���ݲ���
void Search(SqList L);          //���ݲ���
void Sort(SqList &L);           //��������
void Save(SqList L);            //�����ļ�
void Load(SqList &L);           //��ȡ�ļ�
void Insert_Sort(SqList &L);    //��������
void Select_Sort(SqList &L);    //ѡ������
void quick_sort(int l, int r,SqList &L);//��������
void Number_Sort(SqList &L);    //��ѧ������
void Binary_Search(SqList &L);  //�۰����
void Hash_search(SqList L);     //��ϣ����
void Squence_Search(SqList L);  //˳�����
void Creathashtable(SqList L);  //������ϣ��




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
        


/****************�˵�����*******************/
int Menu_select()
{
    int choice;
    printf("****************************�˵�*******************************\n");
    printf("                        0  ��ʼ��             \n");
    printf("                        1  ����               \n");
    printf("                        2  ��ӡ               \n");
    printf("                        3  ����               \n");
    printf("                        4  ����               \n");
    printf("                        5  ɾ��               \n");
    printf("                        6  ׷��               \n");
    printf("                        7  ����               \n");
    printf("                        8  ����               \n");
    printf("                        9  ����               \n");
    printf("                        10 ����               \n");
    printf("                        11 �˳�               \n");
    printf("Enter your choice(0-11):");
    scanf("%d",&choice);
    return choice;
}
/****************��ʼ��*********************/
void Init(SqList &L)
{
    L.elem=(forestry *)malloc(INITLISTSIZE*sizeof(forestry));
    L.length=0;
}
/****************˳���Ľ���***************/
void Create(SqList &L)
{
    int i=0;
    while(1)
    {
        printf("�����������:");
        scanf("%s",L.elem[i].city);
        if(L.elem[i].city[0]=='@')
            break;
        printf("������������ϡ������:");
        scanf("%s",L.elem[i].animal);
        printf("�������ֵء����ֵ����ľ���ܸ�����:");
        scanf("%d",&L.elem[i].num[0]);
        printf("���������ֵظ�����:");
        scanf("%d",&L.elem[i].num[1]);
        printf("������δ�������ֵ�:");
        scanf("%d",&L.elem[i].num[2]);
        L.elem[i].sum=0;
        L.elem[i].order=0;
        L.length++;
        i++;
        char n;
        scanf("%d",n);
    }
}
/****************��Ϣ��ӡ*******************/
void Print(SqList L)
{
	system("cls");
    int i;
    for(i=0; i<L.length; i++)
    {
        printf("������:%s ������ϡ������:%s �ֵء����ֵ����ľ���ܸ�����:%d ���ֵظ�����:%d δ�������ֵأ�%d �ܷ�:%d ����:%d\n",L.elem[i].city,L.elem[i].animal,L.elem[i].num[0],L.elem[i].num[1],L.elem[i].num[2],L.elem[i].sum,L.elem[i],L.elem[i].order);
    }
}
/****************����ɾ��*******************/
void Del(SqList &L)
{
	system("cls");
    printf("����Ҫɾ���ĳ�����:");
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
/****************����׷��*******************/
void Append(SqList &L)
{
	system("cls");
    printf("������Ҫ���ӵĳ�����ҵ��Ϣ:");
    char city[11];
    printf("�����������:");
    scanf("%s",city);
    char animal[15];
    printf("������������ϡ������:");
    scanf("%s",animal);
    int num[3];
    printf("�������ֵء����ֵ����ľ���ܸ�����:");
    scanf("%d",&num[0]);
    printf("���������ֵظ�����:");
    scanf("%d",&num[1]);
    printf("������δ�������ֵ�");
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
/****************���ݲ���*******************/
void Insert(SqList &L)
{
	system("cls");
    printf("������ָ���ĳ�����:");
    char city[11];
    scanf("%s",city);
    forestry *p;
    p=L.elem;
    while(p&&strcmp(p->city,city))
        p++;
    if(!p)
        printf("û�д˵أ�\n");
    else
    {
        forestry *q;
        for(q=L.elem+L.length; q>=p; q--)
        {
            *(q+1)=*q;
        }
    }
    printf("�������������");
    scanf("%s",p->city);
    printf("������������ϡ��������");
    scanf("%s",p->animal);
    printf("�������ֵء����ֵ����ľ���ܸ�����");
    scanf("%d",&p->num[0]);
    printf("���������ֵظ�����:");
    scanf("%d",&p->num[1]);
    printf("������δ�������ֵ�");
    scanf("%d",&p->num[2]);
    L.length++;
}
/****************���ݼ���*******************/
void Compute(SqList &L)
{
	system("cls");
    forestry *p;
    for(p=L.elem; p<L.elem+L.length; p++)
    {
        p->sum=p->num[0]+p->num[1]+p->num[2];
    }
}
/****************�ļ�����*******************/
void Save(SqList L)
{

    FILE *fp;
    if((fp=fopen("student.txt","w"))==NULL)
    {
        printf("�ļ���ʧ��\n");
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
/****************�ļ���ȡ*******************/
void Load(SqList &L)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("student.txt","r"))==NULL)
    {
        printf("�ļ���ʧ��\n");
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
/****************��������*******************/
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
/****************ѡ������*******************/
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
/****************��������*******************/
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
/****************˳�����*******************/
void Squence_Search(SqList L)
{
	system("cls");
    int i;
    char search_number[11];
    printf("����Ҫ���ҵĳ�����:");
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
        printf("����!!!û�д˵���Ϣ!\n");
}
/****************���ֲ���*******************/
void Binary_Search(SqList &L)
{
	system("cls");
    Number_Sort(L);
    char search_number[11];
    printf("����Ҫ���ҵĳ�����:");
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
    printf("����!!!û�д˵���Ϣ!\n");
}
/****************������ϣ��*****************/
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
/****************��ϣ����*******************/
void Hash_search(SqList L)
{
	system("cls");
    Creathashtable(L);
    char search_number[11];
    printf("����Ҫ���ҵĳ�����:");
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
/****************��ѧ������*****************/
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
/****************������*******************/
void Sort(SqList &L)
{
	system("cls");
    int select;
    printf("1����������\n2: ѡ������\n3: ��������\n4: ѧ������\n");
    scanf("%d",&select);
    if(select==1) Insert_Sort(L);
    else if(select==2) Select_Sort(L);
    else if(select==3) Quick_sort(0,L.length-1,L);
    else if(select==4) Number_Sort(L);
}
/****************���Һ���*******************/
void Search(SqList L)
{
	system("cls");
    int opt;
    printf("1:˳�����\n2:���ֲ���\n3:��ϣ����\n");
    scanf("%d",&opt);
    if(opt==1)
        Squence_Search(L);
    else if(opt==2)
        Binary_Search(L);
    else if(opt==3)
        Hash_search(L);
}
/****************������*********************/

int main()
{
    SqList L;
    Init(L); 
    while(switchchioce());
	
}
