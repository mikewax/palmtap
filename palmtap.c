unsigned int input;
int i;

void setup() { 
pinMode(PIN_x, OUTPUT); // strobe
pinMode(PIN_x, OUTPUT); // strobe
pinMode(PIN_x, OUTPUT); // strobe
pinMode(PIN_x, OUTPUT); // strobe
pinMode(PIN_y, INPUT_PULLUP); // probe
pinMode(PIN_y, INPUT_PULLUP); // probe
pinMode(PIN_y, INPUT_PULLUP); // probe
pinMode(PIN_y, INPUT_PULLUP); // probe
} 

void poll(unsigned int input) { 
input = 0;
for ( i = 0; i < 4; i++) {
strobe i;
for ( j = 0; j < 4; j++) {
shift input left;
if (digitalRead(j)) input++; 
}


{ // D7 pin is high due to pullup resistor 
digitalWrite(PIN_D6, LOW); // LED on 
delay(400); // Slow blink 
digitalWrite(PIN_D6, HIGH); // LED off 
delay(400); 
}
 else 
{ // D7 pin is low due to pushbutton pressed 
digitalWrite(PIN_D6, LOW); // LED on 
delay(80); // Fast blink 
digitalWrite(PIN_D6, HIGH); // LED off 
delay(80); 
}
 } 






