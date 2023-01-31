#define D0 16
#define D1 17
#define D2 18
#define D3 19

void setup() {
  Serial.begin(9600);
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
}
void loop() 
{

  int temp1=digitalRead(D0);
  int temp2=digitalRead(D1);
  int temp3=digitalRead(D2);
  int temp4=digitalRead(D3);

  Serial.println(temp1);
  Serial.println(temp2);
  Serial.println(temp3);
  Serial.println(temp4);
  delay(2000);
}
