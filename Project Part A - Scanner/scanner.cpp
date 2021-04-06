bool word (string s)
{
  // declare instance variables
  int state = 0; // state = current state of the dfa, begins at 0 (q0)
  int charpos = 0; // character position of string s
  
  // while loop will run until it reaches the end of the string s
  while (s[charpos] != '\0')
  {
    /* transitions from the initial state (q0)
    state 1 = q0q1 // creates a loop on q0q1
    state 2 = q0qy
    state 3 = qc
    state 4 = qy
    state 5 = qsa
    state 6 = qs
    state 7 = qt
    */
    if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
      state = 1; 
    else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 4;
    else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z'))
      state = 5;
    else if (state == 0 && s[charpos] == 'c')
      state = 3;
    else if (state == 0 && s[charpos] == 's')
      state = 6;
    else if (state == 0 && s[charpos] == 't')
      state = 7;
    
    // transitions from state 1 (q0q1)
    else if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
      state = 1; 
    else if (state == 1 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 4;
    else if (state == 1 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z'))
      state = 5;
    else if (state == 1 && s[charpos] == 'c')
      state = 3;
    else if (state == 1 && s[charpos] == 's')
      state = 6;
    else if (state == 1 && s[charpos] == 't')
      state = 7;
    else if (state == 1 && s[charpos] == 'n')
      state = 2;
    
    // transitions from state 2 (q0qy)
    else if (state == 2 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
      state = 1; 
    else if (state == 2 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 4;
    else if (state == 2 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z'))
      state = 5;
    else if (state == 2 && s[charpos] == 'c')
      state = 3;
    else if (state == 2 && s[charpos] == 's')
      state = 6;
    else if (state == 2 && s[charpos] == 't')
      state = 7;
    
    // transitions states 4-7 (qy, qsa, qt, qs) to state 1 (q0q1)
    else if (state == 4 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
      state = 1; 
    else if (state == 5 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
      state = 1; 
    else if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
      state = 1; 
    else if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
      state = 1; 
    
    // transitions states 3 ('h'), 4 ('y'), 6 ('s'), 7 ('h') to state 5 (qsa)
    else if (state == 3 && s[charpos] == 'h')
      state = 5;
    else if (state == 4 && s[charpos] == 'y')
      state = 5;
    else if (state == 6 && s[charpos] == 's')
      state = 5;
    else if (state == 7 && s[charpos] == 'h')
      state = 5;
    
    else
        return false; // occurs when none of the characters meets the if/else-if statement requirements
    
    charpos++; // changes character position in the string s
  } // end of while
  
  // where did i end up?
  if (state == 0 || state == 1 || state == 2)
    return true;
  else 
    return false;
  
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
