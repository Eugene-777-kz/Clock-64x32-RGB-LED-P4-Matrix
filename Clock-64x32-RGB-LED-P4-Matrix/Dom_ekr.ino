int zik1 = 0;
bool pon = true;
void getNow1() {

  matrix.fillRect(0, 0, 64, 32, myBLACK);
  TimeShow1 = millis();
  if (Mod1 == 1)getsensSGP30();
  do {
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
    switch (wetu) {
      case 1 : matrix.println(String(int(pressBme + corrPress)) + " mmMs"); matrix.swapBuffers(true); break;
      case 2 :
        if (POG == 0) {
          matrix.println(String((location_pres), 0) + (pressSys == 1 ? tPress : tPress0) + " mmMs");
          matrix.swapBuffers(true);
        }
        else if (POG == 1) {
          matrix.println(String(pressures / 1.355269, 0) + " mmMs");
          matrix.swapBuffers(true);
        }
        else if (POG == 2) {
          matrix.println(String(pressuredarc / 1.33372, 0) + " mmMs");
          matrix.swapBuffers(true);
        }
        break;
      case 3: matrix.println(String(int(pressBmp + corrPress)) + " mmMs"); matrix.swapBuffers(true); break;
      case 4: matrix.println(String(int(pressBmp + corrPress)) + " mmMs"); matrix.swapBuffers(true); break;
    }
    matrix.setCursor(40, 28);
    matrix.setTextColor(myCOLORS[e][x31]);
    switch (weti) {
      case 1: matrix.println("+ " + String(tempBme + CorTemp, 0) + " c"); matrix.swapBuffers(true); break;
      case 2: sensors_event_t temp; aht_temp->getEvent(&temp); matrix.fillRect(40, 22, 15, 8, myBLACK); matrix.print ("+ "); matrix.println(String(temp.temperature + CorTemp, 0) + "c"); matrix.swapBuffers(true); break; // matrix.setCursor(55, 28);matrix.setTextColor(myCOLORS[e][x31]);matrix.print (" c");matrix.swapBuffers(true);}
      case 3: matrix.println("+ " + String(tempBmp + CorTemp , 0) + "c"); matrix.swapBuffers(true); break;
      case 4: matrix.println("+ " + String(tempBmp + CorTemp, 0) + "c"); matrix.swapBuffers(true); break;
      case 5: matrix.println("+ " + String(htu.getTemperature() + CorTemp , 0) + "c"); matrix.swapBuffers(true); break;
    }
    matrix.setCursor(13, 28);
    matrix.setTextColor(myCOLORS[e][x31]);
    switch (wety) {
      case 1: matrix.println(String(humBme + CorHum, 0) + "%"); matrix.swapBuffers(true); break;
      case 2: sensors_event_t humidity; aht_humidity->getEvent(&humidity); matrix.fillRect(13, 22, 10, 8, myBLACK); matrix.print(String(humidity.relative_humidity + CorHum, 0)); matrix.println ("%"); matrix.swapBuffers(true); break;
      case 3: matrix.println(String(humNM , 0) + "%"); matrix.swapBuffers(true); break;
      case 4: matrix.println(String(htu.getHumidity() + CorHum, 0) + "%"); matrix.swapBuffers(true); break;
    }
    matrix.setFont();
    matrix.swapBuffers(true);
    if (pon == true && millis() - TimeShow1 > 200) {
      TimeShow1 = millis();
      matrix.drawRGBBitmap(0, 7, image_data_Image24, 12, 12);
      matrix.drawRGBBitmap(28, 19, image_data_Image22, 12, 12);
      matrix.drawRGBBitmap(1, 20, image_data_Image26, 10, 12);
      matrix.drawRGBBitmap(51, 8, image_data_Image28, 12, 12);
      matrix.swapBuffers(true);
      pon = false;
    }
    if (pon == false && millis() - TimeShow1 > 200) {
      TimeShow1 = millis();
      matrix.fillRect(0, 7, 13, 25, myBLACK);
      matrix.drawRGBBitmap(0, 7, image_data_Image25, 12, 12);
      matrix.drawRGBBitmap(28, 19, image_data_Image23, 12, 12);
      matrix.drawRGBBitmap(1, 20, image_data_Image27, 10, 12);
      matrix.drawRGBBitmap(51, 8, image_data_Image29, 12, 12);
      matrix.swapBuffers(true);
      pon = true;
    }
    getprbud();
    zik1++;
  } while (zik1 <= ekrDom);
  if (flagrtc == 0)updateTime();
  ModKey = 0;
  zik1 = 0;
  matrix.fillScreen(0);
  getRTCh(szTime);
  getRTCm(szTime);
}
