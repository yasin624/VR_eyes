//###############################################   MPU 6050
#include "MUP.h"
int x,y,z,e;
int kutu_w=700,kutu_h=400;
int gercek_w=1920,gercek_h=1080;
int w=gercek_w/2,h=gercek_h/2;




/*   başarısız olundu array döndürülmesi bilinemiyor örende gell
int box_mask(int x,int y,int w,int h){
/////  mask = ( x1,y1,x2,y2);
  int boxx[4];

  boxx[0]=x-(w/2);
  boxx[1]=y-(h/2);
  boxx[2]=x+(w/2);
  boxx[3]=y+(h/2);
  
  return boxx;
  
}       
*/




void setup() {  
initializeIMU();
Serial.begin(2000000);


}
int x1,y1,x2,y2;
void loop() {
  struct Orientation o = getIMUOrientation();
  
  ///////////////////////////////////////////////////////////////////   kutu belirleme
  x1=w-(kutu_w/2);
  y1=h-(kutu_h/2);
  x2=w+(kutu_w/2);
  y2=h+(kutu_h/2);
  /////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////değerleri alma
  e=o.Error;
  x=o.Roll;
  y=o.Pitch;
  z=o.Yaw;
  
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////  maplama
   z=map(z,-180,180,-w+(kutu_w/2),w-(kutu_w/2));
   y=map(y,-180,180,-h+(kutu_h/2),h-(kutu_h/2));
   ////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////    kutuyu yeniden konumlandırma
  
  if (e == 1){
      Serial.println(" HATA !!!  BAĞLANTILARI KONTROL EDİN ");
  }
  
  else{
      x1=x1+z;
      x2=x2+z;
      y1=y1-y;
      y2=y2-y;
           

  }
  ////////////////////////////////////////////////////////////////////////////////////////////////                
  ////////////////////////////////////////////////////////////   Ardinunio daki değerleri pytona atma
  Serial.print(x1);
  Serial.print(",");
  Serial.print(y1);
  Serial.print(",");
  Serial.print(x2);
  Serial.print(",");
  Serial.println(y2);
  delay(100);
  
}
