#include<iostream>
#include <fstream>
#include"Virus.h"
using namespace std;
int main() 
{
	Initiate I;
	I.INI(I,I.getCondition());
	Virus client;
	string ID = I.getID();
	int chapter = I.getChapter();
	client.setChapter(chapter);
	client.setID(ID);
	int operation = 0;
	gameProcess(chapter,I,client);
	system("pause");
	return 0;
}
