#include<iostream>
#include<string>
using namespace std;

//-------------------------------------------------------
// CS421 HW1 
// Write a recognizer in C++ for L = {x | x is a binary number}.
// Your name: Jennifer Luu 
//-------------------------------------------------------

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is 0 or 1. (leading 0's are allowed).
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

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout "YES IN L" or "NO NOT IN L" depending on what was returned.
int main()
{
  // instance variables
  string E; // E = stores user's input

  cout << "Enter string to check, enter 'end' to exit" << endl;

  // loop will continue to prompt the user to enter a string until they
  // enter 'exit'
  while (true)
    { 
      // user input
      cin >> E;
      
      // if the user types "exit", it will allow them to exit the while loop
      if (E == "exit")
	break;

      // if the user's string was a binary number, the result from the recognizer
      // function is true and will state "YES IN L"
      if (recognizer(E) == true)
	cout << "YES IN L" << endl;
      
      // will start "NO IN L" was the user's input was not a binary number
      else 
	cout << "NO IN L" << endl;
      
      // feel free to put it in a loop 
    }
  
  return 0;
}// end of main
