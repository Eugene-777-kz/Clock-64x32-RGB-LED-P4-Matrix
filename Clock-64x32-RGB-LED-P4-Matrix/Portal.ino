void Portal()
{
  portal.tick();
  if (portal.form("/update")) {
    loadConfig();
    gorod = portal.getString("txt");
    lat = portal.getString("txt1");
    lon = portal.getString("txt2");
    weatherKey0 = portal.getString("txt3");
    saveConfig();
    if (kch == true) {
      switch (POG) {
        case 0: getWeatherData0(); getWeatherDataz0(); break;
        case 1: WetMap(); break;
        case 2: Meteo(); break;
      }
    }
  }

  if (portal.form("/update2")) {
    loadConfig();
    server = portal.getString("txt4");
    port = portal.getString("txt5");
    USER = portal.getString("txt6");
    PASSWORD = portal.getString("txt7");
    server.toCharArray(mqtt_server, 32);
    int mqtt_port = port.toInt();
    USER.toCharArray(MQTT_USER, 25);
    PASSWORD.toCharArray(MQTT_PASSWORD, 25);
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
    saveConfig();
  }
  if (portal.form("/update16")) {
    loadConfig();
    listStation = portal.getString("txtst1");
    listStation1 = portal.getString("txtst2");
    listStation2 = portal.getString("txtst3");
    listStation3 = portal.getString("txtst4");
    listStation4 = portal.getString("txtst5");
    listStation5 = portal.getString("txtst6");
    listStation6 = portal.getString("txtst7");
    listStation7 = portal.getString("txtst8");
    listStation8 = portal.getString("txtst9");
    listStation9 = portal.getString("txtst10");
    listStation10 = portal.getString("txtst11");
    listStation11 = portal.getString("txtst12");
    nStation = portal.getString("txtnst1");
    nStation1 = portal.getString("txtnst2");
    nStation2 = portal.getString("txtnst3");
    nStation3 = portal.getString("txtnst4");
    nStation4 = portal.getString("txtnst5");
    nStation5 = portal.getString("txtnst6");
    nStation6 = portal.getString("txtnst7");
    nStation7 = portal.getString("txtnst8");
    nStation8 = portal.getString("txtnst9");
    nStation9 = portal.getString("txtnst10");
    nStation10 = portal.getString("txtnst11");
    nStation11 = portal.getString("txtnst12");
    saveConfig();
  }
  if (portal.form("/update3")) {
    loadConfig();
    PUBLISH_CH = portal.getString("txt8");
    PUBLISH_CH1 = portal.getString("txt9");
    PUBLISH_CH2 = portal.getString("txt10");
    PUBLISH_CH3 = portal.getString("txt11");
    PUBLISH_CH4 = portal.getString("txt12");
    PUBLISH_CH5 = portal.getString("txt13");
    PUBLISH_CH6 = portal.getString("txt14");
    PUBLISH_CH7 = portal.getString("txt15");
    RECEIVER_CH1 = portal.getString("txt16");
    RECEIVER_CH2 = portal.getString("txt17");
    RECEIVER_CH3 = portal.getString("txt18");
    RECEIVER_CH4 = portal.getString("txt19");
    PUBLISH_CH.toCharArray(MQTT_SERIAL_PUBLISH_CH, 32);
    PUBLISH_CH1.toCharArray(MQTT_SERIAL_PUBLISH_CH1, 32);
    PUBLISH_CH2.toCharArray(MQTT_SERIAL_PUBLISH_CH2, 32);
    PUBLISH_CH3.toCharArray(MQTT_SERIAL_PUBLISH_CH3, 32);
    PUBLISH_CH4.toCharArray(MQTT_SERIAL_PUBLISH_CH4, 32);
    PUBLISH_CH5.toCharArray(MQTT_SERIAL_PUBLISH_CH5, 32);
    PUBLISH_CH6.toCharArray(MQTT_SERIAL_PUBLISH_CH6, 32);
    PUBLISH_CH7.toCharArray(MQTT_SERIAL_PUBLISH_CH7, 32);
    RECEIVER_CH1.toCharArray(MQTT_SERIAL_RECEIVER_CH1, 32);
    RECEIVER_CH2.toCharArray(MQTT_SERIAL_RECEIVER_CH2, 32);
    RECEIVER_CH3.toCharArray(MQTT_SERIAL_RECEIVER_CH3, 32);
    RECEIVER_CH4.toCharArray(MQTT_SERIAL_RECEIVER_CH4, 32);
    saveConfig();
  }
  if (portal.form("/update4")) {
    loadConfig();
    uuid = portal.getString("txt20");
    api_key = portal.getString("txt21");
    ID0 = portal.getString("txt22");
    ID1 = portal.getString("txt23");
    ID2 = portal.getString("txt24");
    ID3 = portal.getString("txt25");
    int sensors_ID0 = ID0.toInt();
    int sensors_ID1 = ID1.toInt();
    int sensors_ID2 = ID2.toInt();
    int sensors_ID3 = ID3.toInt();
    saveConfig();
    getNarodmon();
  }
  if (portal.form("/update5")) {
    loadConfig();
    Text = portal.getString("txt28");
    saveConfig();
  }
  if (portal.form("/update15")) {
    loadConfig();
    myApiKey = portal.getString("txtnews");
    saveConfig();
    News();
    Val();
  }
  port1();
}
void port1()
{
  if (portal.click()) {
    loadConfig();
    if (ModWEBR == 0 && BCH == false && FlagNr != 1 && modAnclock == false && Ball != 1 && portal.click("btnpl")) {
      St();
      portal.log.println(textNst);
      ModWEBR = 2;
      modWR = 1;
    }
    if (portal.click("selhwebon")) {
      hwebon = portal.getSelected("selhwebon", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
      getPilik();
    }
    if (portal.click("selmwebon")) {
      mwebon = portal.getSelected("selmwebon", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
      getPilik();
    }
    if (portal.click("selhweboff")) {
      hweboff = portal.getSelected("selhweboff", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
      getPilik();
    }
    if (portal.click("selmweboff")) {
      mweboff = portal.getSelected("selmweboff", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
      getPilik();
    }
    if (portal.click("swWR")) {
      WEBR = portal.getCheck("swWR");
    }
    if (ModWEBR == 0 && portal.click("sel66")) {
      NEWStation = portal.getSelected("sel66", Nsst);
      St();
      portal.log.println(textNst);
    }
    if (ModWEBR == 0 &&  portal.click("sld13")) {
      vol = portal.getInt("sld13");
      //audio.setVolume(vol);
      St();
    }
    if (ModWEBR == 2 && modWR == 1 && portal.click("btnst")) {
      audio.stopSong();
      modWR = 0;
      ModWEBR = 0;
      if (Y == 0)Y = W;
    }
    if (ModWEBR == 2 && modWR == 1 && portal.click("sel66")) {
      NEWStation = portal.getSelected("sel66", Nsst);
      St();
      portal.log.println(textNst);
    }
    if (ModWEBR == 2 && modWR == 1 && portal.click("sld13")) {
      vol = portal.getInt("sld13");
      //audio.setVolume(vol);
      St();
    }

    if (portal.click("sw1")) {
      BCH = portal.getCheck("sw1");
    }
    if (ModWEBR != 2 && modWR != 1 && portal.click("btn22")) {
      Serial.println("стоп");
      matrix.fillRect(0, 0, 64, 32 , myBLACK);
      dfPlayer.disableLoop();
      getPilik();
      getRTCh(szTime);
      getRTCm(szTime);
      getKey();
    }
    if (portal.click("btn28")) {
      Serial.println("BIG");
      if (modBig == 0) {
        modBig = 1;
        BCH = true;
        saveConfig();
        getPilik();
        getBigTime();
      }
    }
    if (portal.click("btn29")) {
      Serial.println("BIG");
      if (modBig == 1) {
        modBig = 0;
        BCH = false;
        saveConfig();
        getPilik();
        ModKey = 0;
        matrix.fillRect(0, 0, 64, 32 , myBLACK);
        delay(100);
        matrix.setFont();
        getRTCh(szTime);
        getRTCm(szTime);
      }
    }
    if (portal.click("btnaon")) {
      Serial.println("ANG");
      if (modAnclock == false) {
        modAnclock = true;
        getPilik();
        analogclock();
      }
    }
    if (portal.click("btnaof")) {
      Serial.println("ANG");
      if (modAnclock == true) {
        modAnclock = false;
        getPilik();
      }
    }
    if (portal.click("btnballon")) {
      Serial.println("BAL1");
      if (Ball == 0) {
        getPilik();
        Ball = 1;
        ball();
      }
    }
    if (portal.click("btnballof")) {
      Serial.println("BAL2");
      if (Ball == 1) {
        getPilik();
        Ball = 0;
      }
    }
    if (ModKey == 0 && portal.click("btn17")) {
      ModKey = 3;
      zaderg = 0;
      getPleer();
    }
    if (portal.click("btn27"))ESP.restart();
    if (portal.click("swcom")) {
      printCom = portal.getCheck("swcom");
    }
    if (portal.click("sw")) {
      bz = portal.getCheck("sw");
    }
    if (portal.click("sw2")) {
      Serv = portal.getCheck("sw2");
    }
    if (portal.click("sw3")) {
      Modmqtt = portal.getCheck("sw3");
    }
    if (portal.click("sw4")) {
      Modekr1 = portal.getCheck("sw4");
    }
    if (portal.click("sw5")) {
      Modekr2 = portal.getCheck("sw5");
    }
    if (portal.click("sw6")) {
      Modekr3 = portal.getCheck("sw6");
    }
    if (portal.click("swtoch")) {
      modtoch = portal.getCheck("swtoch");
    }
    if (portal.click("sel8")) {
      x = portal.getSelected("sel8", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
      if (flagrtc == 0)updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (portal.click("sel9")) {
      x1 = portal.getSelected("sel9", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
      if (flagrtc == 0)updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (portal.click("sel10")) {
      x3 = portal.getSelected("sel10", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
      if (flagrtc == 0)updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (portal.click("sel11")) {
      x4 = portal.getSelected("sel11", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
      if (flagrtc == 0)updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (portal.click("sel12")) {
      x5 = portal.getSelected("sel12", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
      if (flagrtc == 0)updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (portal.click("sel13")) {
      x6 = portal.getSelected("sel13", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
      if (flagrtc == 0)updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (portal.click("sel")) {
      x21 = portal.getSelected("sel", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel1")) {
      x22 = portal.getSelected("sel1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel2")) {
      x23 = portal.getSelected("sel2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel3")) {
      x24 = portal.getSelected("sel3", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel4")) {
      x25 = portal.getSelected("sel4", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel5")) {
      x26 = portal.getSelected("sel5", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel6")) {
      x27 = portal.getSelected("sel6", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel16")) {
      x28 = portal.getSelected("sel16", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("seld")) {
      x29 = portal.getSelected("seld", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("seld1")) {
      x30 = portal.getSelected("seld1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("seld2")) {
      x31 = portal.getSelected("seld2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selp")) {
      x32 = portal.getSelected("selp", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selp1")) {
      x33 = portal.getSelected("selp1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selp2")) {
      x34 = portal.getSelected("selp2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selp3")) {
      x35 = portal.getSelected("selp3", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selds")) {
      x36 = portal.getSelected("selds", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel14")) {
      fch = portal.getSelected("sel14", "электрон,простой,квадрат,тонкий1,тонкий2,классич,контурный");
      updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (portal.click("sel15")) {
      fss = portal.getSelected("sel15", "тонкий1,обычный,футурист1,футурист2,квадрат,тонкий2");
      updateTime();
    }
    if (portal.click("sel20")) {
      x7 = portal.getSelected("sel20", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selnr")) {
      x37 = portal.getSelected("selnr", "красный,зеленый,синий,белый,желтый");
    }
    if (portal.click("selnews")) {
      xnews = portal.getSelected("selnews", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selmq")) {
      x39 = portal.getSelected("selmq", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selmq1")) {
      x40 = portal.getSelected("selmq1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selmq2")) {
      x41 = portal.getSelected("selmq2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selvoz")) {
      x42 = portal.getSelected("selvoz", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selvoz1")) {
      x43 = portal.getSelected("selvoz1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selvoz2")) {
      x44 = portal.getSelected("selvoz2", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selvoz3")) {
      x47 = portal.getSelected("selvoz3", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selplr")) {
      x45 = portal.getSelected("selplr", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selplr1")) {
      x46 = portal.getSelected("selplr1", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selwr")) {
      x48 = portal.getSelected("selwr", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selchut")) {
      xchut = portal.getSelected("selchut", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("selvalu")) {
      xvalu = portal.getSelected("selvalu", "красный,зеленый,белый,пурпур,синий,желтый,голубой,фиолет,розовый,оранжевый");
    }
    if (portal.click("sel21")) {
      font = portal.getSelected("sel21", "0,1,2,3,4,5,6,7,8,9,10,11,12");
    }
    if (portal.click("sel16")) {
      hbigon = portal.getSelected("sel16", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
      getPilik();
    }
    if (portal.click("sel17")) {
      mbigon = portal.getSelected("sel17", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
      getPilik();
    }
    if (portal.click("sel18")) {
      hbigoff = portal.getSelected("sel18", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
      getPilik();
    }
    if (portal.click("sel19")) {
      mbigoff = portal.getSelected("sel19", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
      getPilik();
    }
    if (portal.click("sel22")) {
      MQTR = portal.getSelected("sel22", "все выкл.,время,влажность,кач.воздуха,все вкл.");
      Serial.println(MQTR);
    }
    if (portal.click("sld")) {
      ekrPog = portal.getInt("sld");
    }
    if (portal.click("sld1")) {
      ekrDom = portal.getInt("sld1");
    }
    if (portal.click("sld2")) {
      ekrKach = portal.getInt("sld2");
    }
    if (portal.click("sld3")) {
      ekrmqtt = portal.getInt("sld3");
    }
    if (portal.click("selpog")) {
      POG = portal.getSelected("selpog", "WEATHERBIT,WEATHERMAP,METEO");
    }
    if (portal.click("sel23")) {
      weti = portal.getSelected("sel23", "NO,  BME280, AHTxx, BMP280, BMP180, GY21");
    }
    if (portal.click("sel24")) {
      wety = portal.getSelected("sel24", "NO,  BME280, AHTxx, NM, GY21");
    }
    if (portal.click("sel25")) {
      wetu = portal.getSelected("sel25", "NO,  BME280, WB, BMP280, BMP180");
    }

    if (portal.click("sw7")) {
      Modsen = portal.getCheck("sw7");
      getPilik();
    }
    if (portal.click("sld4")) {
      CorTemp = portal.getInt("sld4");
    }
    if (portal.click("sld5")) {
      CorHum = portal.getInt("sld5");
    }
    if (portal.click("sld6")) {
      corrPress = portal.getInt("sld6");
    }
    if (portal.click("sld7")) {
      cords18 = portal.getInt("sld7");
    }
    if (portal.click("sw8")) {
      Modebst1 = portal.getCheck("sw8");
    }
    if (portal.click("sw9")) {
      Modebst2 = portal.getCheck("sw9");
    }
    if (portal.click("sw10")) {
      Modebst3 = portal.getCheck("sw10");
    }
    if (portal.click("swdat")) {
      Modebst4 = portal.getCheck("swdat");
    }
    if (portal.click("swgod")) {
      Modebst5 = portal.getCheck("swgod");
    }
    if (portal.click("swnews")) {
      Modenews = portal.getCheck("swnews");
    }
    if (portal.click("swwebr")) {
      Modewebr = portal.getCheck("swwebr");
    }
    if (portal.click("swprz")) {
      flagpr = portal.getCheck("swprz");
      if (flagpr == true) {
        switch (month) {
          case 0: loadPrazdnik1(); break;
          case 1: loadPrazdnik2(); break;
          case 2: loadPrazdnik3(); break;
          case 3: loadPrazdnik4(); break;
          case 4: loadPrazdnik5(); break;
          case 5: loadPrazdnik6(); break;
          case 6: loadPrazdnik7(); break;
          case 7: loadPrazdnik8(); break;
          case 8: loadPrazdnik9(); break;
          case 9: loadPrazdnik10(); break;
          case 10: loadPrazdnik11(); break;
          case 11: loadPrazdnik12(); break;
        }
      }
    }
    if (portal.click("swkch")) {
      kch = portal.getCheck("swkch");
    }
    if (portal.click("swchut")) {
      chut = portal.getCheck("swchut");
      if (chut == true)Anek();
    }
    if (portal.click("swvalu")) {
      valu = portal.getCheck("swvalu");
      if (valu == true) Val();
    }
    if (portal.click("swnewspod")) {
      Modenewspod = portal.getCheck("swnewspod");
    }
    if (portal.click("swefCh")) {
      modeffeck1 = portal.getCheck("swefCh");
      xef = 0;
      yef = 8;
    }
    if (portal.click("sld8")) {
      frameDelay = portal.getInt("sld8");
    }
    if (portal.click("sld9")) {
      frameDelay1 = portal.getInt("sld9");
    }
    if (portal.click("sld10")) {
      frameDelay2 = portal.getInt("sld10");
    }
    if (portal.click("sldmqtt")) {
      frameDelay5 = portal.getInt("sldmqtt");
    }
    if (portal.click("sldekrmqtt")) {
      frameDelay4 = portal.getInt("sldekrmqtt");
    }
    if (portal.click("sldsob")) {
      frameDelay3 = portal.getInt("sldsob");
    }
    if (portal.click("slddat")) {
      frameDelay6 = portal.getInt("slddat");
    }
    if (portal.click("sldgod")) {
      frameDelay7 = portal.getInt("sldgod");
    }
    if (portal.click("sldnews")) {
      frameDelay8 = portal.getInt("sldnews");
    }
    if (portal.click("sldnewspod")) {
      frameDelay9 = portal.getInt("sldnewspod");
    }
    if (portal.click("sldwr")) {
      frameDelay10 = portal.getInt("sldwr");
    }
    if (portal.click("sldchut")) {
      frameDelay11 = portal.getInt("sldchut");
    }
    if (portal.click("sldvalu")) {
      frameDelay12 = portal.getInt("sldvalu");
    }
    if (portal.click("sld11")) {
      timezone = portal.getInt("sld11");
      getTime();
      updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }
    if (portal.click("sldzadef")) {
      zadef = portal.getInt("sldzadef");
    }
    if (portal.click("sldballef")) {
      ballef = portal.getInt("sldballef");
    }
    if (portal.click("ch")) {
      Modbyd1 = portal.getCheck("ch");
    }
    if (portal.click("ch1")) {
      Modbyd2 = portal.getCheck("ch1");
    }
    if (portal.click("ch2")) {
      Modbyd3 = portal.getCheck("ch2");
    }
    if (portal.click("ch3")) {
      Modbyd4 = portal.getCheck("ch3");
    }
    if (portal.click("ch4")) {
      Modbyd5 = portal.getCheck("ch4");
    }
    if (portal.click("ch5")) {
      Modbyd6 = portal.getCheck("ch5");
    }
    if (portal.click("ch6")) {
      Modbyd7 = portal.getCheck("ch6");
    }

    if (portal.click("sel26")) {
      MPov1 = portal.getSelected("sel26", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20");
      if (MPov1 == 0) {
        Pov1 = 0;
      } else {
        Pov1 = 1;
      }
    }
    if (portal.click("sel27")) {
      mel1 = portal.getSelected("sel27", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr");
      if (mel1 == 21) {
        dfPlayer.playFolder(1, 52);
      } else {
        dfPlayer.playFolder(1, mel1);
      }
    }
    if (portal.click("sel28")) {
      Hbyd1 = portal.getSelected("sel28", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel29")) {
      Mbyd1 = portal.getSelected("sel29", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }

    if (portal.click("sel30")) {
      MPov2 = portal.getSelected("sel30", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20");
      if (MPov1 == 0) {
        Pov1 = 0;
      } else {
        Pov1 = 1;
      }
    }
    if (portal.click("sel31")) {
      mel2 = portal.getSelected("sel31", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr");
      if (mel2 == 21) {
        dfPlayer.playFolder(1, 52);
      } else {
        dfPlayer.playFolder(1, mel2);
      }
    }
    if (portal.click("sel32")) {
      Hbyd2 = portal.getSelected("sel32", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel33")) {
      Mbyd2 = portal.getSelected("sel33", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }

    if (portal.click("sel34")) {
      MPov3 = portal.getSelected("sel34", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20");
      if (MPov3 == 0) {
        Pov3 = 0;
      } else {
        Pov3 = 1;
      }
    }
    if (portal.click("sel35")) {
      mel3 = portal.getSelected("sel35", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr");
      if (mel3 == 21) {
        dfPlayer.playFolder(1, 52);
      } else {
        dfPlayer.playFolder(1, mel3);
      }
    }
    if (portal.click("sel36")) {
      Hbyd3 = portal.getSelected("sel36", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel37")) {
      Mbyd3 = portal.getSelected("sel37", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }

    if (portal.click("sel38")) {
      MPov4 = portal.getSelected("sel38", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20");
      if (MPov4 == 0) {
        Pov4 = 0;
      } else {
        Pov4 = 1;
      }
    }
    if (portal.click("sel39")) {
      mel4 = portal.getSelected("sel39", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr");
      if (mel4 == 21) {
        dfPlayer.playFolder(1, 52);
      } else {
        dfPlayer.playFolder(1, mel4);
      }
    }
    if (portal.click("sel40")) {
      Hbyd4 = portal.getSelected("sel40", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel41")) {
      Mbyd4 = portal.getSelected("sel41", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }

    if (portal.click("sel42")) {
      MPov5 = portal.getSelected("sel42", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20");
      if (MPov5 == 0) {
        Pov5 = 0;
      } else {
        Pov5 = 1;
      }
    }
    if (portal.click("sel43")) {
      mel5 = portal.getSelected("sel43", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr");
      if (mel5 == 21) {
        dfPlayer.playFolder(1, 52);
      } else {
        dfPlayer.playFolder(1, mel5);
      }
    }
    if (portal.click("sel44")) {
      Hbyd5 = portal.getSelected("sel44", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel45")) {
      Mbyd5 = portal.getSelected("sel45", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }

    if (portal.click("sel46")) {
      MPov6 = portal.getSelected("sel46", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20");
      if (MPov6 == 0) {
        Pov6 = 0;
      } else {
        Pov6 = 1;
      }
    }
    if (portal.click("sel47")) {
      mel6 = portal.getSelected("sel47", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr");
      if (mel6 == 21) {
        dfPlayer.playFolder(1, 52);
      } else {
        dfPlayer.playFolder(1, mel6);
      }
    }
    if (portal.click("sel48")) {
      Hbyd6 = portal.getSelected("sel48", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel49")) {
      Mbyd6 = portal.getSelected("sel49", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }

    if (portal.click("sel50")) {
      MPov7 = portal.getSelected("sel50", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20");
      if (MPov7 == 0) {
        Pov7 = 0;
      } else {
        Pov7 = 1;
      }
    }
    if (portal.click("sel51")) {
      mel7 = portal.getSelected("sel51", "нет,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,wr");
      if (mel7 == 21) {
        dfPlayer.playFolder(1, 52);
      } else {
        dfPlayer.playFolder(1, mel7);
      }
    }
    if (portal.click("sel52")) {
      Hbyd7 = portal.getSelected("sel52", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel53")) {
      Mbyd7 = portal.getSelected("sel53", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }

    if (portal.click("sw12")) {
      MNR = portal.getCheck("sw12");
      if (MNR == true) {
        Y = 0;
      } else {
        Y = W;
        getPilik();
      }
    }
    if (portal.click("sel54")) {
      hon = portal.getSelected("sel54", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel55")) {
      minon = portal.getSelected("sel55", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }
    if (portal.click("sel56")) {
      hof = portal.getSelected("sel56", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel57")) {
      minof = portal.getSelected("sel57", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }

    if (portal.click("selmg")) {
      MG = portal.getSelected("selmg", "ЖЕНСКИЙ,МУЖСКОЙ,КУРАНТЫ,ЗУММЕР,КАМИННЫЕ ЧАСЫ");
      switch (MG) {
        case 1:
          Mgl = 23;
          dfPlayer.playFolder(Mgl, 35);
          delay(800);
          break;
        case 0:
          Mgl = 22;
          dfPlayer.playFolder(Mgl, 35);
          delay(800);
          break;
        case 2:
          Mgl = 12;
          dfPlayer.playFolder(Mgl, 01);
          delay(1000);
          break;
        case 4:
          Mgl = 13;
          dfPlayer.playFolder(Mgl, 01);
          delay(800);
          break;
      }
      getPilik();
    }
    if (portal.click("sld12")) {
      Y = portal.getInt("sld12");
      dfPlayer.volume(Y);
      W = Y;
    }
    if (portal.click("sel58")) {
      EQ = portal.getSelected("sel58", "NORM,POP,ROCK,JAZZ,CLAS,BASS");
      getPilik();
    }
    if (portal.click("selns")) {
      myS = portal.getSelected("selns", "РАЗВЛЕЧЕНИЯ,ЗДОРОВЬЕ,СЦЕНА,СПОРТ,ТЕХНОЛОГИИ,БИЗНЕСС");
      getPilik();
    }
    if (ModKey == 3 && portal.click("sw14")) {
      PLU = portal.getCheck("sw14");
      getPilik();
    }

    if (portal.click("selyark")) {
      e = portal.getSelected("selyark", "20%,30%,40%,50%,60%,80%");
      getPilik();
      updateTime();
      getRTCh(szTime);
      getRTCm(szTime);
    }

    if (ModKey == 3 && PLU == false && portal.click("btn31")) {
      PLR++;
      if (PLR > 20)PLR = 1;
    }
    if (ModKey == 3 && PLU == true && portal.click("btn31")) {
      papk++;
      if (papk > 8)papk = 8;
    }
    if (ModKey == 3 && PLU == false && portal.click("btn30")) {
      PLR--;
      if (PLR < 1)PLR = 20;
    }
    if (ModKey == 3 && PLU == true && portal.click("btn30")) {
      papk--;
      if (papk < 4)papk = 4;
    }
    if (ModKey == 3 && portal.click("btn25")) {
      Serial.println("btn25");
      modPleer = 0;
      matrix.fillRect(0, 0, 64, 32 , myBLACK);
      ModKey = 0;
    }

    if (portal.click("sel60")) {
      hron = portal.getSelected("sel60", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
      Serial.println(hron);
    }
    if (portal.click("sel61")) {
      mron = portal.getSelected("sel61", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
      Serial.println(mron);
    }
    if (portal.click("sel62")) {
      hroff = portal.getSelected("sel62", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23");
    }
    if (portal.click("sel63")) {
      mroff = portal.getSelected("sel63", "00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59");
    }
    if (portal.click("sel64")) {
      HUM = portal.getSelected("sel64", "00%,01%,02%,03%,04%,05%,06%,07%,08%,09%,10%,11%,12%,13%,14%,15%,16%,17%,18%,19%,20%,21%,22%,23%,24%,25%,26%,27%,28%,29%,30%,31%,32%,33%,34%,35%,36%,37%,38%,39%,40%,41%,42%,43%,44%,45%,46%,47%,48%,49%,50%,51%,52%,53%,54%,55%,56%,57%,58%,59%,60%,61%,62%,63%");
      getPilik();
      Serial.println(HUM);
    }
    if (portal.click("sel65")) {
      co2 = portal.getSelected("sel65", "00,50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000");
      CO2 = co2 * 50;
      Serial.println(CO2);
    }

    if (portal.click("sw15")) {
      flagRTC = portal.getCheck("sw15");
      getPilik();
    }
    if (portal.click("btn18")) {
      getPilik();
      watch.settime(s, m, h, day, month, year, dow - 1);
    }
    if (portal.click("sw16")) {
      effekt = portal.getCheck("sw16");
      getPilik();
    }
    if (ModKey == 0 && portal.click("btnekrd")) {
      ModKey = 2;
      getNow1();
    }
    if (ModKey == 0 && portal.click("btnekrp")) {
      ModKey = 2;
      getNow();
    }
    if (ModKey == 0 && portal.click("btnekrv")) {
      ModKey = 2;
      getNow2();
    }
    if (ModKey == 0 && portal.click("btnekrm")) {
      ModKey = 2;
      getNow4();
    }


    if (ModWEBR == 0 && portal.click("btn12")) {
      switch (ModN) {
        case 0:
          ModNreg = 1;
          ModN++;
          break;
        case 1:
          ModNreg = 2;
          ModN++;
          break;
        case 2:
          ModNreg = 3;
          ModN++;
          break;
        case 3:
          ModNreg = 0;
          ModN = 0;
          break;
      }
    }
    if (ModWEBR == 0 && ModKey == 0 && portal.click("btn13")) {
      getPilik();
      Y = 0;
    }

  }
  saveConfig();
}
