// include header files
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// initialise global varaibles
const int CE = 9,
          CSN = 10;

const byte len = 16;
const char key[] = "IEEE802";

const uint64_t address = 0xA1B2C3D4;

// initialise rNF Module
RF24 radio(CE, CSN);

// loop function
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  radio.begin();
  radio.enableDynamicPayloads();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

// loop function
void loop() {
  String text;
  while (Serial.available()) {
    text = Serial.readString();
  }
  
  if(text.length() != 0){
    String string_cipher = Encode(text, text.length());
    char char_cipher[len];
    
    for(int i = 0; i < text.length(); i++){
      char_cipher[i] = string_cipher[i];
    }

    radio.write(char_cipher, text.length() - 1);
    
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    
    Serial.print("text: "); 
    Serial.println(text); 
    Serial.print("cipher: "); 
    Serial.println(string_cipher); 
    Serial.print(""); 
  }
}

// get string from user function
String get_string() {
  String input;
  while (Serial.available() != 0) {
      input = Serial.readString();
  }
  return input;
}

// encryption function
String Encode(String text, int string_length) {
  int alpha,
      keyword,
      output,
      i = 0,
      j = 0;
  String cipher;
  
  while (i < string_length) {
    alpha = text[i];
    keyword = key[j];
    output = ((alpha - 65) + (keyword - 65));
    cipher += char(output);
    if(sizeof(key) - 1 >= i){
      j = 0;
    }
    i++;
  }
  return cipher;
}
