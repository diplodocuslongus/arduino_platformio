#include "Arduino.h"
// TODO
// add ifdef and precompiler in the pio..ini
// iniini in 
/*

 Esplora TFT Temperature Display

 This example for the Arduino TFT screen is for use

 with an Arduino Esplora.

 This example reads the temperature of the Esplora's

 on board thermisistor and displays it on an attached

 LCD screen, updating every second.

 This example code is in the public domain.

 Created 15 April 2013 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/EsploraTFTTemp

 */

// include the necessary libraries
#include <Esplora.h>
#include <TFT.h>            // Arduino LCD library
#include <SPI.h>

char tempPrintout[3];  // array to hold the temperature data
bool led_on = false;

void setup() {

  // Put this line at the beginning of every sketch that uses the GLCD

  EsploraTFT.begin();

  // clear the screen with a black background

  EsploraTFT.background(0, 0, 0);

  // set the text color to magenta

  EsploraTFT.stroke(200, 20, 180);

  // set the text to size 2

  EsploraTFT.setTextSize(2);

  // start the text at the top left of the screen

  // this text is going to remain static

  EsploraTFT.text("Degrees in C :\n ", 0, 0);

  // set the text in the loop to size 5

  EsploraTFT.setTextSize(5);
}

void loop() {
  if (Esplora.readButton(SWITCH_2) == LOW) {
  // if (Esplora.readButton(SWITCH_DOWN) == LOW) {
    // If the button is pressed, play a tone with a frequency of 440 Hz (Note A4).
    Esplora.tone(440);
  } else {
    // If the button is not pressed, turn the tone off.
    Esplora.noTone();
  }
  int buttonState = Esplora.readButton(SWITCH_1);

  // The buttons on the Esplora are LOW when pressed.
  if (buttonState == LOW) {
    // If the button is pressed, turn on the red LED to full brightness (255).
    // The arguments are R, G, B values from 0 (off) to 255 (full brightness).
    led_on = not led_on;
  } 
  if (led_on){
    Esplora.writeRed(0);
    Esplora.writeGreen(0);
    Esplora.writeBlue(255);
    }
  else{
    Esplora.writeRed(0);
    Esplora.writeGreen(0);
    Esplora.writeBlue(0);
  }
  // read the temperature  in Celsius and store it in a String
  String temperature = String(Esplora.readTemperature(DEGREES_C));

  // convert the string to a char array
  temperature.toCharArray(tempPrintout, 3);
  // set the text color to white
  EsploraTFT.stroke(255, 255, 255);
  // print the temperature one line below the static text
  EsploraTFT.text(tempPrintout, 0, 30);
  delay(1000);
  // erase the text for the next loop
  EsploraTFT.stroke(0, 0, 0);
  EsploraTFT.text(tempPrintout, 0, 30);
}
