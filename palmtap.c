
unsigned int input, preinput;
int i, j;
_Bool fresh, repeat;
const int bounce = 250;
const int repmode = 750;

unsigned int poll() { 
  input = 0;
  for ( i = 16; i < 20; i++) {
    digitalWrite( i, LOW ); delay(1);
    for ( j = 20; j < 24; j++) { input << 1; if ( !digitalRead(j) ) input++;  }
    digitalWrite( i, HIGH ); }
  return input; 
}

void setup() { 
  const char *encode[16];
  encode[0] = "0"; encode[1] = "0"; encode[2] = "0"; encode[3] = "0";
  encode[4] = "0"; encode[5] = "0"; encode[6] = "0"; encode[7] = "0";
  encode[8] = "0"; encode[9] = "0"; encode[10] = "0"; encode[11] = "0";
  encode[12] = "0"; encode[13] = "0"; encode[14] = "0"; encode[15] = "0";
 
  for ( i = 16; i < 20; i++) pinMode( i, OUTPUT); // strobe
  for ( j = 20; j < 24; j++) pinMode( j, INPUT_PULLUP); // probe
} 

int main() {

  timer = 0; fresh = 0; repeat = 0;
  elapsedMillis timer; 
  Serial.begin(9600); 

  for ( ; ; ) {
    if ( timer > bounce && ( fresh || repeat )) {
      processOutput( input ); timer = 0; fresh = 0; }
    if ( timer > repmode && input > 0 ) {
      repeat = 1; processOutput( input ); timer = 0; }

    preinput = input; input = poll();
    input > preinput: timer = 0, fresh = 1;
    input < preinput: timer = 0, repeat = 0;
  }
  return 0;
}

void processOutput(unsigned int output) {









