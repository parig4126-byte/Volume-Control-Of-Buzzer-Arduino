const int CLK = 2; 
const int DT = 3;
const int buzzer = 9; 

int counter = 0;      
int currentStateCLK;
int lastStateCLK;

void setup() {
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  
  lastStateCLK = digitalRead(CLK);
  Serial.begin(9600);
  Serial.println("Analog Volume Control Ready!");
}

void loop() {
  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK && currentStateCLK == HIGH) {
    if (digitalRead(DT) != currentStateCLK) {
      counter += 5; 
    } else {
      counter -= 5; 
    }
    if (counter > 255) counter = 255;
    if (counter < 0) counter = 0;
    
    analogWrite(buzzer, counter);
    
    Serial.print("Volume Level (0-255): ");
    Serial.println(counter);
    
    delay(50); 
  }
  
  lastStateCLK = currentStateCLK;
}