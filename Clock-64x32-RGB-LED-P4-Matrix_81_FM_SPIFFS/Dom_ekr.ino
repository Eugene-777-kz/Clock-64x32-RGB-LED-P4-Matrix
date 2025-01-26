void getNow1() {
  
  matrix.fillRect(0, 0, 64, 32, myBLACK);
  if(Mod1 == 1)getsensSGP30();
  for (int zik1 = 0; zik1 < ekrDom; zik1 ++) {
    ArduinoOTA.handle();
      portal.tick();
     if (h < 10) {
      matrix.setCursor(43, -1);
    } else {
      matrix.setCursor(38, -1);
    }
    matrix.setTextSize(1);
    matrix.setFont(&TomThumb);
    matrix.setTextColor(myCOLORS[e][x29]);
    updateTime();
    matrix.fillRect(54, 0, 7, 6, myBLACK);//
    printTime();
    matrix.println(String(h) + ":" + (m < 10 ? "0" : "") + String(m));
    matrix.swapBuffers(true);
    matrix.setFont();
    matrix.setCursor(2, -1);
    matrix.setTextColor(myCOLORS[e][x30]);
    matrix.setFont(&Heebo7pt8b);
    matrix.println(utf8rus("дома:"));
    matrix.setFont();
    matrix.swapBuffers(true);
    matrix.setTextSize(1);
    matrix.setFont(&TomThumb);
    matrix.setCursor(13, 16);
    matrix.setTextColor(myCOLORS[e][x31]);
    if (wetu == 1) {matrix.println(String(int(pressBme + corrPress)) + " mmMs"); matrix.swapBuffers(true);}
    if (wetu == 2 && POG == 0) {matrix.println(String((location_pres), 0) + (pressSys == 1 ? tPress : tPress0) + " mmMs");matrix.swapBuffers(true);}
    if (wetu == 2 && POG == 1) {matrix.println(String(pressures/1.355269, 0) + " mmMs");matrix.swapBuffers(true);}
    if (wetu == 2 && POG == 2) {matrix.println(String(pressuredarc/1.33372, 0) + " mmMs");matrix.swapBuffers(true);}
    if (wetu == 3) {matrix.println(String(int(pressBmp + corrPress)) + " mmMs");matrix.swapBuffers(true);}
    if (wetu == 4) {matrix.println(String(int(pressBmp + corrPress)) + " mmMs"); matrix.swapBuffers(true);}
    matrix.setCursor(40, 28);
    matrix.setTextColor(myCOLORS[e][x31]);
    if (weti == 1) {matrix.println("+ " + String(tempBme + CorTemp, 0) + " c");matrix.swapBuffers(true);}
    if (weti == 2) {sensors_event_t temp;aht_temp->getEvent(&temp); matrix.fillRect(40, 22, 15, 8, myBLACK); matrix.print ("+ ");matrix.println(String(temp.temperature + CorTemp, 0) + "c");matrix.swapBuffers(true);}    // matrix.setCursor(55, 28);matrix.setTextColor(myCOLORS[e][x31]);matrix.print (" c");matrix.swapBuffers(true);}
    if (weti == 3) {matrix.println("+ " + String(tempBmp + CorTemp , 0) + "c");matrix.swapBuffers(true);}
    if (weti == 4) {matrix.println("+ " + String(tempBmp + CorTemp, 0) + "c");matrix.swapBuffers(true);}
    if (weti == 5) {matrix.println("+ " + String(htu.getTemperature() + CorTemp , 0) + "c");matrix.swapBuffers(true);}
    matrix.setCursor(13, 28);
    matrix.setTextColor(myCOLORS[e][x31]);
    if (wety == 1) matrix.println(String(humBme + CorHum, 0) + "%");
    matrix.swapBuffers(true);
    if (wety == 2) {sensors_event_t humidity;aht_humidity->getEvent(&humidity);matrix.fillRect(13, 22, 10, 8, myBLACK);matrix.print(String(humidity.relative_humidity + CorHum, 0));matrix.println ("%");matrix.swapBuffers(true);}
    if (wety == 3) {matrix.println(String(humNM , 0) + "%");matrix.swapBuffers(true);}
    if (wety == 4) {
      matrix.println(String(htu.getHumidity() + CorHum, 0) + "%");
      matrix.swapBuffers(true);
    }
    matrix.setFont();
    matrix.drawRGBBitmap(0, 7, image_data_Image24, 12, 12);
    matrix.drawRGBBitmap(28, 19, image_data_Image22, 12, 12);
    matrix.drawRGBBitmap(1, 20, image_data_Image26, 10, 12);
    matrix.drawRGBBitmap(51, 8, image_data_Image28, 12, 12);
    matrix.swapBuffers(true);
    delay(300);
    matrix.fillRect(0, 7, 13, 25, myBLACK);
    matrix.drawRGBBitmap(0, 7, image_data_Image25, 12, 12);
    matrix.drawRGBBitmap(28, 19, image_data_Image23, 12, 12);
    matrix.drawRGBBitmap(1, 20, image_data_Image27, 10, 12);
    matrix.drawRGBBitmap(51, 8, image_data_Image29, 12, 12);
    matrix.swapBuffers(true);
    getprbud();
    delay(300);
   }
  if(flagrtc == 0)updateTime();
  ModKey = 0;
  matrix.fillScreen(0);
  getRTCh(szTime);
  getRTCm(szTime);
}
