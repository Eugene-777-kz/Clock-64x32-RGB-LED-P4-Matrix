void getNow2()
{
   
   matrix.fillRect(0, 0, 64, 32, myBLACK);
  for (int zik2 = 0; zik2 < ekrKach; zik2 ++) {   // Задержка на экране Качество воздуха
    ArduinoOTA.handle();
    portal.tick();
    getprbud();
    matrix.fillRect(0, 0, 64, 32, myBLACK);
    getsensSGP30();
    matrix.setCursor(4, 0);
    matrix.setTextColor(myCOLORS[e][x42]);
    matrix.print (utf8rus("Качество"));
    matrix.setCursor(7, 6);
    matrix.print (utf8rus("воздуха"));
    matrix.setFont();
    matrix.setCursor(1, 16);
    matrix.setTextColor(myCOLORS[e][x43]);
    matrix.println("eCO2");
    matrix.setCursor(26, 16);
    matrix.setTextColor(myCOLORS[e][x47]);
    matrix.print (String(mySensor.CO2));
    matrix.setCursor(1, 24);
    matrix.setTextColor(myCOLORS[e][x44]);
    matrix.println("TVOC");
    matrix.setCursor(26, 24);
    matrix.setTextColor(myCOLORS[e][x47]);
    matrix.print (String(mySensor.TVOC));
    matrix.setFont();
    printTime();
    if (mySensor.CO2 >= 399) {matrix.drawRGBBitmap(54, 0, vozduh_data2_Voz, 5, 32);matrix.swapBuffers(true);}
    if (mySensor.TVOC == 0) {matrix.drawRGBBitmap(58, 0, vozduh_data2_VozTV, 5, 32);matrix.swapBuffers(true);delay(100);}
    if (mySensor.CO2 >= 400) {matrix.drawRGBBitmap(54, 0, vozduh_data2_Voz1, 5, 32);matrix.swapBuffers(true);}
    if (mySensor.TVOC >= 0) {matrix.drawRGBBitmap(58, 0, vozduh_data2_VozTV1, 5, 32);matrix.swapBuffers(true);delay(100);}
    if (mySensor.CO2 >= 600) {matrix.drawRGBBitmap(54, 0, vozduh_data2_Voz2, 5, 32);matrix.swapBuffers(true);}
    if (mySensor.TVOC >= 50) {matrix.drawRGBBitmap(58, 0, vozduh_data2_VozTV2, 5, 32);matrix.swapBuffers(true);delay(100);}
    if (mySensor.CO2 >= 800) {matrix.drawRGBBitmap(54, 0, vozduh_data2_Voz3, 5, 32);matrix.swapBuffers(true);}
    if (mySensor.TVOC >= 150) {matrix.drawRGBBitmap(58, 0, vozduh_data2_VozTV3, 5, 32);matrix.swapBuffers(true);delay(100);}
    if (mySensor.CO2 >= 1000) {matrix.drawRGBBitmap(54, 0, vozduh_data2_Voz4, 5, 32);matrix.swapBuffers(true);}
    if (mySensor.TVOC >= 300) {matrix.drawRGBBitmap(58, 0, vozduh_data2_VozTV4, 5, 32);matrix.swapBuffers(true);delay(100);}
    if (mySensor.CO2 >= 1400) {matrix.drawRGBBitmap(54, 0, vozduh_data2_Voz5, 5, 32);matrix.swapBuffers(true);}
    if (mySensor.TVOC >= 600) {matrix.drawRGBBitmap(58, 0, vozduh_data2_VozTV5, 5, 32);matrix.swapBuffers(true);delay(100);}
    if (mySensor.CO2 >= 1600) {matrix.drawRGBBitmap(54, 0, vozduh_data2_Voz6, 5, 32);matrix.swapBuffers(true);}
    if (mySensor.TVOC >= 1000) {matrix.drawRGBBitmap(58, 0, vozduh_data2_VozTV6, 5, 32);matrix.swapBuffers(true);delay(100);}
    if (mySensor.CO2 >= 2000) {matrix.drawRGBBitmap(54, 0, vozduh_data2_Voz7, 5, 32);matrix.swapBuffers(true);}
    if (mySensor.TVOC >= 1300) {matrix.drawRGBBitmap(58, 0, vozduh_data2_VozTV7, 5, 32);matrix.swapBuffers(true);delay(100);}
    delay(1000);
    if(flagrtc == 0)updateTime();
  }
  ModKey = 0;
  if(flagrtc == 0)updateTime();
  matrix.fillRect(0, 0, 64, 32, myBLACK);
  getRTCh(szTime);
  getRTCm(szTime);
}
