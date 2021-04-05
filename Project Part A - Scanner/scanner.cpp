bool word (string s)
{
  // declare instance variables
  int state = 0; // state = current state of the dfa, begins at 0 (q0)
  int charpos = 0; // character position of string s
  
  // while loop will run until it reaches the end of the string s
  while (s[charpos] != '\0')
  {
    // checks if the first character is a vowel
    if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
      state = 1;
    else if
      state = 2;
  }
  
  /**********************************************
  int state = 0;
  int charpos = 0;
  
  // replace the following todo the word dfa
  while (s[charpos] != '\0')
  {
    if (state == 0 && s[charpos] == 'a')
      state = 1;
    else if (state == 1 && s[charpos] == 'b')
      state = 2;
    else if (state == 2 && s[charpos] == 'b')
      state = 2;
    else 
      return false;
    charpos++;
  } // end of while
  
  // where did i end up?
  if (state == 2)
    return true; // end in a file state
  else
    retun false;
  **********************************************/
}
