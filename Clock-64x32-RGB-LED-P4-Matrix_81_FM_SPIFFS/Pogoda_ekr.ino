void getNow()
{
  matrix.fillRect(0, 0, 64, 32, myBLACK);
  matrix.setCursor(14, 0); //
  matrix.setTextColor(myCOLORS[e][x32]);
  matrix.setFont(&Heebo7pt8b);
  matrix.println(utf8rus("погода"));
  matrix.swapBuffers(true);
  matrix.setFont();
  if(Mod1 == 1)getsensSGP30();
  if(printCom)Serial.println(String(day));
   if (day >= 10)matrix.setCursor(2, 4); 
   if (day < 10)matrix.setCursor(7, 4); 
  matrix.setTextSize(1);
  matrix.setFont(&TomThumb);
  matrix.setTextColor(myCOLORS[e][x33]);
  matrix.print(String(day));
  matrix.setFont();
  matrix.swapBuffers(true);
  if(printCom)Serial.println(String(location_temp));
  matrix.setTextSize(1);
  matrix.setFont(&TomThumb);
  matrix.setTextColor(myCOLORS[e][x34]);
  if(location_temp > 0){matrix.setCursor(1, 29);texttemp = "+ " ;matrix.print(texttemp + String(location_temp, 0) + "c");}
  if(location_temp == 0)matrix.setCursor(3, 29);
  if(location_temp < 0)matrix.setCursor(1, 29); 
  if(location_temp < 0 || location_temp == 0) matrix.print(String(location_temp, 0) + "c");
  matrix.swapBuffers(true);
  matrix.setFont();
  if(printCom)Serial.println(String(coded1));
  matrix.setCursor(52, 4); 
  matrix.setTextSize(1);
  matrix.setFont(&TomThumb);
  matrix.setTextColor(myCOLORS[e][x33]);
  Serial.println(month);
  if (((month == 3 || month == 5 || month == 8 || month == 10) && day == 30) || ((month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) && day == 31) || ((month == 1) && day == 28))
  {
    daynow = 1;
  } else {
    daynow = day + 1;
  }
  matrix.setFont();
  if (h < 10) {
    matrix.setCursor(26, 9); 
  } else {
    matrix.setCursor(22, 9); 
  }
  matrix.setTextSize(1);
  matrix.setFont(&TomThumb);
  matrix.setTextColor(myCOLORS[e][x35]);
  printTime();
  matrix.println(String(h) + ":" + (m < 10 ? "0" : "") + String(m));
  matrix.swapBuffers(true);
  matrix.setFont();
  if(daynow >= 10){matrix.setCursor(53, 4);matrix.setTextSize(1);matrix.setFont(&TomThumb); matrix.setTextColor(myCOLORS[e][x33]); matrix.print(daynow); matrix.swapBuffers(true); matrix.setFont();}
  if(daynow < 10){matrix.setCursor(54, 4);matrix.setTextSize(1); matrix.setFont(&TomThumb); matrix.setTextColor(myCOLORS[e][x33]);matrix.print(daynow); matrix.swapBuffers(true); matrix.setFont();}
  matrix.setTextSize(1);
  matrix.setFont(&TomThumb);
  matrix.setTextColor(myCOLORS[e][x34]);
  if(tempfor2 >= 10){texttempmax = "+ ";matrix.setCursor(39, 29);matrix.print(texttempmax + String(tempfor2, 0) + "c");}
  if(tempfor2 < -10){matrix.setCursor(40, 29);matrix.print(String(tempfor2, 0) + "c");}
  if(tempfor2 > 0 && tempfor2 < 10){texttempmax = "+ "; matrix.setCursor(44, 29); matrix.print(texttempmax + String(tempfor2, 0) + "c");}
  if(tempfor2 < 0 && tempfor2 >= -10){matrix.setCursor(44, 29);matrix.print(String(tempfor2, 0) + "c");}
  if(tempfor2 == 0){matrix.setCursor(48, 29);matrix.print(String(tempfor2, 0) + "c");}
  matrix.swapBuffers(true);
  matrix.setFont();
  
       if(location_wind_cdir_full == "Северный") matrix.drawRGBBitmap(28, 17, image_data_N, 9, 9);
       matrix.swapBuffers(true);
       if(location_wind_cdir_full == "Юго-Западный") matrix.drawRGBBitmap(28, 17, image_data_SW, 9, 9);
       matrix.swapBuffers(true);
       if(location_wind_cdir_full == "Южный") matrix.drawRGBBitmap(28, 17, image_data_S, 9, 9);
       matrix.swapBuffers(true);
       if(location_wind_cdir_full == "Юго-Восточный") matrix.drawRGBBitmap(28, 17, image_data_SE, 9, 9);
       matrix.swapBuffers(true);
       if(location_wind_cdir_full == "Северо-Западный") matrix.drawRGBBitmap(28, 17, image_data_NW, 9, 9);
       matrix.swapBuffers(true);
       if(location_wind_cdir_full == "Северо-Восточный") matrix.drawRGBBitmap(28, 17, image_data_NE, 9, 9);
       matrix.swapBuffers(true);
       if(location_wind_cdir_full == "Восточный") matrix.drawRGBBitmap(28, 17, image_data_W, 9, 9);
       matrix.swapBuffers(true);
       if(location_wind_cdir_full == "Западный") matrix.drawRGBBitmap(28, 17, image_data_E, 9, 9);
       matrix.swapBuffers(true);
       if (String(location_wind_cdir_full) == "Западный-Юго-Западный"){matrix.drawRGBBitmap(28, 17, image_data_E, 9, 9);matrix.swapBuffers(false);delay(500);matrix.drawRGBBitmap(28, 17, image_data_SW, 9, 9);matrix.swapBuffers(false);delay(500);}
       if (String(location_wind_cdir_full) == "Западный-Северо-Западный"){matrix.drawRGBBitmap(28, 17, image_data_E, 9, 9);matrix.swapBuffers(false);delay(500);matrix.drawRGBBitmap(28, 17, image_data_NW, 9, 9);matrix.swapBuffers(false);delay(500);}
       if (String(location_wind_cdir_full) == "Восточный-Северо-Восточный"){matrix.drawRGBBitmap(28, 17, image_data_W, 9, 9);matrix.swapBuffers(false);delay(500);matrix.drawRGBBitmap(28, 17, image_data_NE, 9, 9);matrix.swapBuffers(false);delay(500);}
       if (String(location_wind_cdir_full) == "Восточный-Юго-Восточный"){matrix.drawRGBBitmap(28, 17, image_data_W, 9, 9);matrix.swapBuffers(false);delay(500);matrix.drawRGBBitmap(28, 17, image_data_SE, 9, 9);matrix.swapBuffers(false);delay(500);}
       if (String(location_wind_cdir_full) == "Юго-Юго-Западный"){matrix.drawRGBBitmap(28, 17, image_data_S, 9, 9);matrix.swapBuffers(false);delay(500);matrix.drawRGBBitmap(28, 17, image_data_SW, 9, 9);matrix.swapBuffers(false);delay(500);}
       if (String(location_wind_cdir_full) == "Юго-Юго-Восточный"){matrix.drawRGBBitmap(28, 17, image_data_S, 9, 9);matrix.swapBuffers(false);delay(500);matrix.drawRGBBitmap(28, 17, image_data_SE, 9, 9);matrix.swapBuffers(false);delay(500);}
       if (String(location_wind_cdir_full) == "Северо-Северо-Западный"){matrix.drawRGBBitmap(28, 17, image_data_N, 9, 9);matrix.swapBuffers(false);delay(500);matrix.drawRGBBitmap(28, 17, image_data_NW, 9, 9);matrix.swapBuffers(false);delay(500);}
       if (String(location_wind_cdir_full) == "Северо-Северо-Восточный"){matrix.drawRGBBitmap(28, 17, image_data_N, 9, 9);matrix.swapBuffers(false);delay(500);matrix.drawRGBBitmap(28, 17, image_data_NE, 9, 9);matrix.swapBuffers(false);delay(500);}
      if(flagrtc == 0)updateTime();
      getImeg();
      delay(1000);
      matrix.fillScreen(0);
      getRTCh(szTime);
      getRTCm(szTime);
}
void getImeg()
{
  for (int zik = 0; zik < ekrPog; zik ++) {
      ArduinoOTA.handle();
       portal.tick();
      getprbud();
      switch (location_code) {
      case 200: //Гроза с небольшим дождем
      case 201: // Гроза с дождем
      case 202: // гроза с сильным дождем
      case 210: // Легкая гроза
      case 211: // Гроза
      case 212: // Сильная гроза
      case 221: // Рваная гроза
      case 230: // Гроза с мелким дождиком
      case 231: // Гроза с моросью
      case 232: // Гроза с сильным дождиком
        matrix.drawRGBBitmap(7, 13, image_data_Image14, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(7, 13, image_data_Image15, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 300: // Слабая морось
      case 301: // Морось
      case 302: // Сильный дождь
      case 310: // Моросящий дождь
      case 311: // Моросящий дождь
      case 312: // Сильный моросящий дождь
      case 500: // Легкий дождь
      case 501: // Умеренный дождь
      case 511: // Холодный дождь
      case 521: // Дождь
      case 531: // Рваный дождь
      case 613: // Мокрый дождь
        matrix.drawRGBBitmap(7, 13, image_data_Image10, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(7, 13, image_data_Image11, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 313: // Ливень, дождь и изморозь
      case 314: // Сильный ливень дождь и изморозь
      case 502: // Сиильный дождь
      case 503: // Очень сильный дождь
      case 504: // Сильный дождь
      case 520: // Темно, ливень
      case 522: // Сильный пролевной дождь
        matrix.drawRGBBitmap(10, 14, image_data_Image8, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(10, 14, image_data_Image9, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 601: // Снег
      case 602: // Сильный снегопад
      case 622: // Сильный снегопад
      case 623: // Кратковременный снегопад
        matrix.drawRGBBitmap(7, 13, image_data_Image4, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(7, 13, image_data_Image5, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
      case 600: //легкий снег
      case 610: // Снег с дождем
      case 611: // Мокрый снег
      case 612: // Легкий дождь со снегом
      case 615: //Небольшой дождь и снег
      case 616: // Дождь и снег
      case 620: // Легкий снегопад
      case 621: // Ливень и снег
        matrix.drawRGBBitmap(7, 13, image_data_Image6, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(7, 13, image_data_Image7, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 701: // Туман
      case 711: // Дым
      case 721: // Мгла
      case 731: // Песчаная буря
      case 741: // Туман
      case 751: // Песок
      case 761: // Пыль
      case 762: // Вулканический пепел
      case 771: // Шквал
      case 781: // Торнадо
        //int zik = 0;
        //for (int zik = 0; zik < 100; zik ++){
        matrix.drawRGBBitmap(7, 13, image_data_Image2, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(7, 13, image_data_Image3, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        //}
        break;
      case 800: // Ясно, чистое небо
        if (h < 21 && h > 6) {
          matrix.drawRGBBitmap(7, 13, image_data_Image, 10, 10);
          matrix.swapBuffers(false);
          delay(F);
          matrix.drawRGBBitmap(7, 13, image_data_Image1, 10, 10);
          matrix.swapBuffers(false);
          delay(F);
        } else {
          matrix.drawRGBBitmap(7, 13, image_data_Image20, 10, 10);
          matrix.swapBuffers(false);
          delay(F);
          matrix.drawRGBBitmap(7, 13, image_data_Image21, 10, 10);
          matrix.swapBuffers(false);
          delay(F);
        }
        break;
      case 801: // Мало облачно 25%
      case 802: // Облано 50%
      case 803: // Облачно 80%
        if (h < 21 && h > 6) {
          matrix.drawRGBBitmap(7, 13, image_data_Image16, 10, 10);
          matrix.swapBuffers(false);
          delay(F);
          matrix.drawRGBBitmap(7, 13, image_data_Image17, 10, 10);
          matrix.swapBuffers(false);
          delay(F);
        } else {
          matrix.drawRGBBitmap(7, 13, image_data_Image18, 10, 10);
          matrix.swapBuffers(false);
          delay(F);
          matrix.drawRGBBitmap(7, 13, image_data_Image19, 10, 10);
          matrix.swapBuffers(false);
          delay(F);
        }
        break;
      case 804: // Пасмурно 100%
        matrix.drawRGBBitmap(7, 13, image_data_Image12, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(7, 13, image_data_Image13, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
    }
    switch (coded1) {
      case 200: //Гроза с небольшим дождем
      case 201: // Гроза с дождем
      case 202: // гроза с сильным дождем
      case 210: // Легкая гроза
      case 211: // Гроза
      case 212: // Сильная гроза
      case 221: // Рваная гроза
      case 230: // Гроза с мелким дождиком
      case 231: // Гроза с моросью
      case 232: // Гроза с сильным дождиком
        matrix.drawRGBBitmap(47, 13, image_data_Image14, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image15, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 300: // Слабая морось
      case 301: // Морось
      case 302: // Сильный дождь
      case 310: // Моросящий дождь
      case 311: // Моросящий дождь
      case 312: // Сильный моросящий дождь
      case 500: // Легкий дождь
      case 501: // Умеренный дождь
      case 511: // Холодный дождь
      case 521: // Дождь
      case 531: // Рваный дождь
      case 613: // Мокрый дождь
        matrix.drawRGBBitmap(47, 13, image_data_Image10, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image11, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 313: // Ливень, дождь и изморозь
      case 314: // Сильный ливень дождь и изморозь
      case 502: // Сиильный дождь
      case 503: // Очень сильный дождь
      case 504: // Сильный дождь
      case 520: // Темно, ливень
      case 522: // Сильный пролевной дождь
        matrix.drawRGBBitmap(47, 13, image_data_Image8, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image9, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 601: // Снег
      case 602: // Сильный снегопад
      case 622: // Сильный снегопад
      case 623: // Кратковременный снегопад
        matrix.drawRGBBitmap(47, 13, image_data_Image4, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image5, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
      case 600: //легкий снег
      case 610: // Снег с дождем
      case 611: // Мокрый снег
      case 612: // Легкий дождь со снегом
      case 615: //Небольшой дождь и снег
      case 616: // Дождь и снег
      case 620: // Легкий снегопад
      case 621: // Ливень и снег
        matrix.drawRGBBitmap(47, 13, image_data_Image6, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image7, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 701: // Туман
      case 711: // Дым
      case 721: // Мгла
      case 731: // Песчаная буря
      case 741: // Туман
      case 751: // Песок
      case 761: // Пыль
      case 762: // Вулканический пепел
      case 771: // Шквал
      case 781: // Торнадо
        //int zik = 0;
        //for (int zik = 0; zik < 100; zik ++){
        matrix.drawRGBBitmap(47, 13, image_data_Image2, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image3, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 800: // Ясно, чистое небо
        matrix.drawRGBBitmap(47, 13, image_data_Image, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image1, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 801: // Мало облачно 25%
      case 802: // Облано 50%
      case 803: // Облачно 80%
        matrix.drawRGBBitmap(47, 13, image_data_Image16, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image17, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
      case 804: // Пасмурно 100%
        matrix.drawRGBBitmap(47, 13, image_data_Image12, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        matrix.drawRGBBitmap(47, 13, image_data_Image13, 10, 10);
        matrix.swapBuffers(false);
        delay(F);
        break;
         
    }
  }
      ModKey = 0;
}
