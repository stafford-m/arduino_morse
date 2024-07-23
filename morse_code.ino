/*
dot = 1 unit - check
dash = 3 units - check
space between parts of letter = 1 unit
dots, dashs, and the spaces between them in a single letter are covered by dot() and dash()

space between letters = 3 units - 2 units in next_letter() since each dot and dash is already followed with a 1 unit delay
space between words = 7 units - 4 units in next_word() since each dot and dash is already followed with a 1 unit delay plus a 2 unit delay for next_letter().
*/

#define unit 300 // ms

void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(unit);
  digitalWrite(LED_BUILTIN, LOW);
  delay(unit);
}

void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(unit * 3);
  digitalWrite(LED_BUILTIN, LOW);
  delay(unit);
}

void next_letter() {
  delay(unit * 2);
}

void next_word() {
  delay(unit * 4);
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  char message[] = "a z";
  const size_t message_length = sizeof(message);

  for (int i = 0; i < message_length; i++) {
    morse_letter(message[i]);
  }
}

void morse_letter(char letr) {
  switch (letr) {

    case 'a' :
      dot(); dash();
      break;
    
    case 'b' :
      dash(); dot(); dot(); dot();
      break;

    case 'c' :
      dash(); dot(); dash(); dot();
      break;

    case 'd' :
      dash(); dot(); dot();
      break;
    
    case 'e' :
      dot();
      break;

    case 'f' :
      dot(); dot(); dash(); dot();
      break;

    case 'g' :
      dash(); dash(); dot();
      break;

    case 'h' :
      dot(); dot(); dot(); dot();
      break;

    case 'i' :
      dot(); dot();
      break;

    case 'j' :
      dot(); dash(); dash(); dash();
      break;
    
    case 'k' :
      dash(); dot(); dash();
      break;

    case 'l' :
      dot(); dash(); dot(); dot();
      break;
    
    case 'm' :
      dash(); dash();
      break;

    case 'n' :
      dash(); dot();
      break;

    case 'o' :
      dash(); dash(); dash();
      break;

    case 'p' :
      dot(); dash(); dash(); dot();
      break;

    case 'q' :
      dash(); dash(); dot(); dash();
      break;

    case 'r' :
      dot(); dash(); dot();
      break;

    case 's' :
      dot(); dot(); dot();
      break;

    case 't' :
      dash();
      break;

    case 'u' :
      dot(); dot(); dash();
      break;

    case 'v' :
      dot(); dot(); dot(); dash();
      break;

    case 'w' :
      dot(); dash(); dash();
      break;

    case 'x' :
      dash(); dot(); dot(); dash();
      break;

    case 'y' :
      dash(); dot(); dash(); dash();
      break;

    case 'z' :
      dash(); dash(); dot(); dot();
      break;
    
    case ' ' :
      next_word();
      break;

    default :
      break;
  }
  next_letter();
}
