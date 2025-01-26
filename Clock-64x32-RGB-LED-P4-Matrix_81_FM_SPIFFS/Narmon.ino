
//=========================================================================================================
//                                  narodmon.ru
void getNarodmon() {
        int sensors_ID0 = ID0.toInt();
        int sensors_ID1 = ID1.toInt();
        int sensors_ID2 = ID2.toInt();
        int sensors_ID3 = ID3.toInt();
  
  if (WiFi.status() != WL_CONNECTED)  return;
  if (printCom) {
     printTime();
     Serial.println("Connection to narodmon.ru");
   }
  if (ESPclient.connect("http://narodmon.ru", 80)) {
    if (printCom) Serial.println("connection failed");
    return;
  }
  if (!sensors_ID0) return;
  String line = "";
  String reqline = "http://narodmon.ru/api/sensorsValues?sensors=";
  if (sensors_ID0) reqline += String(sensors_ID0);
  if (sensors_ID1) reqline += "," + String(sensors_ID1);
  if (sensors_ID2) reqline += "," + String(sensors_ID2);
  if (sensors_ID3) reqline += "," + String(sensors_ID3);  
  reqline += "&uuid=" + uuid + "&api_key=" + api_key;
  if (api_key == "" ){
    NarFlag = 0;
  }else{
    NarFlag = 1;
  }
  if (printCom) {
     Serial.println("=======================================================");
     Serial.println(reqline);
    Serial.println("=======================================================");
  }
  HTTPClient http;
  if (http.begin(ESPclient, reqline)) { // HTTP
    int httpCode = http.GET();
    if (httpCode > 0) {
     if(printCom)Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        line = http.getString();
      }
     
    } else {
      if(printCom)Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      
    }
    http.end();
  } 
  else {
    if(printCom)Serial.printf("[HTTP} Unable to connect\n");
  }
  if(printCom){
    Serial.print("answer=");
    Serial.println(line);
  } 
 
  const size_t capacity = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(1) + 2 * JSON_OBJECT_SIZE(6) + 340; //https://arduinojson.org/v6/assistant/
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, line);
  if (!doc.capacity()) {
   if(printCom)Serial.println("          Parse weather forecast - FAILED!!!");
   
    return;
  }
  JsonObject sensors_0 = doc["sensors"][0];
  float sensors_0_value = sensors_0["value"]; 
  long sensors_0_time = sensors_0["time"];
  JsonObject sensors_1 = doc["sensors"][1];
  float sensors_1_value = sensors_1["value"];
  long sensors_1_time = sensors_1["time"];
  JsonObject sensors_2 = doc["sensors"][2];
  float sensors_2_value = sensors_2["value"];
  long sensors_2_time = sensors_2["time"];
  JsonObject sensors_3 = doc["sensors"][3];
  float sensors_3_value = sensors_3["value"];
  long sensors_3_time = sensors_3["time"];
  long timestamp = epochNM + (millis() / 1000);
  if (printCom) {
    Serial.println("sensors_0 = " + String(sensors_0_value, 1) + "    sensors_1 = " + String(sensors_1_value, 1) + "    sensors_2 = " + String(sensors_2_value, 1) + "    sensors_3 = " + String(sensors_3_value, 1));
    Serial.println("time_0 = " + String(timestamp - sensors_0_time) + "      time_1 = " + String(timestamp - sensors_1_time) + "      time_2 = " + String(timestamp - sensors_2_time) + "      time_3 = " + String(timestamp - sensors_3_time));
  }

  tempNM = 0;
  pressNM = 0;
  humNM = 0;
  vetNM = 0;
  cloutNM = 0;
  if (sensors_ID0) {
    tempNM = sensors_0_value;   //tempNM = sensors_1_value;
  }
  if (sensors_ID1) {
    humNM = sensors_2_value;   //humNM = sensors_2_value;
  }
  if (sensors_ID2) {
    pressNM = sensors_1_value;  //pressNM = sensors_0_value;
  }
 
}
