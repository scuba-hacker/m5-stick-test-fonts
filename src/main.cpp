#define TEXT "aA MWyz~12" // Text that will be printed on screen in any font

#include "Free_Fonts.h"

#include <M5StickCPlus.h>

#include <TFT_eSPI.h>

void header(const char *string, uint16_t color);
void drawDatumMarker(int x, int y);

TFT_eSPI& tft=M5.Lcd;

void setup()
{
  tft.begin();
  tft.setRotation(1);
}

//  -D TFT_WIDTH=135
//  -D TFT_HEIGHT=240

void loop2() {

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Show all 48 fonts in centre of screen ( x,y coordinate 160,120)
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Where font sizes increase the screen is not cleared as the larger fonts overwrite
  // the smaller one with the background colour.

  // Set text datum to middle centre
  tft.setTextDatum(MC_DATUM);

  // Set text colour to orange with black background
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  
  tft.fillScreen(TFT_BLACK);            // Clear screen
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF1, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF1);                 // Select the font
  tft.drawString(TEXT, 100, 90, GFXFF);// Print the string name of the font
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF2, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF2);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF3, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF3);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF4, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF4);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF5, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF5);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF6, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF6);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF7, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF7);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF8, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF8);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF9, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF9);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF10, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF10);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF11, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF11);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF12, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF12);
    tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF13, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF13);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF14, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF14);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF15, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF15);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF16, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF16);
    tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF17, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF17);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF18, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF18);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF19, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF19);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF20, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF20);
    tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF21, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF21);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF22, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF22);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF23, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF23);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF24, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF24);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF25, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF25);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF26, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF26);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF27, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF27);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF28, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF28);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF29, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF29);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF30, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF30);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF31, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF31);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF32, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF32);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF33, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF33);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF34, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF34);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF35, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF35);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF36, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF36);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF37, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF37);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF38, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF38);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF39, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF39);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF40, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF40);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF41, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF41);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF42, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF42);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF43, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF43);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF44, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF44);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF45, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF45);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF46, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF46);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF47, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF47);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString(sFF48, 110, 10, GFXFF);// Print the string name of the font
  tft.setFreeFont(FF48);
  tft.drawString(TEXT, 100, 90, GFXFF);
  delay(1000);

}


