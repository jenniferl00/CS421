#include<iostream>
#include<string>
#include<queue> // include queue.h or equivalent such as <queue>

using namespace std;

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is a binary number}.
// Your name: Jennifer Luu
//----------------------------------------------

// Copy the recognizer function here from the other file.

// The recognizer function should return TRUE or FALSE 
// checking each character to make sure it is 0 or 1. 
// (leading 0's are allowed).
bool recognizer(string s)
{
  // the loop will determine if the entered string was a binary number by
  // checking if each character was a 0 or 1
  for (int i=0; i < s.length(); i++)
    {
      // if the character in the string was a 0 or 1, it will continue
      if (s[i] == '0' || s[i] == '1')
        continue;

      // if at any point there is a character that is not a 0 or 1, the
      // function will return false  
      else
        return false;
    }

  // if the loop was able to iterate through the string without running into 
  // any other characters (that's not a 0 or 1), it will return true
  return true;
}// end of recognizer

// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can 
//   terminate the program with control-C 
//   after about 20 strings have been displayed.
int main()
{ 
  // instance variables
  int count = 0; // the number of elements that have been processed
  string s; // binary string
  string response; // user input
  int num = 1; // power number for 3^num, used to section the # of elements

  // queue declaration of strings
  queue <string> q;
  // "0", "1", and "3" will be pushed into the queue
  q.push("0");
  q.push("1");
  q.push("2");

  // the loop will continue until the user asks to exit the loop
  while(true)
    {
      // generate a string
      s = q.front(); // sets string 's' to the first element of the queue
      q.pop(); // fifo, gets rid of first element (0)
      s.push_back('0'); // pushes '0' into string s
      q.push(s); // pushes the string s into the queue
      s.pop_back(); // removes the last element of the string s
      s.push_back('1'); // pushes '1' into string s
      q.push(s); // pushes the string s into the queue
      s.pop_back(); // removes the last element of the string s
      s.push_back('2'); // pushes '2' into string s
      q.push(s); // pushes the string s into the queue
      s.pop_back(); // removes the last element of string s

      // count increments whenever an element has been processed
      count++;

      // if the recognizer says true, display it 
      if (recognizer(s) == true)
	cout << s << " is binary" << endl;

      int answer = 3; // answer of 3^num, used to section the # of elements

      // loop is used to find the answer for 3^num
      for (int i=0; i<num; i++)
	  answer = answer*3;

      // used to section the number of elements
      // if count == 3^num (9, 27, 81...)
      if (count == answer)
	{
	  // increments num to move onto the next power of 3
	  num++;
	  // prints out the number of processed elements
	  cout << "# of elements processed = " << count << endl;
	  // gives the user control to continue or exit the loop
	  cout << "Enter a character and <cr> to continue..." << endl;
	  cin >> response;

	  // condition to exit the while loop
	  if (response == "exit")
	    break;
	}      
    }// end of while
  return 0;
}// end of main
