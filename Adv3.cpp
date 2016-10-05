#include<iostream>
#include"Virus.h"
#include<fstream>
#include<string>
#include<windows.h>
void Adv3::printINI()
{
	system("cls");
	color(0, 14);
	cout << "Access granted!" << endl;
	color(0, 15);
	cout << "--------------------------------------------------------------------------" << endl << endl
		<< "We are very suprised to find that you have passed this text," << endl
		<< "and knowing your clinical condition!" << endl
		<< "In this computer there are so many PLACES that you have left your MEMORY in." << endl
		<< "It is very important for you to know how to FIND them." << endl
		<< "So you must find a MAP that can guid you, so that you can keep yourself not lost" << endl
		<< "First you'll need to run a command as an administrater///" << endl << endl << endl;
	cout << ">";
}
int Adv3::accOrder(Adv3 &INI, Virus &current)
{
	Initiate back;
	string a;
	string ls = "@ls";
	string cat = "@cat";
	string hel = "@help";
	string bac = "@back";
	string qui = "@quit";
	string log = "login";
	string grant = "MapisRightHere";
	string sudo = "@sudo";
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
				<< "@cat---Display the file content" << endl
				<< "@sudo---Run a command as an administrater" << endl << endl
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
						chapter = "3";
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
					color(0, 12);
					cout << "You must be an administrater to read this file!" << endl << endl;
					color(0, 15);
					cout << ">";
					break;
				}
				else if (file == "map.txt")
				{
					color(0, 12);
					cout << "You must be an administrater to read this file!" << endl << endl;
					color(0, 15);
					cout << ">";
					break;
				}
				else if (file == "help.txt")
				{
					color(0, 12);
					cout << "You must be an administrater to read this file!" << endl << endl;
					color(0, 15);
					cout << ">";
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
		else if (a == sudo)
		{
			string command;
			while (cin >> command)
			{
				if (command == ls)
				{
					color(0, 13);
					cout << "password.txt" << endl
						<< "map.txt" << endl
						<< "help.txt" << endl << endl;
					color(0, 15);
					cout << ">";
					break;
				}
				else if (command == hel)
				{
					cout << "login---Login on the system" << endl
						<< "@ls---List files" << endl
						<< "@help---Display the help" << endl
						<< "@quit---Save and quit this game" << endl
						<< "@back---Save and go back to the begin" << endl
						<< "@cat---Display the file content" << endl
						<< "@sudo---Run a command as an administrater" << endl << endl
						<< ">";
					break;
				}
				else if (command == bac)
				{
					INI.back(back);
					return 2;
				}
				else if (command == qui)
				{
					INI.quit(current);
				}
				else if (command == log)
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
								chapter = "3";
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
					break;
				}
				else if (command == cat)
				{
					string file;
					while (cin >> file)
					{
						if (file == "password.txt")
						{
							cout << "The password is " << endl
								<< "------------------------------" << endl;
							color(0, 14);
							cout << "         MapisRightHere       " << endl;
							color(0, 15);
							cout << "------------------------------" << endl << endl;
							break;
						}
						else if (file == "map.txt")
						{
							color(0, 12);
							cout << "You must input the password successfully first!" << endl << endl;
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
								<< "@cat---Display the file content" << endl
								<< "@sudo---Run a command as an administrater" << endl << endl
								<< ">";
							break;
						}
						else
						{
							color(0, 12);
							cout << "File not found!" << endl << endl;
							color(0, 15);
							cout << ">";
							break;
						}

					}
				}
				else
				{
					cout << command << ":  " << "command not found. Use ";
					color(0, 10);
					cout << "@help";
					color(0, 15);
					cout << "to list available commands" << endl << endl;
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
			cout << "to list available commands" << endl << endl;
			cout << ">";
		}
	}
	return 0;
}
