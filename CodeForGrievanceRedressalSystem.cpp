#include<iostream>
#include<fstream>
#include<string.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
using namespace std;
char p1[17]="Drainage_Problem",p2[23]="Bad_condition_of_roads",p3[27]="Inadequete_Supply_of_water";int v1=0,v2=0,v3=0;
class postedproblem
{
	char posted[50];int v1;
	public:
	void readdata(char*,int);
	void printdata();
	int returnvote();
	void modifyvote(int);
};
void postedproblem::readdata(char *s,int i)
{
	strcpy(posted,s);v1=i+1000;
}
void postedproblem::printdata()
{
	cout<<"Problem="<<posted<<endl;cout<<"\t\t\t";
	cout<<"Votes="<<v1<<endl;
}
void postedproblem::modifyvote(int i)
{
	v1=i;
}
int postedproblem::returnvote()
{
	return v1;
}
class problem
{
	char a1[26];int h1;
	public:
	void readdata(char *a,int p);
	void printdata();
	int returnvote();
	void modifyvote(int);	
};
problem mainstud1,mainstud2,mainstud3;
void problem::readdata(char *a,int p)
{
	strcpy(a1,a);
	h1=p;
}
void problem::printdata()
{
	cout<<"Problem="<<a1<<endl;cout<<"\t\t\t";
	cout<<"Votes="<<h1<<endl;
}
int problem::returnvote()
{
	return h1;
}
void problem::modifyvote(int j)
{
	h1=j;
}
class SignUp
{
	int i;char a[20];
	public:
	int q,p,vp;
	void readdata(int,char*);
	int returnid();
	char* returnpassword();
	int returnq();
	int returnp();
};
void SignUp::readdata(int y,char* x)
{
	i=y;strcpy(a,x);
	q=0;p=0;vp=0;
}
int SignUp::returnid()
{
	return i;
}
char* SignUp::returnpassword()
{
	return a;
}
int SignUp::returnq()
{
	return q;
}
int SignUp::returnp()
{
	return p;
}
int xy;
int ph,ch;
int gloarr[10000],ind=0;
int main()
{
	postedproblem pstud;
	problem stud;
	SignUp stud1;
	mainstud1.readdata(p1,v1);
	mainstud2.readdata(p2,v2);
	mainstud3.readdata(p3,v3);	
	ifstream OBJ;
	OBJ.open("Problem.txt",ios::in);
	OBJ.read((char*)&stud,sizeof(stud));
	v1=v1+stud.returnvote();
	OBJ.read((char*)&stud,sizeof(stud));
	v2=v2+stud.returnvote();
	OBJ.read((char*)&stud,sizeof(stud));
	v3=v3+stud.returnvote();
	mainstud1.modifyvote(v1-1000);
	mainstud2.modifyvote(v2-1000);
	mainstud3.modifyvote(v3-1000);
	while(1)
	{
cout<<endl<<endl<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"**************************************************************** YOU ARE IN GRIEVANCE REDRESSAL SYSTEM ****************************************************************\n";
cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
cout<<"************************************************************************** Options Available **************************************************************************";
cout<<endl<<endl;
		cout<<"\t\t\t1.Admin login\n\n\t\t\t2.Locality login\n\n\t\t\t3.Exit\n\n\t\t\tEnter choice where you want to go \n\n\n\t\t\t";
		cin>>ph;
		if(ph==1)
		{
			system("CLS");
			int aid;char apassword[20];
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"**************************************************************** YOU ARE IN ADMIN LOGIN PAGE *************************************************************************\n";
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
cout<<endl<<endl;
			cout<<"\t\t\tEnter your Admin ID\n\t\t\t";
			cin>>aid;
			cout<<"\t\t\tEnter your Admin Password\n\t\t\t";
			s:
			{
				string passwd="";
				int ch1;
				while(ch1=getch())
				{
					if(ch1==13||ch1=='$')
					{
						break;
					}
					else if(ch1==8)
					{
						if(passwd.length()>0)
						{
							cout<<"\b \b";
							passwd.erase(passwd.length()-1);
						}		
					}						
					else if(ch1>=0&&ch1<=127)
					{
						cout<<"*";
						passwd+=ch1;
					}
				}
				if(passwd.length()<6)
				{
					cout<<"\n\t\t\tPassword should be having minimum of 6 characters\n\n\t\t\tPlease try again\n\n\t\t\t";
					passwd="";
					goto s;
				}
				char tpassword[passwd.size()+1];
				strcpy(tpassword,passwd.c_str());
				strcpy(apassword,tpassword);
			}
			ifstream InObj;int m1,m2,m3;
			InObj.open("Problem.txt",ios::in);
			InObj.read((char*)&stud,sizeof(stud));
			m1=stud.returnvote();
			InObj.read((char*)&stud,sizeof(stud));
			m2=stud.returnvote();
			InObj.read((char*)&stud,sizeof(stud));
			m3=stud.returnvote();	
			if(m1>=m2&&m1>=m3)
			{
				xy=m1;
			}
			if(m2>=m1&&m2>=m3)
			{
				xy=m2;
			}
			if(m3>=m1&&m3>=m2)
			{
				xy=m3;
			}
			InObj.close();int sz=0;
			ifstream pin1;
			pin1.open("PostedProblems.txt",ios::in);
			pin1.seekg(0,ios::beg);
			pin1.read((char*)&pstud,sizeof(pstud));
			while(!pin1.eof())
			{
				gloarr[ind++]=pstud.returnvote();sz++;
				pin1.read((char*)&pstud,sizeof(pstud));
			}
			pin1.close();int newarr[sz];
			for(int f=0;f<sz;f++)
			{
				newarr[f]=gloarr[f];
			}
		//	cout<<"The contents of the new array\n";
		//	for(int d=0;d<sz;d++)
		//	{
		//		cout<<newarr[d]<<" ";
		//	}
		//	cout<<endl;
			int maximum=newarr[0];
			for(int t=0;t<sz;t++)
			{
				if(newarr[t]>maximum)
				{
					maximum=newarr[t];
				}
			}
		//	cout<<"Maximum="<<maximum<<endl;
			if(aid==974&&(strcmp(apassword,"Admin@242000")==0))
			{
				ofstream fout1("AdminProblem.txt",ios::out);
				ofstream pout("AdminProblemPosted.txt",ios::out);
				ifstream fin1("Problem.txt",ios::in);
				ifstream pin4("PostedProblems.txt",ios::in);
				fin1.seekg(0,ios::beg);
				fin1.read((char*)&stud,sizeof(stud));
				while(!fin1.eof())
				{
					if(stud.returnvote()>=xy)
					{
						fout1.write((char*)&stud,sizeof(stud));
					}
					fin1.read((char*)&stud,sizeof(stud));
				}
				fin1.close();
				fout1.close();
				pin4.seekg(0,ios::beg);
				pin4.read((char*)&pstud,sizeof(pstud));
				while(!pin4.eof())
				{
					if(pstud.returnvote()>=maximum)
					{
						pout.write((char*)&pstud,sizeof(pstud));
					}
					pin4.read((char*)&pstud,sizeof(pstud));
				}
				pin4.close();
				pout.close();
				system("CLS");
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"**************************************************************** YOU ARE IN ADMIN PORTAL *****************************************************************************\n";
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
cout<<endl<<endl;
				cout<<"\t\t\tProblems that have been sent to admin's are\n\n\n";
				cout<<"\n\t\t\t->ALREADY EXISTING PROBLEMS\n";
				ifstream fin2("AdminProblem.txt",ios::in);
				fin2.read((char*)&stud,sizeof(stud));
				while(!fin2.eof())
				{
					cout<<"\t\t\t";
					stud.printdata();
					fin2.read((char*)&stud,sizeof(stud));
				}
				fin2.close();
				cout<<"\n\n\n\t\t\t->POSTED PROBLEMS\n";
				ifstream pin2;
				pin2.open("AdminProblemPosted.txt",ios::in);
				pin2.read((char*)&pstud,sizeof(pstud));
				while(!pin2.eof())
				{
					cout<<"\t\t\t";
					pstud.printdata();
					pin2.read((char*)&pstud,sizeof(pstud));
				}
				pin2.close();
				cout<<endl<<endl;
				goto com;
			}
			else
			{
				system("CLS");
				cout<<"\n\t\t\tYou have entered either wrong id or password\n\n\n";
				goto com;
			}
		}
		else if(ph==2)
		{
			system("CLS");int id,th;char lpassword[20];
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"************************************************************* YOU ARE IN LOCALITY LOGIN PAGE *************************************************************************\n";
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
cout<<endl<<endl;
cout<<"******************************************************************* Options Available ********************************************************************************";
cout<<endl<<endl;
			cout<<"\t\t\t1.Login\n\n\n\t\t\t2.SignUp\n\n\n\t\t\tEnter your choice\n\t\t\t";int oh;cin>>oh;
			if(oh==1)
			{
				cout<<"\t\t\tEnter your login ID\n\t\t\t";cin>>id;
				cout<<"\t\t\tEnter your Password\n\t\t\t";	
				s1:
				{
					string passwd="";
					int ch1;
					while(ch1=getch())
					{
						if(ch1==13||ch1=='$')
						{
							break;
						}
						else if(ch1==8)
						{
							if(passwd.length()>0)
							{
								cout<<"\b \b";
								passwd.erase(passwd.length()-1);
							}		
						}
						else if(ch1>=0&&ch1<=127)
						{
							cout<<"*";
							passwd+=ch1;
						}
					}
					if(passwd.length()<6)
					{
						cout<<"\n\t\t\tPassword should be having minimum of 6 characters\n\n\t\t\tPlease try again\n\n\t\t\t";
						passwd="";
						goto s1;
					}
					char tpassword[passwd.size()+1];
					strcpy(tpassword,passwd.c_str());
					strcpy(lpassword,tpassword);
				}
				start:
				{
					
				}
				fstream SignObj("SignUpFile.txt",ios::in|ios::out);
				SignObj.seekg(0);
				SignObj.read((char*)&stud1,sizeof(stud1));
				int r=0;
				while(!SignObj.eof())
				{
					if((id==stud1.returnid())&&(strcmp(lpassword,stud1.returnpassword())==0))
					{
						system("CLS");
						r++;
						int p1,q1=sizeof(stud1);
						if(stud1.q==0||stud1.p==0||stud1.vp==0)
						{
							v1=0;v2=0;v3=0;
							if(stud1.q!=0&&stud1.vp!=0)
							{
								system("CLS");
								cout<<"YOU HAVE LOGGED IN SUCCESSFULLY\n";
								cout<<"YOU HAVE VOTED FOR THE ALREADY EXISTING PROBLEMS AND POSTED PROBLEMS\n";
								cout<<"YOU CAN NOW POST YOUR PROBLEM\n";
								cout<<"                     OPTIONS AVAILABLE                \n";
								cout<<"TO POST YOUR PROBLEM PRESS 1\n";
								cout<<"                            (OR)                         \n";
								cout<<"TO SEE THE VOTES FOR THE ALREADY EXISTING PROBLEMS PRESS 2\n";
								cout<<"                            (OR)                         \n";
								cout<<"TO SEE THE VOTES FOR POSTED PROBLEMS PRESS 3\n";
								cout<<"                            (OR)                          \n";
								cout<<"TO 'LOGOUT' FROM THE LOCALITY PORTAL PRESS ANY OTHER KEY\n";
								cout<<"\n\t\tENTER YOUR CHOICE\n";
								int kh;cin>>kh;
								if(kh==1)
								{
									system("CLS");
									goto pospro;
								}
								else if(kh==2)
								{
									system("CLS");
									goto seevotesofalready;
								}
								else if(kh==3)
								{
									system("CLS");
									goto seevotesofposted;
								}
								else
								{
									system("CLS");
									cout<<"YOU ARE OUT OF THE LOCALITY LOGIN PORTAL\n";
									SignObj.close();
									goto com;
								}
							}
							if(stud1.p!=0&&stud1.vp!=0)
							{
								system("CLS");
								votalr:
								{
									system("CLS");
									v1=0;v2=0;v3=0;
									system("CLS");
									cout<<"YOU HAVE LOGGED IN SUCCESSFULLY\n";
									cout<<"YOU HAVE POSTED YOUR PROBLEM AND YOU HAVE VOTED FOR THE POSTED PROBLEMS\n";
									cout<<"YOU CAN NOW VOTE FOR THE ALREADY EXISTING PROBLEMS IN YOUR LOCALITY\n";
									cout<<"Problems That Are Already There\n";
									cout<<"1.Drainage_problem\n2.Bad_condition_of_roads\n3.Inadequete_supply_of_water\n";
									cout<<"			          OPTIONS AVAILABLE     \n";
									cout<<"TO SEE THE VOTES FOR THE ALREADY EXISTING PROBLEMS PRESS 4\n";
									cout<<"                      (OR)                         \n";
									cout<<"TO SEE THE VOTES FOR POSTED PROBLEMS PRESS 5\n";
									cout<<"                      (OR)            \n";
									cout<<"Enter The Problem Number You Want To Vote\n";
									cout<<"                      (OR)                 \n";									
									cout<<"TO 'LOGOUT' FROM THE LOCALITY PORTAL PRESS ANY KEY\n";	
									cout<<"\n\t\tENTER YOUR CHOICE\n";
									cin>>ch;
									if(ch==4)
									{
										system("CLS");
										goto seevotesofalready;
									}
									else if(ch==5)
									{
										system("CLS");
										goto  seevotesofposted;
									}
									else if(ch==1)
									{
										v1++;
									}
									else if(ch==2)
									{
										v2++;
									}
									else if(ch==3)
									{
										v3++;
									}
									else
									{
										system("CLS");
										cout<<"YOU ARE OUT OF THE LOCALITY LOGIN PORTAL\n";
										SignObj.close();	
										goto com;
									}
									cout<<"v1="<<v1<<" v2="<<v2<<" v3="<<v3<<endl;
									stud1.q++;
									p1=SignObj.tellg();
									SignObj.seekp(p1-q1,ios::beg);
									SignObj.write((char*)&stud1,sizeof(stud1));
									SignObj.close();
							
									problem filestud;
									fstream ins1;
									ins1.open("Problem.txt",ios::in|ios::out);
									
									ins1.read((char*)&filestud,sizeof(filestud));
									v1=v1+filestud.returnvote();
									filestud.modifyvote(v1);
									int p=ins1.tellg(),q=sizeof(filestud);
									ins1.seekp(p-q);
									ins1.write((char*)&filestud,sizeof(filestud));
									mainstud1.modifyvote(v1-1000);
								
									ins1.read((char*)&filestud,sizeof(filestud));
									v2=v2+filestud.returnvote();
									filestud.modifyvote(v2);
									p=ins1.tellg();
									ins1.seekp(p-q);
									ins1.write((char*)&filestud,sizeof(filestud));
									mainstud2.modifyvote(v2-1000);
								
									ins1.read((char*)&filestud,sizeof(filestud));
									v3=v3+filestud.returnvote();
									filestud.modifyvote(v3);
									p=ins1.tellg();
									ins1.seekp(p-q);
									ins1.write((char*)&filestud,sizeof(filestud));
									mainstud3.modifyvote(v3-1000);
								
									ins1.close();
							
									system("CLS");
									cout<<"\nCONGRATULATIONS!!!\n\n\nYou Have Successfully Voted\n\n\n";
									cout<<"To Go Back To Your Main Login Page Press 'M' Or 'm'\n\n";
									cout<<"To 'Logout' From Locality Portal Press 'l' Or 'L' Or Any Other Key\n\n";
									char c;
									cin>>c;
									if(c=='M'||c=='m')
									{
										system("CLS");
										goto start;
									}
									else
									{		
										goto com;
									}
								}
							}
							if(stud1.q!=0&&stud1.p!=0)
							{
								system("CLS");
								cout<<"YOU HAVE LOGGED IN SUCCESSFULLY\n";
								cout<<"YOU HAVE VOTED FOR ALREADY EXISTING PROBLEMS AND YOU HAVE POSTED YOUR PROBLEM\n";
								cout<<"YOU CAN NOW VOTE FOR THE POSTED PROBLEMS\n";
								cout<<"                      OPTIONS AVAILABLE                       \n";
								cout<<"TO VOTE FOR POSTED PROBLEMS PRESS 1\n";
								cout<<"                      (OR)                                    \n";
								cout<<"TO SEE VOTES OF ALREADY EXISTING PROBLEMS PRESS 2\n";
								cout<<"                      (OR)                                    \n";
								cout<<"TO SEE VOTES OF POSTED PROBLEMS PRESS 3\n";
								cout<<"                      (OR)                                    \n";
								cout<<"TO 'LOGOUT' FROM THE LOCALITY PORTAL PRESS ANY OTHER KEY\n";
								cout<<"\n\t\tENTER YOUR CHOICE\n";
								int wh;cin>>wh;
								if(wh==1)
								{
									system("CLS");
									goto votpos;
								}
								else if(wh==2)
								{
									system("CLS");
									goto seevotesofalready;
								}
								else if(wh==3)
								{
									system("CLS");
									goto seevotesofposted;
								}
								else
								{
									system("CLS");
									cout<<"YOU ARE OUT OF THE LOCALITY LOGIN PORTAL\n";
									SignObj.close();	
									goto com;
								}
							}
							if(stud1.q!=0&&stud1.p==0&&stud1.vp==0)
							{
								system("CLS");
								cout<<"YOU HAVE LOGGED IN SUCCESSFULLY\n";	
								cout<<"YOU HAVE VOTED FOR THE ALREADY EXISTING PROBLEMS\n";
								cout<<"YOU CAN NOW POST YOUR PROBLEM OR VOTE FOR THE POSTED PROBLEMS\n";
								cout<<"                        OPTIONS AVAILABLE                      \n";
								cout<<"TO POST A PROBLEM PRESS 1\n";
								cout<<"                           (OR)                                \n";
								cout<<"TO VOTE FOR POSTED PROBLEMS PRESS 2\n";
								cout<<"                           (OR)                                \n";
								cout<<"TO SEE VOTES OF ALREADY EXISTING PROBLEMS PRESS 3\n";
								cout<<"                           (OR)                                \n";
								cout<<"TO SEE VOTES OF POSTED PROBLEMS PRESS 4\n";
								cout<<"                           (OR)                                \n";
								cout<<"TO 'LOGOUT' FROM THE LOCALITY PORTAL PRESS ANY OTHER KEY\n";
								cout<<"\n\t\tENTER YOUR CHOICE\n";
								int zh;
								cin>>zh;
								if(zh==1)
								{
									system("CLS");
									goto pospro;
								}
								else if(zh==2)
								{
									system("CLS");
									goto votpos;
								}
								else if(zh==3)
								{
									system("CLS");
									goto seevotesofalready;
								}
								else if(zh==4)
								{
									system("CLS");
									goto seevotesofposted;
								}
								else
								{
									system("CLS");
									cout<<"YOU ARE OUT OF THE LOCALITY LOGIN PORTAL\n";
									SignObj.close();	
									goto com;
								}
							}
							if(stud1.p!=0&&stud1.vp==0&&stud1.q==0)
							{
								system("CLS");
								cout<<"YOU HAVE LOGGED IN SUCCESSFULLY\n";	
								cout<<"YOU HAVE POSTED YOUR PROBLEM\n";
								cout<<"YOU CAN NOW VOTE FOR THE ALREADY EXISTING PROBLEMS AND POSTED PROBLEMS\n";
								cout<<"                           OPTIONS AVAILABLE                          \n";
								cout<<"TO VOTE FOR ALREADY EXISTING PROBLEMS PRESS 1\n";
								cout<<"                              (OR)                                    \n";
								cout<<"TO VOTE FOR POSTED PROBLEMS PRESS 2\n";
								cout<<"                              (OR)                                    \n";
								cout<<"TO SEE VOTES OF ALREADY EXISTING PROBLEMS PRESS 3\n";
								cout<<"                              (OR)                                    \n";
								cout<<"TO SEE VOTES OF POSTED PROBLEMS PRESS 4\n";
								cout<<"                              (OR)                                    \n";
								cout<<"TO 'LOGOUT' FROM THE LOCALITY PORTAL PRESS ANY OTHER KEY\n";
								cout<<"\n\t\tENTER YOUR CHOICE\n";
								int sh;cin>>sh;
								if(sh==1)
								{
									system("CLS");
									goto votalri;		
								}
								else if(sh==2)
								{
									system("CLS");
									goto votpos;
								}
								else if(sh==3)
								{
									system("CLS");
									goto seevotesofalready;
								}
								else if(sh==4)
								{
									system("CLS");
									goto seevotesofposted;
								}
								else
								{
									system("CLS");
									cout<<"YOU ARE OUT OF THE LOCALITY LOGIN PORTAL\n";
									SignObj.close();	
									goto com;
								}
							}
							if(stud1.vp!=0&&stud1.p==0&&stud1.q==0)
							{
								system("CLS");
								cout<<"YOU HAVE LOGGED IN SUCCESSFULLY\n";
								cout<<"YOU HAVE VOTED FOR THE POSTED PROBLEMS\n";
								cout<<"YOU CAN NOW VOTE FOR ALREADY EXISTING PROBLEMS AND YOU CAN POST YOUR PROBLEM\n";
								cout<<"                           OPTIONS AVAILABLE                              \n";
								cout<<"TO VOTE FOR ALREADY EXISTING PROBLEMS PRESS 1\n";
								cout<<"                             (OR)                                         \n";
								cout<<"TO POST YOUR PROBLEM PRESS 2\n";
								cout<<"                             (OR)                                         \n";
								cout<<"TO SEE THE VOTES OF ALREADY EXISTING PROBLEMS PRESS 3\n";
								cout<<"                             (OR)                                         \n";
								cout<<"TO SEE THE VOTES OF POSTED PROBLEMS PRESS 4\n";
								cout<<"                             (OR)                                         \n";
								cout<<"TO 'LOGOUT' FROM THE LOCALITY PORTAL PRESS ANY OTHER KEY\n";
								cout<<"\n\t\tENTER YOUR CHOICE\n";
								int th;cin>>th;
								if(th==1)
								{
									system("CLS");
									votalri:
									{
										v1=0;v2=0;v3=0;
										cout<<"You can now vote for the problems in your locality\n";
										cout<<"Problems that are already there\n";
										cout<<"1.Drainage_problem\n2.Bad_condition_of_roads\n3.Inadequete_supply_of_water\n";
										cout<<"IF YOU DO NOT WANT TO VOTE PRESS 0\n";
										cout<<"Enter your choice\n";	
										cin>>ch;
										if(ch==0)
										{
											cout<<"You are out of the locality login portal\n";
											SignObj.close();
											goto com;
										}
										if(ch==1)
										{
											v1++;
										}
										if(ch==2)
										{
											v2++;
										}
										if(ch==3)
										{
											v3++;
										}
										cout<<"v1="<<v1<<" v2="<<v2<<" v3="<<v3<<endl;
										stud1.q++;
										p1=SignObj.tellg();
										SignObj.seekp(p1-q1,ios::beg);
										SignObj.write((char*)&stud1,sizeof(stud1));
										SignObj.close();
							
										problem filestud;
										fstream ins1;
										ins1.open("Problem.txt",ios::in|ios::out);
									
										ins1.read((char*)&filestud,sizeof(filestud));
										v1=v1+filestud.returnvote();
										filestud.modifyvote(v1);
										int p=ins1.tellg(),q=sizeof(filestud);
										ins1.seekp(p-q);
										ins1.write((char*)&filestud,sizeof(filestud));
										mainstud1.modifyvote(v1-1000);
								
										ins1.read((char*)&filestud,sizeof(filestud));
										v2=v2+filestud.returnvote();
										filestud.modifyvote(v2);
										p=ins1.tellg();
										ins1.seekp(p-q);
										ins1.write((char*)&filestud,sizeof(filestud));
										mainstud2.modifyvote(v2-1000);
									
										ins1.read((char*)&filestud,sizeof(filestud));
										v3=v3+filestud.returnvote();
										filestud.modifyvote(v3);
										p=ins1.tellg();
										ins1.seekp(p-q);
										ins1.write((char*)&filestud,sizeof(filestud));
										mainstud3.modifyvote(v3-1000);
									
										ins1.close();
										
										system("CLS");
										cout<<"\n\n\nCONGRATULATIONS!!!\n\n\nYou Have Successfully Voted For Already Existing Problems\n\n\n";
										cout<<"To Go Back To Your Main Login Page Press 'M' Or 'm'\n\n";
										cout<<"To 'Logout' From Locality Portal Press 'l' Or 'L' Or Any Other Key\n\n";
										char c;
										cin>>c;
										if(c=='M'||c=='m')
										{
											system("CLS");
											goto start;
										}
										else
										{
											goto com;
										}
									
									}
								}
								else if(th==2)
								{
									system("CLS");
									goto pospro;
								}
								else if(th==3)
								{
									system("CLS");
									goto seevotesofalready;
								}
								else if(th==4)
								{
									system("CLS");
									goto seevotesofposted;
								}
								else
								{
									system("CLS");
									cout<<"YOU ARE OUT OF THE LOCALITY LOGIN PORTAL\n";
									SignObj.close();	
									goto com;	
								}
							}
							system("CLS");
							cout<<"YOU HAVE LOGGED IN SUCCESSFULLY\n";
							cout<<"YOU CAN NOW VOTE FOR THE ALREADY EXISTING PROBLEMS,POSTED PROBLEMS AND YOU CAN POST YOU PROBLEMS\n";
							cout<<"                              OPTIONS AVAILABLE                        \n";
							cout<<"TO VOTE FOR ALREADY EXISTING PROBLEMS\n";
							cout<<"PROBLEMS THAT ARE ALREADY EXISTING\n";
							cout<<"1.Drainage_problem\n2.Bad_condition_of_roads\n3.Inadequete_supply_of_water\n";
							cout<<"                                 (OR)                                  \n";
							cout<<"TO POST A PROBLEM PRESS 4\n";
							cout<<"                                 (OR)                                  \n";
							cout<<"TO VOTE FOR POSTED PROBLEMS PRESS 5\n";
							cout<<"                                 (OR)                                  \n";
							cout<<"TO SEE VOTES OF ALREADY EXISTING PROBLEMS PRESS 6\n";
							cout<<"                                 (OR)                                  \n";
							cout<<"TO SEE VOTES OF POSTED PROBLEMS PRESS 7\n";
							cout<<"                                 (OR)                                  \n";
							cout<<"TO 'LOGOUT' FROM THE LOCALITY PORTAL PRESS ANY OTHER KEY\n";
							cout<<"\n\t\tENTER YOUR CHOICE\n";	
							cin>>ch;
							if(ch==5)
							{
								votpos:
								{
									system("CLS");
									int number=1;
									ifstream PostObj1("PostedProblems.txt",ios::in);
									PostObj1.seekg(0,ios::end);int t=PostObj1.tellg();
									if(t==0)
									{
										cout<<"No problems have been yet posted\n";
										PostObj1.close();
										SignObj.close();
										goto com;
									}
									else
									{
										PostObj1.seekg(0,ios::beg);
										PostObj1.read((char*)&pstud,sizeof(pstud));   
									}   
									while(!PostObj1.eof())
									{
										cout<<"NUMBER:"<<number<<endl;
										pstud.printdata();
										PostObj1.read((char*)&pstud,sizeof(pstud));
										number++;			
										cout<<endl;
									}
									PostObj1.close();
									cout<<"Enter your choice for which problems you want to vote\n";int jh;
									cin>>jh;
									fstream PostObj2;
									PostObj2.open("PostedProblems.txt",ios::in|ios::out);
									PostObj2.seekg(0,ios::beg);
									int a=1;
									while(a<=jh)
									{
										PostObj2.read((char*)&pstud,sizeof(pstud));
										a++;
									}
									int vote=1+pstud.returnvote();
									int w1=PostObj2.tellg(),w2=sizeof(pstud);
									PostObj2.seekp(w1-w2,ios::beg);
									pstud.modifyvote(vote);
									PostObj2.write((char*)&pstud,sizeof(pstud));
									PostObj2.close();
									stud1.vp++;
									p1=SignObj.tellg();
									SignObj.seekp(p1-q1,ios::beg);
									SignObj.write((char*)&stud1,sizeof(stud1));
									SignObj.close();
								
									system("CLS");
									cout<<"\n\nCONGRATULATIONS!!!\n\n\nYo Have Successfully Voted For The Posted Problems\n\n\n";
									cout<<"To Go Back To Your Main Login Page Press 'M' Or 'm'\n\n";
									cout<<"To 'Logout' From Locality Portal Press 'l' Or 'L' Or Any Other Key\n\n";
									char c;
									cin>>c;
									if(c=='M'||c=='m')
									{
										system("CLS");
										goto start;
									}
									else
									{
										goto com;
									}
								}								
							}
							else if(ch==1)
							{
								v1++;
							}
							else if(ch==2)
							{
								v2++;
							}
							else if(ch==3)
							{
								v3++;
							}
							else if(ch==4)
							{
								system("CLS");
								pospro:
								{
									cout<<"YOU CAN POST NOW\n";
									char post[100];
									ofstream PostObj;
									PostObj.open("PostedProblems.txt",ios::app);
									cout<<"Enter your problem in not more than 2 sentences\n";
									cin>>post;
									pstud.readdata(post,1);
									PostObj.write((char*)&pstud,sizeof(pstud));
									PostObj.close();
									system("CLS");
									cout<<"CONGRATULATIONS!!!\nYour problem has been successfully posted\n\n\n";
									stud1.p++;
									p1=SignObj.tellg();
									SignObj.seekp(p1-q1,ios::beg);
									SignObj.write((char*)&stud1,sizeof(stud1));
									SignObj.close();
									cout<<"To Go Back To Your Main Login Page Press 'M' Or 'm'\n\n";
									cout<<"To 'Logout' From Locality Portal Press 'l' Or 'L' Or Any Other Key\n\n";
									char c;
									cin>>c;
									if(c=='M'||c=='m')
									{
										system("CLS");
										goto start;
									}
									else
									{
										goto com;
									}
								}
							}
							else if(ch==6)
							{
								system("CLS");
								goto seevotesofalready;
							}
							else if(ch==7)
							{
								system("CLS");
								goto seevotesofposted;
							}
							else
							{
								system("CLS");
								cout<<"YOU ARE OUT OF THE LOCALITY LOGIN PORTAL\n";
								SignObj.close();	
								goto com;
							}
							stud1.q++;
							p1=SignObj.tellg();
							SignObj.seekp(p1-q1,ios::beg);
							SignObj.write((char*)&stud1,sizeof(stud1));
							SignObj.close();
							cout<<"v1="<<v1<<" v2="<<v2<<" v3="<<v3<<endl;
							
							problem filestud;
							fstream ins1;
							ins1.open("Problem.txt",ios::in|ios::out);
								
							ins1.read((char*)&filestud,sizeof(filestud));
							v1=v1+filestud.returnvote();
							filestud.modifyvote(v1);
							int p=ins1.tellg(),q=sizeof(filestud);
							ins1.seekp(p-q);
							ins1.write((char*)&filestud,sizeof(filestud));
							mainstud1.modifyvote(v1-1000);
							
							ins1.read((char*)&filestud,sizeof(filestud));
							v2=v2+filestud.returnvote();
							filestud.modifyvote(v2);
							p=ins1.tellg();
							ins1.seekp(p-q);
							ins1.write((char*)&filestud,sizeof(filestud));
							mainstud2.modifyvote(v2-1000);
								
							ins1.read((char*)&filestud,sizeof(filestud));
							v3=v3+filestud.returnvote();
							filestud.modifyvote(v3);
							p=ins1.tellg();
							ins1.seekp(p-q);
							ins1.write((char*)&filestud,sizeof(filestud));
							mainstud3.modifyvote(v3-1000);
								
							ins1.close();
							system("CLS");
							cout<<"\n\n\nCONGRATULATIONS!!!\n\n\nYou Have Successfully Voted For Already Existing Problems\n\n\n";
							cout<<"To Go Back To Your Main Login Page Press 'M' Or 'm'\n\n";
							cout<<"To 'Logout' From Locality Portal Press 'l' Or 'L' Or Any Other Key\n\n";
							char c;
							cin>>c;
							if(c=='M'||c=='m')
							{
								system("CLS");
								goto start;
							}
							else
							{
								goto com;
							}
						}
						else
						{
							system("CLS");
							cout<<"YOU HAVE VOTED FOR THE EXISTING AND POSTED PROBLEMS.\nYOU HAVE POSTED YOUR PROBLEM AS WELL.\n";
							SignObj.close();
							cout<<"TO SEE THE VOTES OF ALREADY EXISTING PROBLEMS PRESS 1\n";
							cout<<"TO SEE THE VOTES OF POSTED PROBLEMS PRESS 2\n";
							cout<<"TO 'LOGOUT' FROM THE LOCALITY PORTAL PRESS ANY OTHER KEY\n";
							int wh;cin>>wh;
							system("CLS");
							if(wh==1)
							{
								goto seevotesofalready;
							}
							else if(wh==2)
							{
								goto seevotesofposted;
							}
							else
							{
								goto com;	
							}	
						}
					}
					SignObj.read((char*)&stud1,sizeof(stud1));
				}
				if(r==0)
				{
					cout<<"\n\t\t\tYou have entered invalid details\n";SignObj.close();
					goto com;
				}
			}
			if(oh==2)
			{
				cout<<"\n\t\t\tCreate ID\n\t\t\t";cin>>id;
				cout<<"\t\t\tCreate password\n\t\t\t";	
				s2:
				{
					string passwd="";
					int ch1;
					while(ch1=getch())
					{
						if(ch1==13||ch1=='$')
						{
							break;
						}
						else if(ch1==8)
						{
							if(passwd.length()>0)
							{
								cout<<"\b \b";
								passwd.erase(passwd.length()-1);
							}		
						}
						else if(ch1>=0&&ch1<=127)
						{
							cout<<"*";
							passwd+=ch1;
						}
					}
					if(passwd.length()<6)
					{
						cout<<"\n\t\t\tPassword should be having minimum of 6 characters\n\n\t\t\tPlease try again\n\n\t\t\t";
						passwd="";
						goto s2;
					}
					char tpassword[passwd.size()+1];
					strcpy(tpassword,passwd.c_str());
					strcpy(lpassword,tpassword);
				}
				ifstream SignInObj;
				SignInObj.open("SignUpFile.txt",ios::in);
				SignInObj.read((char*)&stud1,sizeof(stud1));
				while(!SignInObj.eof())
				{
					if(id==stud1.returnid())
					{
						cout<<"\n\t\t\tYou have entered already existing ID\n";SignInObj.close();
						goto com;
					}
					SignInObj.read((char*)&stud1,sizeof(stud1));
				}
				SignInObj.close();
				SignUp temp;
				ofstream SignOutObj;
				SignOutObj.open("SignUpFile.txt",ios::app);
				temp.readdata(id,lpassword);
				SignOutObj.write((char*)&temp,sizeof(temp));
				cout<<"\n\t\t\tYour Details have been saved successfully\n";
				SignOutObj.close();
				goto com;
			}
			if(oh!=1&&oh!=2)
			{
				cout<<"\n\t\t\tYou have entered invalid option\n";
				goto com;
			}
		}
		else if(ph==3)
		{
			system("CLS");
			return 0;
		}
		else
		{
			cout<<"You have entered Invalid Choice\n";
			return 0;
		}
		seevotesofalready:
		{	
		//	cout<<"\n\nTHE CONTENTS OF THE Problem.txt FILE ARE AS FOLLOWS\n\n";
		//	ifstream fin("Problem.txt",ios::in);
		//	fin.seekg(0,ios::beg);
		//	fin.read((char*)&stud,sizeof(stud));
		//	while(!fin.eof())
		//	{
		//		stud.printdata();
		//		fin.read((char*)&stud,sizeof(stud));	
		//	}
		//	fin.close();
			cout<<"\n\nVOTES OF THE ALREADY EXISTING PROBLEMS ARE AS FOLLOWS\n\n";
			mainstud1.printdata();
			mainstud2.printdata(); 
			mainstud3.printdata();
			cout<<"To Go Back To Your Main Login Page Press 'M' Or 'm'\n\n";
			cout<<"To 'Logout' From Locality Portal Press 'l' Or 'L' Or Any Other Key\n\n";
			char c;
			cin>>c;
			if(c=='M'||c=='m')
			{
				system("CLS");
				goto start;
			}
			else
			{
				goto com;
			}
		}
		seevotesofposted:
		{
			cout<<"\n\nTHE CONTENTS OF THE PostedProblems.txt\n\n";
			ifstream pin;
			pin.open("PostedProblems.txt",ios::in);
			pin.seekg(0,ios::end);
			int t=pin.tellg();
			if(t==0)
			{
				cout<<"No problems have been yet posted\n";
				pin.close();
				goto com;
			}
			else
			{
				pin.seekg(0,ios::beg);
				pin.read((char*)&pstud,sizeof(pstud));	
			}
			while(!pin.eof())
			{
				pstud.printdata();
				pin.read((char*)&pstud,sizeof(pstud));	
			}
			pin.close();
			cout<<"To Go Back To Your Main Login Page Press 'M' Or 'm'\n\n";
			cout<<"To 'Logout' From Locality Portal Press 'l' Or 'L' Or Any Other Key\n\n";
			char c;
			cin>>c;
			if(c=='M'||c=='m')
			{
				system("CLS");
				goto start;
			}
			else
			{
				goto com;
			}
		}
		com:
		{						
			cout<<"\t\t\tTo go back to the main page press 1 to exit press 0\n\t\t\t";int eh;cin>>eh;
			if(eh==1)
			{										
				system("CLS");
				goto z;
			}								
			if(eh==0)
			{
				return 0;
			}
			if(eh!=1&&eh!=0)						
			{
			cout<<"\t\t\tYou have entered an invalid choice\n";
			return 0;
			}
		}
		z:
		{
			
		}
	}
}
