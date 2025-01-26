int y = 0;
void getNreg() {
  TimeShow2 = millis();
  y = 0;
  do {
    if (y == 0 && millis() - TimeShow2 > 300) {
      TimeShow2 = millis();
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes, 64, 32);
      matrix.swapBuffers(true);
      y++;
    }

    if (y == 1 && millis() - TimeShow2 > 200) {
      TimeShow2 = millis();
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes1, 64, 32);
      matrix.swapBuffers(true);
      y++;
    }

    if (y == 2 && millis() - TimeShow2 > 300) {
      TimeShow2 = millis();
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes2, 64, 32);
      matrix.swapBuffers(true);
      dfPlayer.setTimeOut(1900);
      y++;
    }

    if (y == 3 && millis() - TimeShow2 > 300) {
      TimeShow2 = millis();
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes3, 64, 32);
      matrix.swapBuffers(true);
      y++;
    }

    if (y == 4 && millis() - TimeShow2 > 200) {
      TimeShow2 = millis();
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes4, 64, 32);
      matrix.swapBuffers(true);
      y++;
    }

    if (y == 5 && millis() - TimeShow2 > 100) {
      TimeShow2 = millis();
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes5, 64, 32);
      matrix.swapBuffers(true);
      y++;
    }

    if (y == 6 && millis() - TimeShow2 > 100) {
      TimeShow2 = millis();
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes6, 64, 32);
      matrix.swapBuffers(true);
      y++;
    }

    if (y == 7 && millis() - TimeShow2 > 10) {
      TimeShow2 = millis();
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes7, 64, 32);
      matrix.swapBuffers(true);
      y++;
    }
  } while (y < 8);
  if (MG == 3) {
    buser();
  } else {
    dfPlayer.volume(Y);
    dfPlayer.playFolder(Mgl, 41);//спокойной ночи
    y++;
  }
  NRG();
}

