// Functions for Button Control

int charDelay = 8; //Amount of time between keypresses to avoid key buffer overflows


/* initButtons */
void initButtons() {
  for (int i = 0; i < numButtons; i++) { //loops through the array of Bounce2 buttons
    buttons[i].attach(buttonPins[i], INPUT);  //attaches them as inputs
    buttons[i].interval(25); //sets an interval of 25ms for responsiveness
  }
}

/* readButtons */
void readButtons() {
  for (int i = 0; i < numButtons; i++)  { //loops through the array of Bounce2 buttons
    buttons[i].update(); //updates each of them
    if (buttons[i].rose() ) { //checks to see if any button has risen
      sendKey(i); //calls sendKey()
    }
  }
}

/* sendKey */
void sendKey(int k) {
  switch (k) { //takes one argument (int k) and uses a switch/case structure to call different functions
    case 0: sendShortcut('x'); sendShortcut('s'); break;  //Switch 1, Save
    case 1: sendShortcut('k'); break;                     //Switch 4, Cut line
    case 2: sendShortcut('x'); sendShortcut('c'); break;  //Switch 2 Save and quit
    case 3: sendShortcut('y'); break;                     //Switch 5, paste line
    case 4: sendShortcut('x'); sendShortcut('f'); break;  //Switch 3, find file or open a file
    case 5: sendShortcut('x'); sendLetter('u'); break;    //Switch 6, Undo last command
    case 6: sendLetter('{'); break;                       //Switch 8, Type {
    case 7: sendLetter('"'); break;                       //Switch 9, Type "
    case 8: sendLetter(')'); break;                       //Switch 7, Type )

    /*case 0: sendLetter('x'); break;
    case 1: sendLetter('c'); break;
    case 2: sendLetter('v'); break;
    case 3: sendLetter('a'); break;
    case 4: sendLetter('z'); break;
    case 5: sendLetter('y'); break;
    case 6: sendLetter('m'); break;
    case 7: sendLetter('P'); break;
    case 8: sendLetter('?'); break;*/

  }
}

/* sendLetter */
void sendLetter(char c) { //takes one argument (char c)
  bleKeyboard.write(c); delay(charDelay);
  bleKeyboard.releaseAll();
}

/* sendShortcut */
void sendShortcut(char c) { //takes one argument (char c) and combines it with a modifier (CRTL, CMD, ALT, SHIFT, etc.)
  bleKeyboard.press(KEY_LEFT_CTRL); delay(charDelay);
  bleKeyboard.press(c); delay(charDelay);
  bleKeyboard.release(c); delay(charDelay);
  bleKeyboard.release(KEY_LEFT_CTRL); delay(charDelay);
  bleKeyboard.releaseAll();
}

/* sendCompound */
void sendCompound(char c) { //takes one argument (char c) and combines it with multiple modifiers (CRTL, CMD, ALT, SHIFT, etc.)
  bleKeyboard.releaseAll();
}

/* sendMacro */
void sendMacro(String s, int d) { //takes one argument (String s) and sends the string one character at a time.
  int l = s.length() + 1;           // Determine length of string
  char c[l];                        // Create array for characters
  s.toCharArray(c, l);              // Copy characters to array
  for (int i = 0; i < l - 1; i++) { // Loop through character array
    char p = c[i];                  // Get the current character
    bleKeyboard.press(p); delay(d); // Press/Release the key w/ delay
    bleKeyboard.release(p); delay(d);
  }
  bleKeyboard.releaseAll();
}
