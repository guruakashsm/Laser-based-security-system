       /* Elephant Early Warning System Program */

// constants won't change. They're used here to set pin numbers:
const int buttonPin_1 = A3;     // input from line 1
const int buttonPin_2 = A1;     // Ref. 2.5v
const int buttonPin_3 = A2;     // input from line 2

const int ledPin_1 =  10;      // Red light pin
const int tip_1 =  11;      // Logic HIGH (TIP IC input)
const int ledPin_2 =  12;      // Green LED
const int tip_2 =  9;       // Logic HIGH (TIP IC input)
// variables initilization 
int buttonState_1= LOW;         
int buttonState_2= LOW;           
int buttonState_3= LOW;
int buttonState_4= LOW;
int state_1=LOW;
int state_2=LOW;
int state_3=LOW;
int state_4=LOW;   
int count=0;

void setup() {Serial.begin(9600);
  Serial.println("AT\r"); 
  delay(100);
  Serial.println("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  Serial.println("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  // initialize the LED pin as an output:
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(tip_1,OUTPUT);
  pinMode(tip_2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  //////
delay(1000);
digitalWrite(ledPin_1,HIGH);
digitalWrite(ledPin_2,HIGH);
digitalWrite(tip_1,HIGH);
digitalWrite(tip_2,HIGH);
delay(1000);
digitalWrite(ledPin_1,LOW);
digitalWrite(ledPin_2,HIGH);
digitalWrite(tip_1,LOW);
digitalWrite(tip_2,LOW);
}

void loop() {
  // read the state of the pushbutton value:
  ///***** First line
      buttonState_1 = analogRead(buttonPin_1);
      buttonState_2 = analogRead(buttonPin_2);
      if (buttonState_2 > buttonState_1) {
      delay(4000);
      state_1 = analogRead(buttonPin_1);
      state_2 = analogRead(buttonPin_2);
      if (buttonState_2 > buttonState_1 && state_2 > state_1)
      {
      Serial.print('\n');
      Serial.print("1st line voltage low");
    // turn LED on:
    // 2nd line checking
      buttonState_3 = analogRead(buttonPin_3);
      buttonState_2 = analogRead(buttonPin_2);
      if (buttonState_2 > buttonState_3) {
      //delay(4000);
      state_3 = analogRead(buttonPin_3);
      state_2 = analogRead(buttonPin_2);
      if (buttonState_2 > buttonState_3 && state_2 > state_3)
     {
    digitalWrite(ledPin_1,HIGH);
    digitalWrite(tip_1,HIGH);
    digitalWrite(tip_2,HIGH);
    sendsms();
    digitalWrite(tip_2, LOW);
    digitalWrite(tip_1, LOW);
    Serial.print('\n');
    Serial.println("2nd line voltage low");
    count=count+1;
    if (count>=7){
    sms_off();
    }
    }
    }
    }
    digitalWrite(ledPin_1, LOW);
    digitalWrite(tip_2, LOW);
    digitalWrite(tip_1, LOW);
    }  
    digitalWrite(ledPin_1, LOW);
    digitalWrite(tip_2, LOW);
    digitalWrite(tip_1, LOW);
}

void sendsms()
{
  // ******** SMS to no Warning Box *B#,*C#,*D#,*E#,*F#     
  Serial.println("AT\r");
  delay(1000);
  Serial.println("AT+CMGF=1\r");
  delay(1000);
  Serial.println("AT+CMGS=\"8489336839\"\r");
  delay(1000);
  Serial.println("Elephant Detected Madukarai");
  delay(1000);
  Serial.println((char)26);
  delay(6000);
  // ******** 2nd SMS     
  Serial.println("AT\r");
  delay(1000);
  Serial.println("AT+CMGF=1\r");
  delay(1000);
  Serial.println("AT+CMGS=\"8098581633\"\r");
  delay(1000);
  Serial.println("Elephant Detected Madukarai");
  delay(1000);
  Serial.println((char)26);
  delay(6000);
  // ******** 3rd SMS    
  Serial.println("AT\r");
  delay(1000);
  Serial.println("AT+CMGF=1\r");
  delay(1000);
  Serial.println("AT+CMGS=\"9789189966\"\r");
  delay(1000);
  Serial.println("Elephant Detected Madukarai");
  delay(1000);
  Serial.println((char)26);
  delay(6000);
}
// Off mode
void sms_off()
{
 Serial.print("sms off"); 
 digitalWrite(tip_2, LOW);
 digitalWrite(tip_1, LOW);
 // 1st sms
 Serial.println("AT\r");
  delay(1000);
  Serial.println("AT+CMGF=1\r");
  delay(1000);
  Serial.println("AT+CMGS=\"8489336839\"\r");
  delay(1000);
  Serial.println("Malfunction Detected Madukarai, adjust allignment");
  delay(1000);
  Serial.println((char)26);
  delay(6000); 
 // 1st sms
 Serial.println("AT\r");
  delay(1000);
  Serial.println("AT+CMGF=1\r");
  delay(1000);
  Serial.println("AT+CMGS=\"8098581633\"\r");
  delay(1000);
  Serial.println("Malfunction Detected Madukarai, adjust allignment");
  delay(1000);
  Serial.println((char)26);
  delay(6000); 
 digitalWrite(ledPin_1, HIGH);
 delay(53200000); // 12hrs off
 count=0; 
}
