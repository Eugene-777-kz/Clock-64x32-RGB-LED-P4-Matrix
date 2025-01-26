
void getBigTime()
{
   //loadConfig();
   do {
    if(modBig == 0){
     matrix.fillRect(0, 0, 64, 32, myBLACK);
       }
    ArduinoOTA.handle();
    matrix.fillRect(0, 0, 64, 32, myBLACK);
    if(m % 2 == 0 && s == 0)getwifi();
    updateTime();
    matrix.fillScreen(0);
    matrix.setFont();
    matrix.setCursor(g-9, 22);
    if (h < 10) {matrix.setCursor(g+6, 22);}
    matrix.setTextSize(1);
    matrix.setFont(&fontsb[font]);
    matrix.setTextColor(myCOLORS[e][x7]);
      if ( m < 10 ) {
      mintext = 0;
      matrix.println(String(h) + " " + mintext + String(m));
      matrix.swapBuffers(true);
       } else {
      matrix.println(String(h) + " " + String(m));
      matrix.swapBuffers(true);
        }        
      matrix.setFont();
      matrix.swapBuffers(true);
      if ( h >= hof && h < hon && m == 00 && s == 00 ){dfPlayer.playFolder(Mgl, h);yield();}
       if(Y == 0){
    if(s % 2 == 0){
    matrix.drawPixel(32, 15, myCOLORS[e][x7]);
    matrix.drawPixel(31, 16, myCOLORS[e][x7]);
       }else{
    matrix.drawPixel(32, 16, myCOLORS[e][x7]);
    matrix.drawPixel(31, 15, myCOLORS[e][x7]);
       }
     }
      if (s % 2 == 0) {
      matrix.setTextSize(1);
      matrix.setFont(&fontsb[font]);
      matrix.setCursor(30, 28);
      matrix.println(":");
      matrix.swapBuffers(true);
      } else {
      matrix.setTextSize(1);
      matrix.setFont(&fontsb[font]);
      matrix.setCursor(30, 28);
      matrix.println(";");
      }
      matrix.swapBuffers(true);
      matrix.setFont();
      portal.tick();
    if(Serv == true)client.loop();
    if(m % 2 == 0 && s == 20 && flagrtc == 0)zppMqtt();
    if(s == 10 && ModWEBR != 2 && modWR != 1){
    if(Modsen == 1)getds18b20();
    if(Mod1 == true)getsensSGP30();
    switch(weti){
    case 1:getsensorsBme();break;
    case 2:getsensorsAth();break;
    case 3:sensorsBmp280();break;
    case 4:sensorsBmp180();break;
    case 5:getsensGY21();break;
     }
    }
    if(effekt == 1){
    switch(s){
    case 00:getscrullbig(frameSkrull+15);break;
    case 25:getscrullbigy(frameSkrull+15);break; 
    case 45:getscrullbigy1(frameSkrull+30);break;
     }
    }
    getper();
    getprbud();
   
    if (h == hbigoff && m == mbigoff){getPilik();modBig = 0;matrix.fillRect(0, 0, 64, 32 , myBLACK);delay(100);matrix.setFont();getRTCh(szTime);getRTCm(szTime);} 
  }while (modBig == 1 && BCH == true);
   matrix.setFont();
   matrix.fillRect(0, 0, 64, 32 , myBLACK);
   getRTCh(szTime);
   getRTCm(szTime);   
}
