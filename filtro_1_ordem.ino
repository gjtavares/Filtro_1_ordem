/* 
 Filtro de 1° ordem
 Gabriel Jeronimo
 2020
*/

#define Qtd_Amostras 8 // Número de amostras

float yMed(void);
float filtro(float);
float filtro1ordem(float);

float ym, inv_ym;

  
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() 
{
     ym=yMed();
     Serial.print(ym);
     Serial.print(',');
     //Serial.println(filtro(ym));
  	 Serial.println(filtro1ordem(ym));
  
     delay(1);
}

float yMed(void)
{  
  float randNum,ruido;
  randNum=random(-100,100)/100.0;
  ruido=1+5*randNum/100; // 5% de ruído (-0.95 a +1.05)
  return(ruido*analogRead(0));
}  

/*float filtro(float yin)
{
  float yout;
  static float yout_ant=0;  
  yout=1.2*yin;                 //lei de filtragem
  return(yout); 
}*/  

float filtro1ordem(float yin)
{  
  static float Saida_Filtro = 0;
  static float yin_anterior = 0;
  
  Saida_Filtro = (float)((Saida_Filtro + 0.3333*yin + 0.3333*yin_anterior)/1.66667) ;
  yin_anterior = yin;
  return((float)Saida_Filtro);
 }
