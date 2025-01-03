#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int position = 0;      // Start position
  int direction = 1;     // 1 = moving right, -1 = moving left

  while (true) {
    lcd.clear();
    lcd.setCursor(position, 0); // Ball on the first row
    lcd.print("o");            // Display the ball

    position += direction;     // Move the ball

    // Check for bounce
    if (position == 15 || position == 0) {
      direction = -direction; // Reverse direction
    }

    delay(150); // Adjust speed of the ball
  }
}
