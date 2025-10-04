#ifdef BUILD_INCLUDE_MAIN_FONT_TESTS

void cycle_font_demos()
{
  tft.setRotation(1);
  loop_all_free_fonts_demo(); 
  loop_free_font_demo();
  loop_custom_fonts();
  loop_fast_fonts();
  loop_smooth_font_demo_1();
  loop_smooth_font_demo_2();
  loop_smooth_font_demo_3();
  loop_smooth_font_demo_4();

  tft.setRotation(0);
  unicode_font_test();
  tft.setRotation(1);
}

void loop_smooth_font_demo_1() {

  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set the font colour AND the background colour
                                          // so the anti-aliasing works

  tft.setCursor(0, 0); // Set cursor at top left of screen


  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Small font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  Serial.println("Loading font");

  tft.loadFont(AA_FONT_SMALL);    // Must load the font first

  tft.println("Small 15pt font (demo_1)"); // println moves cursor down for a new line

  tft.println(); // New line

  tft.print("ABC"); // print leaves cursor at end of line

  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.println("1234"); // Added to line after ABC

  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  // print stream formatting can be used,see:
  // https://www.arduino.cc/en/Serial/Print
  int ivalue = 1234;
  tft.println(ivalue);       // print as an ASCII-encoded decimal
  tft.println(ivalue, DEC);  // print as an ASCII-encoded decimal
  tft.println(ivalue, HEX);  // print as an ASCII-encoded hexadecimal
  tft.println(ivalue, OCT);  // print as an ASCII-encoded octal
  tft.println(ivalue, BIN);  // print as an ASCII-encoded binary

  tft.println(); // New line
  tft.setTextColor(TFT_MAGENTA, TFT_BLACK);
  float fvalue = 1.23456;
  tft.println(fvalue, 0);  // no decimal places
  tft.println(fvalue, 1);  // 1 decimal place
  tft.println(fvalue, 2);  // 2 decimal places
  tft.println(fvalue, 5);  // 5 decimal places

  delay(2000);

  // Get ready for the next demo while we have this font loaded
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.println("Wrong and right ways to");
  tft.println("print changing values...");

  tft.unloadFont(); // Remove the font to recover memory used


  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  tft.loadFont(AA_FONT_LARGE); // Load another different font

  //tft.fillScreen(TFT_BLACK);
  
  // Draw changing numbers - does not work unless a filled rectangle is drawn over the old text
  for (int i = 0; i <= 99; i++)
  {
    tft.setCursor(50, 50);
    tft.setTextColor(TFT_GREEN, TFT_BLACK); // TFT_BLACK is used for anti-aliasing only
                                            // By default background fill is off
    tft.print("      "); // Overprinting old number with spaces DOES NOT WORK!
    tft.setCursor(50, 50);
    tft.print(i / 10.0, 1);

    // Adding a parameter "true" to the setTextColor() function fills character background
    // This extra parameter is only for smooth fonts!
    tft.setTextColor(TFT_GREEN, TFT_BLACK, true);
    tft.setCursor(50, 90);
    tft.print(i / 10.0, 1);
    
    delay (50);
  }

  delay(2000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font text wrapping
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  tft.fillScreen(TFT_BLACK);
  
  tft.setTextColor(TFT_YELLOW, TFT_BLACK); // Change the font colour and the background colour

  tft.setCursor(0, 0); // Set cursor at top left of screen

  tft.println("Large font!");

  tft.setTextWrap(true); // Wrap on width
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.println("Long lines wrap to the next line");

  tft.setTextWrap(false, false); // Wrap on width and height switched off
  tft.setTextColor(TFT_MAGENTA, TFT_BLACK);
  tft.println("Unless text wrap is switched off");

  tft.unloadFont(); // Remove the font to recover memory used

  delay(2000);
}

void loop_smooth_font_demo_2() {

  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set the font colour and the background colour

  tft.setTextDatum(TC_DATUM); // Top Centre datum

  int xpos = tft.width() / 2; // Half the screen width
  int ypos = 10;


  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Small font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  tft.loadFont(AA_FONT_SMALL); // Must load the font first

  tft.drawString("Small 15pt font (demo_2)", xpos, ypos);

  ypos += tft.fontHeight();   // Get the font height and move ypos down

  tft.setTextColor(TFT_GREEN, TFT_BLACK);

  // If the string does not fit the screen width, then the next character will wrap to a new line
  tft.drawString("Ode To A Small Lump Of Green Putty I Found In My Armpit One Midsummer Morning", xpos, ypos);

  tft.setTextColor(TFT_GREEN, TFT_BLUE); // Background colour does not match the screen background!
  tft.drawString("Anti-aliasing causes odd looking shadow effects if the text and screen background colours are not the same!", xpos, ypos + 60);

  tft.unloadFont(); // Remove the font to recover memory used

  delay(2000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  tft.loadFont(AA_FONT_LARGE); // Load another different font

  tft.fillScreen(TFT_BLACK);

  // The "true" parameter forces background drawing for smooth fonts
  tft.setTextColor(TFT_GREEN, TFT_BLUE, true); // Change the font colour and the background colour

  tft.drawString("36pt font", xpos, ypos);

  ypos += tft.fontHeight();  // Get the font height and move ypos down

  // Set text padding to 100 pixels wide area to over-write old values on screen
  tft.setTextPadding(100);

  // Draw changing numbers - likely to flicker using this plot method!
  for (int i = 0; i <= 99; i++) {
    tft.drawFloat(i / 10.0, 1, xpos, ypos);
    delay (50);
  }

  // Turn off text padding by setting value to 0
  tft.setTextPadding(0);

  tft.unloadFont(); // Remove the font to recover memory used

  delay(2000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Setting the 12 datum positions works with free fonts
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Integer numbers, floats and strings can be drawn relative to a x,y datum, e.g.:
  // tft.drawNumber( 123, x, y);
  // tft.drawFloat( 1.23, dp, x, y); // Where dp is number of decimal places to show
  // tft.drawString( "Abc", x, y);

  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_DARKGREY, TFT_BLACK, false);

  // Use middle of screen as datum
  xpos = tft.width() /2;
  ypos = tft.height()/2;

  tft.loadFont(AA_FONT_SMALL);
  tft.setTextDatum(TL_DATUM);
  tft.drawString("[Top left]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(TC_DATUM);
  tft.drawString("[Top centre]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(TR_DATUM);
  tft.drawString("[Top right]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(ML_DATUM);
  tft.drawString("[Middle left]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("[Middle centre]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(MR_DATUM);
  tft.drawString("[Middle right]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(BL_DATUM);
  tft.drawString("[Bottom left]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(BC_DATUM);
  tft.drawString("[Bottom centre]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(BR_DATUM);
  tft.drawString("[Bottom right]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(L_BASELINE);
  tft.drawString("[Left baseline]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(C_BASELINE);
  tft.drawString("[Centre baseline]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(R_BASELINE);
  tft.drawString("[Right baseline]", xpos, ypos);
  drawDatumMarker(xpos, ypos);
  delay(500);

  tft.unloadFont(); // Remove the font to recover memory used

  delay(2000);
}

void loop_smooth_font_demo_3() {

  tft.fillScreen(TFT_DARKGREY);

  int xpos = tft.width() / 2; // Half the screen width
  int ypos = 50;


  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Small font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  spr.loadFont(AA_FONT_SMALL); // Must load the font first into the sprite class

  spr.createSprite(100, 50);   // Create a sprite 100 pixels wide and 50 high

  spr.fillSprite(TFT_BLUE);

  spr.drawRect(0, 0, 100, 50, TFT_WHITE); // Draw sprite border outline (so we see extent)

  spr.setTextColor(TFT_YELLOW, TFT_DARKGREY); // Set the sprite font colour and the background colour

  spr.setTextDatum(MC_DATUM); // Middle Centre datum
  
  spr.drawString("15pt font (d_3)", 50, 25 ); // Coords of middle of 100 x 50 Sprite

  spr.pushSprite(10, 10); // Push to TFT screen coord 10, 10

  spr.pushSprite(10, 70, TFT_BLUE); // Push to TFT screen, TFT_BLUE is transparent
 
  spr.unloadFont(); // Remove the font from sprite class to recover memory used

  delay(4000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  tft.fillScreen(TFT_BLACK);

  // Beware: Sprites are a differerent "class" to TFT, so different fonts can be loaded
  // in the tft and sprite instances, so load the font in the class instance you use!
  // In this example this means the spr. instance.

  spr.loadFont(AA_FONT_LARGE); // Load another different font into the sprite instance

  // 100 x 50 sprite was created above and still exists...

  spr.fillSprite(TFT_GREEN);

  spr.setTextColor(TFT_BLACK, TFT_GREEN); // Set the font colour and the background colour

  spr.setTextDatum(MC_DATUM); // Middle Centre datum

  spr.drawString("Fits", 50, 25); // Make sure text fits in the Sprite!
  spr.pushSprite(10, 10);         // Push to TFT screen coord 10, 10

  spr.fillSprite(TFT_RED);
  spr.setTextColor(TFT_WHITE, TFT_RED); // Set the font colour and the background colour

//  spr.drawString("Too big", 50, 25); // Text is too big to all fit in the Sprite!
//  spr.pushSprite(10, 70);            // Push to TFT screen coord 10, 70

  // Draw changing numbers - no flicker using this plot method!

  // >>>> Note: it is best to use drawNumber() and drawFloat() for numeric values <<<<
  // >>>> this reduces digit position movement when the value changes             <<<<
  // >>>> drawNumber() and drawFloat() functions behave like drawString() and are <<<<
  // >>>> supported by setTextDatum() and setTextPadding()                        <<<<

  spr.setTextDatum(TC_DATUM); // Top Centre datum

  spr.setTextColor(TFT_WHITE, TFT_BLUE); // Set the font colour and the background colour

  for (int i = 0; i <= 200; i++) {
    spr.fillSprite(TFT_BLUE);
    spr.drawFloat(i / 100.0, 2, 50, 10); // draw with 2 decimal places at 50,10 in sprite
    spr.pushSprite(10, 70); // Push to TFT screen coord 10, 130
    delay (20);
  }

  spr.unloadFont(); // Remove the font to recover memory used

  spr.deleteSprite(); // Recover memory
  
  delay(1000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Mono spaced font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  
  spr.loadFont(AA_FONT_MONO); // Mono spaced fonts have fixed inter-character gaps to
                              // aid formatting
  int bnum = 1;

  // Example of drawing buttons
  for (int j = 0; j < 4; j++)
  {
    for (int k = 0; k < 4; k++)
    {
      int x = 80 + k * 45;
      int y = 20  + j * 30;
      button(x, y, bnum++);
    }
  }

  for (int i = 0; i < 100; i++)
  {
    button(10, 10, i);
    delay(50);
  }
  
  spr.unloadFont();

  delay(2000);
}

// #########################################################################
// Draw a number in a rounded rectangle with some transparent pixels
// Load the font before calling
// #########################################################################
void button(int x, int y, int num )
{

  // Size of sprite
  #define IWIDTH  40
  #define IHEIGHT 25

  // Create a 16 bit sprite 40 pixels wide, 25 high (2000 bytes of RAM needed)
  spr.setColorDepth(16);
  spr.createSprite(IWIDTH, IHEIGHT);

  // Fill it with black (this will be the transparent colour this time)
  spr.fillSprite(TFT_BLACK);

  // Draw a background for the numbers
  spr.fillRoundRect(  0, 0,  IWIDTH, IHEIGHT, 8, TFT_RED);
  spr.drawRoundRect(  0, 0,  IWIDTH, IHEIGHT, 8, TFT_WHITE);

  // Set the font parameters

  // Set text coordinate datum to middle centre
  spr.setTextDatum(MC_DATUM);

  // Set the font colour and the background colour
  spr.setTextColor(TFT_WHITE, TFT_RED);

  // Draw the number
  spr.drawNumber(num, IWIDTH/2, 1 + IHEIGHT/2);

  // Push sprite to TFT screen CGRAM at coordinate x,y (top left corner)
  // All black pixels will not be drawn hence will show as "transparent"
  spr.pushSprite(x, y, TFT_BLACK);

  // Delete sprite to free up the RAM
  spr.deleteSprite();
}

void loop_smooth_font_demo_4() {
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set the font colour and the background colour

  tft.setTextDatum(TC_DATUM); // Top Centre datum

  int xpos = tft.width() / 2; // Half the screen width
  int ypos = 50;


  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Small font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  spr.loadFont(AA_FONT_SMALL); // Must load the font first into the sprite class
  
  spr.setTextColor(TFT_YELLOW, TFT_BLACK); // Set the sprite font colour and the background colour

  tft.setCursor(xpos - 80, ypos);          // Set the tft cursor position, yes tft position!
  spr.printToSprite("Small 15pt font (demo_4)");    // Prints to tft cursor position, tft cursor NOT moved

  ypos += spr.fontHeight();   // Get the font height and move ypos down

  spr.unloadFont(); // Remove the font from sprite class to recover memory used

  delay(4000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  tft.fillScreen(TFT_BLACK);

  spr.loadFont(AA_FONT_LARGE); // Load another different font

  spr.setTextColor(TFT_WHITE, TFT_BLUE); // Set the font colour and the background colour

  tft.setCursor(xpos - 90, ypos);  // Set the tft cursor position
  spr.printToSprite("36pt font");  // Text is rendered via a minimally sized sprite

  ypos += spr.fontHeight();  // Get the font height and move ypos down

  // Draw changing numbers - no flicker using this plot method!
  for (int i = 0; i <= 200; i++) {
    tft.setCursor(10, 10);
    // Number is converted to String type by (String) (number)
    spr.printToSprite(" " + (String) (i / 100.0) + " "); // Space padding helps over-write old numbers
    delay (20);
  }

  spr.unloadFont(); // Remove the font to recover memory used

  delay(2000);
}

void unicode_font_test()
{
  tft.setTextColor(fg, bg);

  //----------------------------------------------------------------------------
  // Anti-aliased font test

  String test1 = "Hello World";

  // Load a smooth font from SPIFFS
  tft.loadFont(Final_Frontier_28);

  tft.setRotation(0);

  // Show all characters on screen with 2 second (2000ms) delay between screens
  tft.showFont(2000); // Note: This function moves the cursor position!

  tft.fillScreen(bg);
  tft.setCursor(0,0);

  tft.println(test1);

  // Remove font parameters from memory to recover RAM
  tft.unloadFont();

  delay(2000);

  //----------------------------------------------------------------------------
  // We can have any random mix of characters in the font

  String test2 = "仝倀"; // Unicodes 0x4EDD, 0x5000

  tft.loadFont(Unicode_Test_72);

  tft.setRotation(1);

  // Show all characters on screen with 2 second (2000ms) delay between screens
  tft.showFont(2000); // Note: This function moves the cursor position!

  tft.fillScreen(bg);
  tft.setCursor(0,0);

  tft.setTextColor(TFT_CYAN, bg);
  tft.println(test2);

  tft.setTextColor(TFT_YELLOW, bg);
  tft.println("12:00pm");

  tft.setTextColor(TFT_MAGENTA, bg);
  tft.println("1000Ω");

  // Remove font parameters from memory to recover RAM
  tft.unloadFont();

  delay(2000);

  //----------------------------------------------------------------------------
  // Latin and Hiragana font mix

  String test3 = "こんにちは";
    
  tft.loadFont(Latin_Hiragana_24);

  tft.setRotation(0);
  
  // Show all characters on screen with 2 second (2000ms) delay between screens
  tft.showFont(2000); // Note: This function moves the cursor position!

  tft.fillScreen(bg);
  tft.setTextColor(TFT_GREEN, bg);
  tft.setCursor(0,0);

  tft.println("Konnichiwa");
  tft.println(test3);
  tft.println();
  tft.println("Sayonara");
  tft.println("さようなら"); // Sayonara

  // Remove font parameters from memory to recover RAM
  tft.unloadFont();

  delay(2000);
  //
  //----------------------------------------------------------------------------
}


void loop_fast_fonts() 
{
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  int ypos = 105;
  int xposNum = 5;
  int yposNum = 5;
  drawTime = millis();

  for (int i = 0; i < 1000; i++) {
    yield();tft.drawNumber(i, xposNum, yposNum, 1);
  }

  drawTime = millis() - drawTime;

  tft.setTextColor(TFT_RED, TFT_BLACK);
  int xpos = 20;
  xpos += tft.drawFloat(drawTime / 2890.0, 3, xpos, ypos, 4);
  tft.drawString(" ms per char", xpos, ypos, 4);
  if (drawTime < 100) tft.drawString("Font 1 not loaded!", 50, 210, 4);
  
  delay(4000);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
    drawTime = millis();

  for (int i = 0; i < 1000; i++) {
    yield();tft.drawNumber(i, xposNum, yposNum, 2);
  }

  drawTime = millis() - drawTime;

  tft.setTextColor(TFT_RED, TFT_BLACK);
  xpos = 20;
  xpos += tft.drawFloat(drawTime / 2890.0, 3, xpos, ypos, 4);
  tft.drawString(" ms per char", xpos, ypos, 4);
  if (drawTime < 200) tft.drawString("Font 2 not loaded!", 50, 210, 4);
  
  delay(4000);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
    drawTime = millis();

  for (int i = 0; i < 1000; i++) {
    yield();tft.drawNumber(i, xposNum, yposNum, 4);
  }

  drawTime = millis() - drawTime;

  tft.setTextColor(TFT_RED, TFT_BLACK);
  xpos = 20;
  xpos += tft.drawFloat(drawTime / 2890.0, 3, xpos, ypos, 4);
  tft.drawString(" ms per char", xpos, ypos, 4);
  if (drawTime < 200) tft.drawString("Font 4 not loaded!", 50, 210, 4);
  
  delay(4000);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
    drawTime = millis();

  for (int i = 0; i < 1000; i++) {
    yield();tft.drawNumber(i, xposNum, yposNum, 6);
  }

  drawTime = millis() - drawTime;

  tft.setTextColor(TFT_RED, TFT_BLACK);
  xpos = 20;
  xpos += tft.drawFloat(drawTime / 2890.0, 3, xpos, ypos, 4);
  tft.drawString(" ms per char", xpos, ypos, 4);
  if (drawTime < 200) tft.drawString("Font 6 not loaded!", 50, 210, 4);
  
  delay(4000);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
    drawTime = millis();

  for (int i = 0; i < 1000; i++) {
    yield();tft.drawNumber(i, xposNum, yposNum, 7);
  }

  drawTime = millis() - drawTime;

  tft.setTextColor(TFT_RED, TFT_BLACK);
  xpos = 20;
  xpos += tft.drawFloat(drawTime / 2890.0, 3, xpos, ypos, 4);
  tft.drawString(" ms per char", xpos, ypos, 4);
  if (drawTime < 200) tft.drawString("Font 7 not loaded!", 50, 210, 4);
  
  delay(4000);
  tft.fillScreen(TFT_YELLOW);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
    drawTime = millis();

  for (int i = 0; i < 1000; i++) {
    yield();tft.drawNumber(i, xposNum, yposNum, 8);
  }

  drawTime = millis() - drawTime;

  tft.setTextColor(TFT_RED, TFT_BLACK);
  xpos = 20;
  xpos += tft.drawFloat(drawTime / 2890.0, 3, xpos, ypos, 4);
  tft.drawString(" ms per char", xpos, ypos, 4);
  if (drawTime < 200) tft.drawString("Font 8 not loaded!", 50, 210, 4);
  
  delay(4000);
}

void loop_custom_fonts() 
{

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Show custom fonts
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Where font sizes increase the screen is not cleared as the larger fonts overwrite
  // the smaller one with the background colour.

  // We can set the text datum to be Top, Middle, Bottom vertically and Left, Centre
  // and Right horizontally. These are the text datums that can be used:
  // TL_DATUM = Top left (default)
  // TC_DATUM = Top centre
  // TR_DATUM = Top right
  // ML_DATUM = Middle left
  // MC_DATUM = Middle centre <<< This is used below
  // MR_DATUM = Middle right
  // BL_DATUM = Bottom left
  // BC_DATUM = Bottom centre
  // BR_DATUM = Bottom right
  // L_BASELINE = Left character baseline (Line the 'A' character would sit on)
  // C_BASELINE = Centre character baseline
  // R_BASELINE = Right character baseline

  //Serial.println();

  // Set text datum to middle centre (MC_DATUM)
  tft.setTextDatum(MC_DATUM);

  // Set text colour to white with black background
  // Unlike the stock Adafruit_GFX library, the TFT_eSPI library DOES draw the background
  // for the custom and Free Fonts
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.fillScreen(TFT_MAGENTA);            // Clear screen
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString("Yellowtail 32", TFT_HEIGHT/2,10, GFXFF);// Print the string name of the font
  tft.setFreeFont(CF_Y32);                 // Select the font
  tft.drawString(TEXT, TFT_HEIGHT/2,80, GFXFF);// Print the string name of the font
  delay(2000);

  tft.fillScreen(TFT_BLUE);            // Clear screen
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString("Satisfy 24", TFT_HEIGHT/2,10, GFXFF);// Print the string name of the font
  tft.setFreeFont(CF_S24);                 // Select the font
  tft.drawString(TEXT, TFT_HEIGHT/2,80, GFXFF);// Print the test text in the custom font
  delay(2000);

  tft.fillScreen(TFT_RED);            // Clear screen
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString("Roboto 24", TFT_HEIGHT/2,10, GFXFF);// Print the string name of the font
  tft.setFreeFont(CF_RT24);                 // Select the font
  tft.drawString(TEXT, TFT_HEIGHT/2,80, GFXFF);// Print the test text in the custom font
  delay(2000);

  tft.fillScreen(TFT_DARKGREY);            // Clear screen
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString("Orbitron 24", TFT_HEIGHT/2,10, GFXFF);// Print the string name of the font
  tft.setFreeFont(CF_OL24);                 // Select the font
  tft.drawString(TEXT, TFT_HEIGHT/2,80, GFXFF);// Print the test text in the custom font
  delay(2000);
  
  // Here we do not clear the screen and rely on the new text over-writing the old
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString("Orbitron 32", TFT_HEIGHT/2,10, GFXFF);// Print the string name of the font
  tft.setFreeFont(CF_OL32);                 // Select the font
  tft.drawString(TEXT, TFT_HEIGHT/2,80, GFXFF);// Print the test text in the custom font
  delay(2000);

  // Here we use text background padding to over-write the old text
  tft.fillScreen(TFT_YELLOW);            // Clear screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  // Here we use text background padding to over-write the old text
  tft.setTextPadding(tft.width() - 20); // Blanked area will be width of screen minus 20 pixels
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString("Orbitron 32 with padding", TFT_HEIGHT/2,10, GFXFF);// Print the string name of the font
  tft.setFreeFont(CF_OL32);                 // Select the font
  tft.drawString(TEXT, TFT_HEIGHT/2,80, GFXFF);// Print the test text in the custom font
  delay(2000);

  // Here we use text background padding to over-write the old text
  tft.fillScreen(TFT_YELLOW);            // Clear screen
  tft.setTextColor(TFT_BLUE, TFT_YELLOW);
  tft.setTextPadding(tft.width() - 20); // Blanked area will be width of screen minus 20 pixels
  tft.setFreeFont(FF18);                 // Select the font
  tft.drawString("Orbitron 32 with padding", TFT_HEIGHT/2,10, GFXFF);// Print the string name of the font
  // Use 80 pixel wide padding so old numbers over-write old ones
  // One of the problrms with proportionally spaced numbers is that they jiggle position
  tft.setTextPadding(80);
  tft.setTextDatum(MC_DATUM);
  tft.setFreeFont(CF_OL32);
  for( int i = 100; i > 0; i--)
  {
    tft.drawNumber( i, TFT_HEIGHT/2,80);
    delay(250);
  }

  // Reset text padding to zero (default)
  tft.setTextPadding(0);
}

void loop_all_free_fonts_demo() {

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


void loop_free_font_demo() {

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

#endif