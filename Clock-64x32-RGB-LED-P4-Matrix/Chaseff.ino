void CHeff()
{
  int modeffeck = 0;
  xef = 0;
  yef = 8;
  do {
    ArduinoOTA.handle();
    matrix.fillRect(0, 0, 64, 32, myBLACK);
    updateTime();
    portal.tick();
    matrix.setCursor(xef, yef);
    if (h == 00 && m == 00 && s == 00) {
      matrix.fillRect(0, 0, 64, 32, myBLACK);
      matrix.setCursor(xef, yef);
    }
    matrix.setTextSize(1);
    matrix.setFont(&fonts[fch]);
    matrix.setTextColor(myCOLORN[x37]);
    if (m < 10) {
      mintext = 0;
      matrix.println(String(h) + " " + mintext + String(m));
      matrix.swapBuffers(true);
    } else {
      matrix.println(String(h) + " " + String(m));
      matrix.swapBuffers(true);
    }
    matrix.setCursor(xef + 21, yef + 4);
    if (h < 10) matrix.setCursor(xef + 11, yef + 4);
    if (modtoch == false) matrix.println(":");
    matrix.setFont(&fonts[fch]);
    if (s % 2 == 0) {
      if (modtoch == false && h < 10)
      {
        matrix.fillRect(xef + 11, yef - 2, 4, 2, myBLACK); matrix.swapBuffers(true);
      }
      else if (modtoch == false && h >= 10) {
        matrix.fillRect(xef + 21, yef - 2, 4, 2, myBLACK); matrix.swapBuffers(true);
      }
    }
    if (s % 2 != 0) {
      if (modtoch == false && h < 10)
      {
        matrix.fillRect(xef + 11, yef + 2, 4, 2, myBLACK); matrix.swapBuffers(true);
      }
      else if (modtoch == false && h >= 10) {
        matrix.fillRect(xef + 21, yef + 2, 4, 2, myBLACK); matrix.swapBuffers(true);
      }
      if (modtoch == true) {
        matrix.println(":");
        matrix.swapBuffers(true);
      }
    }
    matrix.setFont();
    matrix.swapBuffers(true);
    if (h == 00 && m == 00 && s == 00) {
      matrix.fillRect(0, 0, 64, 32, myBLACK);
      xef = 0;
      yef = 8;
      matrix.setCursor(xef, yef);
    }
    delay(zadef);
    if (modeffeck1 == false) {
      if ( h < 10) {
        if (xef < 28 && yef == 8)ef1();
        if (xef >= 28 && yef < 24)ef2();
        if (yef >= 24 && xef > 0)ef3();
        if (xef == 0 && yef > 8)ef4();
      } else {
        if (xef < 18 && yef == 8)ef1();
        if (xef >= 18 && yef < 24)ef2();
        if (yef >= 24 && xef > 0)ef3();
        if (xef == 0 && yef > 8)ef4();
      }
    } else {
      if ( h < 10) {
        if (xef < 28 && modeffeck == 0)ef5();
        if (xef == 28 && yef == 22)modeffeck++;
        if (xef >= 28 && yef > 8 && modeffeck == 1)ef6();
        if (xef == 28 && yef == 8)modeffeck++;
        if (xef > 0 && yef < 22 && modeffeck == 2)ef7();
        if (xef == 0 && yef == 22)modeffeck++;
        if (yef > 8 && xef >= 0 && modeffeck == 3)ef8();
        if (xef == 0 && yef == 8)modeffeck = 0;
      } else {
        if (xef < 16 && modeffeck == 0)ef5();
        if (xef == 16 && yef == 24)modeffeck++;
        if (xef >= 16 && yef > 8 && modeffeck == 1)ef6();
        if (xef == 16 && yef == 8)modeffeck++;
        if (xef > 0 && yef < 24 && modeffeck == 2)ef7();
        if (xef == 0 && yef == 24)modeffeck++;
        if (yef > 8 && xef >= 0 && modeffeck == 3)ef8();
        if (xef == 0 && yef == 8)modeffeck = 0;
      }
    }
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
      getYtro();
    }
  } while (ModNreg == 3 && MNR == true && FlagNr == 1);
  matrix.setFont();
  matrix.fillRect(0, 0, 64, 32 , myBLACK);
  if (MNR == false)FlagNr = 0;
  getRTCh(szTime);
  getRTCm(szTime);
}
void ef1()
{
  xef++;
}
void ef2()
{
  yef++;

}
void ef3()
{
  xef--;
}
void ef4()
{
  yef--;

}
void ef5()
{
  if ( h < 10)
  {
    xef = xef + 2;
  } else {
    xef++;
  }
  yef++; //

}
void ef6()
{
  yef--;//

}
void ef7()
{
  if ( h < 10)
  {
    xef = xef - 2;
  } else {
    xef--;
  }
  yef++;//
}
void ef8()
{
  yef--;


}
