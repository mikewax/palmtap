
unsigned int input;
int i, j;

void setup() { 
for ( i = 16; i < 20; i++) pinMode( i, OUTPUT); // strobe
for ( j = 20; j < 24; j++) pinMode( j,  INPUT_PULLUP); // probe
} 

void poll(unsigned int input) { 
input = 0;
for ( i = 16; i < 20; i++) {
digitalWrite( i, LOW ); delay(1);
for ( j = 20; j < 24; j++) { input << 1; if ( !digitalRead(j) ) input++;  }
digitalWrite( i, HIGH ); }
return input; }



{ // D7 pin is high due to pullup resistor 
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






