void Anek() {
  location_anek = "";
  location_awt = "";

  String line = "";
  line.reserve(1000);
  if (WiFi.status() == WL_CONNECTED) {
    //kateganekd();
    HTTPClient http;
    String apiGetData = "http://api.forismatic.com/api/1.0/?method=getQuote&key=457653&format=json&lang=ru";//mySrce
    Serial.println("Getting News Data");
    Serial.println(apiGetData);
    http.begin(apiGetData);
    int httpCode = http.GET();
    if (httpCode > 0) {
      if (printCom) Serial.printf("    [HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        line = http.getString();
      } else {
        Serial.println("connection for news data failed: "); //error message if no client connect
        Serial.println();
        return;
      }
    }
  }
  http.end();
  Serial.println("line =" + line);
  const size_t capacity = 2384; //https://arduinojson.org/v6/assistant/
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, line);
  //JsonObject anek = doc[0];
  const char*anekdot = doc["quoteText"];
  location_anek = anekdot;
  const char*awtor = doc["quoteAuthor"];
  location_awt = awtor;

  if (printCom) {
    Serial.print("АФОРИЗМЫ: ");
    Serial.println(location_anek);
    Serial.print("ААВТОР: ");
    Serial.println(location_awt);

  }

}
