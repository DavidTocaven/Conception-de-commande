int pinVm = A0;
int pinVs = DAC0;
int pinVg = DAC1;

float x1 = 0;
float x2 = 0;

unsigned long tk;

float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  //Serial.begin(9600);
  pinMode(pinVm, INPUT);
  pinMode(pinVs, OUTPUT);
  pinMode(pinVg, OUTPUT);
  analogReadResolution(12); 
  analogWriteResolution(12); 
  tk = micros();
}

void loop() {
  unsigned long t = micros();
  delayMicroseconds(10000-t+tk);
  int Vm = analogRead(pinVm);
  float fVm = mapf(Vm,0,4095,-5,5);
  float x1s = 0.9613 * x1 + 0.5563 * fVm;
  float x2s = 0.009805 * x1 + x2 + 0.0028 * fVm;
  float fVg = 0.105 * x1;
  float fVs = (1.111 * x2 + 5) - 10*int((1.111 * x2 +5)/ 10) - 5;
  
  int Vs = int(mapf(fVs,-5,5,0,4095));
  int Vg = int(mapf(fVg,-5,5,0,4095));
  analogWrite(pinVs,Vs);
  analogWrite(pinVg,Vg);
  
  //Serial.println(Vm);
  //Serial.println(Vs);
  //Serial.println(Vg);
  //Serial.println("\n");
  
  x1 = x1s;
  x2 = x2s;
  tk = 10000+tk;
  
  delay(5);
}



