#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/*
 *  Project title: brainfuck interpreter
 *
 *  Project purpose: this project have not any
 *  real purpose, it is made for fun
 *
 *  How to use project: open exe file and enter
 *  brainfuck program and then press enter to run it
 *
 *  Author: Mirovski
 *
 *  Version: v1.1
 *
 *  Date: 9.10.2020.
 *
 *  Project description/documentation:
 *  This is basic brainfuck interpreter that supports
 *  random numbers, but its compatible with classic
 *  brainfuck so classic brainfuck programs can still
 *  run here without  any problems. This is open-source
 *  so you can edit this program and share it if you want.
 *  This is written in 64-bit c++ (version 4.9.2). 
 *  I use Dev-C++ 5.11 IDE for writing this program. List
 *  of commands is following:
 *
 *  + = increases current value
 *
 *  - = decreases current value
 *
 *  > = moves pointer to right side (next cell in
 *  list will be selected by pointer)
 *
 *  < = does same thing as > command but it moves
 *  pointer to left side/previous cell in list
 *  will be selected by pointer
 *
 *  . = prints character that have ascii value that
 *  is selected by pointer
 *
 *  , = saves ascii value of entered character to
 *  memory
 *
 *  [ = if current pointer value is zero program goes
 *  to command after next matching ] else it goes to
 *  next matching ]
 *
 *  ] = if current pointer value is not zero program
 *  goes to previously matching [ else program ignores
 *  this command
 *
 *  ? = this command does not exists in classic brainfuck
 *  but it exists in this or another interpreter/compiler
 *  when program reads this command it will put random
 *  number beetwen 0 and 255 in current pointer
 *
 *  ! = this command also does not exist in classic brainfuck
 *  and this is command same as command ? command but its
 *  random number generated by seed, seed will be current
 *  pointer value
 *
 *  ~ = this command does not exists in classic brainfuck,
 *  it clears console/makes console empty
 *
 *  $ = this command does not exists in classic brainfuck,
 *  this command deletes only last character from output
 *
 *  @ = this command also does not exists in classic
 *  brainfuck, it makes delay for miliseconds specified by
 *  pointer value
 *
*/

using namespace std;

// this is list of values
char storage[30000] = {0};

// this is program pointer
char* p = storage;

// here will be brainfuck code
string program;

// this is identation of loops
int identation = 0;

// this is important for while loops
int a;
int b;

// console output
string output = "";

// main function
int main()
{
	
	// asking user to write program and clearing screen
	cin >> program;
	system("cls");
	
	// number of command
	int i = 0;
	
	// main loop
	while (i < program.length())
	{
		
		// reading and executing command
		switch (program[i])
		{
			
			// moving pointer left
			case '<':
				--p;
				break;
				
			// moving pointer right
			case '>':
				++p;
				break;
				
			// decreasing pointer
			case '-':
				-- * p;
				break;
				
			// increasing pointer
			case '+':
				++ * p;
				break;
				
			// printing character by ascii value in current pointer
			case '.':
				putchar(*p);
				output += *p;
				break;
				
			// getting ascii value of entered character to current pointer
			case ',':
				*p = getchar();
				break;
				
			// setting current pointer by totally random number
			case '?':
				*p = rand() % 255;
				break;
				
			// setting current pointer by random with seed that is current pointer value
			case '!':
				srand(int(*p));
				*p = rand() % 255;
				break;
				
			// clear console
			case '~':
				system("cls");
				output = "";
				break;
				
			// clear last character from console
			case '$':
                		system("cls");
                		output = output.substr(0, output.length() - 1);
                		cout << output; 
                		break;
				
			// make delay
			case '@':
				Sleep(int(*p));
				break;
				
			// open loop bracket
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
				
			// closing loop bracket
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
		
		// moving program to next command
		i++;
	}
	
	// telling user that program finished running and waiting for user to press any key to exit
	cout << endl << "-------------------------" << endl << "Program finished running." << endl << endl;
	cout << "Press any key to exit program...";
	_getch();
	
	// exiting with code 0 (everything is fine)
	return 0;
}
