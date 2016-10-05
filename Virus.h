#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#ifndef VIRUS_H
#define VIRUS_H
class Virus 
{
	friend void saveData(fstream &, Virus &);
	//友元，用于储存数据
	friend void changeID(Virus &);
	//友元，用于更换账号
	friend void iRead(fstream &, Virus &);
	//友元，重载函数iRead用于更换账号时写入数据
	friend ifstream &Read(ifstream &, Virus &);
	friend bool check(Virus &, Virus &);
	//友元，用户想要更换账号时check函数检查是否存在该账号,若存在，则写入文件
	//重载Initiate的友元check
	friend void findID(ifstream &, Virus &);
private:
	string ID;
	int chapter;
	double process;
	//chapter记录章节,process记录游戏进度，ID记录游戏账号
public:
	void acceptOrder(int, ifstream &);
	void setID(string);
	string getID();
	void setChapter(int);
	int getChapter();
	
	void setPro(int);
	double getPro();
};
void saveData(Virus &);
void changeID(Virus &);
void iRead(fstream &, Virus &);
bool check(Virus &, Virus &);
ifstream &Read(ifstream &, Virus &);
void findID(ifstream &, Virus &);
class Initiate
{
	//Initiate类的友元
	friend bool check(Initiate &, Initiate &);

private:
	int chapter;
	string ID;
	int condition = -1;
public:
	void INI(Initiate &, int);
	void choose();
	void establish(ofstream &, int,Initiate &);
	//用于创建新的账号
	ifstream &iRead(ifstream &, Initiate &);
	//用于读取BasicData中的数据
	void iRead(fstream &, Initiate &);
	//与changeID配套，当check函数返回值为真时执行
	void setChapter(int);
	int getChapter();
	void setCondition(int);
	int getCondition();
	void setID(string);
	string getID();
};
class Adventure 
{
private:
	int chapter;
public:
	void setChapter(int a);
	int getChapter();
	void quit(Virus &);
	//保存并退出游戏，所有子类将继承
 	void back(Initiate &);
	//保存并回到主菜单，所有子类将继承
	void chaID(Virus &);
	//保存并退出账号
	virtual void accOrder();
	//虚函数接受命令，各子类有自己的版本
	virtual void setChapter(fstream &, string,string);
	virtual void printINI();
};
void saveData(Initiate &);
bool check(Initiate &, Initiate &);
//用于检查玩家输入的账号是否存在
class Adv1:public Adventure
{
private:
	int chapter = 0;
public:
	int accOrder(Adv1 &,Virus &);
	void printINI();
	void setChapter( string);
};
class Adv2:public Adventure
{
private:
	int chapter = 1;
public:
	int accOrder(Adv2 &, Virus &);
	void printINI();
	void setChapter(string);
};
class Adv3:public Adventure
{
private:
	int chapter = 1;
public:
	int accOrder(Adv3 &, Virus &);
	void printINI();
	
};
void print();
//用于打印所有账号
void gameProcess(int, Initiate&, Virus&);
//游戏主进程函数
void end();
//输出游戏结束语段
void color(unsigned short, unsigned short);
//用于设置文字颜色
//1:蓝，2：绿，3,：浅暗蓝，4：深红，5：紫:，6：土黄，7：白，8：灰，
//9：深蓝，10：亮绿，11：浅亮蓝,12：深红，13：淡紫，14：亮黄
//调用setcolor(0,15);可调回原色
#endif