void NRG() {
  do {
    ArduinoOTA.handle();
    int mok = 0;
    while (mok < 1) {
      mok++;
      if (Y != 0) {
        Y = 0;
      }
    }
    portal.tick();
    matrix.fillRect(0, 0, 64, 32, myBLACK);
    if (ModNreg == 0) {
      if (dow == 2) matrix.drawRGBBitmap(2, 25, image_data_BLUE, 5, 3);
      if (dow == 3) matrix.drawRGBBitmap(11, 25, image_data_BLUE, 5, 3);
      if (dow == 4) matrix.drawRGBBitmap(20, 25, image_data_BLUE, 5, 3);
      if (dow == 5) matrix.drawRGBBitmap(29, 25, image_data_BLUE, 5, 3);
      if (dow == 6) matrix.drawRGBBitmap(38, 25, image_data_BLUE, 5, 3);
      if (dow == 7) matrix.drawRGBBitmap(47, 25, image_data_BLUE, 5, 3);
      if (dow == 1) matrix.drawRGBBitmap(56, 25, image_data_BLUE, 5, 3);
      if (Modbyd2 == 1) {
        matrix.drawRGBBitmap(2, 28, image_data_GREEN, 5, 2);
      } else {
        matrix.drawRGBBitmap(2, 28, image_data_GREY, 5, 2);
      }
      if (Modbyd3 == 1) {
        matrix.drawRGBBitmap(11, 28, image_data_GREEN, 5, 2);
      } else {
        matrix.drawRGBBitmap(11, 28, image_data_GREY, 5, 2);
      }
      if (Modbyd4 == 1) {
        matrix.drawRGBBitmap(20, 28, image_data_GREEN, 5, 2);
      } else {
        matrix.drawRGBBitmap(20, 28, image_data_GREY, 5, 2);
      }
      if (Modbyd5 == 1) {
        matrix.drawRGBBitmap(29, 28, image_data_GREEN, 5, 2);
      } else {
        matrix.drawRGBBitmap(29, 28, image_data_GREY, 5, 2);
      }
      if (Modbyd6 == 1) {
        matrix.drawRGBBitmap(38, 28, image_data_GREEN, 5, 2);
      } else {
        matrix.drawRGBBitmap(38, 28, image_data_GREY, 5, 2);
      }
      if (Modbyd7 == 1) {
        matrix.drawRGBBitmap(47, 28, image_data_RED, 5, 2);
      } else {
        matrix.drawRGBBitmap(47, 28, image_data_GREY, 5, 2);
      }
      if (Modbyd1 == 1) {
        matrix.drawRGBBitmap(56, 28, image_data_RED, 5, 2);
      } else {
        matrix.drawRGBBitmap(56, 28, image_data_GREY, 5, 2);
      }
      matrix.swapBuffers(true);
    }
    matrix.setCursor(g, 16);
    if ( h < 10) matrix.setCursor(g + 10, 16);
    matrix.setTextSize(1);
    matrix.setFont(&fonts[fch]);
    if (ModNreg == 0 || ModNreg == 1) matrix.setTextColor(myCOLORN[x37]);
    if (ModNreg == 2)matrix.setTextColor(myBLACK);
    if (ModNreg == 3)CHeff();
    if ((h == hof - 1) || (h == hof && m <= minof)) matrix.setTextColor(matrix.Color333(1, 0, 0));
    if (m < 10) {
      mintext = 0;
      matrix.println(String(h) + " " + mintext + String(m));
      matrix.swapBuffers(true);
    } else {
      matrix.println(String(h) + " " + String(m));
      matrix.swapBuffers(true);
    }
    matrix.setCursor(30, 19);
    if (modtoch == false) matrix.println(":");
    matrix.setFont(&fonts[fch]);
    if (s % 2 == 0) {
      if (modtoch == false) {
        matrix.fillRect(30, 13, 4, 2, myBLACK);
        matrix.swapBuffers(true);
      }
      if (modtoch == true) {
        matrix.println(":");
        matrix.swapBuffers(true);
      }                        //  {matrix.fillRect(30, 12, 4, 2, myRED);matrix.fillRect(30, 18, 4, 2, myRED);matrix.swapBuffers(true);}
    }
    if (s % 2 != 0) {
      if (modtoch == false) {
        matrix.fillRect(30, 17, 4, 2, myBLACK);
        matrix.swapBuffers(true);
      }
    }
    matrix.setFont();
    matrix.swapBuffers(true);
    getper();
    if (ModBYD[dow] == 1 && h <= Hb[dow]) {
      Serial.println(ModBYD[dow]);
      Serial.println(Hb[dow]);
      matrix.setTextSize(1);
      matrix.setFont(&TomThumb);
      matrix.setCursor(20, 30);
      if (Hb[dow] > 9)matrix.setCursor(14, 30);
      matrix.setTextColor(myCOLORN[x37]);
      if (ModNreg == 2 || ModNreg == 0)matrix.setTextColor(myBLACK);
      matrix.println(String(day) + "/" + String(Hb[dow]) + ":" + (Mb[dow] < 10 ? "0" : "") + String(Mb[dow]));
      matrix.setFont();
      matrix.swapBuffers(true);
      if (s % 10 == 0 && ModBYD[dow] == 1 && ModNreg != 0)getscrullHR(frameEff + 55);
    } else {
      if ((ModNreg != 0) && ((dow + 1) > 7))dow = 0;
      if (ModBYD[dow + 1] == 1) {
        if (((month == 3 || month == 5 || month == 8 || month == 10) && day == 30) || ((month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) && day == 31) || ((month == 1) && day == 28))
        {
          daynow = 1;
        } else {
          daynow = day + 1;
        }
        matrix.setTextSize(1);
        matrix.setFont(&TomThumb);
        matrix.setCursor(20, 30);
        if (Hb[dow + 1] > 9)matrix.setCursor(14, 30);
        matrix.setTextColor(myCOLORN[x37]);
        if (ModNreg == 2 || ModNreg == 0)matrix.setTextColor(myBLACK);
        matrix.println(String(daynow) + "/" + String(Hb[dow + 1]) + ":" + (Mb[dow + 1] < 10 ? "0" : "") + String(Mb[dow + 1]));
        matrix.setFont();
        matrix.swapBuffers(true);
        if (s % 10 == 0 && ModBYD[dow + 1] == 1 && ModNreg != 0) getscrullHR1(frameEff + 55);
      }
    }
    getprbud();
    matrix.setFont();
    if (m % 2 == 0 && s == 0)getwifi();
    updateTime();
    if ((hon < hof) && (h < min(hon, hof) || h > max(hon, hof + 1))) {
      getPilik();
      FlagNr = 0;
      Y = W;
      matrix.fillRect(0, 0, 64, 32 , myBLACK);
      matrix.setFont();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if ((hon > hof) && (h > min(hon, hof) && h < max(hon, hof + 1))) {
      getPilik();
      FlagNr = 0;
      Y = W;
      matrix.fillRect(0, 0, 64, 32 , myBLACK);
      matrix.setFont();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (h == hof && m == minof && s == 00) {
      getPilik();
      FlagNr = 0;
      Y = W;
      matrix.fillRect(0, 0, 64, 32 , myBLACK);
      delay(100);
      matrix.setFont();
      getRTCh(szTime);
      getRTCm(szTime);
      fytro = 0;
      getYtro();
    }
  } while (FlagNr == 1 && MNR == true &&  ModWEBR != 2);
  matrix.setFont();
  matrix.fillRect(0, 0, 64, 32 , myBLACK);
  if (MNR == false)FlagNr = 0;
  getRTCh(szTime);
  getRTCm(szTime);
}
