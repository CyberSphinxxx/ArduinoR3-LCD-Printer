#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define custom characters for a simple anime-style face
byte eyes[] = {
  B00000,
  B01010,
  B10101,
  B01010,
  B00000,
  B00000,
  B00000,
  B00000
};

byte mouth[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01110,
  B00000,
  B00000
};

void setup() {
  lcd.init();
  lcd.backlight();

  // Create custom characters
  lcd.createChar(0, eyes);
  lcd.createChar(1, mouth);

  // Display anime-themed text
  lcd.setCursor(0, 0);
  lcd.print("Kon'nichiwa!"); // Japanese for "Hello!"

  // Display anime face on the second row
  lcd.setCursor(4, 1);
  lcd.write(byte(0)); // Eyes
  lcd.print("^_^");
  lcd.write(byte(1)); // Mouth
}

void loop() {
  // You can add animations or scrolling text here later!
}
