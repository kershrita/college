// Motors
#define M11 3
#define M12 4
#define M21 5
#define M22 6

// Anaolg Digits
#define A0 16
#define A1 17
#define A2 18
#define A3 19


void forward(){
   digitalWrite(M11, HIGH);
   digitalWrite(M12, LOW);
   digitalWrite(M21, HIGH);
   digitalWrite(M22, LOW);
}

void backward(){
   digitalWrite(M11, LOW);
   digitalWrite(M12, HIGH);
   digitalWrite(M21, LOW);
   digitalWrite(M22, HIGH); 
}

void left(){
   digitalWrite(M11, HIGH);
   digitalWrite(M12, LOW);
   digitalWrite(M21, LOW);
   digitalWrite(M22, LOW);
}

void right(){
   digitalWrite(M11, LOW);
   digitalWrite(M12, LOW);
   digitalWrite(M21, HIGH);
   digitalWrite(M22, LOW);
}

void Stop(){
   digitalWrite(M11, LOW);
   digitalWrite(M12, LOW);
   digitalWrite(M21, LOW);
   digitalWrite(M22, LOW);
}

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
}

void loop() {
  int Digit1=digitalRead(A0);
  int Digit2=digitalRead(A1);
  int Digit3=digitalRead(A2);
  int Digit4=digitalRead(A3);
 
  if(Digit1==0 && Digit2==0 && Digit3==1 && Digit4==0) //Binary value received from DTMF Module - 0010 == 2
  forward();

  else if(Digit1==0 && Digit2==1 && Digit3==0 && Digit4==0) //0100 == 4
  right();
  
  else if(Digit1==0 && Digit2==1 && Digit3==1 && Digit4==0) //0110 == 6
  left();

  else if(Digit1==1 && Digit2==0 && Digit3==0 && Digit4==0) //1000 == 8
  backward();

  else if(Digit1==0 && Digit2==1 && Digit3==0 && Digit4==1) //0101 == 5
  Stop();
}
