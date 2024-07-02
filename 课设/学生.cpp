#include <stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define INITLISTSIZE 5
#define LISTINCREMENT 5
#define M 1000007

typedef struct student          //ѧ����Ϣ�洢�ṹ
{
    char no[11];
    char name[15];
    int score[3];
    int sum;
    float average;
    int order;                  //���ɼ�����
} student;

typedef struct SqList           //˳���洢�ṹ
{
    student *elem;
    int listsize;
    int length;
} SqList;

student HashTable[M];           //��ϣ��

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
/****************������*********************/
int main()
{
    SqList L;
    Init(L);
    while(1)
    {
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
    }
    return 0;
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
    L.elem=(student *)malloc(INITLISTSIZE*sizeof(student));
    L.length=0;
}
/****************˳���Ľ���***************/
void Create(SqList &L)
{
    int i=0;
    while(1)
    {
        printf("������ѧ��:");
        scanf("%s",L.elem[i].no);
        if(L.elem[i].no[0]=='@')
            break;
        printf("����������:");
        scanf("%s",L.elem[i].name);
        printf("��������ѧ�ɼ�:");
        scanf("%d",&L.elem[i].score[0]);
        printf("������Ӣ��ɼ�:");
        scanf("%d",&L.elem[i].score[1]);
        printf("���������ݽṹ�ɼ�:");
        scanf("%d",&L.elem[i].score[2]);
        L.elem[i].sum=0;
        L.elem[i].average=0;
        L.elem[i].order=0;
        L.length++;
        i++;
    }
}
/****************��Ϣ��ӡ*******************/
void Print(SqList L)
{
    int i;
    for(i=0; i<L.length; i++)
    {
        printf("ѧ��:%s ����:%s ��ѧ:%d Ӣ��:%d ���ݽṹ:%d �ܷ�:%d ƽ����:%.2f ����:%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].score[0],L.elem[i].score[1],L.elem[i].score[2],L.elem[i].sum,L.elem[i].average,L.elem[i].order);
    }
}
/****************����ɾ��*******************/
void Del(SqList &L)
{
    printf("����Ҫɾ����ѧ��ѧ��:");
    char number[11];
    scanf("%s",number);
    int i=0;
    while(i<L.length&&strcmp(number,L.elem[i].no))
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
    printf("������Ҫ���ӵ�ѧ����Ϣ:");
    char no[11];
    printf("������ѧ��:");
    scanf("%s",no);
    char name[15];
    printf("����������:");
    scanf("%s",name);
    int score[3];
    printf("��������ѧ�ɼ�:");
    scanf("%d",&score[0]);
    printf("������Ӣ��ɼ�:");
    scanf("%d",&score[1]);
    printf("���������ݽṹ�ɼ�:");
    scanf("%d",&score[2]);
    float sum=0;
    float average=0;
    strcpy(L.elem[L.length].no,no);
    strcpy(L.elem[L.length].name,name);
    memcpy(L.elem[L.length].score,score,sizeof(score));
    L.elem[L.length].sum=sum;
    L.elem[L.length].average=average;
    L.elem[L.length].order=0;
    L.length+=1;
}
/****************���ݲ���*******************/
void Insert(SqList &L)
{
    printf("������ָ����ѧ��ѧ��:");
    char no[11];
    scanf("%s",no);
    student *p;
    p=L.elem;
    while(p&&strcmp(p->no,no))
        p++;
    if(!p)
        printf("û�д��ˣ�\n");
    else
    {
        student *q;
        for(q=L.elem+L.length; q>=p; q--)
        {
            *(q+1)=*q;
        }
    }
    printf("������ѧ�ţ�");
    scanf("%s",p->no);
    printf("������������");
    scanf("%s",p->name);
    printf("��������ѧ�ɼ���");
    scanf("%d",&p->score[0]);
    printf("������Ӣ��ɼ���");
    scanf("%d",&p->score[1]);
    printf("���������ݽṹ�ɼ���");
    scanf("%d",&p->score[2]);
    L.length++;
}
/****************���ݼ���*******************/
void Compute(SqList &L)
{
    student *p;
    for(p=L.elem; p<L.elem+L.length; p++)
    {
        p->sum=p->score[0]+p->score[1]+p->score[2];
        p->average=p->sum/3.0;
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

    student *p;
    for(p=L.elem; p<L.elem+L.length; p++)
    {
        fprintf(fp,"%s %s %d %d %d %d %f %d\n",p->no,p->name,p->score[0],p->score[1],p->score[2],p->sum,p->average,p->order);
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
    student *p;
    p=L.elem;
    while(fscanf(fp,"%s%s%d%d%d%d%f%d",p->no,p->name,&p->score[0],&p->score[1],&p->score[2],&p->sum,&p->average,&p->order)==8)
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
    student p;
    int i, j;
    for (i = 1; i < L.length; i++)
        if (L.elem[i].sum > L.elem[i - 1].sum)
        {
            p = L.elem[i];
            for (j = i - 1; j >= 0 && L.elem[j].sum < p.sum; j--)
                L.elem[j + 1] = L.elem[j];
            L.elem[j + 1] = p;
        }
    student *t;
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
        student p;
        p = L.elem[index];
        L.elem[index] = L.elem[i];
        L.elem[i] = p;
    }
    student *t;
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
    int i=s,j=t,x=L.elem[(i+j)/2].sum;
    student y;
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
    student *p;
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
    int i;
    char search_number[11];
    printf("����Ҫ���ҵ�ѧ��ѧ��:");
    scanf("%s",search_number);
    for( i=0; i<L.length; i++)
    {
        if(strcmp(search_number,L.elem[i].no)==0)
        {
            printf("%s %s %d %d %d %d %.2f %d\n",L.elem[i].no,L.elem[i].name,L.elem[i].score[0],L.elem[i].score[0],L.elem[1].score[2],L.elem[i].sum,L.elem[i].average,L.elem[i].order);
            break;
        }
    }
    if(i==L.length)
        printf("����!!!û�д�ѧ����Ϣ!\n");
}
/****************���ֲ���*******************/
void Binary_Search(SqList &L)
{
    Number_Sort(L);
    char search_number[11];
    printf("����Ҫ���ҵ�ѧ��ѧ��:");
    scanf("%s",search_number);
    int low=0,high=L.length-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(strcmp(L.elem[mid].no,search_number)==0)
        {
            printf("%s %s %d %d %d %d %.2f %d\n",L.elem[mid].no,L.elem[mid].name,L.elem[mid].score[0],L.elem[mid].score[0],L.elem[mid].score[2],L.elem[mid].sum,L.elem[mid].average,L.elem[mid].order);
            return;
        }
        else if(strcmp(L.elem[mid].no,search_number)<0)
            low=mid+1;
        else if(strcmp(L.elem[mid].no,search_number)>0)
            high=mid-1;
    }
    printf("����!!!û�д�ѧ����Ϣ!\n");
}
/****************������ϣ��*****************/
void Creathashtable(SqList L)
{
    int i=0;
    while(i<L.length)
    {
        int len=strlen(L.elem[i].no);
        int j=0;
        int sum=0;
        while(j<4&&len)
        {
            sum+=(L.elem[i].no[len-1]-'0')*pow(10,j);
            j++;
            len--;
        }
        if(strlen(HashTable[sum].no)==0)
            HashTable[sum]=L.elem[i];
        else
        {
            while(strlen(HashTable[sum].no)!=0)
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
    Creathashtable(L);
    char search_number[11];
    printf("����Ҫ���ҵ�ѧ��ѧ��:");
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
    student *p=&HashTable[sum];
    while(strcmp(p->no,search_number)!=0)
    {
        p++;
    }
    printf("%s %s %d %d %d %d %.2f %d\n",p->no,p->name,p->score[0],p->score[1],p->score[2],p->sum,p->average,p->order);
}
/****************��ѧ������*****************/
void Number_Sort(SqList &L)
{
    for (int i = 0; i <L.length - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < L.length; j++)
        {
            if (strcmp(L.elem[index].no,L.elem[j].no)>0)
            {
                index = j;
            }
        }
        student p;
        p = L.elem[index];
        L.elem[index] = L.elem[i];
        L.elem[i] = p;
    }
}
/****************������*******************/
void Sort(SqList &L)
{
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
