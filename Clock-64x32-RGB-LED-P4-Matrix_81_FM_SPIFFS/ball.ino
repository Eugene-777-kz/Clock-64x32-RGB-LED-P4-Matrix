void ball()
{
int8_t ball[3][4] = {                                                   // Массив с начальными координатами кругов, а так же со значениями, на сколько координаты меняются при каждом выполнении цикла
  {  6,  6,  1,  1 },                                                   // Координаты Синего круга {6;6} и каждый цикл они меняются на 1 по X и на 1 по Y
  { 17, 15,  1, -1 },                                                   // Координаты Зелёного круга {17;15} и каждый цикл они меняются на 1 по X и на -1 по Y
  { 27,  6, -1,  1 }                                                    // Координаты Синего круга {27;6} и каждый цикл они меняются на -1 по X и на 1 по Y
};

static const uint16_t ballcolor[3] = {                                  // Массив с цветами кругов
  matrix.Color333(0, 0, 3),                                             // Синий
  matrix.Color333(0, 3, 0),                                             // Зелёный
  matrix.Color333(3, 0, 0)                                              // Красный
};
  do{
   byte ib;                                                               // переменная для того, чтобы круги "бегали" по экрану, меняя координаты
   matrix.fillScreen(0);                                                 // очищаем экран
    for (byte ib = 0; ib < 3; ib++) {                                        // запускаем счётчик для смены координат кругов
    matrix.fillCircle(ball[ib][0], ball[ib][1], 5, ballcolor[ib]);         // Рисуем 3 круга с разными начальными координатами и разного цвета, но одинакового радиуса
    ball[ib][0] += ball[ib][2];                                           // Обновляем Х-координату кругов
    ball[ib][1] += ball[ib][3];                                           // Обновляем Y-координату кругов
    if ((ball[ib][0] == 5) || (ball[ib][0] == (matrix.width() - 5))) {    // Если круг по Х дошёл до границы, то
      ball[ib][2] *= -1;                                                 // инициируем движение в обратную сторону
    }
    if ((ball[ib][1] == 5) || (ball[ib][1] == (matrix.height() - 5))) {   // Если круг по Y дошёл до границы, то
      ball[ib][3] *= -1;                                                 // инициируем движение в обратную сторону
    }
   }
   matrix.swapBuffers(true);                                            // выводим объекты из буфера на экран
   delay(ballef);
    portal.tick();
  }while(Ball == 1);
     matrix.fillRect(0, 0, 64, 32 , myBLACK);
     getRTCh(szTime);
     getRTCm(szTime);
}
