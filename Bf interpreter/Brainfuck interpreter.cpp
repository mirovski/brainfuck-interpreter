#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

char storage[30000] = {0};
char* p = storage;
string program;
int identation = 0;
int a;
int b;
string filename;

int main()
{
	cin >> program;
	/*string line;
	cin >> filename;
	ifstream file(filename);
	while (std::getline(file, line))
	{
		program += line;
	}
	file >> program;
	file.close();*/
	system("cls");
	int i = 0;
	while (i < program.length())
	{
		switch (program[i])
		{
		case '<':
			--p;
			break;
		case '>':
			++p;
			break;
		case '-':
			-- * p;
			break;
		case '+':
			++ * p;
			break;
		case '.':
			putchar(*p);
			break;
		case ',':
			*p = getchar();
			break;
		case '[':
			identation = 1;
			a = i + 1;
			b;
			while (true)
			{
				if (program[a] == '[')
				{
					identation++;
				}
				else if (program[a] == ']')
				{
					identation--;
				}
				if (identation == 0)
				{
					break;
				}
				a++;
			}
			b = a;
			i = b - 1;
			break;
		case ']':
			identation = -1;
			a = i - 1;
			b;
			while (true)
			{
				if (program[a] == '[')
				{
					identation++;
				}
				else if (program[a] == ']')
				{
					identation--;
				}
				if (identation == 0)
				{
					break;
				}
				a--;
			}
			b = a;
			if (*p != 0)
			{
				i = b;
			}
		}
		i++;
	}
	return 0;
}