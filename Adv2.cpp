#include<iostream>
#include"Virus.h"
#include<fstream>
#include<string>
#include<windows.h>
void Adv2::printINI()
{
	system("cls");
	color(0, 14);
	cout << "Access granted!" << endl;
	color(0, 15);
	cout << "--------------------------------------------------------------------------" << endl << endl
		<< "Welcome to the primary level of this computer  @__@" << endl
		<< "We are very happy to see you!" << endl
		<< "But You have lost your memmory for a long time." << endl
		<< "You will have to find your PASSWORD" << endl << endl << endl;
	cout << ">";
}
int Adv2::accOrder(Adv2 &INI, Virus &current)
{
	Initiate back;
	string a;
	string ls = "@ls";
	string cat = "@cat";
	string hel = "@help";
	string bac = "@back";
	string qui = "@quit";
	string log = "login";
	string grant = "Memory@";
	while (cin >> a)
	{
		cout << ">";
		if (a == ls)
		{
			color(0, 13);
			cout << "password.txt" << endl
				<< "map.txt" << endl
				<< "help.txt" << endl << endl;
			color(0, 15);
			cout << ">";
		}
		else if (a == hel)
		{
			cout << "login---Login on the system" << endl
				<< "@ls---List files" << endl
				<< "@help---Display the help" << endl
				<< "@quit---Save and quit this game" << endl
				<< "@back---Save and go back to the begin" << endl
				<< "@cat---Display the file content" << endl << endl
				<< ">";
		}
		else if (a == bac)
		{
			INI.back(back);
			return 2;
		}
		else if (a == qui)
		{
			INI.quit(current);
		}
		else if (a == log)
		{
			color(0, 14);
			cout << "password ? " << endl << endl;
			color(0, 15);
			cout << ">";
			string password;
			while (cin >> password)
			{
				if (password == grant)
				{
					ifstream L("LastGame.txt");
					string ID;
					string chapter;
					if (L.is_open())
					{
						L >> ID >> chapter;
						L.close();
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
					else
					{
						cerr << "Error!" << endl;
						exit(1);
					}
					//INI.setChapter(ID);
					//fstream B("BasicData.txt");
					//string temp;
					return 1;
				}
				else
				{
					color(0, 12);
					cout << "Password not right!" << endl << endl;
					color(0, 15);
					cout << ">";
					break;
				}

			}
		}
		else if (a == cat)
		{
			string file;
			while (cin >> file)
			{
				if (file == "password.txt")
				{
					cout << "Dear Mary:" << endl
						<< "	I know you don't like a dull person like me. But you know what? " << endl
						<< "Since I left you, I have been constantly depressed. My happiness is to" << endl
						<< "be near you. Incessantly I live over in my memory your caresses,your " << endl
						<< "tears, your affectionate solicitude. The charms of the incomparable Mary" << endl
						<< "kindle continually a burning and a glowing flame in my heart." << endl
						<< "	I'm now so depressed. I think I have lost you. But I want to " << endl
						<< "give you something. Here is the password of my computer. This is VERY " << endl
						<< "important and precious, so don't lose it! Maybe some day it will help " << endl
						<< "you!" << endl << endl
						<< "----------------------------------------" << endl << endl;
					color(0, 14);
					cout << "                 Memory@                " << endl << endl;
					color(0, 15);
					cout << "----------------------------------------" << endl << endl
						<< "	Don't forget to Delete it! " << endl << endl
						<< "	Bye!" << endl << endl
						<< "                                                           Yours Mike " << endl << endl
						<< ">";
					break;
				}
				else if (file == "map.txt")
				{
					color(0, 12);
					cout << "You must be administrater to check this file!" << endl << endl;
					color(0, 15);
					cout << ">";
					break;
				}
				else if (file == "help.txt")
				{
					cout << "login---Login on the system" << endl
						<< "@ls---List files" << endl
						<< "@help---Display the help" << endl
						<< "@quit---Save and quit this game" << endl
						<< "@back---Save and go back to the begin" << endl
						<< "@cat---Display the file content" << endl << endl
						<< ">";
					break;
				}
				else
				{
					color(0, 12);
					cout << "File not Found!" << endl << endl;
					color(0, 15);
					cout << ">";
					break;
				}
			}
		}
		else
		{
			cout << a << ":  " << "command not found. Use ";
			color(0, 10);
			cout << "@help";
			color(0, 15);
			cout << " to list available commands" << endl << endl
				<< ">";
		}
	}
	return 0;
}
void Adv2::setChapter(string ID)
{
	ifstream B("BasicData.txt");
	string temp;
	char chapter[2];
	while (B >> temp >> chapter)
	{
		if (ID == temp)
		{
			/////////////////////////////////////////
			break;
		}
	}
}
