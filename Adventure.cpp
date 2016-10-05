#include<iostream>
#include"Virus.h"
#include<fstream>
#include<string>
#include<windows.h>
void Adventure::setChapter(int cha)
{
	chapter = cha;
}
int Adventure::getChapter()
{
	return chapter;
}
void Adventure::quit(Virus &temp)
{
	cout << "Save your DATA or not?" << endl;
	color(0, 10);
	cout << "'@Y'";
	color(0, 15);
	cout << "= Yes//////";
	color(0, 10);
	cout << "'@N'";
	color(0, 15);
	cout << "= No" << endl << endl
		<< ">";
	string commond;
	cin >> commond;
	if (commond == "@Y")
	{
		saveData(temp);
		exit(0);
	}
	else if (commond == "@N")
	{
		exit(0);
	}
	else
	{
		color(0, 10);
		cout << "No such commond!" << endl << endl;
		color(0, 15);
		cout << ">";
	}
}
void Adventure::back(Initiate &temp)
{
	cout << "Save your DATA or not?" << endl;
	color(0, 10);
	cout << "'@Y'";
	color(0, 15);
	cout << "= Yes//////";
	color(0, 10);
	cout << "'@N'";
	color(0, 15);
	cout << "= No" << endl << endl
		<< ">";
	string commond;
	cin >> commond;
	if (commond == "@Y")
	{
		saveData(temp);
	}
	else if (commond == "@N")
	{
	}
	else
	{
		color(0, 10);
		cout << "No such commond!" << endl << endl;
		color(0, 15);
		cout << ">";
	}
}
void Adventure::chaID(Virus &a)
{
	saveData(a);
	changeID(a);
}
void Adventure::accOrder()
{}
void Adventure::setChapter(fstream &in, string a, string chapter)
{}
void Adventure::printINI()
{}
void saveData(Initiate &current)
{
	Initiate temp;
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
