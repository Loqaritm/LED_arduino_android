
int LEDpin = 9;
bool LEDon = false;
int brightness = 255;
int frequency = 20;
int fadeAmount = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char getdata='c';
  String temp = "";
  if(Serial.available() > 0){
    char data = Serial.read();
    if (data == 's'){
      LEDon = true;
    }
    else if(data == 'e'){
      LEDon = false;
    }
    else if(data == 'l'){
      while(data != 't'){
        data = Serial.read();
        temp += data;
      }
      brightness = temp.toInt();
      temp = "";
    }
    else if(data == 'f'){
      while(data != 't'){
        data = Serial.read();
        temp+=data;
      }
      frequency = temp.toInt();
      temp = "";
    }
  }

  if(LEDon){
    analogWrite(LEDpin, brightness);
  }
  

//
//  analogWrite(LEDpin, brightness);
//  brightness += fadeAmount;
//
//  if (brightness <= 0 || brightness >= 255) {
//    fadeAmount = -fadeAmount
//  }

  delay(30);
}
