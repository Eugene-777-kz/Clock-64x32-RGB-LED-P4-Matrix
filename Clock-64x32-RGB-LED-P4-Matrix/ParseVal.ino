void Val() {
  String line = "";
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverPath = "https://www.cbr-xml-daily.ru/latest.js";
    Serial.println("Getting valute");
    http.begin(serverPath);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.printf("    [HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        line = http.getString();
        //Serial.println(line);
      } else {
        Serial.println("connection for news data failed: " + String(serverPath)); //error message if no client connect
        Serial.println();
        return;
      }
    }

    http.end();
    const size_t capacity = 1536; //https://arduinojson.org/v6/assistant
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, line);
    float ud  = doc["rates"]["USD"];
    usd = 1 / ud;
    float er  = doc["rates"]["EUR"];
    eur = 1 / er;
    float bn  = doc["rates"]["BYN"];
    byn = 1 / bn;
    if (printCom) {
      Serial.println(line);
      Serial.println("1 доллар = " + String(usd) + " рублей.");
      Serial.println("1 евро = " + String(eur) + " рублей.");
      Serial.println("1 белорусский рубль = " + String(byn) + " рублей.");

    }
  }

}
bool valyte()
{
  valutedok = " ";
  valutedok += "1 доллар = ";
  valutedok += String(usd, 2);
  valutedok += " рублей. ";
  valutedok += "1 евро = ";
  valutedok += String(eur, 2);
  valutedok += " рублей. ";
  valutedok += "1 белорусский рубль = ";
  valutedok += String(byn, 2);
  valutedok += " рублей. ";
}
