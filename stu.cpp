#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
//********************顺序表***************************
template <class T>
class SeqList
{
private:
	T* array;
	int max;
	int last;
public:
	SeqList(int max);
	SeqList(SeqList& L);
	~SeqList();
	int size();
	int length();
	int search(T& x);
	bool getData(int index, T& x);
	bool setData(int index, T& x);
	bool insert(int index, T& x);
	bool remove(int index, T& x);
	bool isEmpty();
	bool isFull();
	void makeEmpty();
	void output();
};  
//********************顺序表的实现***************************
template <class T>
SeqList<T>::SeqList(int max) {
	array = new T[max];
	if (array == NULL)cout << "储存分配错误" << endl;
	this->max = max;
	last = -1;
}
template <class T>
SeqList<T>::SeqList(SeqList& L) {
	this->max = L.max;
	this->last = L.last;
	this->array = new T[max];
	if (array == NULL)cout << "储存分配错误" << endl;
	for (int i = 0; i <= last; i++)
	{
		this->array[i] = L.array[i];
	}
}
template <class T>
SeqList<T>::~SeqList() {
	delete[]array;
}
template <class T>
int SeqList<T>::size() {
	return max;
}
template <class T>
int SeqList<T>::length() {
	return last+1;
}
template <class T>
int SeqList<T>::search(T& x) {
	for (int i = 0; i <= last; i++) {
		if (array[i] == x) {
			return i;
		}

	}return -1;
}
template <class T>
bool SeqList<T>::getData(int index, T& x) {
	if (index >= 0 || index <= last) {
		x = array[index];
		return true;
	}
	return false;
}
template <class T>
bool SeqList<T>::setData(int index, T& x) {
	if (index >= 0 || index <= last) {
		array[index] = x;
		return true;
	}
	return false;
}
template <class T>
bool SeqList<T>::insert(int index, T& x) {
	if (index < 0 || index >= max)return false;
	for (int i = last; i >= index; i--) {
		array[i + 1] = array[i];
	}
	array[index] = x;
	last++;
	return true;
}
template <class T>
bool SeqList<T>::remove(int index, T& x) {
	if (index<0 || index>max)return false;
	x = array[index];
	for (int i = 0; i < last; i++) {
		if (i >= index) {
			array[i] = array[i + 1];
		}
	}
	last--;
	return true;
}
template <class T>
bool SeqList<T>::isEmpty() {
	if (last == -1)
		return true;
	else return false;
}
template <class T>
bool SeqList<T>::isFull() {
	if (last == max - 1)
		return true;
	else return false;
}
template <class T>
void SeqList<T>::makeEmpty() {
	last = -1;
}


//********************学生类***************************
class Student
{
public:
	int id;
	string name;
	string sex;
	int age;	
};

//********************界面***************************
class View
{
private:
	SeqList <Student>  * stus;
public:
	View()
	{
		stus = new SeqList <Student> (10);
		readStu();
	}
	~View()
	{
		delete stus;
	}
public:
	bool MainView();
	void QueryView();
	void InsertView();
	void UpdateView();
	void DelView();
	bool ExitView();
public:
    void stuWrite();
	void readStu(); 
};

bool View::MainView()
{
	system("cls");
	cout << "**************学生管理系统******************" << endl;
	cout << "1、查询全部学生" << endl;
	cout << "2、添加学生" << endl;
	cout << "3、修改学生" << endl;
	cout << "4、删除学生" << endl;
	cout << "5、退出" << endl;
	cout << "*********************************************" << endl;

	int n;
	cin >> n;
	
	switch(n)
	{
	case 1:QueryView();break;
	case 2:InsertView();break;
	case 3:UpdateView();break;
	case 4:DelView();break;
	case 5:return ExitView();
	}
	return true;
}

void View::QueryView()
{
	system("cls");
	cout << "当前系统下的学生如下：" << endl;
	int length = stus ->length();
	for(int i = 0; i < length; i++)
	{
		Student stu;
		stus ->getData(i , stu);
		cout << "******************************" << endl;
		cout << "学号：" << stu.id << endl;
		cout << "姓名：" << stu.name << endl;
		cout << "性别：" << stu.sex << endl;
		cout << "年龄：" << stu.age << endl;
	}
	char n;
	cin >> n;
}

