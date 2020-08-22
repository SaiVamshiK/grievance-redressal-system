#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
char p1[17]="Drainage_Problem",p2[23]="Bad_condition_of_roads",p3[27]="Inadequete_Supply_of_water";int v1=1000,v2=1000,v3=1000;
class problem
{
	char a1[26];int h1;
	public:
	void readdata(char *a,int p);
	void printdata();
	int returnvote();
	void modifyvote(int);
};
void problem::readdata(char *a,int p)
{
	strcpy(a1,a);
	h1=p;
}
int main()
{  
	ofstream obj("Problem.txt",ios::out);
	problem stud;
	stud.readdata(p1,v1);
	obj.write((char*)&stud,sizeof(stud));
	stud.readdata(p2,v2);
	obj.write((char*)&stud,sizeof(stud));
	stud.readdata(p3,v3);
	obj.write((char*)&stud,sizeof(stud));
	obj.close();
	ofstream obj2("SignUpFile.txt",ios::out);
	obj2.close();
	ofstream fout1("AdminProblem.txt",ios::out);
	fout1.close();
	ofstream fout2("PostedProblems.txt",ios::out);
	fout2.close();
	ofstream fout3("AdminProblemPosted.txt",ios::out);
	fout3.close();
}


