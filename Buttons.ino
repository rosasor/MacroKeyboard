/* Functions for Button Control */
int charDelay = 12; // Amount of time between keypresses to avoid key buffer overflows

/* initButtons */
void initButtons() {
  for (int i = 0; i < numButtons; i++) { // Loops through the array of Bounce2 buttons
    buttons[i].attach(buttonPins[i], INPUT);  // Attaches them as inputs
    buttons[i].interval(25); // Sets an interval of 25ms for responsiveness
  }
}

/* readButtons */
void readButtons() {
  for (int i = 0; i < numButtons; i++)  { // Loops through the array of Bounce2 buttons
    buttons[i].update(); // Updates each of them
    if (buttons[i].rose() ) { // Checks to see if any button has risen
      sendKey(i); // Calls sendKey()
    }
  }
}

/* sendKey */
void sendKey(int k) {
  switch (k) { //takes one argument (int k) and uses a switch/case structure to call different functions
    case 0: sendLetter('y'); sendMacro("bruh. ", charDelay); sendLetter(KEY_RETURN); break; // Switch 1
    case 1: sendLetter('y'); sendMacro("no time run ", charDelay); sendLetter(KEY_RETURN); break; break; // Switch 4
    case 2: sendLetter('y'); sendMacro("kys ", charDelay); sendLetter(KEY_RETURN); break; break; // Switch 2
    case 3: sendLetter('y'); sendMacro("i have kit move ", charDelay); sendLetter(KEY_RETURN); break; break; // Switch 5
    case 4: sendLetter('y'); sendMacro("it stands for keep yourself safe ", charDelay); sendLetter(KEY_RETURN); break; break; // Switch 3
    case 5: sendLetter('y'); sendMacro("im hacking ", charDelay); sendLetter(KEY_RETURN); break; break; // Switch 6
    case 6: sendLetter('y'); sendMacro("uwu ", charDelay); sendLetter(KEY_RETURN); break; break; // Switch 8
    case 7: sendLetter('y'); sendMacro("owo ", charDelay); sendLetter(KEY_RETURN); break; break; // Switch 9
    case 8: sendLetter('y'); sendMacro("venmo me @rosawashere ", charDelay); sendLetter(KEY_RETURN); break; break; // Switch 7
  }
}

/* sendLetter */
void sendLetter(char c) { // Takes one argument (char c)
  bleKeyboard.press(c); delay(charDelay);
  bleKeyboard.release(c); delay(charDelay);
  bleKeyboard.releaseAll();
}

/* sendShortcut */
void sendShortcut(char c) { // Takes one argument (char c) and combines it with a modifier (CRTL, CMD, ALT, SHIFT, etc.)
  bleKeyboard.press(KEY_LEFT_CTRL); delay(charDelay);
  bleKeyboard.press(c); delay(charDelay);
  bleKeyboard.release(c); delay(charDelay);
  bleKeyboard.release(KEY_LEFT_CTRL); delay(charDelay);
  bleKeyboard.releaseAll();
}

/* sendCompound */
void sendCompound(char c) { // Takes one argument (char c) and combines it with multiple modifiers (CRTL, CMD, ALT, SHIFT, etc.)
  bleKeyboard.releaseAll();
}

/* sendMacro */
void sendMacro(String s, int d) { // Takes one argument (String s) and sends the string one character at a time.
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
