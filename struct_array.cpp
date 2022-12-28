
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

struct user{
	string name;
	string pass;
	int age;
	string gender;
};

struct user data[10];

	/*data[0].name = "admin";
	data[0].pass = "iit123";
	data[0].age = 30;
	data[0].gender = "male";*/
int head = 0;

void reg()
{
	
	head++;
	cout << "Enter name: ";
	cin >> data[head].name;
	cout << "Enter password: ";
	cin >> data[head].pass;
	cout << "Enter age: ";
	cin >> data[head].age;
	cout << "Enter gender: ";
	cin >> data[head].gender;

	cout << "Congratulations! registration successful." << endl;

}

int find(string s)
{
	for(int i = 0 ; i <= head ; i++)
	{
		if(data[i].name == s)
			return i;
	}
	return -1;
}

void login()
{
	string name, pass;

	int i = 5;
	while(i--)
	{
		cout << "Enter name: ";
		cin >> name;
		int j = find(name);
		if(j>=0)
		{
			cout << "Enter password: ";
			cin >> pass;
			if(data[j].pass == pass)
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
	while(1)
	{
	cout << "1. Registration\n2. Login\nEnter your choice : ";
	int x;
	cin >> x;
	if(x==1) reg();
	else if(x == 2) login();
	else 
	{
	    cout << "Invalid command" << endl;
	    break;
	}
	}
	return 0;
}