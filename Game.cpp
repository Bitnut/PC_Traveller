#include<iostream>
#include"Virus.h"
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;
void Initiate::INI(Initiate &I,int condition)  
{
	color(0, 7);
	std::cout << "                                                                              游戏开始 @——@ " << endl<<endl<<endl;
	color(0, 15);
	//打印选择菜单
	I.choose();
	int  order = 0;
     //condition储存状态：1表示继续上次游戏，2表示创建新账号操作,3表示重回主菜单，
     //4表示退出游戏,5表示重新循环,6查询各账号
	while (std::cin >> order)
	{
			switch (order)
			{
			case 1:
			{
				ifstream last;
				int check = 0;
				//检查文件是否为空
				last.open("LastGame.txt");
				if (last.is_open())
				{
					check =last.get();
					if (!last.eof())
					{
						ifstream input("LastGame.txt");
						if (input.is_open())
						{
							string ID;
							int chapter;
							last >> ID >> chapter;
							I.setID(ID);
							I.setChapter(chapter);
							condition = 1;
							I.setCondition(condition);
							//cout << ID << chapter<<endl;
							//cout << I.getChapter ()<< I.getID();
							break;
						}
						else
						{
							cerr << "Error!" << endl;
							exit(1);
						}
						break;
					}
					else
					{
						cerr << "NO SUCH DATA!" << endl << endl;
						condition = 5;
						I.setCondition(condition);
					}
				}
				else
				{
					cerr << "Error!";
					exit(1);
				}
				break;
			}
			case 2:
			{
				ofstream est;
				I.establish(est, condition,I);
				if (condition == 4 || condition == 2 || condition == 3)
				{
					I.setCondition(condition);
					break;
				}
			}
			case 3:
			{
				condition = 3;
				I.setCondition(condition);
				break;
			}
			case 6:
			{
				print();
				condition = 3;
				I.setCondition(condition);
				break;
			}
			case 0:
			{
				I.choose();
				condition = 0;
				I.setCondition(condition);
				break;
			}
			case 4:
			{
				exit(0);
			}
			default:
			{
				color(0, 12);
				std::cout << "输入有误，请重新选择！" << endl;
				color(0, 15);
				condition = 0;
				I.setCondition(condition);
				break;
			}
			}
			switch (condition)
			{
			case 1:
			case 2:
			case 4:
			case 6:
				break;
			case 3:
			case 5:
			{
				I.choose();
				break;
			}
			default: {
				cerr << "Programe should1 never come here!" << endl;
				break;
			}
			}
			//最后检查结果，如果是1、 2或4跳出循环结束INI函数
			if (condition == 1 || condition == 2 || condition == 4)
				break;	
	}
	//若一开始选择输入时发生错误。程序将跳到这里，且condition=-1，下一步进入到开始游戏进程。operation=0.
}
void Initiate::choose() 
{
	     cout << "请选择操作类型" << endl<<endl<<endl;
		 cout << "---------------------------------------------------------------------" << endl;
		 cout<< "'1'表示继续上次游戏" << endl
			 << "'2'表示新建一个账号" << endl
			 << "'6'表示显示账号列表"<<endl
			 << "'4'表示退出游戏" << endl
			 << "'3'表示重新弹出选项菜单" << endl<<endl;
}
//establish 函数，创建新账号时使用
void Initiate::establish(ofstream &est,int condition,Initiate &I) 
{	
	est.open("BasicData.txt", ofstream::in | ofstream::app);
	string a;
	string q = "@quit";
	string b = "@back";
	string p = "print";
	cout << "请输入新账号、、" << "//新账号应该至少包含";
	color(0, 11);
	cout << "6~32" ;
	color(0, 15);
	cout << "个的字符或者";
	color(0, 11);
	cout << "3~8";
	color(0, 15);
	cout << "个的中文，" << endl
		<< "退出编辑回到开始菜单请输入";
	color(0, 10);
	cout << "‘@back’" << endl;
	color(0, 15);
	cout << "直接退出游戏请输入";
	color(0, 10);
	cout << "‘@quit’" << endl;
	color(0, 15);
	cout << "显示账号列表输入";
	color(0, 10);
	cout<<"'print'"<<endl<<endl;
	color(0, 15);
	while (std::cin >> a) 
	{
		
	    if (a== b)
		{
			condition = 3;
			I.setCondition(condition);
			break;
		}
		else if (a== q)
		{
			condition = 4;
			I.setCondition(condition);
			break;
		}
		else if (a==p)
		{
			print();
			condition = 6;
			I.setCondition(condition);
			break;
		}
		else
		{
			int len = 0;
			len = a.size();
			if (len > 6 && len < 32)
			{
				condition = 2;
				I.setCondition(condition);
				break;
			}
			else
			{
				color(0, 12);
				cout << "输入格式不正确,情重新输入！" << endl;
				color(0, 15);
				cout << "退出编辑回到开始菜单请输入";
				color(0, 10);
				cout << "‘@back’" << endl;
				color(0, 15);
				cout << "直接退出游戏请输入";
				color(0, 10);
				cout<<"‘@quit’" << endl<<endl;
				color(0, 15);
				condition = 5;
				I.setCondition(condition);
				continue;
			}
		}
	}
	switch (condition)
	{
	case 2:
	{
		est << a << "\n"<<"0"<<"\n";
		ofstream input("LastGame.txt", ios::out | ios::trunc);
		if (input.is_open())
		{
			input << a << endl<<"0"<<endl;
			break;
		}
		else
		{
			cerr << "Error!" << endl;
			exit(1);
		}
		break;
	}
	case 3:
	case 4:
	case 5:
	case 6:
		break;	
	default:
	{
		cerr << "Programe should never come here!" << endl;
		break;
	}
	}
}
void Initiate::setCondition(int a)
{
	condition = a;
}
int Initiate::getCondition()
{
	return condition;
}
//iRead函数从BasicData中读取文件信息
//in文件输入流绑定某文件，temp为类参数用于暂存信息
ifstream & Initiate::iRead(ifstream &in,Initiate &temp)
{      
	in >> temp.ID >> temp.chapter;
	return in;
}
//用户想要更换账号时check函数检查是否存在该账号,若存在，则写入文件
bool check(Initiate &check, Initiate &input)
{
	ifstream i("BasicData.txt");
	bool condition = 0;
	if (i.is_open())
	{
		Initiate ini;
		while (ini.iRead(i, check) && !i.eof())
		{
			if (input.ID==check.ID)
			{
				condition = 1;
				break;
			}
		}
	}
	else
	{
		cerr << "Error!"<<endl;
		exit(1);
	}
	if (condition == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Initiate::setChapter(int a) 
{
	chapter = a;
}
int Initiate::getChapter() {
	return chapter;
}
//findID函数执行遍历直到查找到对应的账号，然后载入章节信息，返回新类,更换账号时使用
void findID(ifstream &in,Virus &current) 
{
	Virus trans;
	while (Read(in,trans)&&!in.eof()) 
	{
		if (trans.getID()==current.getID())
		{
			current.setChapter(trans.getChapter());
			//在lastgame文件中重新写入记录
			ofstream input("LastGame.txt",ios::out|ios::trunc);
			if (input.is_open())
			{
				input << current.getID() <<endl<< current.getChapter();
			}
			else
			{
				cerr << "Error!" << endl;
				exit(1);
			}
			break;
		}
	}
}
void Initiate::setID(string temp)
{
	ID = temp;
}
string Initiate::getID()
{
	return ID;
}
ifstream &Read(ifstream &in, Virus &temp)
{
	string ID;
	int chapter;
	in >> ID >> chapter;
	temp.setID(ID);
	temp.setChapter(chapter);
	return in;
}



//changeID运行更换账号命令
void changeID(Virus &current)
{
	//先对游戏进度进行储存
	fstream save("BasicData.txt");
	if (save.is_open())
	{
		iRead(save, current);
		//然后进行更换
		std::cout << "请输入您想变更的账号======" << endl
				  << "输入'@back'返回主菜单" << endl
				  << "输入'print'输出账号列表" << endl;
		Virus temp;
		string tempID;
		cin>>tempID;
		temp.setID(tempID);
		if (check(temp, current))
		{
			ifstream is("BasicData.txt");
			findID(is, current);
		}
		else
		{
			std::cout << "输入ID有误，请重新输入！" << endl
				<< "'@back'返回主菜单" << endl
				<< "'print'输出账号列表" << endl;
		}
	}
	else
	{
		cerr << "Error!" << endl;
	}
	ofstream input("LastGame.txt", ios::out | ios::trunc);
	if (input.is_open())
	{
		input << current.getID() << endl << current.getChapter();
	}
	else
	{
		cerr << "Error!" << endl;
		exit(1);
	}
}
//重载函数iRead用于更换账号时写入数据
void iRead(fstream &cha, Virus &current)
{
	Virus temp;
	while (cha >> temp.ID)
	{
		if (temp.ID==current.ID)
		{
			cha << current.chapter;
			break;
		}
		else
		{
			cha >> temp.chapter;
		}
	}
}
//用户想要更换账号时check函数检查是否存在该账号,若存在，则写入文件
bool check(Virus &check, Virus &input)
{
	ifstream i("BasicData.txt");
	bool sit = 0;
	if (i.is_open())
	{
		Initiate ini;
		while (Read(i, check))
		{
			if (!(input.getID()==check.getID()))
			{
				sit = false;
			}
			else
			{
				sit=true;
				break;
			}
				
		}
	}
	else
	{
		cerr << "Error!" << endl;
		return false;
	}
	return true;
}
void Virus::setID(string a)
{
	ID = a;
}
string Virus::getID()
{
	return ID;
}
void Virus::setChapter(int a)
{
	chapter = a;
}
int Virus::getChapter()
{
	return chapter;
}
//用于更换账号时储存章节信息
void saveData(Virus &current)
{
	Virus temp;
	fstream basic("BasicData.txt");
	if (basic.is_open())
	{
		while (basic >> temp.getID())
		{
			if (temp.getID() == current.getID())
			{
				basic << endl << current.getChapter();
				break;
			}
			else
			{
				int tem = 0;
				basic >> tem;
				temp.setChapter(tem);
			}
		}
	}
	else
	{
		cerr << "Error!" << endl;
		exit(1);
	}
	switch (current.getChapter())
	{
	case 1:
	{
		ifstream L("LastGame.txt");
		string ID;
		string chapter;
		if (L.is_open())
		{
			L >> ID >> chapter;
			L.close();
			cout << chapter;
			chapter = "0";
			ofstream out("LastGame.txt");
			if (out.is_open())
			{
				out << ID << endl << chapter << endl;
			}
			else
			{
				cerr << "Error!" << endl;
				exit(1);
			}
		}
	}
	case 2:
	{
		ifstream L("LastGame.txt");
		string ID;
		string chapter;
		if (L.is_open())
		{
			L >> ID >> chapter;
			L.close();
			cout << chapter;
			chapter = "1";
			ofstream out("LastGame.txt");
			if (out.is_open())
			{
				out << ID << endl << chapter << endl;
			}
			else
			{
				cerr << "Error!" << endl;
				exit(1);
			}
		}
	}
	case 3:
	{
		ifstream L("LastGame.txt");
		string ID;
		string chapter;
		if (L.is_open())
		{
			L >> ID >> chapter;
			L.close();
			cout << chapter;
			chapter = "2";
			ofstream out("LastGame.txt");
			if (out.is_open())
			{
				out << ID << endl << chapter << endl;
			}
			else
			{
				cerr << "Error!" << endl;
				exit(1);
			}
		}
	}
	default:
		break;
	}
}
void Virus::setPro(int cha)
{
	//////////process=
}
double Virus::getPro()
{
	return process;
}

//打印账号列表
void print()
{
	ifstream input("BasicData.txt");
	if (input.is_open())
	{
		string a;
		string chapter;
		do
		{
			input >> a >> chapter;
			cout << a << endl<<endl;
		} while (!input.eof());
	}
	else
	{
		cerr << "Error!" << endl;
		exit(1);
	}
}
//游戏主进程函数gameProcess
void gameProcess(int chapter,Initiate &I,Virus &client)
{
	int operation = 0;
	//存储记录游戏命令，0为开始游戏，-1为退出游戏进程,1为通关，2为重启主菜单进程
	while (!(operation==-1))
	{
		switch (operation)
		{
		case 0:
		{
			if (!(I.getCondition() == -1))
			{
				switch (chapter)
				{
				case 0:
				{
					Adv1 one;
					one.printINI();
					operation = one.accOrder(one, client);
					break;
				}
				case 1:
				{
					Adv2 two;
					two.printINI();
					operation = two.accOrder(two, client);
					break;
				}
				case 2:
				{
					Adv3 three;
					three.printINI();
					operation = three.accOrder(three, client);
					break;
				}
				case 3:
				{
					end();
					operation = -1;
					break;
				}
				default:
				{
					cerr << "Program should2 never come here!" << endl;
					break;
				}
				}
			}
			else
			{
				cout << "输入错误，请重新选择！" << endl << endl;
				operation = 2;
			}
			break;
		}			
		case 1:
		{
			chapter++;
			I.setChapter( chapter );
			client.setChapter(chapter);
			switch (chapter)
			{
			case 0:
			{
				Adv1 one;
				one.printINI();
				operation = one.accOrder(one, client);
				break;
			}
			case 1:
			{
				Adv2 two;
				two.printINI();
				operation = two.accOrder(two, client);
				break;
			}
			case 2:
			{
				Adv3 three;
				three.printINI();
				operation = three.accOrder(three, client);
				break;
			}
			case 3:
			{
				end();
				operation = -1;
				break;
			}
			default:
			{
				cerr << "Program should1 never come here!" << endl;
				break;
			}
			}
			break;
		}
		case 2:
		{
			I.INI(I, I.getCondition());
			Virus client;
			string ID = I.getID();
			int chapter = I.getChapter();
			client.setChapter(chapter);
			client.setID(ID);
			operation = 0;
			break;
		}
		default:
		{
			cerr << "Program should never come here!" << endl;
			break;
		}
		}
	}
}
void end()
{
	cout << "..............END OF THIS GAME NOW..............." << endl
		 << "........The game is going to be continued........" << endl << endl << endl
		 << "..................HPC PRESENTS..................." << endl;
}
void color(unsigned short ForeColor, unsigned short BackGroundColor)                                //设定字体颜色 
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor | BackGroundColor);
}
