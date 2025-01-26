const byte CENTRE_X = ((matrix_width - 32) / 2) - 1;
const byte CENTRE_Y = (matrix_height / 2) - 1;
#define R_HOUR 7
#define R_MIN  10
#define R_SEC   12
double radians;
int xa;
int ya;
int ja = 0;
unsigned int NewChas = 24;
unsigned int NewMin = 60;
unsigned int NewSek = 60;
void drawtime() {


  //watch.gettime();
  if (watch.Hours > 12)
    watch.Hours -= 12;
  portal.tick();
  matrix.fillScreen(0);
  matrix.drawCircle(CENTRE_X, CENTRE_Y, 14, myCOLORA[e][0]);
  for (int i = 0; i < 60; i += 15) {
    radians = (90.0F - (i * 6.0F)) * M_PI / 180.0;
  }
  matrix.setTextColor(myCOLORA[e][4]);
  for (int i = 0; i < 60; i += 5) {
    radians = (90.0F - (i * 6.0F)) * M_PI / 180.0;
    xa = round(CENTRE_X + 12 * cos(radians));
    ya = round(CENTRE_Y - 12 * sin(radians));
    matrix.fillCircle(xa, ya, 1, myCOLORA[e][4]);
    xa = round(CENTRE_X + 10 * cos(radians));
    ya = round(CENTRE_Y - 10 * sin(radians));
    matrix.setCursor(xa, ya);
  }
  matrix.setFont();
}
void getChas(char *psz)
{
  radians = (90.0F - ((h * 30.0F) + ((m * 29.0F) / 60.0F))) * M_PI / 180.0F;
  xa = round(CENTRE_X + R_HOUR * cos(radians));
  ya = round(CENTRE_Y - R_HOUR * sin(radians));
  matrix.drawLine(xa, ya, CENTRE_X, CENTRE_Y - 1, myCOLORA[e][3]);
  matrix.drawLine(xa, ya, CENTRE_X, CENTRE_Y + 1, myCOLORA[e][3]);
  matrix.drawLine(xa, ya, CENTRE_X - 1, CENTRE_Y, myCOLORA[e][3]);
  matrix.drawLine(xa, ya, CENTRE_X + 1, CENTRE_Y, myCOLORA[e][3]);
}
void getMin(char *psz)
{

  radians = (90.0F - (m * 6.0F)) * M_PI / 180.0;
  xa = round(CENTRE_X + R_MIN * cos(radians));
  ya = round(CENTRE_Y - R_MIN * sin(radians));
  matrix.drawLine(xa, ya, CENTRE_X, CENTRE_Y - 1, myCOLORA[e][3]);
  matrix.drawLine(xa, ya, CENTRE_X, CENTRE_Y + 1, myCOLORA[e][3]);
  matrix.drawLine(xa, ya, CENTRE_X - 1, CENTRE_Y, myCOLORA[e][3]);
  matrix.drawLine(xa, ya, CENTRE_X + 1, CENTRE_Y, myCOLORA[e][3]);

}
void getSek(char *psz, bool f)

{
  radians = (90.0F - ((float)s * 6.0F)) * M_PI / 180.0F;
  xa = round(CENTRE_X + R_SEC * cos(radians));
  ya = round(CENTRE_Y - R_SEC * sin(radians));
  matrix.drawLine(xa, ya, CENTRE_X, CENTRE_Y, myCOLORA[e][1]);

  matrix.fillCircle(xa, ya, 1, myCOLORA[e][1]);
  if (s >= min(0, 15) && s < max(0, 15) || s > min(30, 45) && s < max(30, 45)) {
    matrix.setTextColor(myCOLORA[e][4]);
    matrix.setCursor(39, 3);
    if (day < 10)matrix.setCursor(42, 3);
    matrix.print(String(day));
    matrix.setTextColor(myCOLORA[e][3]);
    matrix.setCursor(39, 13);
    if (month < 9) matrix.print("0");
    matrix.println(month + 1);
    time_t now = time(nullptr);
    struct tm* p_tm = localtime(&now);
    year = p_tm->tm_year + 1900;
    matrix.setTextColor(myCOLORA[e][0]);
    matrix.setCursor(34, 23);
    matrix.println(year);
  }
  else if (s >= min(15, 30) && s <= max(15, 30) || s >= min(45, 60) && s <= max(45, 60)) {
    matrix.setTextColor(myCOLORA[e][4]);
    matrix.setCursor(33, 3);
    if (weti == 1) matrix.println("+" + String(tempBme + CorTemp, 0) + "\260" + "C");
    if (weti == 2) {
      sensors_event_t temp;
      aht_temp->getEvent(&temp);
      matrix.print ("+");
      matrix.println(String(temp.temperature + CorTemp, 0) + "\260" + "C");
    }
    if (weti == 3) matrix.println("+" + String(tempBmp + CorTemp , 0) + "\260" + "C");
    if (weti == 4) matrix.println("+" + String(tempBmp + CorTemp, 0) + "\260" + "C");
    if (weti == 5) matrix.println("+" + String(htu.getTemperature() + CorTemp , 0) + "\260" + "C");
    matrix.setTextColor(myCOLORA[e][3]);
    matrix.setCursor(39, 13);
    if (wety == 1) matrix.println(String(humBme + CorHum , 0) + "%");
    if (wety == 2) {
      sensors_event_t humidity;
      aht_humidity->getEvent(&humidity);
      matrix.print(String(humidity.relative_humidity + CorHum, 0));
      matrix.println ("%");
    }
    if (wety == 3) matrix.println(String(humNM + CorHum , 0) + "%");
    if (wety == 4) matrix.println(String(htu.getHumidity() + CorHum, 0) + "%");
    matrix.setTextColor(myCOLORA[e][0]);
    matrix.setCursor(33, 23);
    if (wetu == 1) matrix.println(String(int(pressBme + corrPress)) + "mm");
    if (wetu == 2 && Modebst1 == true && POG == 0)matrix.println(String((location_pres), 0) + (pressSys == 1 ? tPress : tPress0) + "mm");
    if (wetu == 2 && Modebst1 == true && POG == 1)matrix.println(String(pressures / 1.355269, 0) + "mm");
    if (wetu == 2 && Modebst1 == true && POG == 2)matrix.println(String(pressuredarc / 1.33372, 0) + "mm");
    if (wetu == 3) matrix.println(String(int(pressBmp + corrPress)) + "mm");
    if (wetu == 4) matrix.println(String(int(pressBmp + corrPress)) + "mm");

  }
}
void analogclock()
{
  do {
    matrix.fillRect(0, 0, 64, 32 , myBLACK);
    if ( h >= hof && h < hon && m == 00 && s == 00) {
      getGov_vrema();
    }
    updateTime();
    portal.tick();
    drawtime();
    getChas(szTime);
    getMin(szTime);
    getSek(szTime, flasher);
    matrix.swapBuffers(false);
    delay(1000);
  } while (modAnclock == true);
  matrix.fillRect(0, 0, 64, 32 , myBLACK);
  getRTCh(szTime);
  getRTCm(szTime);
}
