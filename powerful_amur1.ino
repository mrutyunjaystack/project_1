 int led_red = 12;  
 int led_yellow = 7;  
 int led_green = 10;   
 int push_button = 5;  
int x;
 long greentime = 5000;            
 long yellowtime = 5000;           
 long redtime = 5000;              
 long red_time_pedestrian=10000; 

void setup() {
  Serial.begin(9600);
    pinMode(led_red, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(led_green, OUTPUT);
    pinMode(push_button, INPUT);
}

void loop() {
    if (digitalRead(push_button) == HIGH) {  // Pedestrian Request
        delay(50);
      x=digitalRead(push_button);
      Serial.println(x);
        
        if (x == HIGH) {
            digitalWrite(led_red, HIGH);
            digitalWrite(led_yellow, LOW);
            digitalWrite(led_green, LOW);
            delay(red_time_pedestrian);
        }
    } else {
        trafficFlow(led_green, greentime);
        trafficFlow(led_yellow, yellowtime);
        trafficFlow(led_red, redtime);
    }
}
void trafficFlow(int led, long duration) {
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led, HIGH);

    unsigned long start = millis();
    while (millis() - start < duration) {
        if (digitalRead(push_button) == HIGH) return;  
    }
}
