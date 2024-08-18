#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

# define distance_boundry 35

// KEYBOARD SETUP
char key_pressed;
String inputPassword;
String tollAmount = "207"; // Predefined toll amount

const byte number_of_rows = 4;
const byte number_of_columns = 4;

byte row_pins[number_of_rows] = {2, 3, 4, 5}; 
byte column_pins[number_of_columns] = {6, 7, 8, 9}; 

char key_array[number_of_rows][number_of_columns] = {  
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad k = Keypad(makeKeymap(key_array), row_pins, column_pins, number_of_rows, number_of_columns);

// ULTRASONIC SENSOR SETUP
int trigPin = 10; 
int echoPin = 11;
int led_pin=A5;
long duration;
int distance;

// SERVO MOTOR SETUP
Servo servoMotor;

// LCD DISPLAY SETUP
LiquidCrystal lcd_1(13, 12, A1, A2, A3, A4);

enum GateState { GATE_OFF, CAR_DETECTED, WAIT_FOR_CONFIRMATION, ENTER_TOLL, GATE_OPEN };
GateState currentState = GATE_OFF;

// Initial setup
void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    servoMotor.attach(A0); // Connect the servo motor to analog pin A0
  	pinMode(led_pin,OUTPUT);
  	digitalWrite(led_pin,LOW);
  
    lcd_1.begin(16, 2);
  	lcd_1.setCursor(0, 0);
  	lcd_1.print("ROBOWIZARDS TOLL");
    lcd_1.setCursor(0, 1);
    lcd_1.print("GATE:OFF");
  
    Serial.begin(9600);
    closeGate(); // Ensure gate starts closed
}

// To calculate the distance of incoming traffic.
int calculateDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    return distance;  
}

// closing and opening the gate.
void openGate() {
    servoMotor.write(90); // Open the gate
    Serial.println("Gate opened");
}

void closeGate() {
    servoMotor.write(0); // Close the gate
    Serial.println("Gate closed");
}

void inputTollFunction() {
    key_pressed = k.getKey();
    if (key_pressed) {
        lcd_1.setCursor(5 + inputPassword.length(), 1);
        lcd_1.print(key_pressed);
        inputPassword += key_pressed;
        
        if (key_pressed == 'C') {
            lcd_1.setCursor(0, 1);
            lcd_1.print("$               ");
            inputPassword = "";
        }

        if (inputPassword == tollAmount) {
            lcd_1.clear();
            lcd_1.print("Correct");
            delay(1000); // Added delay for feedback
            lcd_1.setCursor(0, 0);
            lcd_1.print("GATE:OPEN");
            openGate();
            currentState = GATE_OPEN;
        } else if (key_pressed == '#') {
            lcd_1.setCursor(0, 1);
            lcd_1.print("Incorrect Toll ");
            delay(1000);
            lcd_1.clear();
            lcd_1.setCursor(0, 0);
            lcd_1.print("Enter Toll:");
            lcd_1.setCursor(0, 1);
            lcd_1.print("$");
            inputPassword = "";
        }
    }
}

void gateInput() {
    key_pressed = k.getKey();
    if (key_pressed == 'A') {
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("Enter Toll:");
        lcd_1.setCursor(0, 1);
        lcd_1.print("Rs.");
        inputPassword = "";
        currentState = ENTER_TOLL;
    }
}

// Calculating the velocity of incoming traffic;
int calcVelocity()
{
  int velocity = 0;
  int distanceInit = calculateDistance();
  delay(500);
  int distanceFinal = calculateDistance();
  velocity = (distanceInit - distanceFinal)/ 0.2; // Change in distance over time taken (cm/s)
  return (velocity);
  
}

// Looping portion
void loop() {
    distance = calculateDistance();
  	int velocity = calcVelocity();
    // Serial.println("Distance: " + String(distance));
  	Serial.println("Velocity: " + String(velocity) + " cm/s");
    
  	int a = 0;
  	while (true
    switch (currentState) {
        case GATE_OFF:
            if (distance < distance_boundry) { // If a car is detected within 15 cm
                digitalWrite(led_pin,HIGH);
              	lcd_1.clear();
              	lcd_1.setCursor(0, 0);
                lcd_1.print("TOLL:$ " + tollAmount);
                lcd_1.setCursor(0, 1);
                lcd_1.print("Press A");
                currentState = WAIT_FOR_CONFIRMATION;
                Serial.println("Car detected, waiting for confirmation");
            }
            break;

        case WAIT_FOR_CONFIRMATION:
            gateInput();
            break;

        case ENTER_TOLL:
            inputTollFunction();
            break;

        case GATE_OPEN:
            if (distance >= distance_boundry) {
              	digitalWrite(led_pin,LOW);
                lcd_1.clear();
                lcd_1.setCursor(0, 0);
                lcd_1.print("ROBOWIZARDS");
              	lcd_1.setCursor(0, 1);
              	lcd_1.print("GATE:OFF");
                closeGate();
                currentState = GATE_OFF;
            }
      		else GATE_OPEN;
            break;
      	case 5:
      		lcd_1.clear();
      		lcd_1.setCursor(0, 0);
            lcd_1.print("ROBOWIZARDS");
            lcd_1.setCursor(0, 1);
            lcd_!.print("GATE:OFF")

        default:
          lcd_1.clear();
    }
}















distance = calculateDistance();
  	int velocity = calcVelocity();
     Serial.println("Distance: " + String(distance));
  	//Serial.println("Velocity: " + String(velocity) + " cm/s");
  switch (currentState) {
      case GATE_OFF:
      if (distance < distance_boundry) { // If a car is detected within 15 cm
        openGate();
        digitalWrite(led_pin,HIGH);
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("TOLL:$ " + tollAmount);
        lcd_1.setCursor(0, 1);
        lcd_1.print("Press A");
        currentState = WAIT_FOR_CONFIRMATION;
        Serial.println("Car detected, waiting for confirmation");
      }
      break;

      case WAIT_FOR_CONFIRMATION:
      gateInput();
      break;

      case ENTER_TOLL:
      inputTollFunction();
      break;

      case GATE_OPEN:
      if (distance >= distance_boundry) {
        digitalWrite(led_pin,LOW);
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("ROBOWIZARDS");
        lcd_1.setCursor(0, 1);
        lcd_1.print("GATE:OFF");
        // closeGate();
        currentState = GATE_OFF;
      }
      else GATE_OPEN;	  
      break;
    




    /* C++ LAB 3

WRITE A PROGRAM TO MANIPULATE COMPLEX NUMBERS USING OPERATOR OVERLOADING (ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION)*/

#include <iostream>
using namespace std;


class complex 
{
    int real;
    int imaginary;
    public:
        // Constructor Initialization.
        complex(int a = 0, int b = 0) : real(a), imaginary(b){}
        // Operator Overloading +
        complex operator + (complex m)
        {
            complex temp;
            temp.real = real + m.real;
            temp.imaginary = imaginary + m.imaginary;
            return temp;
        }
        complex operator - (complex n)
        {
            complex temp;
            temp.real = real - n.real;
            temp.imaginary = imaginary - n.imaginary;
            return temp;
        }
        void output()
        {
            cout << "The sum of two numbers is : " << real << " + " << " i" << imaginary << endl;
        }

};


int main()
{
    complex c1(30, 40), c2(40, 30);
    complex c3 = c1 + c2;
    complex c4 = c1 - c2;
    c3.output();
    c4.output();
}