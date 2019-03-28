#include<iostream>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
struct write
{
	char name[100], surname[100];
	int num : 10, num2 : 8, num3 : 8, num4 : 8;
	
};

void t(int f)
{
	ofstream text("out1.txt");
	char str[100];
	for (size_t i = 0; i < f; i++)
	{
		cin.ignore();
		cout << "Write your name and surname" << endl;
		cin.getline(str, 100);
		text << str << endl;
		cin >> str;
		text << str << endl;
		cin >> str;
		text << str << endl;
		cin >> str;
		text << str << endl;
		cin >> str;
		text << str << endl;
	}
}

void sort(int n, write* s) {

	for (int i = 0; i < n - 1; i++)
	{
		for (size_t j = 0; j < n - 1; j++)
		{
			if ((strcmp(s[j].name, s[j + 1].name) == 1))
			{
				swap(s[j], s[j + 1]);
			}
			else if ((strcmp(s[j].surname, s[j + 1].surname) == 1))
			{
				swap(s[j], s[j + 1]);
			}
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
	}
}

void sortbnumb(int n, write* s) {
	for (int i = 0; i < n - 1; i++)
	{
		for (size_t j = 0; j < n - 1; j++)
		{
			if (s[j].num > s[j + 1].num)
			{
				swap(s[j], s[j + 1]);
			}
			else if (s[j].num2 > s[j + 1].num2)
			{
				swap(s[j], s[j + 1]);
			}
			else if (s[j].num3 > s[j + 1].num3)
			{
				swap(s[j], s[j + 1]);
			}
			else if (s[j].num4 > s[j + 1].num4)
			{
				swap(s[j], s[j + 1]);
			}
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
	}
}

void printcatalog(int n, write* s) {
	for (size_t i = 0; i < n; i++)
	{
		cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
	}
}

void deletecatalog(int n, int f, write*& s) {
	int d, h = 0;;
	cout << " repeat the # of user" << endl;
	cin >> d;
	write *tmp = new write[f - 1];
	for (size_t i = 0; i < n; i++)
	{
		if (i != d)
		{
			tmp[h] = s[i];
			h++;
		}
	}
	delete[] s;
	s = tmp;
	f = f - 1;
	for (size_t i = 0; i < f; i++)
	{
		cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
	}
}
write* arr = 0;

void addincatalog( int f, int n, write* s) {

	int num, n2, n3, n4;
	write*s = new write[f + 1];
	for (int i = 0; i < n; i++)
	{
		s[i] = arr[i];
	}
	for (int i = 0; i < f; i++)
	{
		text >> s[i].name;
		text >> s[i].surname;
		text >> num;
		text >> n2;
		text >> n3;
		text >> n4;
		s[i].num = num;
		s[i].num2 = n2;
		s[i].num3 = n3;
		s[i].num4 = n4;

	}
}



void task1()
{
	ifstream in("out1.txt");
	
	int f;
	cout << "Enter number of users in list" << endl;
	cin >> f;
	int k, l;
	int n, n2, n3, n4;
	//t(f);
	int t = 1;
	write *s = new write[f];
	cin.ignore();
	for (size_t i = 0; i < f; i++)
	{
		in >> s[i].name;
		in >> s[i].surname;
		in >> n;
		in >> n2;
		in >> n3;
		in >> n4;
		s[i].num = n;
		s[i].num2 = n2;
		s[i].num3 = n3;
		s[i].num4 = n4;

	}
	for (size_t i = 0; i < f; i++)
	{
		cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
	}
	while (t == 1)
	{


		cout << "do you want to change something in catalog(1 for yes,0 for no)" << endl;
		cin >> k;
		int i;
		if (k == 1)
		{
			cout << "# of user?(if #1 - 0, if #2 -1, if #3 - 2)" << endl;
			cin >> i;
			cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;

			int h;
			cout << "what you want to change in catalog(1 for name, 2 for surname,3 for first part of number,4 for second part of number,5 for third part of number,6for fourth part of number" << endl;
			cin >> h;
			switch (h)
			{
			case 1: cout << "Enter name" << endl;
				cin >> s[i].name; break;
			case 2: cout << "Enter surname" << endl;
				cin >> s[i].surname; break;
			case 3:int q;
				cout << "Enter first part of number" << endl;
				cin >> q;
				s[i].num = q;
				break;
			case 4:int e; cout << "Enter second part of number" << endl;
				cin >> e;
				s[i].num2 = e;
				break;
			case 5:int i; cout << "Enter third part of number" << endl;
				cin >> i;
				s[i].num3 = i;
			case 6:int x; cout << "Enter fourth part of number" << endl;
				cin >> x;
				s[i].num4 = x;
			default:
				break;
			}
			for (size_t i = 0; i < f; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		cout << "do you want to sort catalog by names?(1 for yes,0 for no)" << endl;
		cin >> l;
		if (l == 1)
		{
			sort(f, s);
		}

		cout << "do you want to sort catalog by numbers?(1 for yes,0 for no)" << endl;
		cin >> l;
		if (l == 1)
		{
			sortbnumb(f, s);
		}
		cout << "do you want to delete something in catalog?(1 for yes,0 for no)" << endl;
		cin >> l;
		int d;
		if (l == 1)
		{
			cout << "enter # of user";
			cin >> d;
			deletecatalog(f, d, s);
		}

		cout << "do you want to add something in catalog?(1 for yes,0 for no)" << endl;
		cin >> l;
		int g;
		if (l == 1)
		{
			cout << "enter new user" << endl;
			cin >> g;
			addincatalog(f, g, s);
		}
		cout << "Do you want to check telephones again?(1 for yes,0 for no)" << endl;
		cin >> t;
		if (t == 1)
		{
			printcatalog(f, s);
		}
	}

}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int a, d;
	
	do
	{
		printf("Which task");
		scanf_s("%d", &d);
		switch (d)
		{

		case 1: task1(); break;

		default:
			break;
		}
		printf(" do you want continue y(1)/no(2)");
		scanf_s("%d", &a);
	} while (a == 1);
	system("pause");
}