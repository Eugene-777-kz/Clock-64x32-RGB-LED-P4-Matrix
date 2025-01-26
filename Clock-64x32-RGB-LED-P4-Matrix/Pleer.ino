void getPilik()
{
  if (MG == 3) {
    buser();
  } else {
    dfPlayer.setTimeOut(100);
    dfPlayer.volume(Y);
    dfPlayer.playFolder(22, 50);//тирлиньк
  }
}
void getKey()
{
  dfPlayer.disableLoop();
}
void getPleer()
{
  if (ModKey == 0 || ModKey == 1 || ModKey == 2 ) {
    matrix.fillRect(0, 0, 64, 32, myBLACK);
  }
  while ((ModKey == 3 || modPleer == 1) && zaderg < 1000) {
    ArduinoOTA.handle();
    matrix.fillRect(0, 0, 64, 32, myBLACK);
    getwifi();
    Portal();
    //action();
    matrix.fillRect(0, 0, 64, 32, myBLACK);
    matrix.setCursor(16, 0);
    if (PLU == false) {
      x8 = 0;
    } else {
      x8 = 4;
    }
    matrix.setTextColor(myCOLORS[e][x8]);
    matrix.setFont(&Heebo7pt8b);
    matrix.println(utf8rus("плеер"));
    //matrix.swapBuffers(true);
    //matrix.setFont();
    //matrix.fillRect(0, 0, 64, 32, myBLACK);
    if (PLR < 10) {
      matrix.setCursor(31, 28);
    } else {
      matrix.setCursor(25, 28);
    }
    matrix.setTextColor(myCOLORS[e][x46]);
    matrix.setFont(&Heebo7pt8b);
    if (PLU == false)matrix.println(PLR);
    if (PLU == true) {
      matrix.setCursor(12, 28);//изм
      matrix.print(utf8rus("цикл:"));//изм
      matrix.println(papk);//изм
    }
    matrix.swapBuffers(true);
    matrix.setFont();
    matrix.setCursor(20, 11);
    if (h < 10) {
      matrix.setCursor(25, 11);
    }
    matrix.setFont(&TomThumb);
    //geteepromR();
    matrix.setTextColor(myCOLORS[e][x45]);
    if ( m < 10 ) {
      mintext == 0;
      matrix.println(String(h) + "  " + mintext + String(m));
      matrix.swapBuffers(true);
    } else {
      matrix.println(String(h) + "  " + String(m));
      matrix.swapBuffers(true);
    }
    if (s % 2 == 0) {
      matrix.setFont(&TomThumb);
      matrix.setCursor(30, 17);
      matrix.println(":");
      matrix.swapBuffers(true);
    }
    matrix.setFont();
    zaderg++;
  }
  dfPlayer.volume(Y);
  if (zaderg == 1000) {
    modPleer = 0;
    ModKey = 0;
    dfPlayer.disableLoop();
  }
  if (PLU == false)dfPlayer.playFolder(04, PLR);
  if (PLU == true)dfPlayer.loopFolder(papk);
  matrix.fillScreen(0);
  getRTCh(szTime);
  getRTCm(szTime);

}
