Project title: brainfuck interpreter

Project purpose: this project have not any
real purpose, it is made for fun

How to use project: open exe file and enter
brainfuck program and then press enter to run it

Author: Mirovski

Version: v1.1

Date: 9.10.2020.

Project description/documentation:
This is basic brainfuck interpreter that supports
random numbers, but its compatible with classic
brainfuck so classic brainfuck programs can still
run here without  any problems. This is open-source
so you can edit this program and share it if you want.
This is written in 64-bit c++ (version 4.9.2). 
I use Dev-C++ 5.11 IDE for writing this program. List
of commands is following:

 *  (+) = increases current value

 *  (-) = decreases current value
 
 *  (>) = moves pointer to right side (next cell in
 *  list will be selected by pointer)

 *  (<) = does same thing as > command but it moves
 *  pointer to left side/previous cell in list
 *  will be selected by pointer

 *  (.) = prints character that have ascii value that
 *  is selected by pointer

 *  (,) = saves ascii value of entered character to
 *  memory

 *  ([) = if current pointer value is zero program goes
 *  to command after next matching ] else it goes to
 *  next matching ]

 *  (]) = if current pointer value is not zero program
 *  goes to previously matching [ else program ignores
 *  this command

 *  (?) = this command does not exists in classic brainfuck
 *  but it exists in this or another interpreter/compiler
 *  when program reads this command it will put random
 *  number beetwen 0 and 255 in current pointer

 *  (!) = this command also does not exist in classic brainfuck
 *  and this is command same as command ? command but its
 *  random number generated by seed, seed will be current
 *  pointer value

 *  (~) = this command does not exists in classic brainfuck,
 *  it clears console/makes console empty

 *  ($) = this command does not exists in classic brainfuck,
 *  this command deletes only last character from output

 *  (@) = this command also does not exists in classic
 *  brainfuck, it makes delay for miliseconds specified by
 *  pointer value
