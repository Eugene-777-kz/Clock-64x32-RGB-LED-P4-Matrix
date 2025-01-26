void News() {
   location_news = "";
   location_news1 = "";
   location_news2 = "";
   location_news3 = "";
   location_news4 = "";
   location_news5 = "";
   location_news6 = "";
   location_news7 = "";
   location_news8 = "";
   location_news9 = "";
     
    String line = "";
  if(WiFi.status() == WL_CONNECTED){
   kateg();
   HTTPClient http;
  String apiGetData = "http://" + String(servername) + "/v2/top-headlines?" + "country=ru" + "&category=" + mySource + "&apiKey=" + myApiKey;
  Serial.println("Getting News Data");
  Serial.println(apiGetData);
  http.begin(apiGetData);
  int httpCode = http.GET();
   if (httpCode > 0) {
      if(printCom) Serial.printf("    [HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        line = http.getString();
      } else {
    Serial.println("connection for news data failed: " + String(apiGetData)); //error message if no client connect
    Serial.println();
    return;
      }
    }
   }
    http.end();
    //Serial.println("line =" + line); 
    const size_t capacity = JSON_OBJECT_SIZE(1) + 16386; //https://arduinojson.org/v6/assistant/
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, line);
   JsonObject news = doc["articles"][0];
   const char* titlenews = news["title"];
    location_news = titlenews;
    JsonObject news1 = doc["articles"][1];
   const char* titlenews1 = news1["title"];
   location_news1 = titlenews1;
    JsonObject news2 = doc["articles"][2];
   const char* titlenews2 = news2["title"];
   location_news2 = titlenews2;
    JsonObject news3 = doc["articles"][3];
   const char* titlenews3 = news3["title"];
   location_news3 = titlenews3;
    JsonObject news4 = doc["articles"][4];
   const char* titlenews4 = news4["title"];
   location_news4 = titlenews4;
    JsonObject news5 = doc["articles"][5];
   const char* titlenews5 = news5["title"];
   location_news5 = titlenews5;
    JsonObject news6 = doc["articles"][6];
   const char* titlenews6 = news6["title"];
   location_news6 = titlenews6;
    JsonObject news7 = doc["articles"][7];
   const char* titlenews7 = news7["title"];
   location_news7 = titlenews7;
    JsonObject news8 = doc["articles"][8];
   const char* titlenews8 = news8["title"];
   location_news8 = titlenews8;
    JsonObject news9 = doc["articles"][9];
   const char* titlenews9 = news9["title"];
   location_news9 = titlenews9;
   if (printCom) {
   Serial.print("НОВОСТИ:");
   Serial.println(location_news);
   Serial.print("НОВОСТИ1:");
   Serial.println(location_news1);
   Serial.print("НОВОСТИ2:");
   Serial.println(location_news2);
   Serial.print("НОВОСТИ3:");
   Serial.println(location_news3);
   Serial.print("НОВОСТИ4:");
   Serial.println(location_news4);
   Serial.print("НОВОСТИ5:");
   Serial.println(location_news5);
   Serial.print("ПОДРОБН6:");
   Serial.println(location_news6);
   Serial.print("НОВОСТИ7:");
   Serial.println(location_news7);
   Serial.print("НОВОСТИ8:");
   Serial.println(location_news8);
   Serial.print("ПОДРОБНО9:");
   Serial.println(location_news9);

   //Serial.print("ПОДРОБНО:");
   //Serial.println(location_fulnews);
   }
  
}
void kateg()
{ 
  switch(myS){
  case 0:mySource = "entertainment";break;
  case 1:mySource = "health";break;
  case 2:mySource = "science";break;
  case 3:mySource = "sport";break;
  case 4:mySource = "technology";break;
  case 5:mySource = "business";break;
  }
}