void loop() {

  int xpos =  0;
  int ypos = 40;

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Select different fonts to draw on screen using the print class
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  header("Using print() method", TFT_NAVY);

  // For comaptibility with Adafruit_GFX library the text background is not plotted when using the print class
  // even if we specify it.
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

  tft.setFreeFont(TT1);     // Select the orginal small TomThumb font
  tft.println();             // Move cursor down a line
  tft.print("The really tiny TomThumb font");    // Print the font name onto the TFT screen

  tft.setFreeFont(FSB9);   // Select Free Serif 9 point font, could use:
  // tft.setFreeFont(&FreeSerif9pt7b);
  tft.println();          // Free fonts plot with the baseline (imaginary line the letter A would sit on)
  // as the datum, so we must move the cursor down a line from the 0,0 position
  tft.print("Serif Bold 9pt");  // Print the font name onto the TFT screen

  tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
  tft.println();                // Move cursor down a line
  tft.print("Serif Bold 12pt"); // Print the font name onto the TFT screen

  tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
  tft.println();                // Move cursor down a line
  tft.print("Serif Bold 18pt"); // Print the font name onto the TFT screen

  tft.setFreeFont(FSB24);       // Select Free Serif 24 point font
  tft.println();                // Move cursor down a line
  tft.print("Serif Bold 24pt"); // Print the font name onto the TFT screen

  delay(1000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Now use drawString() so we can set font background colours and the datum
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  header("Using drawString()", TFT_BLACK);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.setTextDatum(TC_DATUM); // Centre text on x,y position

  xpos = tft.width() / 2; // Half the screen width
  ypos = 50;

//  tft.setFreeFont(FSB9);                              // Select the font
//  tft.drawString("Serif Bold 9pt", xpos, ypos, GFXFF);  // Draw the text string in the selected GFX free font
//  ypos += tft.fontHeight(GFXFF);                      // Get the font height and move ypos down

//  tft.setFreeFont(FSB12);
//  tft.drawString("Serif Bold 12pt", xpos, ypos, GFXFF);
//  ypos += tft.fontHeight(GFXFF);

  tft.setFreeFont(FSB18);
  tft.drawString("Serif Bold 18pt", xpos, ypos, GFXFF);
  ypos += tft.fontHeight(GFXFF);

  tft.setFreeFont(FSB24);
  tft.drawString("Serif Bold 24pt", xpos, ypos, GFXFF);
  ypos += tft.fontHeight(GFXFF);

  // Set text padding to 100 pixels wide area to over-write old values on screen
  tft.setTextPadding(100);
  for (int i = 0; i <= 20; i++) {
    tft.drawFloat(i / 10.0, 1, xpos, ypos, GFXFF);
    delay (200);
  }

  delay(1000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Same again but with colours that show bounding boxes
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


  header("With background", TFT_DARKGREY);

  tft.setTextColor(TFT_YELLOW, TFT_BLACK);

  tft.setTextDatum(TC_DATUM); // Centre text on x,y position

  xpos = tft.width() / 2; // Half the screen width
  ypos = 50;

  // tft.setFreeFont(FSB9);                              // Select the font
  // tft.drawString("Serif Bold 9pt", xpos, ypos, GFXFF);  // Draw the text string in the selected GFX free font
  // ypos += tft.fontHeight(GFXFF);                        // Get the font height and move ypos down

  // tft.setFreeFont(FSB12);
  // tft.drawString("Serif Bold 12pt", xpos, ypos, GFXFF);
  // ypos += tft.fontHeight(GFXFF);

  tft.setFreeFont(FSB18);
  tft.drawString("Serif Bold 18pt", xpos, ypos, GFXFF);
  ypos += tft.fontHeight(GFXFF);

  tft.setFreeFont(FSBI24);
  tft.drawString("Bold Italic 24pt", xpos, ypos, GFXFF);
  ypos += tft.fontHeight(GFXFF);

  // Set text padding to 100 pixels wide area to over-write old values on screen
  tft.setTextPadding(100);
  for (int i = 0; i <= 20; i++) {
    tft.drawFloat(i / 10.0, 1, xpos, ypos, GFXFF);
    delay (200);
  }

  delay(1000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Now show setting the 12 datum positions works with free fonts
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Numbers, floats and strings can be drawn relative to a datum
  header("Text with a datum", TFT_BLACK);
  tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
  tft.setFreeFont(FSS12);
  tft.setTextDatum(TL_DATUM);
  tft.drawString("[Top left]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(TC_DATUM);
  tft.drawString("[Top centre]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(TR_DATUM);
  tft.drawString("[Top right]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(ML_DATUM);
  tft.drawString("[Middle left]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("[Middle centre]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(MR_DATUM);
  tft.drawString("[Middle right]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(BL_DATUM);
  tft.drawString("[Bottom left]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(BC_DATUM);
  tft.drawString("[Bottom centre]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(BR_DATUM);
  tft.drawString("[Bottom right]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(L_BASELINE);
  tft.drawString("[Left baseline]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(C_BASELINE);
  tft.drawString("[Centre baseline]", 100, 90, GFXFF);
  drawDatumMarker(TFT_HEIGHT/2,TFT_WIDTH/2);
  delay(1000);

  tft.fillRect(0, 80, TFT_HEIGHT, 80, TFT_BLACK);
  tft.setTextDatum(R_BASELINE);
  tft.drawString("[Right baseline]", 100, 90, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  //while(1);
  delay(4000);

}

// Print the header for a display screen
void header(const char *string, uint16_t color)
{
  tft.fillScreen(color);
  tft.setTextSize(1);
  tft.setTextColor(TFT_MAGENTA, TFT_BLUE);
  tft.fillRect(0, 0, TFT_HEIGHT, 30, TFT_BLUE);
  tft.setTextDatum(TC_DATUM);
  tft.drawString(string, TFT_HEIGHT / 2, 2, 4); // Font 4 for fast drawing with background
}

// Draw a + mark centred on x,y
void drawDatumMarker(int x, int y)
{
  tft.drawLine(x - 5, y, x + 5, y, TFT_GREEN);
  tft.drawLine(x, y - 5, x, y + 5, TFT_GREEN);
}


// There follows a crude way of flagging that this example sketch needs fonts which
// have not been enbabled in the User_Setup.h file inside the TFT_HX8357 library.
//
// These lines produce errors during compile time if settings in User_Setup are not correct
//
// The error will be "does not name a type" but ignore this and read the text between ''
// it will indicate which font or feature needs to be enabled
//
// Either delete all the following lines if you do not want warnings, or change the lines
// to suit your sketch modifications.

#ifndef LOAD_GLCD
//ERROR_Please_enable_LOAD_GLCD_in_User_Setup
#endif

#ifndef LOAD_FONT2
//ERROR_Please_enable_LOAD_FONT2_in_User_Setup!
#endif

#ifndef LOAD_FONT4
//ERROR_Please_enable_LOAD_FONT4_in_User_Setup!
#endif

#ifndef LOAD_FONT6
//ERROR_Please_enable_LOAD_FONT6_in_User_Setup!
#endif

#ifndef LOAD_FONT7
//ERROR_Please_enable_LOAD_FONT7_in_User_Setup!
#endif

#ifndef LOAD_FONT8
//ERROR_Please_enable_LOAD_FONT8_in_User_Setup!
#endif

#ifndef LOAD_GFXFF
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif


// There follows a crude way of flagging that this example sketch needs fonts which
// have not been enbabled in the User_Setup.h file inside the TFT_HX8357 library.
//
// These lines produce errors during compile time if settings in User_Setup are not correct
//
// The error will be "does not name a type" but ignore this and read the text between ''
// it will indicate which font or feature needs to be enabled
//
// Either delete all the following lines if you do not want warnings, or change the lines
// to suit your sketch modifications.

#ifndef LOAD_GLCD
//ERROR_Please_enable_LOAD_GLCD_in_User_Setup
#endif

#ifndef LOAD_GFXFF
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif

