#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimeLib.h>
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET); //Declaration for the size,setting,etc. of the OLED
unsigned long OldestMillis;
unsigned long NewMillis;
const int ButtonPin = 2;  // Pin connected to button
int ButtonState = 0;      // Variable to store button state
int ButtonPressed = 0;
int ChronoHour = 1;
int ChronoMinute = 2;
int ChronoSecond = 3;
int ChronoMillis = 999;
int Hours;
int Minutes;
int Seconds;
int Millis;

void displayChrono()
{
    display.clearDisplay();

    display.setTextColor(WHITE);

    String title = "STOPWATCH";

    int Hours = ChronoHour;
    int Minutes = ChronoMinute;
    int Seconds = ChronoSecond;
    int Millis = ChronoMillis;

    display.setTextSize(2);
    display.setCursor(0,0);
    display.print(title);

    display.setTextSize(4);
    display.setCursor(0,18);
    display.print(Hours,10);

    display.drawChar(52, 18, ':', WHITE, BLACK, 4);

    display.setTextSize(4);
    display.setCursor(78,18);
    display.print(Minutes,10);

    display.setTextSize(2);
    display.setCursor(52,50);
    display.print(Seconds,10);

    display.display();
}

void displayTime()
{
    display.clearDisplay();

    display.setTextColor(WHITE);

    String title = "TIME";

    int Hours = hour();
    int Minutes = minute();
    int Seconds = second();

    display.setTextSize(2);
    display.setCursor(0,0);
    display.print(title);

    display.setTextSize(4);
    display.setCursor(0,18);
    display.print(Hours,10);

    display.drawChar(52, 18, ':', WHITE, BLACK, 4);

    display.setTextSize(4);
    display.setCursor(78,18);
    display.print(Minutes,10);

    display.setTextSize(2);
    display.setCursor(52,50);
    display.print(Seconds,10);

    display.display();
}

void setup() 
{
    pinMode(ButtonPin, INPUT_PULLUP); 
    Serial.begin(9600); // Start serial communication at 9600 baud
    Serial.println("Debugging started...");
    setTime(16, 34, 0, 17, 8, 2026); // hour, min, sec, day, month, year
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
}

void loop() 
{
    ButtonState = digitalRead(ButtonPin);
    OldestMillis = millis();

    if (ButtonState == LOW)
    {
        ButtonPressed = 1;
    }

    // Serial.print("Current time: ");
    // Serial.print(h);
    // Serial.print(":");
    // Serial.print(m);
    // Serial.print(":");
    // Serial.println(s);
    displayChrono();
    Serial.println(NewMillis);
    delay(1000);
}

