// =====================================================
// Arduino Obstacle Avoiding Car
// Arduino Uno + Ultrasonic Sensor + Motor Driver
// =====================================================

// ---------------- MOTOR DRIVER PINS ----------------

// Left motor
#define ENA 5
#define IN1 6
#define IN2 7

// Right motor
#define ENB 10
#define IN3 8
#define IN4 9

// ---------------- ULTRASONIC SENSOR ----------------

#define TRIG_PIN 2
#define ECHO_PIN 3

// ---------------- SETTINGS ----------------

#define MOTOR_SPEED 180
#define OBSTACLE_DISTANCE 20

bool robotRunning = false;


// =====================================================
// SETUP
// =====================================================

void setup() {

  Serial.begin(9600);

  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Make sure motors are stopped
  stopCar();

  Serial.println("=================================");
  Serial.println(" Arduino Obstacle Avoiding Car");
  Serial.println("=================================");
  Serial.println("Type START to begin.");
  Serial.println("Type STOP to stop.");
}


// =====================================================
// MAIN LOOP
// =====================================================

void loop() {

  // Check Serial commands
  checkSerialCommand();

  // Do nothing until START is received
  if (!robotRunning) {
    stopCar();
    return;
  }

  // Measure distance
  long distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check obstacle
  if (distance <= OBSTACLE_DISTANCE) {

    Serial.println("Obstacle detected!");

    stopCar();
    delay(200);

    // Rotate until path becomes clear
    rotateUntilClear();

  } 
  else {

    // Path is clear
    moveForward();
  }

  delay(50);
}


// =====================================================
// SERIAL COMMAND FUNCTION
// =====================================================

void checkSerialCommand() {

  if (Serial.available() > 0) {

    String command = Serial.readStringUntil('\n');

    command.trim();
    command.toUpperCase();

    if (command == "START") {

      robotRunning = true;

      Serial.println();
      Serial.println("Robot STARTED");
      Serial.println();

    }

    else if (command == "STOP") {

      robotRunning = false;

      stopCar();

      Serial.println();
      Serial.println("Robot STOPPED");
      Serial.println();

    }

    else {

      Serial.println("Unknown command.");
      Serial.println("Use START or STOP.");
    }
  }
}


// =====================================================
// ULTRASONIC DISTANCE
// =====================================================

long getDistance() {

  // Clear trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // If no echo is received
  if (duration == 0) {
    return 400;
  }

  // Convert time to distance
  long distance = duration * 0.0343 / 2;

  return distance;
}


// =====================================================
// MOVE FORWARD
// =====================================================

void moveForward() {

  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);
}


// =====================================================
// STOP CAR
// =====================================================

void stopCar() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}


// =====================================================
// ROTATE LEFT
// =====================================================

void rotateLeft() {

  // Left motor backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);
}


// =====================================================
// ROTATE UNTIL PATH IS CLEAR
// =====================================================

void rotateUntilClear() {

  Serial.println("Rotating to find a clear path...");

  while (robotRunning) {

    // Rotate
    rotateLeft();

    delay(100);

    // Check distance
    long distance = getDistance();

    Serial.print("Checking: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Stop rotating when path is clear
    if (distance > OBSTACLE_DISTANCE) {

      stopCar();

      Serial.println("Clear path found!");

      delay(200);

      break;
    }

    // Check if STOP was received
    checkSerialCommand();
  }
}
