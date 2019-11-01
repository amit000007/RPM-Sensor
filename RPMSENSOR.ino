float x;
int val;
long last=0;
int stat=LOW;
int stat2;
int counter=0;
int pin=8;
int sens=1;  // this value indicates the limit reading between dark and light,
              // it has to be tested as it may change acording on the 
              // distance the leds are placed.
int n=1; // the number of blades of the propeller

int milis =1000; // the time it takes each reading
void setup()
{
  Serial.begin(9600);
  pinMode(pin,INPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  val=digitalRead(pin);
  //Serial.println(val);
  //delay(500);
   if(val==0)
   {
    
   stat=LOW;
   }
   else
   {
   stat=HIGH;
   
   }
   digitalWrite(13,stat); //as iR light is invisible for us, the led on pin 13 
                          //indicate the state of the circuit.

   if(stat2!=stat){  //counts when the state change, thats from (dark to light) or 
        x++;             //from (light to dark), remmember that IR light is invisible for us.
     counter++;
     stat2=stat;
   }
   if(millis()-last>=milis){
     double rpm =counter*30.00;
     double vel = rpm*0.10527792;
     
     long t = millis();
     
     Serial.print(rpm);Serial.println("  RPM");
  
     counter=0;
     last=millis();
     
    
   }
  
}