void View::InsertView()
{
	system("cls");
	cout << "请输入一个学生的信息" << endl;
	Student stu;
	cin >> stu.id;
	cin >> stu.name;
	cin >> stu.sex;
	cin >> stu.age;
	cout << "是否要添加此学生？（输入y添加，其它不添加）" << endl;
	char n;
	cin >> n;
	if('y' == n)
	{
		stus ->insert( stus ->length() , stu);
	}
}

void View::UpdateView()
{
	system("cls");
	cout << "请输入需要修改信息的学生" << endl;
	int id;
	cin>>id;
	Student stu;
	int length=stus->length();
	int index;
	for(index=0;index<length;index++){
		stus->getData(index,stu);
		if(stu.id==id) break; 
	}
	if(index<length){
		cout<<"**********************"<<endl;
		cout<<"学号："<<stu.id<<endl;
		cout<<"姓名："<<stu.name<<endl;
		cout<<"性别："<<stu.sex<<endl;
		cout<<"年龄："<<stu.age<<endl;
		cout<<"**********************"<<endl;
		cout<<"是要修改这个学生吗（y）"<<endl;
		int x;
		cin>>x;
		if('y'==x){
			cout<<"请输入新姓名："<<endl;
			cin>>stu.name;
			cout<<"请输入新年龄："<<endl;
			cin>>stu.age;
			stus->setData(index,stu);
		}
	}
	else{
		cout<<"对不起，查无此人"<<endl;
	}
	cout<<"请输入任意值退出"<<endl;
	char n;
	cin >> n;
}

void View::DelView()
{
	system("cls");
	cout << "删除学生界面" << endl;
	cout << "请输入需要删除信息的学生" << endl;
	int id;
	cin>>id;
	Student stu;
	int length=stus->length();
	int index;
	for(index=0;index<length;index++){
		stus->getData(index,stu);
		if(stu.id==id) break; 
	}
	if(index<length){
		cout<<"**********************"<<endl;
		cout<<"学号："<<stu.id<<endl;
		cout<<"姓名："<<stu.name<<endl;
		cout<<"性别："<<stu.sex<<endl;
		cout<<"年龄："<<stu.age<<endl;
		cout<<"**********************"<<endl;
		cout<<"是要删除这个学生吗（输入y删除，其他不删除）"<<endl;
		char x;
		cin>>x;
		if('y'==x){
			stus->remove(index,stu);
			cout<<"学号为"<<stu.id<<"的学生已被删除！"<<endl; 
		}
	}
	else{
		cout<<"对不起，您输入的学号有误，请重新输入"<<endl;
	}
	cout<<"请输入任意值退出"<<endl;
	char n;
	cin >> n;
}

bool View::ExitView()
{
	system("cls");
	cout << "真的要退出吗？(y)" << endl;
	char n;
	cin >> n;
	if('y' == n){
		stuWrite();
		return false;
	}
	return true;
}

void View::stuWrite(){
	ofstream out("data.txt");
	int length=stus->length();
	
	out<<length<<endl;
	for(int i=0;i<length;i++){
		Student stu;
		stus->getData(i,stu);
		out<<stu.id<<" "<<stu.name<<" "<<stu.sex<<" "<<stu.age<<endl;
		out.close();
	}
}

void View::readStu(){
	ifstream in("data.txt");
	int length;
	in>>length;
	for(int i=0;i<length;i++){
		Student stu;
		in>>stu.id>>stu.name>>stu.sex>>stu.age;
		in.close();
	} 
}

//********************主函数***************************
int main()
{
	View view;
	while( view.MainView() );
	
	/*
	ofstream out("stu.bat",ios::binary);
	out.write((char*)&stu,sizeof(stu))
	out.close();
	*/
	
	/*
	Student stu1;
	ifstream in("stu.bat",ios::binary)
	in.read((char*)&stu,sizeof(stu))
	in.close();
	cout<<stu1.id<<
	*/
	
}
