#include<Arduino.h>
int z,y,x,a,b,c,clk;
//void disp_7474(int z,int y,int x)
//{
 //digitalWrite(2, x);
 //digitalWrite(3, y);
 //digitalWrite(4, z);
//}
void setup()
{

//Serial.begin(9600);
	pinMode(13,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(8,INPUT);
	pinMode(9,INPUT);
	pinMode(10,INPUT);
//Serial.println("abc xyz clock low");
	}
	
void loop()
{
	digitalWrite(13,HIGH);
	delay(1000);
        
	a = digitalRead(8);
        b = digitalRead(9);
        c = digitalRead(10);
	
        
        x = ((a&&c) || (b&&!c));
	y= ((!a&&c)||(b&&!c));
	z = ((!a&&!b) || (a&&b));
	
        digitalWrite(13,LOW);
	 delay(1000); 
	   
	 digitalWrite(2,x);
         digitalWrite(3,y);
         digitalWrite(4,z);
       //disp_7474(z,y,x);
      
	 
        //Serial.print(a); 
        //Serial.print(b); 
        //Serial.print(c);
        //Serial.print(" ");
	//Serial.print(x);
	//Serial.print(y);
       // Serial.println(z);   
	
      }
