int sensor1 = A0, sensor2 =A1,
tempC[2] ={70,85},tempF[2]{5,15},
ledC=2,ledF=3,RelojDisp1=8,RelojDisp2=9,
timer = 30, boton = 13;
float lectura;


void setup()
{
  Serial.begin(9600);
  for (int h=0;h<=13;h++){
  pinMode(h, OUTPUT);
  }
}
void display (int a, int b, int c, int d, int e, int f, int g)// Función del display
{//superior
  digitalWrite (4,a);   
  digitalWrite (5,b);   
  digitalWrite (6,c);
  digitalWrite (7,d);
  //inferior
  digitalWrite (10,e);
  digitalWrite (11,f);
  digitalWrite (12,g);
  
}
void imprime1 (int mensaje){

    if (mensaje==0){
      display (0,0,0,0,0,0,1); 
    }
 
    if (mensaje==1){
      display (1,0,0,1,1,1,1);
    }
    if (mensaje==2){
      display (0,0,1,0,0,1,0);
    }
    if (mensaje==3){
      display (0,0,0,0,1,1,0);
    }
    if (mensaje==4){
      display (1,0,0,1,1,0,0);
    }
    if (mensaje==5){
      display (0,1,0,0,1,0,0);
    }
    if (mensaje==6){
      display (0,1,0,0,0,0,0);
    }
    if (mensaje==7){
      display (0,0,0,1,1,1,1); 
    }
    if (mensaje==8){
      display (0,0,0,0,0,0,0); 
    }
    if (mensaje==9){
      display (0,0,0,1,1,0,0);
    }
 
  
}

void loop(){
//Lectura de TempC
   float voltaje = 5.0 /1024 * analogRead(sensor1); ;
   float temp = voltaje * 100 -50 ;
if (temp<=tempC[0]){
  
digitalWrite(2, HIGH);
  
}else if (temp>=tempC[1]){
digitalWrite(2, LOW);
} 
  
//Lectura de TempFria
   float voltaje2 = 5.0 /1024 *analogRead(sensor2);  ;
   float temp2 = voltaje2 * 100 -50 ;
  
//Extrae entero para pantalla  
  int enteroF = (int) temp2;
  int v,b,n;
  v = enteroF;
  
  b = v/10; //primera salida
   n= v - (b*10);//segunda salida
  imprime1(b);
  
  digitalWrite(8, HIGH);
  delay (timer);
  digitalWrite(8, LOW);
  
 
  imprime1(n);
  digitalWrite(9, HIGH);
  delay (timer);
  digitalWrite(9, LOW);

if (temp2<=tempF[0]){
  
digitalWrite(3, LOW);
  
}else if (temp2>=tempF[1]){
digitalWrite(3, HIGH);
} 
  
}  

  
