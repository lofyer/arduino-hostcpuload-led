/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
 clears it.
 
 A good test for this is to try it with a GPS receiver 
 that sends out NMEA 0183 sentences. 
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

static int led(int i){
  if(i<0||i>5){
    Serial.println("Input a number between 0-5.");
    return 1;
  }
  int led_num=i+5;
  if(i==0){
    Serial.println("Clear");
    int num=6;
    for(num;num<11;num++){
      digitalWrite(num,LOW);
    }
    return 0;
  }
  int j=6;
  for(j;j<=led_num;j++)
    digitalWrite(j,HIGH);
}

void setup() {
  // initialize serial:
  Serial.begin(115200);
  // reserve 200 bytes for the inputString:
  int led=6;  
  // initialize the digital pin as an output.
  for(led;led<11;led++)
    pinMode(led, OUTPUT);   
}

void loop() {
  // print the string when a newline arrives:
  /*if (stringComplete) {
    Serial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
    
  }
  */
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    Serial.print("Key: ");
    Serial.println(inChar);
    Serial.print("ascii: ");
    Serial.println((int)(inChar-48));
    led(0);
    led((int)(inChar-48)); 
    // add it to the inputString:
    //inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    //if (inChar == '\n') {
    //  stringComplete = true;
    //} 
  }
}


