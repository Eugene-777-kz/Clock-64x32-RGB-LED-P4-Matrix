void build() {
  String s;
  BUILD_BEGIN(s);
  GP.THEME(GP_DARK);
  GP.TITLE("𝕸𝖆𝖙𝖗𝖎𝖝 🔴🟢🔵 𝕮𝖑𝖔𝖈𝖐", "font30 fontcyan_000000");
  if (modWR == 0 && portal.uri() == "/update") {
    GP.HR();
    GP.LABEL("МЕСТОПОЛОЖЕНИЕ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("ПОГОДНЫЙ СЕРВЕР", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("selpog", "WEATHERBIT,WEATHERMAP,METEO", POG); GP.BREAK();
    GP.LABEL("ВАШИ КООРДИНАТЫ", "font16 fontred_a5381b"); GP.BREAK();
    GP.LABEL("И ВАШ API С ПОГОДНОГО СЕРВЕРА", "font16 fontred_a5381b"); GP.BREAK();
    GP.FORM_BEGIN("/update");
    GP.TEXT("txt", "Город", gorod , "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt1", "Широта", lat , "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt2", "Долгота", lon , "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt3", "Ключ API", weatherKey0 , "font20 fontyellow_c79536"); GP.BREAK();
    GP.SUBMIT("💾 СОХРАНИТЬ ", "backgroundred_a5381b widthauto height30 font20 fontblue_000000");
    GP.HR();
    GP.LABEL("ЗАПРОС ПОГОДЫ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swkch", kch); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.HR();
    GP.LABEL("МОДУЛЬ RTC", "font20 fontcyan_16747a"); GP.LED_GREEN("led6", flagRTC); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("sw15", flagRTC); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СИНХРОНИЗАЦИЯ С СЕРВЕРОМ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.BUTTON("btn18", "✍ RTC ⌚", "backgroundgreen_gradient widthauto height30 font20 fontblue_264280"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ЧАСОВОЙ ПОЯС", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld11", timezone, -12, 12); GP.BREAK();
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280 borderradius50");

  } else if (modWR == 0 && portal.uri() == "/update1") {
    GP.HR();
    GP.LABEL("🎶 ПЛЕЕР 🎶", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.BUTTON("btn17", "🎶 ПЛЕЕР ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BUTTON("btn13", "🔇 MUTE ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); add.BREAK();
    GP.BUTTON("btn25", "▶", "backgroundgreen_gradient width100 height30 font20 fontblue_264280"); GP.BUTTON("btn22", "◼", "backgroundgreen_gradient width100 height30 font20 fontblue_264280"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("РЕЖИМ ВОСПРОИЗВЕДЕНИЯ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.LABEL("ОДИН.", "font16 fontred_a5381b"); GP.SWITCH("sw14", PLU); GP.LABEL("ЦИКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ВЫБОР МЕЛОДИИ, ПАПКИ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.BUTTON("btn30", "♪   ➖   🎼", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BUTTON("btn31", "♪   ➕   🎼", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); add.BREAK();
    GP.HR();
    GP.LABEL("ГРОМКОСТЬ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld12", Y, 0, 30); GP.BREAK();
    GP.LABEL("ЭКВАЛАЙЗЕР", "font16 fontgreen_4CAF50"); GP.SELECT("sel58", "NORM,POP,ROCK,JAZZ,CLAS,BASS", EQ); GP.BREAK();
    GP.LABEL("ЦВЕТ ЧАСОВ.............", "font16 fontred_a5381b"); GP.SELECT("selplr", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x45);; GP.BREAK();
    GP.LABEL("ЦВЕТ ПАПКИ / МЕЛ.", "font16 fontred_a5381b"); GP.SELECT("selplr1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x46);; GP.BREAK();
    GP.HR();
    GP.LABEL("🔊 ОЗВУЧИВАНИЕ ВРЕМЕНИ 🔊", "font20 fontcyan_16747a"); GP.BREAK();
    GP.SELECT("selmg", "ЖЕНСКИЙ,МУЖСКОЙ,КУРАНТЫ,ЗУММЕР,КАМИННЫЕ ЧАСЫ", MG); GP.BREAK();
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (modWR == 0 && portal.uri() == "/update2") {
    GP.FORM_BEGIN("/update2");
    GP.HR();
    GP.LABEL("УСТАНОВКИ MQTT", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.TEXT("txt4", "Сервер", server , "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt5", "Порт", port , "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt6", "Имя", USER , "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt7", "Пароль", PASSWORD , "font20 fontyellow_c79536"); GP.BREAK();
    GP.SUBMIT("💾 СОХРАНИТЬ ", "backgroundred_a5381b widthauto height30 font20 fontblue_000000");
    GP.FORM_END();
    GP.HR();
    GP.LABEL("НАСТРОЙКИ MQTT", "font20 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ. MQTT", "font16 fontred_a5381b"); GP.SWITCH("sw2", Serv); GP.LABEL(" ВКЛ. MQTT", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ЦВЕТ MQTT...........", "font16 fontred_a5381b"); GP.SELECT("selmq1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x40);; GP.BREAK();
    GP.LABEL("ЦВЕТ ЧАСОВ.........", "font16 fontred_a5381b"); GP.SELECT("selmq2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x41);; GP.BREAK();
    GP.LABEL("ЦВЕТ СТРОКИ......", "font16 fontred_a5381b"); GP.SELECT("selmq", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x39);; GP.BREAK();
    GP.BUTTON("btnekrm", "MQTT", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update27", "🖨   НАСТРОЙКИ ВЫВОДА", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update25", "💪          НАГРУЗКИ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update3", "📚       ТОПИКИ MQTT", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (portal.uri() == "/update25") {
    GP.FORM_BEGIN("/update25");
    GP.HR();
    GP.LABEL("НАГРУЗКИ MQTT", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("ВЫБОР ТИПА НАГРУЗКИ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel22", "все выкл.,время,влажность,кач.воздуха,все вкл.", MQTR); GP.BREAK();
    GP.HR();
    GP.LABEL("ПАРАМЕТРЫ РЕЛЕ ВРЕМЕНИ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ВКЛ...", "font16 fontred_a5381b"); GP.SELECT("sel60", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", hron); GP.LABEL(" :", "font20 fontred_ffffff"); GP.SELECT("sel61", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", mron); GP.BREAK(); //
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SELECT("sel62", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", hroff); GP.LABEL(" :", "font20 fontred_ffffff"); GP.SELECT("sel63", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", mroff); GP.BREAK(); //
    GP.HR();
    GP.LABEL("ПАРАМЕТР ВЛАЖНОСТИ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel64", "00%,01%,02%,03%,04%,05%,06%,07%,08%,09%,10%,11%,12%,13%,14%,15%,16%,17%,18%,19%,20%,21%,22%,23%,24%,25%,26%,27%,28%,29%,30%,31%,32%,33%,34%,35%,36%,37%,38%,39%,40%,41%,42%,43%,44%,45%,46%,47%,48%,49%,50%,51%,52%,53%,54%,55%,56%,57%,58%,59%,60%,61%,62%,63%", HUM); GP.BREAK();
    GP.HR();
    GP.LABEL("ПАРАМЕТР КАЧ.ВОЗДУХА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel65", "00,50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000", co2); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update2", "  ↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();
  } else if (portal.uri() == "/update27") {
    GP.FORM_BEGIN("/update27");
    GP.HR();
    GP.LABEL("РЕЖИМ ВЫВОДА ИНФОРМАЦИИ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.LABEL("НА ГЛ.ЭКРАН", "font16 fontred_a5381b"); GP.SWITCH("sw3", Modmqtt); GP.LABEL(" НА ЭКРАН MQTT", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ СТРОКИ MQTT НА ГЛ.ЭКРАНЕ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldmqtt", frameDelay5, 1, 20); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ЦВЕТ СТРОКИ MQTT НА ГЛ.ЭКРАНЕ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel16", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x28); GP.BREAK(); //
    GP.BREAK();
    GP.LABEL("КОЛ-ВО ПРОГОНА СТРОК НА ЭКРАНЕ MQTT", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld3", ekrmqtt, 1, 5); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ НА ЭКРАНЕ MQTT", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldekrmqtt", frameDelay4, 1, 20); GP.BREAK();
    GP.HR();
    GP.LABEL("ЦВЕТ ОТПРАВЛЕННОГО ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("С АНДРОИД ПРИЛОЖЕНИЯ MQTT", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("НА ГЛАВНЫЙ ЭКРАН", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel4", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x25); GP.BREAK(); //
    GP.HR();
    GP.BUTTON_LINK("/update2", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();


  } else if (portal.uri() == "/update3") {
    GP.FORM_BEGIN("/update3");
    GP.HR();
    GP.LABEL("ТОПИКИ НА ПЕРЕДАЧУ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.TEXT("txt8", "Температура", PUBLISH_CH, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt9", "Влажность", PUBLISH_CH1, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt10", "Давление", PUBLISH_CH2, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt11", "Реле1", PUBLISH_CH3, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt12", "Реле2", PUBLISH_CH4, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt13", "Реле3", PUBLISH_CH5, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt14", "TVOC", PUBLISH_CH6, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt15", "CO2", PUBLISH_CH7, "font20 fontyellow_c79536"); GP.BREAK();
    GP.HR();
    GP.LABEL("ТОПИКИ НА ПРИЕМ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.TEXT("txt16", "Температура", RECEIVER_CH1, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt17", "Влажность", RECEIVER_CH2, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt18", "Давление", RECEIVER_CH3, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt19", "Текст", RECEIVER_CH4, "font20 fontyellow_c79536"); GP.BREAK();
    GP.SUBMIT("💾 СОХРАНИТЬ ", "backgroundred_a5381b widthauto height30 font20 fontblue_000000");
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/update2", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();

  } else if (modWR == 0 && portal.uri() == "/update4") {
    GP.FORM_BEGIN("/update4");
    GP.TITLE("УСТАНОВКИ НАРОДМОН", "font16 fontcyan_16747a");
    GP.TEXT("txt20", "Uuid", uuid, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt21", "Ключ", api_key, "font20 fontyellow_c79536"); add.BREAK();
    GP.HR();
    GP.LABEL("ДАТЧИКИ НАРОДМОН", "font20 fontcyan_16747a"); GP.BREAK();
    GP.TEXT("txt22", "ID0", ID0, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt23", "ID1", ID1, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt24", "ID2", ID2, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txt25", "ID3", ID3, "font20 fontyellow_c79536"); GP.BREAK();
    GP.SUBMIT("💾 СОХРАНИТЬ ", "backgroundred_a5381b widthauto height30 font20 fontblue_000000");
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (modWR == 0 && portal.uri() == "/update5") {
    GP.FORM_BEGIN("/update5");
    GP.HR();
    GP.LABEL("СООБЩЕНИЕ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("ДО 50-И ЗНАКОМЕСТ !!!", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.TEXT("txt28", "ТЕКСТ", Text, ""); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldsob", frameDelay3, 1, 20); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ЦВЕТ ОТПРАВЛЯЕМОГО ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel6", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x27); GP.BREAK(); //
    GP.BREAK();
    GP.SUBMIT("🖥 ОТПРАВИТЬ ", "backgroundred_a5381b widthauto height30 font20 fontblue_000000");
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (modWR == 0 && portal.uri() == "/update6") {
    GP.FORM_BEGIN("/update6");
    GP.HR();
    GP.LABEL("ГЛАВНЫЙ ЭКРАН", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("ИЗМЕНЕНИЕ ЯРКОСТИ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ЯРКОСТЬ", "font16 fontred_a5381b"); GP.SELECT("selyark", "20%,30%,40%,50%,60%,80%", e); GP.BREAK(); // !!!
    GP.HR();
    GP.LABEL("ИЗМЕНЕНИЕ ШРИФТА", "font16 fontcyan_16747a"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ЧАСЫ:МИН.", "font16 fontyellow_c79536"); GP.SELECT("sel14", "электрон,простой,квадрат,тонкий1,тонкий2,классич,контурный", fch); GP.BREAK(); //
    GP.LABEL("СЕКУНДЫ..", "font16 fontyellow_c79536"); GP.SELECT("sel15", "тонкий1,обычный,футурист1,футурист2,квадрат,тонкий2", fss); GP.BREAK(); //
    GP.HR();
    GP.LABEL("АНИМАЦИЯ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("РАЗДЕЛИТЕЛЬНЫХ ТОЧЕК", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ПО ОЧЕРЕДИ", "font16 fontred_a5381b"); GP.SWITCH("swtoch", modtoch); GP.LABEL(" ВМЕСТЕ", "font16 fontred_a5381b"); GP.BREAK();
    GP.HR();
    GP.LABEL("ИЗМЕНЕНИЕ ЦВЕТА", "font16 fontcyan_16747a"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ЧАСЫ:МИН.", "font16 fontgreen_4CAF50"); GP.SELECT("sel8", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x); GP.BREAK(); //
    GP.LABEL("СЕКУНДЫ...", "font16 fontgreen_4CAF50"); GP.SELECT("sel9", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x1); GP.BREAK(); //
    GP.LABEL("ЧИСЛО.........", "font16 fontgreen_4CAF50"); GP.SELECT("sel10", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x3); GP.BREAK(); //
    GP.LABEL("МЕСЯЦ.........", "font16 fontgreen_4CAF50"); GP.SELECT("sel11", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x4); GP.BREAK(); //
    GP.LABEL("Пн-Пт............", "font16 fontgreen_4CAF50"); GP.SELECT("sel12", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x5); GP.BREAK(); //
    GP.LABEL("Сб-Вс.............", "font16 fontgreen_4CAF50"); GP.SELECT("sel13", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x6); GP.BREAK(); //
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

    // } else if (modWR != 1 && portal.uri() == "/update7") {
    //GP.BODY("backgroundimage10");

  } else if (modWR == 0 && portal.uri() == "/update8") {
    GP.FORM_BEGIN("/update8");
    GP.HR();
    GP.LABEL("БОЛЬШИЕ ЧАСЫ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("АВТОМАТИЧЕСКИ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("sw1", BCH); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel16", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", hbigon); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel17", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", mbigon); GP.BREAK(); //
    GP.LABEL("ВРЕМЯ ВЫКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel18", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", hbigoff); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel19", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", mbigoff); GP.BREAK(); //
    GP.HR();
    GP.LABEL("ПРИНУДИТЕЛЬНО", "font16 fontcyan_16747a"); GP.BREAK();
    GP.BUTTON("btn28", "ВКЛЮЧИТЬ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BUTTON("btn29", "ОТКЛЮЧИТЬ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BREAK(); //
    GP.HR();
    GP.LABEL("ЦВЕТ", "font16 fontred_a5381b"); GP.SELECT("sel20", "красный,зеленый,белый,пурпур,синий,желтый,голубой,розовый", x7); GP.LABEL(" ШРИФТ", "font16 fontred_a5381b"); GP.SELECT("sel21", "0,1,2,3,4,5,6,7,8,9,10,11,12", font); GP.BREAK(); //
    GP.LABEL("ЭФФЕКТЫ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("sw16", effekt); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.HR();
    GP.LABEL("АНАЛОГОВЫЕ ЧАСЫ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.BUTTON("btnaon", "ВКЛЮЧИТЬ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BUTTON("btnaof", "ОТКЛЮЧИТЬ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BREAK(); //

    GP.HR();
    GP.LABEL("🔴🟢🔵 ШАРИКИ 🔵🟢🔴", "font16 fontcyan_16747a"); GP.BREAK();
    GP.BUTTON("btnballon", "ВКЛЮЧИТЬ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BUTTON("btnballof", "ОТКЛЮЧИТЬ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ АНИМАЦИИ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldballef", ballef, 5, 150); GP.BREAK();
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (modWR == 0 && portal.uri() == "/update9") {
    GP.FORM_BEGIN("/update9");
    GP.HR();
    GP.LABEL("ДОП. ЭКРАНЫ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("ПОГОДА", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font20 fontred_a5381b"); GP.SWITCH("sw4", Modekr1); GP.LABEL(" ВКЛ.", "font20 fontred_a5381b"); GP.BREAK();
    GP.LABEL("ЗАДЕРЖКА ЭКРАНА", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld", ekrPog, 40, 100); GP.BREAK();
    GP.LABEL("ЦВЕТ ПОГОДА........", "font16 fontred_a5381b"); GP.SELECT("selp", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x32);; GP.BREAK();
    GP.LABEL("ЦВЕТ ЧАСОВ...........", "font16 fontred_a5381b"); GP.SELECT("selp3", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x35);; GP.BREAK();
    GP.LABEL("ЦВЕТ ДЕНЬ.............", "font16 fontred_a5381b"); GP.SELECT("selp1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x33);; GP.BREAK();
    GP.LABEL("ЦВЕТ ПОКАЗАНИЙ", "font16 fontred_a5381b"); GP.SELECT("selp2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x34);; GP.BREAK();
    GP.HR();
    GP.LABEL("ДОМА", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font20 fontred_a5381b"); GP.SWITCH("sw5", Modekr2); GP.LABEL(" ВКЛ.", "font20 fontred_a5381b"); GP.BREAK();
    GP.LABEL("ЗАДЕРЖКА ЭКРАНА", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld1", ekrDom, 40, 100); GP.BREAK();
    GP.LABEL("ЦВЕТ ДОМА...........", "font16 fontred_a5381b"); GP.SELECT("seld1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x30);; GP.BREAK();
    GP.LABEL("ЦВЕТ ЧАСОВ..........", "font16 fontred_a5381b"); GP.SELECT("seld", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x29);; GP.BREAK();
    GP.LABEL("ЦВЕТ ПОКАЗАНИЙ", "font16 fontred_a5381b"); GP.SELECT("seld2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x31);; GP.BREAK();
    GP.HR();
    GP.LABEL("КАЧЕСТВО ВОЗДУХА", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font20 fontred_a5381b"); GP.SWITCH("sw6", Modekr3); GP.LABEL(" ВКЛ.", "font20 fontred_a5381b"); GP.BREAK();
    GP.LABEL("ЗАДЕРЖКА ЭКРАНА", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld2", ekrKach, 1, 30); GP.BREAK();
    GP.LABEL("ЦВЕТ НАЗВАНИЯ....", "font16 fontred_a5381b"); GP.SELECT("selvoz", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x42);; GP.BREAK();
    GP.LABEL("ЦВЕТ eCO2...............", "font16 fontred_a5381b"); GP.SELECT("selvoz1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x43);; GP.BREAK();
    GP.LABEL("ЦВЕТ TVOC..............", "font16 fontred_a5381b"); GP.SELECT("selvoz2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x44);; GP.BREAK();
    GP.LABEL("ЦВЕТ ПОКАЗАНИЙ.", "font16 fontred_a5381b"); GP.SELECT("selvoz3", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x47);; GP.BREAK();
    GP.HR();
    GP.BUTTON("btnekrd", "ДОМА", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BUTTON("btnekrp", "ПОГОДА", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BREAK();
    GP.BUTTON("btnekrv", "ВОЗДУХ", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BUTTON("btnekrm", "MQTT", "backgroundgreen_gradient width140 height30 font20 fontblue_264280"); GP.BREAK();
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (modWR == 0 && portal.uri() == "/update10") {
    GP.FORM_BEGIN("/update10");
    GP.HR();
    GP.LABEL("ДОМАШНИЕ ДАТЧИКИ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("ВНИМАНИЕ!!! ВЫБИРАТЬ ТОЛЬКО", "font16 fontred_a5381b"); GP.BREAK();
    GP.LABEL("ПОДКЛЮЧЕННЫЕ ДАТЧИКИ", "font16 fontred_a5381b"); GP.BREAK();
    GP.LABEL("BMP180...", "font16 fontcyan_16747a"); GP.LED_GREEN("led3", M4); GP.LABEL("AHTxx..", "font16 fontcyan_16747a"); GP.LED_GREEN("led1", M2); GP.BREAK();
    GP.LABEL("BMP280..", "font16 fontcyan_16747a"); GP.LED_GREEN("led2", M3); GP.LABEL("GY21....", "font16 fontcyan_16747a"); GP.LED_GREEN("led4", M5); GP.BREAK();
    GP.LABEL("BME280..", "font16 fontcyan_16747a"); GP.LED_GREEN("led", M1); GP.LABEL("SGP30..", "font16 fontcyan_16747a"); GP.LED_GREEN("led5", Mod1); GP.BREAK();
    GP.HR();
    GP.LABEL("ТЕМПЕРАТУРЫ", "font20 fontgreen_4CAF50"); GP.SELECT("sel23", "NO,  BME280, AHTxx, BMP280, BMP180, GY21", weti); GP.BREAK(); //
    GP.LABEL("КОРРЕКЦИЯ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld4", CorTemp, -10, 10); GP.BREAK();
    GP.HR();
    GP.LABEL("ВЛАЖНОСТИ....", "font20 fontgreen_4CAF50"); GP.SELECT("sel24", "NO,  BME280, AHTxx, NM, GY21", wety); GP.BREAK(); //
    GP.LABEL("КОРРЕКЦИЯ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld5", CorHum, -10, 10); GP.BREAK();
    GP.HR();
    GP.LABEL("ДАВЛЕНИЯ......", "font20 fontgreen_4CAF50"); GP.SELECT("sel25", "NO,  BME280, WB, BMP280, BMP180", wetu); GP.BREAK(); // посл sel
    GP.LABEL("КОРРЕКЦИЯ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld6", corrPress, -20, 20); GP.BREAK();
    GP.HR();
    GP.LABEL("ДОП. ДАТЧИК DS18B20", "font20 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("sw7", Modsen); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("КОРРЕКЦИЯ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld7", cords18, -10, 10); GP.BREAK();
    GP.LABEL("ЦВЕТ СТРОКИ", "font16 fontred_a5381b"); GP.SELECT("selds", "красный,зеленый,белый,пурпур,синий,желтый,голубой,розовый", x36);; GP.BREAK();
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (modWR == 0 && portal.uri() == "/update11") {
    GP.FORM_BEGIN("/update11");
    GP.HR();
    GP.LABEL("БЕГУЩАЯ СТРОКА", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("СЕГОДНЯ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swgod", Modebst5); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.LABEL("ПРАЗДНИК КАЖДЫЙ ДЕНЬ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swprz", flagpr); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldgod", frameDelay7, 1, 20); GP.BREAK();
    GP.LABEL("ЦВЕТ ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x21); GP.BREAK(); //
    GP.HR();
    GP.LABEL("ПОГОДА", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("sw8", Modebst1); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld8", frameDelay, 1, 20); GP.BREAK();
    GP.LABEL("ЦВЕТ ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x22); GP.BREAK(); //
    GP.HR();
    GP.LABEL("ПРОГНОЗ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("sw9", Modebst2); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld9", frameDelay1, 1, 20); GP.BREAK();
    GP.LABEL("ЦВЕТ ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x23); GP.BREAK(); //
    GP.HR();
    GP.LABEL("НАРОДМОН", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("sw10", Modebst3); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld10", frameDelay2, 1, 20); GP.BREAK();
    GP.LABEL("ЦВЕТ ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel3", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x24); GP.BREAK(); //
    GP.HR();
    GP.LABEL("ДОМАШНИЕ ДАТЧИКИ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swdat", Modebst4); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("slddat", frameDelay6, 1, 20); GP.BREAK();
    GP.LABEL("ЦВЕТ ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("sel5", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x26); GP.BREAK(); //
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (modWR == 0 && portal.uri() == "/update12") {
    GP.FORM_BEGIN("/update12");
    GP.HR();
    GP.LABEL("БУДИЛЬНИКИ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update18", "⏰ БУДИЛЬНИК ВС ", "backgroundred_a5381b width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update19", "⏰ БУДИЛЬНИК ПН ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update20", "⏰ БУДИЛЬНИК ВТ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update21", "⏰ БУДИЛЬНИК СР ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update22", "⏰ БУДИЛЬНИК ЧТ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update23", "⏰ БУДИЛЬНИК ПТ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update24", "⏰ БУДИЛЬНИК СБ ", "backgroundred_a5381b width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (portal.uri() == "/update18") {
    GP.LABEL("Вс.", "font30 fontred_a5381b"); GP.CHECK("ch", Modbyd1); GP.BREAK();
    GP.LABEL("ПОВТОР", "font16 fontred_a5381b"); GP.SELECT("sel26", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20", MPov1);  GP.LABEL(" МЕЛОДИЯ", "font16 fontred_a5381b"); GP.SELECT("sel27", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr", mel1); GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel28", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", Hbyd1); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel29", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", Mbyd1); GP.BREAK(); //
    GP.HR();
    GP.BUTTON("btn22", "◼ ПЛЕЕР СТОП", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update12", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();
  } else if (portal.uri() == "/update19") {
    GP.LABEL("Пн.", "font30 fontblue_264280"); GP.CHECK("ch1", Modbyd2); GP.BREAK();
    GP.LABEL("ПОВТОР", "font16 fontred_a5381b"); GP.SELECT("sel30", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20", MPov2);  GP.LABEL(" МЕЛОДИЯ", "font16 fontred_a5381b"); GP.SELECT("sel31", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr", mel2); GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel32", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", Hbyd2); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel33", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", Mbyd2); GP.BREAK(); //
    GP.HR();
    GP.BUTTON("btn22", "◼ ПЛЕЕР СТОП", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update12", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();
  } else if (portal.uri() == "/update20") {
    GP.LABEL("Вт.", "font30 fontblue_264280"); GP.CHECK("ch2", Modbyd3); GP.BREAK();
    GP.LABEL("ПОВТОР", "font16 fontred_a5381b"); GP.SELECT("sel34", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20", MPov3);  GP.LABEL(" МЕЛОДИЯ", "font16 fontred_a5381b"); GP.SELECT("sel35", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr", mel3); GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel36", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", Hbyd3); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel37", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", Mbyd3); GP.BREAK(); //
    GP.HR();
    GP.BUTTON("btn22", "◼ ПЛЕЕР СТОП", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update12", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();
  } else if (portal.uri() == "/update21") {
    GP.LABEL("Ср.", "font30 fontblue_264280"); GP.CHECK("ch3", Modbyd4); GP.BREAK();
    GP.LABEL("ПОВТОР", "font16 fontred_a5381b"); GP.SELECT("sel38", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20", MPov4);  GP.LABEL(" МЕЛОДИЯ", "font16 fontred_a5381b"); GP.SELECT("sel39", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr", mel4); GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel40", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", Hbyd4); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel41", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", Mbyd4); GP.BREAK(); //
    GP.HR();
    GP.BUTTON("btn22", "◼ ПЛЕЕР СТОП", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BREAK();
    GP.BUTTON_LINK("/update12", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();
  } else if (portal.uri() == "/update22") {
    GP.LABEL("Чт.", "font30 fontblue_264280"); GP.CHECK("ch4", Modbyd5); GP.BREAK();
    GP.LABEL("ПОВТОР", "font16 fontred_a5381b"); GP.SELECT("sel42", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20", MPov5);  GP.LABEL(" МЕЛОДИЯ", "font16 fontred_a5381b"); GP.SELECT("sel43", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr", mel5); GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel44", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", Hbyd5); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel45", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", Mbyd5); GP.BREAK(); //
    GP.HR();
    GP.BUTTON("btn22", "◼ ПЛЕЕР СТОП", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update12", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();
  } else if (portal.uri() == "/update23") {
    GP.LABEL("Пт.", "font30 fontblue_264280"); GP.CHECK("ch5", Modbyd6); GP.BREAK();
    GP.LABEL("ПОВТОР", "font16 fontred_a5381b"); GP.SELECT("sel46", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20", MPov6);  GP.LABEL(" МЕЛОДИЯ", "font16 fontred_a5381b"); GP.SELECT("sel47", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr", mel6); GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel48", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", Hbyd6); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel49", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", Mbyd6); GP.BREAK(); //
    GP.HR();
    GP.BUTTON("btn22", "◼ ПЛЕЕР СТОП", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update12", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();
  } else if (portal.uri() == "/update24") {
    GP.LABEL("Сб.", "font30 fontred_a5381b"); GP.CHECK("ch6", Modbyd7); GP.BREAK();
    GP.LABEL("ПОВТОР", "font16 fontred_a5381b"); GP.SELECT("sel50", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20", MPov7);  GP.LABEL(" МЕЛОДИЯ", "font16 fontred_a5381b"); GP.SELECT("sel51", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr", mel7); GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel52", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", Hbyd7); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel53", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", Mbyd7); GP.BREAK(); //
    GP.HR();
    GP.BUTTON("btn22", "◼ ПЛЕЕР СТОП", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BREAK();
    GP.HR();
    GP.BUTTON_LINK("/update12", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();

  } else if (modWR == 0 && portal.uri() == "/update13") {
    GP.FORM_BEGIN("/update13");
    GP.HR();
    GP.LABEL("НОЧНОЙ РЕЖИМ", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("sw12", MNR); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel54", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", hon); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel55", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", minon); GP.BREAK(); //
    GP.LABEL("ВРЕМЯ ВЫКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("sel56", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", hof); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("sel57", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", minof); GP.BREAK(); //
    GP.HR();
    GP.LABEL("ТИП АНИМАЦИИ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("КВАДРАТ", "font16 fontred_a5381b"); GP.SWITCH("swefCh", modeffeck1); GP.LABEL(" ДИАГОНАЛЬ", "font16 fontred_a5381b"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("СКОРОСТЬ АНИМАЦИИ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldzadef", zadef, 50, 200); GP.BREAK();
    GP.LABEL("ЦВЕТ", "font16 fontred_a5381b"); GP.SELECT("selnr", "красный,зеленый,синий,белый,желтый", x37); GP.BREAK(); //
    add.BUTTON("btn12", "⏰ РЕЖИМ ", "backgroundgreen_gradient widthauto height30 font20 fontblue_264280"); GP.BREAK();
    GP.HR();
    GP.FORM_END();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");

  } else if (portal.uri() == "/update14") {
    St();
    portal.log.println(textNst);
    audio.setVolume(vol);
    GP.HR();
    GP.FORM_BEGIN("/update14");
    GP.LABEL("📻 WEB РАДИО 📻", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.BUTTON("btnpl", "▶", "backgroundgreen_gradient width100 height30 font20 fontblue_264280"); GP.BUTTON("btnst", "◼", "backgroundgreen_gradient width100 height30 font20 fontblue_264280"); GP.BREAK();
    GP.BREAK();
    GP.LABEL("ВЫБОР РАДИОСТАНЦИИ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT1("sel66", Nsst, NEWStation); GP.BREAK(); GP.AREA_LOG(2); GP.BREAK();
    // GP.TEXT1("txtist", "название", textNst, "font20 fontyellow_c79536");
    GP.BREAK();
    GP.LABEL("ГРОМКОСТЬ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sld13", vol, 0, 21); GP.BREAK();
    GP.BUTTON_LINK("/update26", "🔧          НАСТРОЙКИ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.BUTTON_LINK("/update16", "💻            ПОТОКИ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    GP.HR();
    GP.FORM_END();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280");
    // } else if (portal.uri() == "/update30") {
    //GP.FORM_BEGIN("/update30");
    //GP.LABEL("ПРЕДУПРЕЖДЕНИЕ!!!!", "font20 fontcyan_16747a"); GP.BREAK();
    // GP.LABEL("НЕДОПУСТИМОЕ ДЕЙСТВИЕ!!!", "font16 fontcyan_16747a"); GP.BREAK();
    // GP.LABEL("ВЕРНИТЕСЬ НАЗАД.", "font16 fontcyan_16747a"); GP.BREAK();
    //GP.BUTTON_LINK("/update14", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280");GP.BREAK();

  } else if (portal.uri() == "/update26") {
    GP.FORM_BEGIN("/update26");
    GP.LABEL("🔧НАСТРОЙКИ🔧", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.LABEL("АВТОМАТИЧЕСКИ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swWR", WEBR); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.LABEL("ВРЕМЯ ВКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("selhwebon", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", hwebon); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("selmwebon", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", mwebon); GP.BREAK(); //
    GP.LABEL("ВРЕМЯ ВЫКЛЮЧЕНИЯ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ЧАСЫ", "font16 fontred_a5381b"); GP.SELECT("selhweboff", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23", hweboff); GP.LABEL(" МИНУТЫ", "font16 fontred_a5381b"); GP.SELECT("selmweboff", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59", mweboff); GP.BREAK(); //
    GP.LABEL("ВКЛЮЧЕНИЕ ИНФО СТРОКИ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swwebr", Modewebr); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    GP.LABEL("ЦВЕТ ИНФО СТРОКИ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("selwr", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", x48); GP.BREAK(); //
    GP.LABEL("Скорость", "font16 fontred_a5381b"); GP.BREAK();
    GP.SLIDER("sldwr", frameDelay10, 4, 30); GP.BREAK();
    GP.BREAK();
    //GP.LABEL("ПРИ ПРОСЛУШИВАНИИ РАДИОСТАНЦИИ", "font16 fontred_a5381b"); GP.BREAK();
    //GP.LABEL("ИЗМЕНЕНИЕ НАСТРОЕК НЕ ВОЗМОЖНО!!!", "font16 fontred_a5381b"); GP.BREAK();
    GP.HR();
    GP.FORM_END();
    GP.BUTTON_LINK("/update14", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();

  } else if (modWR == 0 && portal.uri() == "/update16") {
    GP.FORM_BEGIN("/update16");
    GP.HR();
    GP.LABEL("💻ПОТОКИ💻", "font20 fontcyan_16747a"); GP.BREAK();
    GP.HR();
    GP.TEXT("txtnst1", "название1", nStation, "font20 fontyellow_c79536"); GP.TEXT("txtst1", "Станция1", listStation, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst2", "название2", nStation1, "font20 fontyellow_c79536"); GP.TEXT("txtst2", "Станция2", listStation1, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst3", "название3", nStation2, "font20 fontyellow_c79536"); GP.TEXT("txtst3", "Станция3", listStation2, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst4", "название4", nStation3, "font20 fontyellow_c79536"); GP.TEXT("txtst4", "Станция4", listStation3, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst5", "название5", nStation4, "font20 fontyellow_c79536"); GP.TEXT("txtst5", "Станция5", listStation4, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst6", "название6", nStation5, "font20 fontyellow_c79536"); GP.TEXT("txtst6", "Станция6", listStation5, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst7", "название7", nStation6, "font20 fontyellow_c79536"); GP.TEXT("txtst7", "Станция7", listStation6, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst8", "название8", nStation7, "font20 fontyellow_c79536"); GP.TEXT("txtst8", "Станция8", listStation7, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst9", "название9", nStation8, "font20 fontyellow_c79536"); GP.TEXT("txtst9", "Станция9", listStation8, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst10", "название10", nStation9, "font20 fontyellow_c79536"); GP.TEXT("txtst10", "Станция10", listStation9, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst11", "название11", nStation10, "font20 fontyellow_c79536"); GP.TEXT("txtst11", "Станция11", listStation10, "font20 fontyellow_c79536"); GP.BREAK();
    GP.TEXT("txtnst12", "название12", nStation11, "font20 fontyellow_c79536"); GP.TEXT("txtst12", "Станция12", listStation11, "font20 fontyellow_c79536"); GP.BREAK();
    GP.SUBMIT("💾 СОХРАНИТЬ ", "backgroundred_a5381b widthauto height30 font20 fontblue_000000");
    GP.HR();
    GP.BUTTON_LINK("/update14", "↩  НАЗАД", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BUTTON_LINK("/", "      МЕНЮ", "backgroundyellow_c79536 width100 height30 font16 fontblue_264280"); GP.BREAK();

  } else if (modWR == 0 && portal.uri() == "/update15") {
    GP.HR();
    GP.LABEL("🌏 НОВОСТИ 🌏", "font20 fontcyan_16747a");
    GP.HR();
    GP.FORM_BEGIN("/update15");
    GP.TEXT("txtnews", "Ключ API", myApiKey , "font20 fontyellow_c79536"); GP.BREAK();
    GP.LABEL("КЛЮЧ БРАТЬ ЗДЕСЬ - https://newsapi.org/s/russia-news-api", "font8 fontred_a5381b"); GP.BREAK();
    GP.SUBMIT("💾 СОХРАНИТЬ ", "backgroundred_a5381b widthauto height30 font20 fontblue_000000");
    GP.HR();
    GP.LABEL("НОВОСТИ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swnews", Modenews); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    add.BREAK();
    GP.LABEL("ВЫБОР КАТЕГОРИИ", "font16 fontgreen_4CAF50"); GP.SELECT("selns", "РАЗВЛЕЧЕНИЯ,ЗДОРОВЬЕ,СЦЕНА,СПОРТ,ТЕХНОЛОГИИ,БИЗНЕСС", myS); GP.BREAK();
    GP.HR();
    //GP.LABEL("ВИД НОВОСТЕЙ", "font16 fontcyan_16747a"); GP.BREAK();
    //GP.LABEL("АНОНС", "font16 fontred_a5381b"); GP.SWITCH("swnewspod", Modenewspod); GP.LABEL(" ПОДРОБНО", "font16 fontred_a5381b"); GP.BREAK();
    add.BREAK();
    GP.LABEL("СКОРОСТЬ АНОНСА", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldnews", frameDelay8, 1, 20); GP.BREAK();
    //GP.LABEL("СКОРОСТЬ ПОДРОБНО", "font16 fontyellow_c79536"); GP.BREAK();
    //GP.SLIDER("sldnewspod", frameDelay9, 1, 20); GP.BREAK();
    GP.LABEL("ЦВЕТ ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("selnews", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", xnews); GP.BREAK();
    GP.HR();
    GP.LABEL("АФОРИЗМЫ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swchut", chut); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    add.BREAK();
    GP.LABEL("СКОРОСТЬ АФОРИЗМ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldchut", frameDelay11, 1, 20); GP.BREAK();
    GP.LABEL("ЦВЕТ ТЕКСТА", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("selchut", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", xchut); GP.BREAK();
    GP.HR();
    GP.LABEL("КУРСЫ ВАЛЮТ", "font16 fontcyan_16747a"); GP.BREAK();
    GP.LABEL("ВЫКЛ.", "font16 fontred_a5381b"); GP.SWITCH("swvalu", valu); GP.LABEL(" ВКЛ.", "font16 fontred_a5381b"); GP.BREAK();
    add.BREAK();
    GP.LABEL("СКОРОСТЬ КУРСЫ ВАЛЮТ", "font16 fontyellow_c79536"); GP.BREAK();
    GP.SLIDER("sldvalu", frameDelay12, 1, 20); GP.BREAK();
    GP.LABEL("ЦВЕТ СТРОКИ", "font16 fontgreen_4CAF50"); GP.BREAK();
    GP.SELECT("selvalu", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый", xvalu); GP.BREAK();
    GP.FORM_END();
    GP.HR();
    GP.BUTTON_LINK("/", "МЕНЮ", "backgroundyellow_c79536 width60 height30 font20 fontblue_264280 borderradius50");



  } else {
    GP.HR();
    GP.BUTTON_LINK("/update14", "📻 WEB РАДИО ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    if (modWR == 0) {
      GP.BUTTON_LINK("/update1", "🎸 ПЛЕЕР   🔊 ОЗВУЧКА ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update5", "📝 СООБЩЕНИЕ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update6", "🔅 ГЛАВНЫЙ ЭКРАН ✒🌈 ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update", "🧭 МЕСТОПОЛОЖЕНИЕ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update2", "📑 MQTT ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      // GP.BUTTON_LINK("/update3", "📚 ТОПИКИ MQTT ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update4", "👬 НАРОДМОН ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update10", "🌡 ДАТЧИКИ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update8", "🕰 БОЛЬШИЕ ЧАСЫ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update9", "🖥 ДОП. ЭКРАНЫ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update11", "📖 БЕГУЩАЯ СТРОКА ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update13", "🌃 НОЧНОЙ РЕЖИМ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update12", "⏰ БУДИЛЬНИКИ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update15", "🌏 НОВОСТИ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      //GP.BUTTON_LINK("/update16", "💻 ПЛЕЙЛИСТ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();

    } else {
      GP.BUTTON_LINK("/update14", "🎸 ПЛЕЕР   🔊 ОЗВУЧКА ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "📝 СООБЩЕНИЕ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "🔅 ГЛАВНЫЙ ЭКРАН ✒🌈 ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "🧭 МЕСТОПОЛОЖЕНИЕ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "📑 MQTT  ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      //GP.BUTTON_LINK("/update14", "📚 ТОПИКИ MQTT ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "👬 НАРОДМОН ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "🌡 ДАТЧИКИ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "🕰 БОЛЬШИЕ ЧАСЫ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "🖥 ДОП. ЭКРАНЫ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "📖 БЕГУЩАЯ СТРОКА ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "🌃 НОЧНОЙ РЕЖИМ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "⏰ БУДИЛЬНИКИ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      GP.BUTTON_LINK("/update14", "🌏 НОВОСТИ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
      //GP.BUTTON_LINK("/update14", "💻 ПЛЕЙЛИСТ ", "backgroundyellow_c79536 width350 height30 font20 fontred_a5381b"); GP.BREAK();
    }
    GP.HR();
    GP.LABEL("Медленно", "font16 fontcyan_16747a"); GP.SWITCH("sw", bz); GP.LABEL("Быстро", "font16 fontcyan_16747a"); GP.BUTTON("btn27", "↺ RESET", "backgroundred_a5381b widthauto height30 font20 fontblue_000000 borderradius50"); add.BREAK();
    GP.LABEL("Нет comport вывод", "font16 fontcyan_16747a"); GP.SWITCH("swcom", printCom); GP.LABEL("Есть comport вывод", "font16 fontcyan_16747a"); add.BREAK();
    GP.BUTTON("btn22", "◼ ПЛЕЕР СТОП", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BUTTON("btnst", "СТОП WEBRADIO", "backgroundgreen_gradient widthauto height30 font16 fontblue_000000 borderradius50"); GP.BREAK(); GP.BREAK();
    GP.LABEL("ver.⓼⓸_biz", "font16 fontred_a5381b"); GP.BREAK();//⓵⓶⓷⓸⓹⓺⓻⓼⓽⓾
  }

  BUILD_END();
}
