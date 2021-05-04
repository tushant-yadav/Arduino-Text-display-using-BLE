#include<Wire.h>
#include<SoftwareSerial.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<string.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//The (-1) parameter means that your OLED display doesn’t have a RESET pin.

/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial bt(2,3); /* (Rx,Tx) */  

String line[8] = {""};
int index=0;

void printlines(String lines[]){
  display.setCursor(0, 0);
  for(int i=0;i<8;i++){
    display.println(lines[i]);
    display.setCursor(0,8*i);
  }
}

void shiftlines(String (& line)[8]){
  for(int i=1;i<8;i++){
    line[i-1]=line[i];
  }
}


void setup() {
//Display Setup
  
  pinMode(2,INPUT);
  pinMode(3,OUTPUT)
  
  bt.begin(115200);  /* Define baud rate for software serial communication */
  Serial.begin(115200); /* Define baud rate for serial communication */

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
//Text config
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

}

void loop() { 
   
  // put your main code here, to run repeatedly:
  String words="";
  while(words[-1]!=' ' && bt.available()){
    words+= bt.read();
    if(words[-1]=='\0') break;
  }

  if(line[index%8].length()+words.length()+1>=128){
    index++;
    if(index==8){
      shiftlines(line);
      }
    line[index%8]+="";
    index--;
    delay(500);
  }
  
  
  
  line[index%8]+=" ";
  line[index%8]+=words;
  words="";


  printlines(line);
  
}
