//===============================================================================================================================//
//                              ПОГОДА                                                //
//===============================================================================================================================//
void getWeatherData0() {
  if (weatherKey0 == "" || !displayForecast) return;
  if (WiFi.status() != WL_CONNECTED) {
    updateForecast++;
    return;
  }
  if (printCom) {
    Serial.println("======== START GET WEATHER FROM WEATHERBIT.IO =========");
  }
  location_name = "";
  location_region = "";
  location_country = "";
  location_localtime = "";
  location_temp = 0;
  location_app_temp = 0;
  location_rh = 0;
  location_pres = 0;
  location_wind_spd = 0;
  location_wind_cdir_full = "";
  location_sunrise = "";
  location_sunset = "";
  location_clouds = 0;
  location_vis = 0;
  location_uv = 0;
  location_weather_description = "";
  location_code = 0;
  if (ESPclient.connect(weatherHost0.c_str(), 80)) {}
  else {
    if (printCom) {
      Serial.println(" Not connection server!!!");
      Serial.println("======== END ==========================================");
    }
    updateForecast++;
    return;
  }
  HTTPClient http;
  String line = "";
  String reqline = "http://" + weatherHost0 + "/v2.0/current/daily?city=" + String("&lat=") + String(lat) + String("&lon=") + String(lon) + "&lang=" + weatherLang + "&key=" + weatherKey0;
  if (printCom) Serial.print(reqline);
  if (http.begin(ESPclient, reqline)) {
    int httpCode = http.GET();
    if (httpCode > 0) {
      if(printCom) Serial.printf("    [HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        line = http.getString();
      }
    } else {
      if (printCom) {
         Serial.printf("    [HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
         Serial.println("======== END ==========================================");
      }
      http.end();
      updateForecast++;
      return;
    }
    http.end();
  } else {
    if (printCom) {
      Serial.printf("    [HTTP] Unable to connect\n");
      Serial.println("======== END ==========================================");
    }
    updateForecast++;
    return;
  }
  if (line == "") {
    if (printCom) {

      Serial.printf("[HTTP] The answer is empty\n");
      Serial.println("======== END ==========================================");
    }
    updateForecast++;
    return;
  }
  const size_t capacity = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(37) + 1128; //https://arduinojson.org/v6/assistant/
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, line);
  if (!doc.capacity()) {
    if (printCom) {

      Serial.println("Parse weather forecast - FAILED!!!");
      Serial.println("======== END ==========================================");
    }
    updateForecast++;
    return;
  }
  JsonObject data = doc["data"][0];
  location_rh = data["rh"];
  location_pres = data["pres"];
  if (pressSys == 1) location_pres /= 1.3332239;
  const char* data_timezone = data["timezone"];
  location_region = data_timezone;
  const char* data_ob_time = data["ob_time"];
  location_localtime = data_ob_time;
  const char* data_country_code = data["country_code"];
  location_country = data_country_code;
  location_clouds = data["clouds"];
  const char*   data_city_name = data["city_name"];
  location_name = data_city_name;
  location_wind_spd = data["wind_spd"]; // 1
  const char* data_wind_cdir_full = data["wind_cdir_full"];
  location_wind_cdir_full = data_wind_cdir_full;
  location_vis = data["vis"]; // 5
  const char*   data_sunset = data["sunset"];
  location_sunset = data_sunset;
  location_uv = data["uv"]; // 0
  int           data_wind_dir = data["wind_dir"];
  const char*   data_sunrise = data["sunrise"];
  location_sunrise = data_sunrise;
  JsonObject    data_weather = data["weather"];
  const char*   data_weather_description = data_weather["description"];
  location_weather_description = data_weather_description;
  location_code = data_weather["code"];
  location_temp = data["temp"];
  location_app_temp = data["app_temp"];
  //if ( location_temp > 0 ) texttemp = "+" ;
  String windDegString;
  weatherString = "         ";
  if (displayForecastNow) {
    if (location_temp > 0) {
      texttemp = "+" ;
      weatherString +=  "Сейчас в " + String(gorod) + ":" + " температура " + texttemp + String(location_temp, 1) + "\260" + "С";
    }else{
      weatherString +=  "Сейчас в " + String(gorod) + ":" + " температура " + String(location_temp, 1) + "\260" + "С";
    }
    weatherString += " влажность " + String(location_rh) + "% ";
    weatherString += "давление " + String((location_pres), 0) + (pressSys == 1 ? tPress : tPress0) + "ммРс ";
    weatherString += " ветер " + String(location_wind_cdir_full) + " " + String(location_wind_spd, 1) + "м/с";
    weatherString += " облачность " + String(location_clouds) +  "% " + data_weather_description + "                ";
  }
  updateForecast = 0;
  updateForecastNot = false;
  if (printCom) {

    Serial.println("line =" + line);
    Serial.println("======== END ==========================================");
  }
}
// ============================================================================//
//               ПРОГНОЗ!!!    //
// ============================================================================//
void getWeatherDataz0() {
  if (weatherKey0 == "" || !displayForecast) return;
  if (WiFi.status() != WL_CONNECTED) {
    updateForecasttomorrow++;
    return;
  }
  if (printCom) {
    Serial.println("======== START GET FORECAST FROM WEATHERBIT.IO ========");

  }
  HTTPClient http;
  String line = "";
  String reqline = "http://" + weatherHost0 + "/v2.0/forecast/daily?city=" + String("&lat=") + String(lat) + String("&lon=") + String(lon) + "&lang=" + weatherLang + "&days=2&key=" + weatherKey0;
  if(printCom) Serial.print(reqline);
  if (http.begin(ESPclient, reqline)) {
    int httpCode = http.GET();
    if (httpCode > 0) {
      if(printCom) Serial.printf("  [HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        line = http.getString();
      }
    } else {
      if (printCom) {
        Serial.printf("    [HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        Serial.println("======== END ==========================================");
      }
      http.end();
      updateForecasttomorrow++;
      return;
    }
    http.end();
  } else {
    if (printCom) {
      Serial.printf("    [HTTP] Unable to connect\n");
       Serial.println("======== END ==========================================");
    }
    updateForecasttomorrow++;
    return;
  }
  if (line == "") {
    if (printCom) {

      Serial.printf("[HTTP] The answer is empty\n");
      Serial.println("======== END ==========================================");
    }
    updateForecasttomorrow++;
    return;
  }
  const size_t capacity = JSON_ARRAY_SIZE(2) + 2 * JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(7) + 2 * JSON_OBJECT_SIZE(37) + 2321;
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, line);
  if (!doc.capacity()) {
    if (printCom) {

      Serial.println("Parse weather forecast - FAILED!!!");
      Serial.println("======== END ==========================================");
    }
    updateForecasttomorrow++;
    return;
  }
  JsonObject data_0 = doc["data"][0];
  JsonObject data_0_weather = data_0["weather"];
  const char* data_0_weather_description = data_0_weather["description"];
  float data_0_max_temp = data_0["max_temp"];
  float data_0_min_temp = data_0["min_temp"];
  JsonObject data_1 = doc["data"][1];
  int data_1_rh = data_1["rh"];
  int data_1_clouds = data_1["clouds"];
  float data_1_wind_spd = data_1["wind_spd"];
  JsonObject data_1_weather = data_1["weather"];
  const char* data_1_weather_description = data_1_weather["description"];
  const char* data_1_wind_cdir_full = data_1["wind_cdir_full"];
  float data_1_max_temp = data_1["max_temp"];
  float data_1_min_temp = data_1["min_temp"];
  float data_1_weather_code = data_1_weather["code"];
  if (data_1_min_temp > 0) texttempmin = "+" ;
  if (data_1_max_temp > 0) texttempmax = "+" ;
  weatherStringZ = "";
  coded1 = 0;
  tempfor1 = 0;
  tempfor2 = 0;
  coded1 += int(data_1_weather_code);
  tempfor1 += float(data_1_min_temp);
  tempfor2 += float(data_1_max_temp);
  if (displayForecastTomorrow) {
    weatherStringZ += "Прогноз на завтра: температура от ";
    if (data_1_min_temp > 0){
    texttempmin = "+" ;
    weatherStringZ += texttempmin + String(data_1_min_temp, 1) + " до ";
    }else{
    weatherStringZ += String(data_1_min_temp, 1) + " до ";  
    }
    if (data_1_max_temp > 0){
    texttempmax = "+" ;   
    weatherStringZ += texttempmax + String(data_1_max_temp, 1) + "\260" + "C";
    }else{
    weatherStringZ += String(data_1_max_temp, 1) + "\260" + "C";  
    }
    weatherStringZ += " влажность " + String(data_1_rh) + "%";
    weatherStringZ += " ветер " + String(data_1_wind_cdir_full) + " " + String(data_1_wind_spd, 1);//+ tSpeed
    weatherStringZ += "м/с " + String(data_1_weather_description);
    weatherStringZ += "                   ";
  }
  if(printCom) Serial.println("          Getting weather forecast for tomorrow - is OK.");
  updateForecasttomorrow = 0;
  updateForecastNot = false;
  if(printCom){

  Serial.println("line =" + line);
  Serial.println("======== END ==========================================");
  }
}
