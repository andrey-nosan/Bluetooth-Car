/*
 * ER BROS LAB 
 * 
 * Bluetooth Car project.
 * 
 * Android App is avalable in Play store 
 * app link
 * https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller
 * 
 * Visit for more peojects
 * https://www.youtube.com/channel/UCY6KA8oFk1s36fyPiFEmedQ/?sub_confirmation=1
 * 
 * blog
 * https://erbros1.blogspot.com
 * 
 */



#define ENA 5
#define ENB 6
#define INAF 3
#define INAB 4
#define INBF 7
#define INBB 8
#define FL 9
#define BL 10

char c;
int spd = 230; 

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(INAF, OUTPUT);
  pinMode(INAB, OUTPUT);
  pinMode(INBF, OUTPUT);
  pinMode(INBB, OUTPUT);
  pinMode(FL, OUTPUT);

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(INAF, LOW);
  digitalWrite(INAB, LOW);
  digitalWrite(INBF, LOW);
  digitalWrite(INBB, LOW); 

}

void loop() {
  if(Serial.available()){
    c = Serial.read();
    Serial.println(c);
    }
    if (c =='0') {
      spd = 0;
    }
    else if (c == '2') {
      spd = 160;
    }
    else if (c == '4'){
      spd = 180 ;
    }
    else if (c == '6'){
      spd = 210;
    }
    else if (c == '8'){
      spd = 230;
    }
    else if (c == 'q'){
      spd == 254;
    }

   

    if(c == 'F') { // forward 
      digitalWrite(INAF, HIGH);
      digitalWrite(INBF, HIGH);
      analogWrite(ENA, spd);
      analogWrite(ENB, spd);  
    }
    else if (c == 'B') { //backward
      digitalWrite(INAB, HIGH);
      digitalWrite(INBB, HIGH);
      analogWrite(ENA, spd);
      analogWrite(ENB, spd);
    }
    else if (c == 'L') { // left
      digitalWrite(INBF, HIGH);
      digitalWrite(INAB, HIGH);
      analogWrite(ENA, spd);
      analogWrite(ENB, spd);
    }
    else if (c == 'R') { // right
      digitalWrite(INAF, HIGH);
      digitalWrite(INBB, HIGH);
      analogWrite(ENA, spd);
      analogWrite(ENB, spd);
    }
    else if (c == 'G') { //forward left
      digitalWrite(INBF, HIGH);
      analogWrite(ENA, spd/2);
      analogWrite(ENB, spd);
    }
    else if (c == 'I') {// forward right 
      digitalWrite(INAF, HIGH);
      analogWrite(ENA, spd);
      analogWrite(ENB, spd/2);
    }
    else if (c == 'H') {// back left 
      digitalWrite(INBB, HIGH);
      analogWrite(ENA, spd/2);
      analogWrite(ENB, spd);
    }
    else if (c == 'J') {// back right 
      digitalWrite(INAB, HIGH);
      analogWrite(ENA, spd);
      analogWrite(ENB, spd/2);
    }
    else if (c == 'W') {// Front light on
      digitalWrite(FL, HIGH);
    }
    else if (c == 'w') {// Front light off
      digitalWrite(FL, LOW);
    }
    else if (c == 'U') {// Front light on
      digitalWrite(BL, HIGH);
    }
    else if (c == 'u') {// Front light off
      digitalWrite(BL, LOW);
    }
    else if (c == 'S') {// stop
      digitalWrite(INAF, LOW);
      digitalWrite(INAB, LOW);
      digitalWrite(INBF, LOW);
      digitalWrite(INBB, LOW);
      digitalWrite(ENA, LOW);
      digitalWrite(ENB, LOW);
    }
    
    
}
