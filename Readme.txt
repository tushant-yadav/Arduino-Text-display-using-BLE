Project Plan - 
Select hardware for the task.
-> Selected hardware HC05 Bluetooth module, SSD1306 OLED Screen, Arduino UNO
Get a basic understanding of the usage of OLED Screen and BLE with Arduino UNO. 
Write code to receive a text from Bluetooth to Arduino.
Write code to display a string on the screen.
Integrate 3 & 4 and enable scrolling to display strings larger than screen size.
Start Date - 28 April 2021
End date - 28 April 2021



Pseudo Code:

We set up the HC-05 Bluetooth module on pin 2,3 (Rx, Tx) for serial communication At baud rate 9600.
We set up SSD1306 OLED screen on pins A4, A5 for I2C communication with baud rate 115200.
We set text size =1 that is 7X5 pixels. Colour white.
We receive characters from BlueTooth so we keep on receiving until a word is completed.
Once we have a word we append that word to the line and display the text.
When the line is full we move on to the next line.
When the screen is full that is all 8 lines are full, and we still have text, we remove the oldest line from the screen and append the latest line with a delay of 0.5 seconds.





