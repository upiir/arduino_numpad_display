// simple project using Arduino Leonardo and Nextion Enhanced display to create a virtual numpad/keypad
// created by upir in 2023
//
// YouTube Tutorial Video: https://youtu.be/GuEdR9CSPck
// YouTube Channel: https://www.youtube.com/upir_upir
//
// Links from the video:
// - Source Files: https://github.com/upiir/arduino_numpad_display
// - USB to TTL module: https://s.click.aliexpress.com/e/_DCLBg9b
// - Nextion Display Enhanced 3.5" 320x480: https://s.click.aliexpress.com/e/_DCoXlEl
// - Arduino Leonardo: https://s.click.aliexpress.com/e/_DBeR0RF
//
// Similar Videos Using Nextion Displays:
// - Nextion Keyboard: https://youtu.be/ATPutFn6jfk
// - Nextion for Motorbike: https://youtu.be/tQaJ0RHUIi0
// - Nextion and Micro:bit: https://youtu.be/NpZMQjdKxBI


#include <Keyboard.h> // include Keyboard library to simulate key press
int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps, this one is for USB communication (with PC)
  Serial1.begin(9600); // opens serial port, sets data rate to 9600 bps, this one if for TX/RX pins, for Nextion display
  Keyboard.begin(); //  starts emulating a keyboard connected to a computer.
}

void loop() {
  if (Serial1.available() > 0) { // if some data was received from the Nextion Display
    incomingByte = Serial1.read(); // read the incoming byte (this will also delete the byte from the serial buffer)

    // Optionally, print the data to the serial monitor
    //Serial.print("I received: ");
    //Serial.println((char)incomingByte);
    Keyboard.write(incomingByte); // send the received ascii character as a keypress - i.e., simulate pressing the key on the keyboard
  }
}
