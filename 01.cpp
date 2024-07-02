#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Student
{
public:
	int id;
	char name[20];
	char sex[10];
	int age;
};
int main()
{
	Student stu;
	stu.id = 1;
	strcpy(stu.name , "zhangsan");
	strcpy(stu.sex , "nan");
	stu.age = 19;

	ofstream out("stu.bat" , ios::binary);
	out.write( (char *)&stu , sizeof(stu) );
	out.close();

	
	Student stu1;
	ifstream in("stu.bat" , ios::binary);
	in.read( (char *)&stu1 , sizeof(stu1));
	in.close();
	cout << stu1.id << " " << stu1.name << " " << stu1.sex << " " << stu1.age << endl; 
}
