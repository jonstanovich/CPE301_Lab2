/****************************************
 * Name: Jon Stanovich-Rubalcava
 * Assignment: Lab 2
 * Date: 31 May 2022
 ****************************************/
 
 
//Two-bit button input pins
#define LSBButton 3
#define MSBButton 4

//Chip select output pins (CSXX)
#define CS0001 12
#define CS0010 11
#define CS0100 10
#define CS1000 9

void setup() {
  
  // put your setup code here, to run once:
  pinMode(LSBButton, INPUT);
  pinMode(MSBButton, INPUT);
  
  pinMode(CS0001, OUTPUT);
  pinMode(CS0010, OUTPUT);
  pinMode(CS0100, OUTPUT);
  pinMode(CS1000, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int buttonFirst = NULL;
  int buttonSecond = NULL;
  
  buttonFirst = digitalRead(LSBButton);
  buttonSecond = digitalRead(MSBButton);

    // DECODER BLOCK
  if(buttonSecond == LOW && buttonFirst == LOW){      // First starts on the right
    // write 0001 to the LED
    digitalWrite(CS0001, HIGH);
    digitalWrite(CS0010, LOW);
    digitalWrite(CS0100, LOW);
    digitalWrite(CS1000, LOW);
    
  }else if(buttonSecond == LOW && buttonFirst == HIGH){
    // write 0010 to the LED 
    digitalWrite(CS0001, LOW);
    digitalWrite(CS0010, HIGH);
    digitalWrite(CS0100, LOW);
    digitalWrite(CS1000, LOW);
    
  }else if(buttonSecond == HIGH && buttonFirst == LOW){
    // write 0100 to the LED 
    digitalWrite(CS0001, LOW);
    digitalWrite(CS0010, LOW);
    digitalWrite(CS0100, HIGH);
    digitalWrite(CS1000, LOW);
    
  }else if(buttonSecond == HIGH && buttonFirst == HIGH){
    // write 1000 to the LED 
    digitalWrite(CS0001, LOW);
    digitalWrite(CS0010, LOW);
    digitalWrite(CS0100, LOW);
    digitalWrite(CS1000, HIGH);
    
  } // end DECODER BLOCK
  
}
