void WetMap() {
  temper = 0;
  pressures = 0;
  humiditys = 0;
  cloudsis = 0;
  speeder = 0;
  deg = 0;
  dt_txt = "";
  id_0 = 0;
  descriptions = "";
  temp_1 = 0;
  pressure_1 = 0;
  humidity_1 = 0;
  clouds_1 = 0;
  speed_1 = 0;
  deg_1 = 0;
  dt_txt_1 = "";
  id_1 = 0;
  description_1 = "";
  temp_2 = 0;
  location_wind_cdir_full = "";

  if (0 <= h < 3)pars = 12;
  if (3 <= h < 6)pars = 11;
  if (6 <= h < 9)pars = 10;
  if (9 <= h < 12)pars = 9;
  if (12 <= h < 15)pars = 8;
  if (15 <= h < 18)pars = 7;
  if (18 <= h < 21)pars = 6;
  if (21 <= h)pars = 5;
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String line = "";
    String serverPath = "http://api.openweathermap.org/data/2.5/forecast?lat=" + String(lat) + "&lon=" +  String(lon) + "&cnt=12&units=metric&appid=" + String(weatherKey0) + "&lang=ru";

    Serial.println("Getting weather");
    http.begin(serverPath);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.printf("    [HTTP] GET... code: %d\n", httpCode);
      if (httpCode != 200) {
        flagzapros = false;
      } else {
        flagzapros = true;
      }
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        line = http.getString();
      } else {
        Serial.println("connection for news data failed: " + String(serverPath)); //error message if no client connect
        Serial.println();
        return;
      }
    }

    http.end();
    const size_t capacity = JSON_OBJECT_SIZE(4) + 8192; //https://arduinojson.org/v6/assistant/
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, line);
    JsonObject list = doc["list"][0];
    temper = list["main"]["temp"];
    pressures = list["main"]["pressure"];
    humiditys = list["main"]["humidity"];
    cloudsis = list ["clouds"]["all"];
    speeder = list ["wind"]["speed"];
    deg = list ["wind"]["deg"];
    const char* locdt_txt = list ["dt_txt"];
    dt_txt = locdt_txt;
    JsonObject weather = list["weather"][0];
    id_0 = weather["id"];
    const char* locdescription = weather["description"];
    descriptions = locdescription;

    JsonObject list1 = doc["list"][pars];
    temp_1 = list1["main"]["temp"];
    pressure_1 = list1["main"]["pressure"];
    humidity_1 = list1["main"]["humidity"];
    clouds_1 = list1["clouds"]["all"];
    speed_1 = list1["wind"]["speed"];
    deg_1 = list1["wind"]["deg"];
    const char* locdt_txt_1 = list1["dt_txt"];
    dt_txt_1 = locdt_txt_1;
    JsonObject weather1 = list1["weather"][0];
    id_1 = weather1["id"];
    const char* locdescription_1 = weather1["description"];
    description_1 = locdescription_1;

    JsonObject list2 = doc["list"][pars - 3];
    temp_2 = list2["main"]["temp"];

    if (printCom) {
      Serial.print("Температура: ");
      Serial.print(temper);
      Serial.println("С");
      Serial.print("Давление: ");
      Serial.print(pressures / 1.355269, 0);
      Serial.println("ммРс");
      Serial.print("Влажность: ");
      Serial.print(humiditys);
      Serial.println("%");
      Serial.print("Код погоды: ");
      Serial.println(id_0);
      Serial.print("Облачность: ");
      Serial.print(cloudsis);
      Serial.println("%");
      Serial.print("Скорость ветра: ");
      Serial.print(speeder);
      Serial.println("м/с");
      Serial.print("Направление ветра: ");
      Serial.print(deg);
      Serial.println("°");
      Serial.println(descriptions);
      Serial.println(dt_txt);
      Serial.print("Температура завтра минимальная: ");
      Serial.print(temp_2);
      Serial.println("С");
      Serial.print("Температура завтра максимальная: ");
      Serial.print(temp_1);
      Serial.println("С");
      Serial.print("Давление завтра: ");
      Serial.print(pressure_1 / 1.355269, 0);
      Serial.println("ммРс");
      Serial.print("Влажность завтра: ");
      Serial.print(humidity_1);
      Serial.println("%");
      Serial.print("Код погоды завтра: ");
      Serial.println(id_1);
      Serial.print("Облачность завтра: ");
      Serial.print(clouds_1);
      Serial.println("%");
      Serial.print("Скорость ветра: ");
      Serial.print(speed_1);
      Serial.println("м/с");
      Serial.print("Направление ветра: ");
      Serial.print(deg_1);
      Serial.println("°");
      Serial.println(description_1);
      Serial.println(dt_txt_1);
      //Serial.println(line);
    }
    if (deg >= 345 || deg <= 22)  degString = "Северный";
    if (deg >= 23  && deg <= 68)  degString = "Северо-Восточный";
    if (deg >= 69  && deg <= 114) degString = "Восточный";
    if (deg >= 115 && deg <= 160) degString = "Юго-Восточный";
    if (deg >= 161 && deg <= 206) degString = "Южный";
    if (deg >= 207 && deg <= 252) degString = "Юго-Западный";
    if (deg >= 253 && deg <= 298) degString = "Западный";
    if (deg >= 299 && deg <= 344) degString = "Северо-Западный";
    location_wind_cdir_full = degString;

    if (deg_1 >= 345 || deg_1 <= 22)  degString1 = "Северный";
    if (deg_1 >= 23  && deg_1 <= 68)  degString1 = "Северо-Восточный";
    if (deg_1 >= 69  && deg_1 <= 114) degString1 = "Восточный";
    if (deg_1 >= 115 && deg_1 <= 160) degString1 = "Юго-Восточный";
    if (deg_1 >= 161 && deg_1 <= 206) degString1 = "Южный";
    if (deg_1 >= 207 && deg_1 <= 252) degString1 = "Юго-Западный";
    if (deg_1 >= 253 && deg_1 <= 298) degString1 = "Западный";
    if (deg_1 >= 299 && deg_1 <= 344) degString1 = "Северо-Западный";
    if (temp_2 > temp_1) {
      tempmax = temp_2;
      tempmin = temp_1;
    }
    if (temp_1 > temp_2) {
      tempmax = temp_1;
      tempmin = temp_2;
    }

    location_temp = temper;
    location_code = id_0;
    coded1 = id_1;
    tempfor2 = tempmax;
    weatherString = "         ";
    weatherStringZ = "         ";
    if (displayForecastNow) {
      if (temper > 0) {
        texttemp = "+" ;
        weatherString +=  "Сейчас в г " + String(gorod) + ":" + " температура " + texttemp + String(temper, 1) + "\260" + "С";
      } else {
        weatherString +=  "Сейчас в г " + String(gorod) + ":" + " температура " + String(temper, 1) + "\260" + "С";
      }
      weatherString += " влажность " + String(humiditys) + "% ";
      weatherString += "давление " + String(pressures / 1.355269, 0) + "ммРс ";
      weatherString += " ветер " + degString + " " + String(speeder, 1) + "м/с";
      weatherString += " облачность " + String(cloudsis) +  "% " + String(descriptions) + "                ";
    }
    //if (displayForecastTomorrow) {
    weatherStringZ += "Прогноз на завтра: температура от ";
    if (tempmin > 0) {
      texttempmin = "+" ;
      weatherStringZ += texttempmin + String(tempmin, 1) + " до ";
    } else {
      weatherStringZ += String(tempmin, 1) + " до ";
    }
    if (tempmax > 0) {
      texttempmax = "+" ;
      weatherStringZ += texttempmax + String(tempmax, 1) + "\260" + "C";
    } else {
      weatherStringZ += String(tempmax, 1) + "\260" + "C";
    }

    weatherStringZ += " влажность " + String(humidity_1) + "%";
    weatherStringZ += " ветер " + degString1 + " " + String(speed_1, 1);//+ tSpeed
    weatherStringZ += "м/с " + String(description_1);
    weatherStringZ += "                   ";

  }
}
