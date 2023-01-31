// include header files
#include <LiquidCrystal.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// initialise global varaibles
const int rs = 3, 
          en = 4, 
          d4 = 5, 
          d5 = 6, 
          d6 = 7, 
          d7 = 8,
          CE = 9,
          CSN = 10;

const char key[] = "IEEE802";

const uint64_t address = 0xA1B2C3D4;

// initialise rNF Module
RF24 radio(CE, CSN);

// initialise LCD screen
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);

// setup function
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  radio.begin();
  radio.enableDynamicPayloads();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  LCD.begin(16, 2);
  LCD.print("   System On");
  delay(2500);
  LCD.clear();
}

// loop function
void loop() {
  if (radio.available()) {
    uint8_t len = radio.getDynamicPayloadSize();
    char cipher[len];
    
    radio.read(&cipher, len);
    String text = Decode(cipher, len);

    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    
    LCD.clear();
    LCD.print("Dx: ");
    LCD.setCursor(0, 1);
    LCD.print("Ex: ");
    LCD.setCursor(3, 0);
    LCD.print(cipher);
    LCD.setCursor(3, 1);
    LCD.print(text);
  } 
}

// decryption function
String Decode(char cipher[], int string_length) {
  int alpha,
      keyword,
      output,
      i = 0,
      j = 0;
  String text;
  
  while (i < string_length) {
    alpha = cipher[i];
    keyword = key[j];
    output = ((alpha + 65) - (keyword - 65));
    text += char(output);
    if(sizeof(key) - 1 >= i){
      j = 0;
    }
    i++;
  }
  return text;
}
