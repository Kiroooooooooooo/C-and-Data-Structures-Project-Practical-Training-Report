#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
//********************˳���***************************
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
//********************˳����ʵ��***************************
template <class T>
SeqList<T>::SeqList(int max) {
	array = new T[max];
	if (array == NULL)cout << "����������" << endl;
	this->max = max;
	last = -1;
}
template <class T>
SeqList<T>::SeqList(SeqList& L) {
	this->max = L.max;
	this->last = L.last;
	this->array = new T[max];
	if (array == NULL)cout << "����������" << endl;
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


//********************ɭ����***************************
class Forestry
{
public:
	int area;
	string city;
	string animal;
	int biosp;	
};

//********************����***************************
class View
{
private:
	SeqList <Forestry>  * stus;
public:
	View()
	{
		stus = new SeqList <Forestry> (10);
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
	cout << "**************��ҵ��Ϣ����ϵͳ******************" << endl;
	cout << "1����ѯȫ��������ҵ��Ϣ" << endl;
	cout << "2������³�����ҵ��Ϣ" << endl;
	cout << "3���޸ĳ�����ҵ��Ϣ" << endl;
	cout << "4��ɾ��������ҵ��Ϣ" << endl;
	cout << "5���˳�" << endl;
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
	cout << "��ǰϵͳ�µĳ�����ҵ��Ϣ���£�" << endl;
	int length = stus ->length();
	for(int i = 0; i < length; i++)
	{
		Forestry stu;
		stus ->getData(i , stu);
		cout << "******************************" << endl;
		cout << "��������" << stu.city << endl;
		cout << "ɭ�ָ����ʣ�" << stu.area << endl;
		cout << "������ϡ���֣�" << stu.animal << endl;
		cout << "������������" << stu.biosp << endl;
	}
	cout<<"����������ֵ�˳�"<<endl;
	char n;
	cin >> n;
}

void View::InsertView()
{
	system("cls");
	cout << "������һ�����е���ҵ��Ϣ" << endl;
	Forestry stu;
	cout<<"�������������"<<endl; 
	cin >> stu.city;
	cout<<"������ó���ɭ�ָ����ʣ�������Ҫ����������д����"<<endl;
	cin >> stu.area;
	cout<<"������ó���������ϡ�������ƣ�"<<endl;
	cin >> stu.animal;
	cout<<"������ó���������������"<<endl;
	cin >> stu.biosp;
	cout << "�Ƿ�Ҫ��Ӵ˳�����ҵ��Ϣ��������y��ӣ���������ӣ�" << endl;
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
	cout << "��������Ҫ�޸���Ϣ�ĳ���ɭ�ָ�����" << endl;
	int area;
	cin>>area;
	Forestry stu;
	int length=stus->length();
	int index;
	for(index=0;index<length;index++){
		stus->getData(index,stu);
		if(stu.area==area) break; 
	}
	if(index<length){
		cout<<"**********************"<<endl;
		cout<<"��������"<<stu.city<<endl;
		cout<<"ɭ�ָ����ʣ�"<<stu.area<<endl;
		cout<<"������ϡ���֣�"<<stu.animal<<endl;
		cout<<"������������"<<stu.biosp<<endl;
		cout<<"**********************"<<endl;
		cout<<"��Ҫ�޸����������ҵ��Ϣ��y��"<<endl;
		char x;
		cin>>x;
		if('y'==x){
			cout<<"�������³�������"<<endl;
			cin>>stu.city;
			cout<<"��������ɭ�ָ����ʣ�"<<endl;
			cin>>stu.area;
			cout<<"��������������ϡ���֣�"<<endl;
			cin>>stu.animal;
			cout<<"��������������������"<<endl;
			cin>>stu.biosp;
			stus->setData(index,stu);
		}
	}
	else{
		cout<<"�Բ��𣬲��޴˳�"<<endl;
	}
	cout<<"����������ֵ�˳�"<<endl;
	char n;
	cin >> n;
}


void View::DelView()
{
	system("cls");
	cout << "ɾ��������ҵ��Ϣ����" << endl;
	cout << "��������Ҫɾ����Ϣ�ĳ���ɭ�ָ�����" << endl;
	int area;
	cin>>area;
	Forestry stu;
	int length=stus->length();
	int index;
	for(index=0;index<length;index++){
		stus->getData(index,stu);
		if(stu.area==area) break; 
	}
	if(index<length){
		cout<<"**********************"<<endl;
		cout<<"��������"<<stu.city<<endl;
		cout<<"ɭ�ָ����ʣ�"<<stu.area<<endl;
		cout<<"������ϡ���"<<stu.animal<<endl;
		cout<<"������������"<<stu.biosp<<endl;
		cout<<"**********************"<<endl;
		cout<<"��Ҫɾ��������е���ҵ��Ϣ������yɾ����������ɾ����"<<endl;
		char x;
		cin>>x;
		if('y'==x){
			stus->remove(index,stu);
			cout<<"ɭ�ָ�����Ϊ"<<stu.area<<"�ĳ����ѱ�ɾ����"<<endl; 
		}
	}
	else{
		cout<<"�Բ����������ɭ�ָ�������������������"<<endl;
	}
	cout<<"����������ֵ�˳�"<<endl;
	char n;
	cin >> n;
}

bool View::ExitView()
{
	system("cls");
	cout << "���Ҫ�˳���(y)" << endl;
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
		Forestry stu;
		stus->getData(i,stu);
		out<<stu.city<<" "<<stu.area<<" "<<stu.animal<<" "<<stu.biosp<<endl;
		out.close();
	}
}

void View::readStu(){
	ifstream in("data.txt");
	int length;
	in>>length;
	for(int i=0;i<length;i++){
		Forestry stu;
		in>>stu.city>>stu.area>>stu.animal>>stu.biosp;
		in.close();
	} 
}

//********************������***************************
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
