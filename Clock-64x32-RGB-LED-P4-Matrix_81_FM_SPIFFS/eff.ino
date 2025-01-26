uint8_t ckl = 0;
uint8_t ckl1 = 0;
int16_t textx = matrix.width();
int16_t texty = matrix.height();
int8_t pozx[2][4] = {
  {0, 7, 1, 28},
  {0, 7, -1, 0}
};
 

void getef1(unsigned long eff_delay)//стирание строки слева на право
{
  for(ckl = 0; ckl < 64; ckl++){
   matrix.drawLine(ckl, 0, ckl, 7, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
   
}
void getef2(unsigned long eff_delay)//стиране строкм справа на лево
{
  for(ckl = 64; ckl > 0; ckl--){
   matrix.drawLine(ckl, 24, ckl, 32, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
   
}
void getef3(unsigned long eff_delay)//стирание
{
  for((ckl = 32) && (ckl1 = 32); (ckl < 64) && (ckl1 > 0); (ckl++) && (ckl1--)){
   matrix.drawLine(ckl, 0, ckl, 7, myBLACK);
   matrix.drawLine(ckl1, 0, ckl1, 7, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
   
}
void getef4(unsigned long eff_delay)
{
  for((ckl = 32) && (ckl = 32); (ckl < 64) && (ckl1 > 0); (ckl++) && (ckl1--)){
   matrix.drawLine(ckl, 0, ckl, 32, myBLACK);
   matrix.drawLine(ckl1, 0, ckl1, 32, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
   
}

void getef5(unsigned long eff_delay)
{
  for(ckl = 0; ckl < 64; ckl++){
   matrix.drawLine(ckl, 0, ckl, 32, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
   
}
void getef6(unsigned long eff_delay)
{
  for(ckl = 0; ckl < 32; ckl++){
   matrix.fillCircle(32, 16, ckl, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
}
void getef7(unsigned long eff_delay)
{
  for(ckl = 0; ckl < 64; ckl++){
   matrix.drawRect(0, 0, ckl, ckl, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
   font++;
   if(font>11)font=0;
}
void getef8(unsigned long eff_delay)
{
  for(ckl = 0; ckl < 32; ckl++){
   matrix.drawLine(0, ckl, 64, ckl, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
}

void getef9(unsigned long eff_delay)
{
  for(ckl = 32; ckl > 0; ckl--){
   matrix.drawCircle(32, 16, ckl, myBLACK);
   matrix.drawCircle(16, 8, ckl, myBLACK);
   matrix.drawCircle(48, 24, ckl, myBLACK);
   matrix.drawCircle(48, 8, ckl, myBLACK);
   matrix.drawCircle(16, 24, ckl, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
}
void getef10(unsigned long eff_delay)
{
  for(ckl = 0; ckl  < 32; ckl++){
   matrix.fillCircle(32, 16, ckl, myBLACK);
   matrix.fillCircle(16, 8, ckl, myBLACK);
   matrix.fillCircle(48, 24, ckl, myBLACK);
   matrix.fillCircle(48, 8, ckl, myBLACK);
   matrix.fillCircle(16, 24, ckl, myBLACK); 
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
   }
}
void getef11(unsigned long eff_delay)
{
  for(ckl = 0; ckl < 64; ckl++){
   matrix.drawRect(0, 0, ckl, ckl, myBLACK);
   matrix.drawRect(5, 5, ckl, ckl, myBLACK);
   matrix.drawRect(10, 10, ckl, ckl, myBLACK);
   matrix.drawRect(15, 15, ckl, ckl, myBLACK);
   matrix.drawRect(20, 20, ckl, ckl, myBLACK);
   matrix.drawRect(25, 25, ckl, ckl, myBLACK);
    delay(eff_delay);
    yield();
    matrix.swapBuffers(true);
    }
}

void getscrull(unsigned long scrull_delay)
{  int ypos;
   for(ckl = 0; ckl < (textx + 20); ckl++){
    matrix.setCursor(ckl, ypos);
    matrix.fillRect(0, ypos-1, 64, 9, myBLACK);
    matrix.setTextColor(myRED);
    matrix.setFont(&fontsk[0]);
    matrix.print(utf8rus(String(yr)));
    if((ckl == matrix.width() - 44) && (s != 48) && (ypos == 1)) ckl--;
    if((ckl == matrix.width() - 44) && (s != 58) && (ypos == 25)) ckl--;
    matrix.swapBuffers(true); 
    matrix.setFont(); 
    delay(scrull_delay);
    yield();
    matrix.swapBuffers(true);
  }
  getscrullbigy2(frameSkrull+35);
}

void getscrullx(unsigned long scrull_delay)
{
  int ckls = 0;
  pozx[0][0] = 0;
  pozx[0][2] = 1;
     for(ckls = 0; ckls < 100; ckls++){
     matrix.fillRect(0, 0, 64, 9, myBLACK);
     matrix.setFont(&fontsk[0]);
     matrix.setCursor(pozx[0][0], pozx[0][1]);
     matrix.setTextColor(myRED);
     matrix.print(utf8rus(String(yr)));
     matrix.swapBuffers(true);
     matrix.setFont(); 
     pozx[0][0] += pozx[0][2];
     if((pozx[0][0] == 68 - texty) || (pozx[0][0] == 0)){
      pozx[0][2] *= -1;
     }
     delay(scrull_delay);
     yield();
     matrix.swapBuffers(true);
   }
}
void getscrullz(unsigned long scrull_delay)
{
  int ckls = 0;
  pozx[0][0] = 0;
  pozx[0][2] = 1;
     for(ckls = 0; ckls < 64; ckls++){
     matrix.fillRect(0, 0, 64, 32, myBLACK);
     matrix.setTextSize(1);
     matrix.setFont(&fontsb[font]);
     matrix.setCursor(pozx[0][0], pozx[0][3]);
     matrix.setTextColor(myCOLORS[e][g]);
    if ( m < 10 ) {
      matrix.println(String(h) + " " + "0" + String(m));
      matrix.swapBuffers(true);
       } else {
      matrix.println(String(h) + " " + String(m));
      matrix.swapBuffers(true);
        }
     matrix.swapBuffers(true);
     matrix.setFont(); 
     pozx[0][0] += pozx[0][2];
     delay(scrull_delay);
     yield();
     matrix.swapBuffers(true);
   }
}

void getscrullbig(unsigned long scrull_delay)//большие часы слево напрово
{
  int ckls = 0;
  int xposb = -64;
  int sme = 0;
     for(ckls = 0; ckls < 64+sme; ckls++){
     matrix.fillRect(0, 0, 64, 32, myBLACK);
     matrix.setCursor(xposb, 22);
     if (h < 10)sme = 15; 
     matrix.setTextSize(1);
     matrix.setFont(&fontsb[font]);
     //if (ModNreg == 0) {
      matrix.setTextColor(myCOLORS[e][x7]);
          //}else{
     // matrix.setTextColor(myBLACK);
         //}
     if ( m < 10 ) {
      matrix.println(String(h) + " " + "0" + String(m));
      matrix.swapBuffers(true);
       } else {
      matrix.println(String(h) + " " + String(m));
      matrix.swapBuffers(true);
        }
     matrix.swapBuffers(true);
     matrix.setFont();
     xposb++;
     delay(scrull_delay);
     yield();
     matrix.swapBuffers(true);
   }
}
void getscrullbigy(unsigned long scrull_delay)//большие часы сверху вниз
{
  int ckls = 0;
  int yposb = -22;
     for(ckls = 0; ckls < 44; ckls++){
     matrix.fillRect(0, 0, 64, 32, myBLACK);
     matrix.setCursor(0, yposb);
     if (h < 10) matrix.setCursor(15, yposb);
     matrix.setTextSize(1);
     matrix.setFont(&fontsb[font]);
     //if (ModNreg == 0) {
      matrix.setTextColor(myCOLORS[e][x7]);
         // }else{
     // matrix.setTextColor(myBLACK);
        // }
     if ( m < 10 ) {
      matrix.println(String(h) + " " + "0" + String(m));
      matrix.swapBuffers(true);
       } else {
      matrix.println(String(h) + " " + String(m));
      matrix.swapBuffers(true);
        }
     matrix.swapBuffers(true);
     matrix.setFont();
     yposb++;
     delay(scrull_delay);
     yield();
     matrix.swapBuffers(true);
   }
    //if(Serv == 0 && Modsen == 1)getds18b20();
}
void getscrullbigy1(unsigned long scrull_delay)//большие часы снизу вверх
{
  int ckls = 0;
  int yposb = 44;
     for(ckls = 0; ckls < 22; ckls++){
     matrix.fillRect(0, 0, 64, 32, myBLACK);
     matrix.setCursor(0, yposb);
     if (h < 10){
     matrix.setCursor(15, yposb);
     }
     matrix.setTextSize(1);
     matrix.setFont(&fontsb[font]);
     //if (ModNreg == 0) {
      matrix.setTextColor(myCOLORS[e][x7]);
         // }else{
      //matrix.setTextColor(myBLACK);
        // }
     if ( m < 10 ) {
      matrix.println(String(h) + " " + "0" + String(m));
      matrix.swapBuffers(true);
       } else {
      matrix.println(String(h) + " " + String(m));
      matrix.swapBuffers(true);
        }
     matrix.swapBuffers(true);
     matrix.setFont();
     yposb--;
     delay(scrull_delay);
     yield();
     matrix.swapBuffers(true);
   }
}
void getscrullbigy2(unsigned long scrull_delay)//текст на нижней строке снизу вверх
{
  int ckls = 0;
  int yposc = 38;
     for(ckls = 0; ckls < 14; ckls++){
     uint16_t text_length = text.length();
     int xpo = (64 - text_length * 3) / 2;
     matrix.setCursor(xpo, yposc);
     matrix.fillRect(0, 24, 64, 8, myBLACK);
     matrix.setTextColor(myCOLORS[e][r]);
     matrix.setFont(&fontsk[0]);
     matrix.print(utf8rus(text));
     matrix.swapBuffers(true);
     matrix.setFont();
     yposc--;
     delay(scrull_delay);
     yield();
     matrix.swapBuffers(true);
   }
}
void getscrullHR(unsigned long scrull_delay)//ночной режим строка вверх
{
  int ckls = 0;
  int yposb = 38;
     for(ckls = 0; ckls < 14; ckls++){
     matrix.fillRect(0, 25, 64, 7, myBLACK);
     matrix.setCursor(20, yposb);
     if(Hb[dow]>9)matrix.setCursor(14, yposb);
     matrix.setTextSize(1);
     matrix.setFont(&TomThumb);
     matrix.setTextColor(myCOLORN[x37]);
     if (ModNreg == 2 || ModNreg == 0)matrix.setTextColor(myBLACK);
     matrix.println(String(day) + "/" + String(Hb[dow]) + ":" + (Mb[dow] < 10 ? "0" : "") + String(Mb[dow])); 
     matrix.swapBuffers(true);
     matrix.setFont();
     yposb--;
     delay(scrull_delay);
     yield();
     matrix.swapBuffers(true);
   }
}
void getscrullHR1(unsigned long scrull_delay)//ночной режим эффекты
{
  int ckls = 0;
  int yposb = 38;
     for(ckls = 0; ckls < 14; ckls++){
     matrix.fillRect(0, 25, 64, 7, myBLACK);
     matrix.setCursor(20, yposb);
     if(Hb[dow+1]>9)matrix.setCursor(14, yposb);
     matrix.setTextSize(1);
     matrix.setFont(&TomThumb);
     matrix.setTextColor(myCOLORN[x37]);
     if (ModNreg == 2 || ModNreg == 0)matrix.setTextColor(myBLACK);
     matrix.println(String(daynow) + "/" + String(Hb[dow+1]) + ":" + (Mb[dow+1] < 10 ? "0" : "") + String(Mb[dow+1]));
     matrix.swapBuffers(true);
     matrix.setFont();
     yposb--;
     delay(scrull_delay);
     yield();
     //matrix.swapBuffers(true);
   }
}
