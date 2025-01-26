bool loadConfig() {
  File configFile = SPIFFS.open("/config.json", FILE_READ);
  if (!configFile) {
    if (printCom) Serial.println("Failed to open config file");
    saveConfig();
    configFile.close();
    return false;
  }
  size_t size = configFile.size();
  if (size > 10000) {
    if (printCom) Serial.println("Config file size is too large");
    configFile.close();
    return false;
  }
  jsonConfig = configFile.readString();
  DynamicJsonDocument doc(10000);
  deserializeJson(doc, jsonConfig);
  configFile.close();

  gorod = doc["gorod"].as<String>();
  lat = doc["lat"].as<String>();
  lon = doc["lon"].as<String>();
  weatherKey0 = doc["weatherKey0"].as<String>();
  server = doc["server"].as<String>();
  port = doc["port"].as<String>();
  USER = doc["USER"].as<String>();
  PASSWORD = doc["PASSWORD"].as<String>();
  PUBLISH_CH = doc["PUBLISH_CH"].as<String>();
  PUBLISH_CH1 = doc["PUBLISH_CH1"].as<String>();
  PUBLISH_CH2 = doc["PUBLISH_CH2"].as<String>();
  PUBLISH_CH3 = doc["PUBLISH_CH3"].as<String>();
  PUBLISH_CH4 = doc["PUBLISH_CH4"].as<String>();
  PUBLISH_CH5 = doc["PUBLISH_CH5"].as<String>();
  PUBLISH_CH6 = doc["PUBLISH_CH6"].as<String>();
  PUBLISH_CH7 = doc["PUBLISH_CH7"].as<String>();
  RECEIVER_CH1 = doc["RECEIVER_CH1"].as<String>();
  RECEIVER_CH2 = doc["RECEIVER_CH2"].as<String>();
  RECEIVER_CH3 = doc["RECEIVER_CH3"].as<String>();
  RECEIVER_CH4 = doc["RECEIVER_CH4"].as<String>();
  RECEIVER_CH5 = doc["RECEIVER_CH5"].as<String>();
  RECEIVER_CH6 = doc["RECEIVER_CH6"].as<String>();
  uuid = doc["uuid"].as<String>();
  api_key = doc["api_key"].as<String>();
  ID0 = doc["ID0"].as<String>();
  ID1 = doc["ID1"].as<String>();
  ID2 = doc["ID2"].as<String>();
  ID3 = doc["ID3"].as<String>();
  myApiKey = doc["myApiKey"].as<String>();
  listStation = doc["listStation"].as<String>();
  listStation1 = doc["listStation1"].as<String>();
  listStation2 = doc["listStation2"].as<String>();
  listStation3 = doc["listStation3"].as<String>();
  listStation4 = doc["listStation4"].as<String>();
  listStation5 = doc["listStation5"].as<String>();
  listStation6 = doc["listStation6"].as<String>();
  listStation7 = doc["listStation7"].as<String>();
  listStation8 = doc["listStation8"].as<String>();
  listStation9 = doc["listStation9"].as<String>();
  listStation10 = doc["listStation10"].as<String>();
  listStation11 = doc["listStation11"].as<String>();
  nStation = doc["nStation"].as<String>();
  nStation1 = doc["nStation1"].as<String>();
  nStation2 = doc["nStation2"].as<String>();
  nStation3 = doc["nStation3"].as<String>();
  nStation4 = doc["nStation4"].as<String>();
  nStation5 = doc["nStation5"].as<String>();
  nStation6 = doc["nStation6"].as<String>();
  nStation7 = doc["nStation7"].as<String>();
  nStation8 = doc["nStation8"].as<String>();
  nStation9 = doc["nStation9"].as<String>();
  nStation10 = doc["nStation10"].as<String>();
  nStation11 = doc["nStation11"].as<String>();
  Text = doc["Text"].as<String>();
  Y = doc["Y"];
  timezone = doc["timezone"];
  x = doc["x"];
  x1 = doc["x1"];
  x2 = doc["x2"];
  x3 = doc["x3"];
  x4 = doc["x4"];
  x5 = doc["x5"];
  x6 = doc["x6"];
  x7 = doc["x7"];
  x8 = doc["x8"];
  x21 = doc["x21"];
  x22 = doc["x22"];
  x23 = doc["x23"];
  x24 = doc["x24"];
  x25 = doc["x25"];
  x26 = doc["x26"];
  x27 = doc["x27"];
  x28 = doc["x28"];
  x29 = doc["x29"];
  x30 = doc["x30"];
  x31 = doc["x31"];
  x32 = doc["x32"];
  x33 = doc["x33"];
  x34 = doc["x34"];
  x35 = doc["x35"];
  x36 = doc["x36"];
  x37 = doc["x37"];
  //x38 = doc["x38"];
  x39 = doc["x39"];
  x40 = doc["x40"];
  x41 = doc["x41"];
  x42 = doc["x42"];
  x43 = doc["x43"];
  x44 = doc["x44"];
  x45 = doc["x45"];
  x46 = doc["x46"];
  x47 = doc["x47"];
  x48 = doc["x48"];
  ModNreg = doc["ModNreg"];
  fch = doc["fch"];
  font = doc["font"];
  hof = doc["hof"];
  hon = doc["hon"];
  mel1 = doc["mel1"];
  mel2 = doc["mel2"];
  mel3 = doc["mel3"];
  mel4 = doc["mel4"];
  mel5 = doc["mel5"];
  mel6 = doc["mel6"];
  mel7 = doc["mel7"];
  Hbyd1 = doc["Hbyd1"];
  Hbyd2 = doc["Hbyd2"];
  Hbyd3 = doc["Hbyd3"];
  Hbyd4 = doc["Hbyd4"];
  Hbyd5 = doc["Hbyd5"];
  Hbyd6 = doc["Hbyd6"];
  Hbyd7 = doc["Hbyd7"];
  Mbyd1 = doc["Mbyd1"];
  Mbyd2 = doc["Mbyd2"];
  Mbyd3 = doc["Mbyd3"];
  Mbyd4 = doc["Mbyd4"];
  Mbyd5 = doc["Mbyd5"];
  Mbyd6 = doc["Mbyd6"];
  Mbyd7 = doc["Mbyd7"];
  frameDelay = doc["frameDelay"];
  frameDelay1 = doc["frameDelay1"];
  frameDelay2 = doc["frameDelay2"];
  frameDelay3 = doc["frameDelay3"];
  frameDelay4 = doc["frameDelay4"];
  frameDelay5 = doc["frameDelay5"];
  frameDelay6 = doc["frameDelay6"];
  frameDelay7 = doc["frameDelay7"];
  frameDelay8 = doc["frameDelay8"];
  frameDelay9 = doc["frameDelay9"];
  frameDelay10 = doc["frameDelay10"];
  frameDelay11 = doc["frameDelay11"];
  frameDelay12 = doc["frameDelay12"];
  Modbyd1 = doc["Modbyd1"];
  Modbyd2 = doc["Modbyd2"];
  Modbyd3 = doc["Modbyd3"];
  Modbyd4 = doc["Modbyd4"];
  Modbyd5 = doc["Modbyd5"];
  Modbyd6 = doc["Modbyd6"];
  Modbyd7 = doc["Modbyd7"];
  MPov1 = doc["MPov1"];
  MPov2 = doc["MPov2"];
  MPov3 = doc["MPov3"];
  MPov4 = doc["MPov4"];
  MPov5 = doc["MPov5"];
  MPov6 = doc["MPov6"];
  MPov7 = doc["MPov7"];
  Pov1 = doc["Pov1"];
  Pov2 = doc["Pov2"];
  Pov3 = doc["Pov3"];
  Pov4 = doc["Pov4"];
  Pov5 = doc["Pov5"];
  Pov6 = doc["Pov6"];
  Pov7 = doc["Pov7"];
  NEWStation = doc["NEWStation"];
  vol = doc["vol"];
  hwebon = doc["hwebon"];
  hweboff = doc["hweboff"];
  mwebon = doc["mwebon"];
  mweboff = doc["mweboff"];
  WEBR = doc["WEBR"];
  Modewebr = doc["Modewebr"];
  cords18 = doc["cords18"];
  CorTemp = doc["CorTemp"];
  corrPress = doc["corrPress"];
  CorHum = doc["CorHum"];
  bz = doc["bz"];
  co2 = doc["co2"];
  MG = doc["MG"];
  modtoch = doc["modtoch"];
  printCom = doc["printCom"];
  Modebst1 = doc["Modebst1"];
  Modebst2 = doc["Modebst2"];
  Modebst3 = doc["Modebst3"];
  Modebst4 = doc["Modebst4"];
  Modebst5 = doc["Modebst5"];
  Modekr1 = doc["Modekr1"];
  Modekr2 = doc["Modekr2"];
  Modekr3 = doc["Modekr3"];
  ekrPog = doc["ekrPog"];
  ekrDom = doc["ekrDom"];
  ekrKach = doc["ekrKach"];
  e = doc["e"];
  EQ = doc["EQ"];
  modBig = doc["modBig"];
  Modsen = doc["Modsen"];
  Modsen1 = doc["Modsen1"];
  flagRTC = doc["flagRTC"];
  hbigon = doc["hbigon"];
  hbigoff = doc["hbigoff"];
  mbigon = doc["mbigon"];
  mbigoff = doc["mbigoff"];
  minon = doc["minon"];
  minof = doc["minof"];
  MNR = doc["MNR"];
  BCH = doc["BCH"];
  Serv = doc["Serv"];
  Modmqtt = doc["Modmqtt"];
  MQTR = doc["MQTR"];
  hron = doc["hron"];
  mron = doc["mron"];
  hroff = doc["hroff"];
  mroff = doc["mroff"];
  effekt = doc["effekt"];
  fss = doc["fss"];
  Mgl = doc["Mgl"];
  W = doc["W"];
  weti = doc["weti"];
  wety = doc["wety"];
  wetu = doc["wetu"];
  HUM = doc["HUM"];
  CO2 = doc["CO2"];
  modPleer = doc["modPleer"];
  year = doc["year"];
  modeffeck1 = doc["modeffeck1"];
  zadef = doc["zadef"];
  ANCKL = doc["ANCKL"];
  ballef = doc["ballef"];
  myS = doc["myS"];
  xnews = doc["xnews"];
  Modenews = doc["Modenews"];
  Modenewspod = doc["Modenewspod"];
  kch = doc["kch"];
  chut = doc["chut"];
  xchut = doc["xchut"];
  valu = doc["valu"];
  POG = doc["POG"];
  xvalu = doc["xvalu"];
  flagpr = doc["flagpr"];

  if (printCom) {
    printTime();
    Serial.print("Load Config : ");
    Serial.println(jsonConfig);
  }
  return true;
}
//=================================================================
bool saveConfig() {
  DynamicJsonDocument doc(10000);
  deserializeJson(doc, jsonConfig);
  doc["gorod"] = gorod;
  doc["lat"] = lat;
  doc["lon"] = lon;
  doc["weatherKey0"] = weatherKey0;
  doc["server"] = server;
  doc["port"] = port;
  doc["USER"] = USER;
  doc["PASSWORD"] = PASSWORD;
  doc["PUBLISH_CH"] = PUBLISH_CH;
  doc["PUBLISH_CH1"] = PUBLISH_CH1;
  doc["PUBLISH_CH2"] = PUBLISH_CH2;
  doc["PUBLISH_CH3"] = PUBLISH_CH3;
  doc["PUBLISH_CH4"] = PUBLISH_CH4;
  doc["PUBLISH_CH5"] = PUBLISH_CH5;
  doc["PUBLISH_CH6"] = PUBLISH_CH6;
  doc["PUBLISH_CH7"] = PUBLISH_CH7;
  doc["RECEIVER_CH1"] = RECEIVER_CH1;
  doc["RECEIVER_CH2"] = RECEIVER_CH2;
  doc["RECEIVER_CH3"] = RECEIVER_CH3;
  doc["RECEIVER_CH4"] = RECEIVER_CH4;
  doc["RECEIVER_CH5"] = RECEIVER_CH5;
  doc["RECEIVER_CH6"] = RECEIVER_CH6;
  doc["uuid"] = uuid;
  doc["api_key"] = api_key;
  doc["ID0"] = ID0;
  doc["ID1"] = ID1;
  doc["ID2"] = ID2;
  doc["ID3"] = ID3;
  doc["myApiKey"] = myApiKey;
  // doc["KEY"] = KEY;
  doc["listStation"] = listStation;
  doc["listStation1"] = listStation1;
  doc["listStation2"] = listStation2;
  doc["listStation3"] = listStation3;
  doc["listStation4"] = listStation4;
  doc["listStation5"] = listStation5;
  doc["listStation6"] = listStation6;
  doc["listStation7"] = listStation7;
  doc["listStation8"] = listStation8;
  doc["listStation9"] = listStation9;
  doc["listStation10"] = listStation10;
  doc["listStation11"] = listStation11;
  doc["nStation"] = nStation;
  doc["nStation1"] = nStation1;
  doc["nStation2"] = nStation2;
  doc["nStation3"] = nStation3;
  doc["nStation4"] = nStation4;
  doc["nStation5"] = nStation5;
  doc["nStation6"] = nStation6;
  doc["nStation7"] = nStation7;
  doc["nStation8"] = nStation8;
  doc["nStation9"] = nStation9;
  doc["nStation10"] = nStation10;
  doc["nStation11"] = nStation11;
  doc["Text"] = Text;
  doc["Y"] = Y;
  doc["timezone"] = timezone;
  doc["x"] = x;
  doc["x1"] = x1;
  doc["x2"] = x2;
  doc["x3"] = x3;
  doc["x4"] = x4;
  doc["x5"] = x5;
  doc["x6"] = x6;
  doc["x7"] = x7;
  doc["x8"] = x8;
  doc["x21"] = x21;
  doc["x22"] = x22;
  doc["x23"] = x23;
  doc["x24"] = x24;
  doc["x25"] = x25;
  doc["x26"] = x26;
  doc["x27"] = x27;
  doc["x28"] = x28;
  doc["x29"] = x29;
  doc["x30"] = x30;
  doc["x31"] = x31;
  doc["x32"] = x32;
  doc["x33"] = x33;
  doc["x34"] = x34;
  doc["x35"] = x35;
  doc["x36"] = x36;
  doc["x37"] = x37;
  //doc["x38"] = x38;
  doc["x39"] = x39;
  doc["x40"] = x40;
  doc["x41"] = x41;
  doc["x42"] = x42;
  doc["x43"] = x43;
  doc["x44"] = x44;
  doc["x45"] = x45;
  doc["x46"] = x46;
  doc["x47"] = x47;
  doc["x48"] = x48;
  doc["ModNreg"] = ModNreg;
  doc["fch"] = fch;
  doc["font"] = font;
  doc["hof"] = hof;
  doc["hon"] = hon;
  doc["mel1"] = mel1;
  doc["mel2"] = mel2;
  doc["mel3"] = mel3;
  doc["mel4"] = mel4;
  doc["mel5"] = mel5;
  doc["mel6"] = mel6;
  doc["mel7"] = mel7;
  doc["Hbyd1"] = Hbyd1;
  doc["Hbyd2"] = Hbyd2;
  doc["Hbyd3"] = Hbyd3;
  doc["Hbyd4"] = Hbyd4;
  doc["Hbyd5"] = Hbyd5;
  doc["Hbyd6"] = Hbyd6;
  doc["Hbyd7"] = Hbyd7;
  doc["Mbyd1"] = Mbyd1;
  doc["Mbyd2"] = Mbyd2;
  doc["Mbyd3"] = Mbyd3;
  doc["Mbyd4"] = Mbyd4;
  doc["Mbyd5"] = Mbyd5;
  doc["Mbyd6"] = Mbyd6;
  doc["Mbyd7"] = Mbyd7;
  doc["frameDelay"] = frameDelay;
  doc["frameDelay1"] = frameDelay1;
  doc["frameDelay2"] = frameDelay2;
  doc["frameDelay3"] = frameDelay3;
  doc["frameDelay4"] = frameDelay4;
  doc["frameDelay5"] = frameDelay5;
  doc["frameDelay6"] = frameDelay6;
  doc["frameDelay7"] = frameDelay7;
  doc["frameDelay8"] = frameDelay8;
  doc["frameDelay9"] = frameDelay9;
  doc["frameDelay10"] = frameDelay10;
  doc["frameDelay11"] = frameDelay11;
  doc["frameDelay12"] = frameDelay12;
  doc["Modbyd1"] = Modbyd1;
  doc["Modbyd2"] = Modbyd2;
  doc["Modbyd3"] = Modbyd3;
  doc["Modbyd4"] = Modbyd4;
  doc["Modbyd5"] = Modbyd5;
  doc["Modbyd6"] = Modbyd6;
  doc["Modbyd7"] = Modbyd7;
  doc["MPov1"] = MPov1;
  doc["MPov2"] = MPov2;
  doc["MPov3"] = MPov3;
  doc["MPov4"] = MPov4;
  doc["MPov5"] = MPov5;
  doc["MPov6"] = MPov6;
  doc["MPov7"] = MPov7;
  doc["Pov1"] = Pov1;
  doc["Pov2"] = Pov2;
  doc["Pov3"] = Pov3;
  doc["Pov4"] = Pov4;
  doc["Pov5"] = Pov5;
  doc["Pov6"] = Pov6;
  doc["Pov7"] = Pov7;
  doc["NEWStation"] = NEWStation;
  doc["vol"] = vol;
  doc["hwebon"] = hwebon;
  doc["hweboff"] = hweboff;
  doc["mwebon"] = mwebon;
  doc["mweboff"] = mweboff;
  doc["WEBR"] = WEBR;
  doc["Modewebr"] = Modewebr;
  doc["cords18"] = cords18;
  doc["CorTemp"] = CorTemp;
  doc["corrPress"] = corrPress;
  doc["CorHum"] = CorHum;
  doc["bz"] = bz;
  doc["co2"] = co2;
  doc["MG"] = MG;
  doc["modtoch"] = modtoch;
  doc["printCom"] = printCom;
  doc["Modebst1"] = Modebst1;
  doc["Modebst2"] = Modebst2;
  doc["Modebst3"] = Modebst3;
  doc["Modebst4"] = Modebst4;
  doc["Modebst5"] = Modebst5;
  doc["Modekr1"] = Modekr1;
  doc["Modekr2"] = Modekr2;
  doc["Modekr3"] = Modekr3;
  doc["ekrPog"] = ekrPog;
  doc["ekrDom"] = ekrDom;
  doc["ekrKach"] = ekrKach;
  doc["e"] = e;
  doc["EQ"] = EQ;
  doc["modBig"] = modBig;
  doc["Modsen"] = Modsen;
  doc["Modsen1"] = Modsen1;
  doc["flagRTC"] = flagRTC;
  doc["hbigon"] = hbigon;
  doc["hbigoff"] = hbigoff;
  doc["mbigon"] = mbigon;
  doc["mbigoff"] = mbigoff;
  doc["minon"] = minon;
  doc["minof"] = minof;
  doc["MNR"] = MNR;
  doc["BCH"] = BCH;
  doc["Serv"] = Serv;
  doc["Modmqtt"] = Modmqtt;
  doc["MQTR"] = MQTR;
  doc["hron"] = hron;
  doc["mron"] = mron;
  doc["hroff"] = hroff;
  doc["mroff"] = mroff;
  doc["effekt"] = effekt;
  doc["fss"] = fss;
  doc["Mgl"] = Mgl;
  doc["W"] = W;
  doc["weti"] = weti;
  doc["wety"] = wety;
  doc["wetu"] = wetu;
  doc["HUM"] = HUM;
  doc["CO2"] = CO2;
  doc["modPleer"] = modPleer;
  doc["year"] = year;
  doc["modeffeck1"] = modeffeck1;
  doc["zadef"] = zadef;
  doc["ANCKL"] = ANCKL;
  doc["ballef"] = ballef;
  doc["myS"] = myS;
  doc["xnews"] = xnews;
  doc["Modenews"] = Modenews;
  doc["Modenewspod"] = Modenewspod;
  doc["kch"] = kch;
  doc["chut"] = chut;
  doc["xchut"] = xchut;
  doc["valu"] = valu;
  doc["POG"] = POG;
  doc["xvalu"] = xvalu;
  doc["flagpr"] = flagpr;
  jsonConfig = "";
  if (serializeJson(doc, jsonConfig) == 0) {
    Serial.println(F("Failed to write to jsonConfig"));
  }
  File configFile = SPIFFS.open("/config.json", FILE_WRITE);
  if (!configFile) {
    configFile.close();
    return false;
  }
  if (serializeJson(doc, configFile) == 0) {
    Serial.println(F("Failed to write to file"));
  }
  if (printCom) {
    printTime();
    Serial.print("Save Config : ");
    Serial.println(jsonConfig);
  }
  configFile.close();
  return true;
}
bool loadPrazdnik1() {
  File PrazdnikFile = SPIFFS.open("/prazdniki1.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["1"][day].as<String>();
}
bool loadPrazdnik2() {
  File PrazdnikFile = SPIFFS.open("/prazdniki2.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["2"][day].as<String>();

}
bool loadPrazdnik3() {
  File PrazdnikFile = SPIFFS.open("/prazdniki3.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["3"][day].as<String>();

}
bool loadPrazdnik4() {
  File PrazdnikFile = SPIFFS.open("/prazdniki4.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["4"][day].as<String>();
}
bool loadPrazdnik5() {
  File PrazdnikFile = SPIFFS.open("/prazdniki5.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["5"][day].as<String>();
}
bool loadPrazdnik6() {
  File PrazdnikFile = SPIFFS.open("/prazdniki6.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["6"][day].as<String>();
}
bool loadPrazdnik7() {
  File PrazdnikFile = SPIFFS.open("/prazdniki7.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["7"][day].as<String>();
}
bool loadPrazdnik8() {
  File PrazdnikFile = SPIFFS.open("/prazdniki8.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["8"][day].as<String>();
}
bool loadPrazdnik9() {
  File PrazdnikFile = SPIFFS.open("/prazdniki9.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["9"][day].as<String>();
}
bool loadPrazdnik10() {
  File PrazdnikFile = SPIFFS.open("/prazdniki10.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["10"][day].as<String>();
}
bool loadPrazdnik11() {
  File PrazdnikFile = SPIFFS.open("/prazdniki11.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["11"][day].as<String>();
}
bool loadPrazdnik12() {
  File PrazdnikFile = SPIFFS.open("/prazdniki12.json", "r");
  if (!PrazdnikFile) {
    PrazdnikFile.close();
    return false;
  }
  size_t size = PrazdnikFile.size();
  if (size > 2048) {
    PrazdnikFile.close();
    return true;
  }
  jsonPrazdnik = PrazdnikFile.readString();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, jsonPrazdnik);
  PrazdnikFile.close();
  textpr = doc["12"][day].as<String>();
}
