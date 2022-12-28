#include<iostream>
using namespace std;

void login()
{
	string n, p, name, pass;
	n = "mou";
	p = "iit123";

	int i = 5;
	while(i--)
	{
		cout << "Enter name: ";
		cin >> name;
		if(name==n)
		{
			cout << "Enter password: ";
			cin >> pass;
			if(pass == p)
			{
				cout << "Login successfull!" << endl;
				return;			}
			else
			{
				cout << "Name and password does not match!" << endl;
			}
		}
		else
		{
			cout << "There is no account by this name!" << endl;
		}

		cout << "You have " << i << "attempts left" << endl;

		cout << "Try again!" << endl;

	}

}

int main()
{
	login();
}