#include<iostream>
#include"Virus.h"
#include<fstream>
#include<string>
#include<windows.h>
void Adv1::printINI()
{
	system("cls");
	cout << "This is the begining of the story..." << endl
		<< "You are a virus, not long ago you were brought to this location together with a movie." << endl
		<< "Since the onwer of the computer is a government staff, he did it very carefully. He used  " << endl
		<< "a little software and have changed the format of the movie successfully." << endl << endl << endl
		<< "Now you have no memery of these things, neither any message that brought in with you before" << endl
		<< "First you have to login!" << endl << endl
		<< ">login" << endl
		<< "password ?" << endl << endl
		<< ">";
}
int Adv1::accOrder(Adv1& INI, Virus &current)
{
	Initiate back;
	string a;
	string pas = "password";
	string hel = "@help";
	string bac = "@back";
	string qui = "@quit";
	string log = "login";
	string grant = "Findit";
	while (cin >> a)
	{
		cout << ">";
		if (a == pas)
		{
			cout << "The password is";
			color(0, 14);
			cout << " 'Findit'" << endl << endl;
			color(0, 15);
			cout << ">";
		}
		else if (a == hel)
		{
			cout << "login---Login on the system" << endl
				<< "password---Display the passsword" << endl
				<< "@help---Display the help" << endl
				<< "@quit---Save and quit this game" << endl
				<< "@back---Save and go back to the begin" << endl << endl
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
		else
		{
			cout << a << ":  " << "command not found. Use";
			color(0, 10);
			cout << " @help ";
			color(0, 15);
			cout << "to list available commands" << endl << endl;
			cout << ">";
		}
	}
	return 0;
}
void Adv1::setChapter(string ID)
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
