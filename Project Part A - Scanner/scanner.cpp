bool word (string s)
{
  int state = 0;
  int charpos = 0;
  
  /* replace the following todo the word dfa */
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
}
