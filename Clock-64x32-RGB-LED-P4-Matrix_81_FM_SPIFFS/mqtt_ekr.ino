void getNow4() {
  matrix.fillRect(0, 0, 64, 32, myBLACK);
  for (int zik4 = 0; zik4 < ekrmqtt; zik4 ++) {
    ArduinoOTA.handle();
    matrix.setCursor(17, 2);
    matrix.setTextColor(myCOLORS[e][x40]);
    matrix.setFont(&Heebo7pt8b);
    matrix.println(utf8rus("MQTT"));
    matrix.setFont();
    matrix.swapBuffers(true);
    if (h < 10) {
      matrix.setCursor(28, 12);
    } else {
      matrix.setCursor(23, 12);
    }
    matrix.setTextSize(1);
    matrix.setFont(&TomThumb);
    matrix.setTextColor(myCOLORS[e][x41]);
    matrix.println(String(h) + ":" + (m < 10 ? "0" : "") + String(m));
    matrix.setFont();
    matrix.swapBuffers(true);
    updateTime();
    getprbud();
    if(file1 != 0){
    if(Text > "0")texttemp = '+';
    mqttstring = TEXT + texttemp + file1 + "\260С";
    }else{
      mqttstring = "Температура - нет данных ";
    }
    if(file2 != 0){
      mqttstring += TEXT1 + file2 + "%";
    }else{
      mqttstring += " Влажность - нет данных "; 
    }
    if(file3 != 0){
      mqttstring += TEXT2 + file3 + "ммРс.";
    }else{
     mqttstring += " Давление - нет данных ";  
    }
    
    if (Serv == true && (file1 != 0 || file2 != 0 || file3 != 0)){ scroll_text1(24, frameDelay4, (mqttstring));}
  }
  delay(10);
  ModKey = 0;
  matrix.fillScreen(0);
  getRTCh(szTime);
  getRTCm(szTime);
}
void scroll_text1(uint8_t ypos, unsigned long scroll_delay, String text)
{
  uint16_t text_length = text.length();
  for (int xpos = matrix_width; xpos > -(matrix_width + text_length * 5); xpos--)
  {
    ArduinoOTA.handle();
    matrix.swapBuffers(true);
    matrix.setCursor(xpos, ypos);
    matrix.fillRect(0, ypos - 2, 64, 10, myBLACK);
    matrix.setTextColor(myCOLORS[e][x39]);
    matrix.setFont();
    matrix.setFont(&Heebo7pt8b);
    matrix.print(utf8rus(text));
    matrix.setFont();
    delay(scroll_delay);
   }
}
