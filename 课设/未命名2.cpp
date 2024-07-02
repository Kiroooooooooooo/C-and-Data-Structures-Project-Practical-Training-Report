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


//********************森林类***************************
class Forestry
{
public:
	int area[5];
	string city;
	string animal;
	int biosp;
	int sum=area[0]+area[1]+area[2];
    int order;	
};

//********************界面***************************
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
	cout << "**************林业信息管理系统******************" << endl;
	cout << "1、查询全部城市林业信息" << endl;
	cout << "2、添加新城市林业信息" << endl;
	cout << "3、修改城市林业信息" << endl;
	cout << "4、删除城市林业信息" << endl;
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
	cout << "当前系统下的城市林业信息如下：" << endl;
	int length = stus ->length();
	 
	for(int i = 0; i < length; i++)
	{
		Forestry stu;
		stus ->getData(i , stu);
		cout << "******************************" << endl;
		cout << "城市名：" << stu.city << endl;
		cout << "林地、疏林地与灌木林总覆盖率：" << stu.area[0] << endl;
		cout << "无林地覆盖率：" << stu.area[1] << endl;
		cout << "未成林造林地：" << stu.area[2]<< endl;
		cout << "林业总覆盖率："<<stu.sum<<endl;
		cout << "特有珍稀物种：" << stu.animal << endl;
		cout << "生物种类数：" << stu.biosp << endl;
	}
	cout<<"请输入任意值退出"<<endl;
	char n;
	cin >> n;
}

void View::InsertView()
{
	system("cls");
	cout << "请输入一个城市的林业信息" << endl;
	Forestry stu;
	cout<<"请输入城市名："<<endl; 
	cin >> stu.city;
	cout<<"请输入该城市林地、疏林地与灌木林总覆盖率(单位：%)："<<endl;
	cin >> stu.area[0];
	cout<<"请输入该城市无林地覆盖率(单位：%)："<<endl;
	cin >> stu.area[1];
	cout<<"请输入该城市未成林造林地(单位：%)："<<endl;
	cin >> stu.area[2];
	cout<<"请输入该城市特有珍稀生物名称："<<endl;
	cin >> stu.animal;
	cout<<"请输入该城市生物种类数："<<endl;
	cin >> stu.biosp;
	stu.sum=stu.area[0]+stu.area[1]+stu.area[2];
	if(stu.sum>=35){
		cout<<"提示：该城林业覆盖率较高！"<<endl;
	}
	if(stu.sum<35){
	    cout<<"提示：该城林业覆盖率需提升！"<<endl;	
	} 
	cout << "是否要添加此城市林业信息？（输入y添加，其它不添加）" << endl;
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
	cout << "请输入需要修改信息的城市林地、疏林地与灌木林总覆盖率" << endl;
	int area[5];
	cin>>area[0];
	Forestry stu;
	int length=stus->length();
	int index;
	for(index=0;index<length;index++){
		stus->getData(index,stu);
		if(stu.area[0]==area[0]) break; 
	}
	 
	if(index<length){
		cout<<"**********************"<<endl;
		cout<<"城市名："<<stu.city<<endl;
		cout<<"林地、疏林地与灌木林总覆盖率："<<stu.area[0]<<endl;
		cout<<"无林地覆盖率："<<stu.area[1]<<endl;
		cout<<"未成林造林地："<<stu.area[2]<<endl;
		cout<<"林业总覆盖率："<<stu.sum<<endl;
		cout<<"特有珍稀物种："<<stu.animal<<endl;
		cout<<"生物种类数："<<stu.biosp<<endl;
		cout<<"**********************"<<endl;
		cout<<"是要修改这个城市林业信息吗（y）"<<endl;
		char x;
		cin>>x;
		if('y'==x){
			cout<<"请输入新城市名："<<endl;
			cin>>stu.city;
			cout<<"请输入林地、疏林地与灌木林总覆盖率："<<endl;
			cin>>stu.area[0];
			cout<<"请输入无林地覆盖率："<<endl;
			cin>>stu.area[1];
			cout<<"请输入未成林造林地："<<endl;
			cin>>stu.area[2];
			cout<<"请输入新特有珍稀物种："<<endl;
			cin>>stu.animal;
			cout<<"请输入新生物种类数："<<endl;
			cin>>stu.biosp;
			stus->setData(index,stu);
		}
	}
	else{
		cout<<"对不起，查无此城"<<endl;
	}
	cout<<"请输入任意值退出"<<endl;
	char n;
	cin >> n;
}


void View::DelView()
{
	system("cls");
	cout << "删除城市林业信息界面" << endl;
	cout << "请输入需要删除信息的城市林地、疏林地与灌木林总覆盖率" << endl;
	int area[5];
	cin>>area[0];
	Forestry stu;
	int length=stus->length();
	int index;
	for(index=0;index<length;index++){
		stus->getData(index,stu);
		if(stu.area[0]==area[0]) break; 
	}

	if(index<length){
		cout<<"**********************"<<endl;
		cout<<"城市名："<<stu.city<<endl;
		cout<<"林地、疏林地与灌木林总覆盖率："<<stu.area[0]<<endl;
		cout<<"无林地覆盖率："<<stu.area[1]<<endl;
		cout<<"未成林造林地："<<stu.area[2]<<endl;
		cout<<"林业总覆盖率："<<stu.sum<<endl;
		cout<<"特有珍稀动物："<<stu.animal<<endl;
		cout<<"生物种类数："<<stu.biosp<<endl;
		cout<<"**********************"<<endl;
		cout<<"是要删除这个城市的林业信息吗（输入y删除，其他不删除）"<<endl;
		char x;
		cin>>x;
		if('y'==x){
			stus->remove(index,stu);
			cout<<"林地、疏林地与灌木林总覆盖率为"<<stu.area[0]<<"的城市已被删除！"<<endl; 
		}
	}
	else{
		cout<<"对不起，您输入的林地、疏林地与灌木林总覆盖率有误，请重新输入"<<endl;
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
	ofstream out("各城市林业信息.txt");
	int length=stus->length();
	 
	out<<length<<endl;
	for(int i=0;i<length;i++){
		Forestry stu;
		stus->getData(i,stu);
		out<<stu.city<<" "<<stu.area[0]<<" "<<stu.area[1]<<" "<<stu.area[2]<<" "<<stu.animal<<" "<<stu.biosp<<endl;
		
	}
	out.close();
}

void View::readStu(){
	ifstream in("各城市林业信息.txt");
	int length;
	 
	in>>length;
	for(int i=0;i<length;i++){
		Forestry stu;
		in>>stu.city>>stu.area[0]>>stu.area[1]>>stu.area[2]>>stu.animal>>stu.biosp;
		stus->insert(stus->length(),stu);
	} 
	in.close();
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
