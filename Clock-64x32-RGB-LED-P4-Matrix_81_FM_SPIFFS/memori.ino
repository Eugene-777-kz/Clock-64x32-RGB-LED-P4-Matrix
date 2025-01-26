void getmemor()
{
  if(mem == 0){
     matrix.fillRect(0, 0, 64, 32, myBLACK);
  }
   while (mem == 1){
    ArduinoOTA.handle();
    matrix.fillRect(0, 0, 64, 32, myBLACK);
    getwifi();
    matrix.fillRect(0, 0, 64, 32, myBLACK);
    matrix.setCursor(16, 0);
    matrix.setTextColor(myCOLORS[e][0]);
    matrix.setFont(&Heebo7pt8b);
    matrix.println(utf8rus("память"));
    matrix.setFont(); 
     matrix.swapBuffers(true);
    matrix.setCursor(2, 8);
    matrix.setTextColor(myCOLORS[e][1]);
    matrix.setFont(&TomThumb);
    matrix.println(ESP.getFlashChipSize());
    matrix.setFont(); 
     matrix.swapBuffers(true);
    matrix.setCursor(2, 16);
    matrix.setTextColor(myCOLORS[e][1]);
    matrix.setFont(&TomThumb);
    matrix.println(ESP.getFreeHeap());
    matrix.setFont(); 
     matrix.swapBuffers(true);
    matrix.setCursor(2, 24);
    matrix.setTextColor(myCOLORS[e][1]);
    matrix.setFont(&TomThumb);
    matrix.println(ESP.getMinFreeHeap());
    matrix.setFont(); 
    matrix.swapBuffers(true);
    delay(1000);
    matrix.swapBuffers(true);
   
   }
}
