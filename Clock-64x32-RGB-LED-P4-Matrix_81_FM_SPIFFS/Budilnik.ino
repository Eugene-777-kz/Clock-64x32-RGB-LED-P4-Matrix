void getprbud()
{ 
     switch(dow){
    case 1: mel = mel1;MPov = MPov1;Pov = Pov1;break;
    case 2: mel = mel2;MPov = MPov2;Pov = Pov2;break;
    case 3: mel = mel3;MPov = MPov3;Pov = Pov3;break;
    case 4: mel = mel4;MPov = MPov4;Pov = Pov4;break;
    case 5: mel = mel5;MPov = MPov5;Pov = Pov5;break;
    case 6: mel = mel6;MPov = MPov6;Pov = Pov6;break;
    case 7: mel = mel7;MPov = MPov7;Pov = Pov7;break;
  }
    
  if (h == Hb[dow] &&  m == Mb[dow] && s == 00 && ModBYD[dow] == 1){
    flagpbudik = 1;
    getByd();
  }
  if (Pov == 1 && ModBYD[dow] == 1 && h == Hb[dow] && m == Mb[dow] + MPov && s == 00){
    flagpbudik = 1;
    getByd();
  }
 
}
void getByd() {
   matrix.fillRect(0, 0, 64, 32, myBLACK);
   int byb = 0;
     loadConfig();
     if(MG == 0 || MG == 1 || MG == 2){
      if(Y == 0)Y = W;
     dfPlayer.volume(Y);
     dfPlayer.playFolder(1, mel); 
     }
    do{
    getwifi();
    loadConfig();
    
    matrix.drawRGBBitmap(0, 0, image_data_kot, 64, 32); // Картинка на будильник
    matrix.swapBuffers(true);
    if(MG == 3) {
      while (byb < 40){
     byb++;
    buser();
    delay(500);
      }
    }
    Portal();
     }while (flagpbudik == 1 && (m == Mb[dow] || m == Mb[dow] + MPov));
  matrix.fillRect(0, 0, 64, 32, myBLACK);
  flagpbudik = 0;
  getRTCh(szTime);
  getRTCm(szTime);
}
