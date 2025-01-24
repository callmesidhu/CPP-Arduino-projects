
 long distance ;
 long duration ;
 int limit = 100;
  
void setup() {
 pinMode (8, OUTPUT); 
 pinMode (9, INPUT);
 pinMode (10, OUTPUT); 
 Serial.begin(9600);
}

void loop() {
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(9, HIGH);
  distance = duration*0.034/2;
  Serial.print("distance : ");
  Serial.println(distance); 
  if(distance < limit){
    digitalWrite(10, HIGH);
    }else{
     digitalWrite(10, LOW);
    }
   delay(100);
}
