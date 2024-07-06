#include <LiquidCrystal_I2C.h>
#include "fogml_classifier.h"

// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

float vector[4];

char* feature_names[] = {"sepal_length_(cm)", "sepal_width_(cm)", "petal_length_(cm)", "petal_width_(cm)"};

char* classes[] = {"setosa", "versicolor", "virginica"};

int detected_class;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           //  setup serial

	// initialize the LCD
	lcd.begin(20,4);

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("Hello, world!");
}

void print_vector() {
  for(int i=0; i<4; i++) {
    Serial.print(feature_names[i]);
    Serial.print(":");
    Serial.print(vector[i]);
    if (i<3) Serial.print(",");
  }
  Serial.println();  
}

void scale_features() {
  //'sepal length (cm)'
  vector[0] = vector[0]/1024 * 3.6;
  //'sepal width (cm)'
  vector[1] = vector[1]/1024 * 2.4;
  //'petal length (cm)'
  vector[2] = vector[2]/1024 * 5.9;
  //'petal width (cm)'
  vector[3] = vector[3]/1024 * 2.4;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Read sensor values
  vector[0] = analogRead(A0);
  vector[1] = analogRead(A1);
  vector[2] = analogRead(A2);
  vector[3] = analogRead(A3);

  //Preprocess raw data
  scale_features();

  //Print on serial output and visualise
  print_vector();

  //Classify IRIS
  detected_class = classifier(vector);

  //Display results
  lcd.setCursor(0,0);
  lcd.print("                    ");
  lcd.setCursor(0,0);
  lcd.print(classes[ detected_class ]);
}