
unsigned int input, preinput;
int i, j;

void setup() { 
for ( i = 16; i < 20; i++) pinMode( i, OUTPUT); // strobe
for ( j = 20; j < 24; j++) pinMode( j,  INPUT_PULLUP); // probe
} 

unsigned int poll() { 
input = 0;
for ( i = 16; i < 20; i++) {
digitalWrite( i, LOW ); delay(1);
for ( j = 20; j < 24; j++) { input << 1; if ( !digitalRead(j) ) input++;  }
digitalWrite( i, HIGH ); }
return input; 
}

void processInput() {

preinput = input;
input = poll();

