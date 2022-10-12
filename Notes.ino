/*
  Linux keypad commands
    case 0: sendShortcut('x'); sendShortcut('s'); break;  //Switch 1, Save
    case 1: sendShortcut('k'); break;                     //Switch 4, Cut line
    case 2: sendShortcut('x'); sendShortcut('c'); break;  //Switch 2 Save and quit
    case 3: sendShortcut('y'); break;                     //Switch 5, paste line
    case 4: sendShortcut('x'); sendShortcut('f'); break;  //Switch 3, find file or open a file
    case 5: sendShortcut('x'); sendLetter('u'); break;    //Switch 6, Undo last command
    case 6: sendLetter('{'); break;                       //Switch 8, Type {
    case 7: sendLetter('"'); break;                       //Switch 9, Type "
    case 8: sendLetter(')'); break;                       //Switch 7, Type )

   Broken keys keypad commands
    case 0: sendLetter('P'); break; //Switch 1
    case 1: sendLetter(')'); break; //Switch 4
    case 2: sendLetter('p'); break; //Switch 2
    case 3: sendLetter('{'); break; //Switch 5
    case 4: sendLetter('?'); break; //Switch 3
    case 5: sendLetter(';'); break; //Switch 6
    case 6: sendLetter('"'); break; //Switch 8
    case 7: sendLetter(':'); break; //Switch 9
    case 8: sendLetter('_'); break; //Switch 7

   print words cause fun
    case 0: bleKeyboard.print("bruh."); break; //Switch 1 
    case 1: bleKeyboard.print("no time run"); break; //Switch 4
    case 2: bleKeyboard.print("kys"); break; //Switch 2
    case 3: bleKeyboard.print("i have kit move"); break; //Switch 5
    case 4: bleKeyboard.print("it stands for keep yourself safe"); break; //Switch 3
    case 5: bleKeyboard.print("im hacking"); break; //Switch 6
    case 6: bleKeyboard.print("uwu"); break; //Switch 8
    case 7: bleKeyboard.print("owo"); break; //Switch 9
    case 8: bleKeyboard.print("venmo me @rosawashere"); break; //Switch 7
*/
