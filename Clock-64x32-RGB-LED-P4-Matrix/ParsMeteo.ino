void Meteo() {
  summarydarc = "";
  temperaturedarc = 0;
  apparentTemperaturedarc = 0;
  humiditydarc = 0;
  pressuredarc = 0;
  windSpeeddarc = 0;
  windBearingdarc = 0;
  cloudCoverdarc = 0;
  summarydarc0 = "";
  temperatureHighdarc = 0;
  temperatureLowdarc = 0;
  humiditydarc0 = 0;
  pressuredarc0 = 0;
  windSpeeddarc0 = 0;
  windBearingdarc0 = 0;
  cloudCoverdarc0 = 0;
  location_wind_cdir_full = "";
  location_wind_cdir_full1 = "";

  if (0 <= h < 3)hcor = 36;
  if (3 <= h < 6)hcor = 33;
  if (6 <= h < 9)hcor = 30;
  if (9 <= h < 12)hcor = 27;
  if (12 <= h < 15)hcor = 24;
  if (15 <= h < 18)hcor = 21;
  if (18 <= h < 21)hcor = 18;
  if (21 <= h)hcor = 15;


  String line = "";
  String textcode = " ";
  String textcode1 = " ";
  String degString = " ";
  String degString1 = " ";
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    //String serverPath = "http://api.open-meteo.com/v1/forecast?latitude=" + String(lat) + "&longitude=" +String(lon) + "&hourly=temperature_2m,relativehumidity_2m,precipitation,weathercode,surface_pressure,cloudcover,windspeed_10m,winddirection_10m,windgusts_10m&daily=weathercode,temperature_2m_max,temperature_2m_min&current_weather=true&windspeed_unit=ms&timezone=auto&start_date=" + String(year) + "-" + String(months[month]) + "-" + String(day) + "&end_date=" + String(year) + "-" + String(months[month]) + "-" + String(day+1);

    String serverPath = "http://api.open-meteo.com/v1/forecast?latitude=" + String(lat) + "&longitude=" + String(lon) + "&hourly=temperature_2m,relativehumidity_2m,precipitation,weathercode,surface_pressure,cloudcover,windspeed_10m,winddirection_10m,windgusts_10m&daily=weathercode,temperature_2m_max,temperature_2m_min&current_weather=true&windspeed_unit=ms&timezone=auto";
    //String serverPath = "http://api.open-meteo.com/v1/forecast?latitude=52.43&longitude=30.97&hourly=temperature_2m,relativehumidity_2m,precipitation,weathercode,surface_pressure,cloudcover,windspeed_10m,winddirection_10m,windgusts_10m&current_weather=true";
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
    const size_t capacity = JSON_ARRAY_SIZE(10) + JSON_OBJECT_SIZE(3) + 32768; //https://arduinojson.org/v6/assistant/
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, line);
    //JsonObject list = doc["list"][0];
    //float temperature_2m = doc["hourly"]["temperature_2m"][h];//
    float windspeed_10m = doc["hourly"]["windspeed_10m"][h + hcor];
    windSpeeddarc0 = windspeed_10m;
    float surface_pressure = doc["hourly"]["surface_pressure"][h];
    pressuredarc = surface_pressure;
    float surface_pressure1 = doc["hourly"]["surface_pressure"][h + hcor];
    float temperature = doc["current_weather"]["temperature"];//темп сейчас
    temperaturedarc = temperature;
    float windspeed = doc["current_weather"]["windspeed"];//скорость ветра сейчас
    windSpeeddarc = windspeed;
    int winddirection = doc["current_weather"]["winddirection"];//направление
    int weathercode = doc["hourly"]["weathercode"][h];//код погоды
    int relativehumidity_2m = doc["hourly"]["relativehumidity_2m"][h];//влажность
    humiditydarc = relativehumidity_2m;
    int cloudcover = doc["hourly"]["cloudcover"][h];//облачность в %
    cloudCoverdarc = cloudcover;
    float temperature_2m_max = doc["daily"]["temperature_2m_max"][1];
    temperatureHighdarc = temperature_2m_max;
    float temperature_2m_min = doc["daily"]["temperature_2m_min"][1];
    temperatureLowdarc = temperature_2m_min;
    int weathercode1 = doc["hourly"]["weathercode"][h + hcor];//код погоды
    int winddirection_10m = doc["hourly"]["winddirection_10m"][h + hcor];//направление
    int relativehumidity_2m1 = doc["hourly"]["relativehumidity_2m"][h + hcor];//влажность
    humiditydarc0 = relativehumidity_2m1;
    Serial.println(line);

    if (winddirection >= 345 || winddirection <= 22)  degString = "Северный";
    if (winddirection >= 23  && winddirection <= 68)  degString = "Северо-Восточный";
    if (winddirection >= 69  && winddirection <= 114) degString = "Восточный";
    if (winddirection >= 115 && winddirection <= 160) degString = "Юго-Восточный";
    if (winddirection >= 161 && winddirection <= 206) degString = "Южный";
    if (winddirection >= 207 && winddirection <= 252) degString = "Юго-Западный";
    if (winddirection >= 253 && winddirection <= 298) degString = "Западный";
    if (winddirection >= 299 && winddirection <= 344) degString = "Северо-Западный";
    location_wind_cdir_full = degString;

    if (winddirection_10m >= 345 || winddirection_10m <= 22) degString1 = "Северный";
    if (winddirection_10m >= 23  && winddirection_10m <= 68)  degString1 = "Северо-Восточный";
    if (winddirection_10m >= 69  && winddirection_10m <= 114) degString1 = "Восточный";
    if (winddirection_10m >= 115 && winddirection_10m <= 160) degString1 = "Юго-Восточный";
    if (winddirection_10m >= 161 && winddirection_10m <= 206) degString1 = "Южный";
    if (winddirection_10m >= 207 && winddirection_10m <= 252) degString1 = "Юго-Западный";
    if (winddirection_10m >= 253 && winddirection_10m <= 298) degString1 = "Западный";
    if (winddirection_10m >= 299 && winddirection_10m <= 344) degString1 = "Северо-Западный";

    switch (weathercode) {
      case 0: textcode = "Ясно"; location_code = 800; break;
      case 1: textcode = "Преимущественно ясно"; location_code = 801; break;
      case 2: textcode = "переменная облачность"; location_code = 802; break;
      case 3: textcode = "плотная облачность"; location_code = 804; break;
      case 45: textcode = "Туман"; location_code = 701; break;
      case 48: textcode = "Изморозь"; location_code = 600; break;
      case 51: textcode = "Легкая морось"; location_code = 300; break;
      case 53: textcode = "Умеренная морось"; location_code = 300; break;
      case 55: textcode = "Плотная морось"; location_code = 300; break;
      case 56: textcode = "Легкая ледяная морось"; location_code = 300; break;
      case 57: textcode = "Плотная ледяная морось"; location_code = 300; break;
      case 61: textcode = "Слабый дождь"; location_code = 300; break;
      case 63: textcode = "Умеренный дождь"; location_code = 300; break;
      case 65: textcode = "Сильный дождь"; location_code = 300; break;
      case 66: textcode = "Ледяной легкий дождь"; location_code = 300; break;
      case 67: textcode = "Ледяной сильный дождь"; location_code = 300; break;
      case 71: textcode = "Легкий снегопад"; location_code = 601; break;
      case 73: textcode = "Умеренный снегопад"; location_code = 601; break;
      case 75: textcode = "Сильный снегопад"; location_code = 601; break;
      case 77: textcode = "Снежные зерна"; location_code = 601; break;
      case 80: textcode = "Ливнь слабый"; location_code = 313; break;
      case 81: textcode = "Ливень умеренный"; location_code = 313; break;
      case 82: textcode = "Ливень сильный"; location_code = 313; break;
      case 86: textcode = "Сильный снег"; location_code = 601; break;
      case 95: textcode = "Слабая гроза"; location_code = 200; break;
      case 96: textcode = "Гроза со слабым градом"; location_code = 200; break;
      case 99: textcode = "Гроза с сильным градом"; location_code = 200; break;
    }
    switch (weathercode1) {
      case 0: textcode1 = "Ясно"; coded1 = 800; break;
      case 1: textcode1 = "Преимущественно ясно"; coded1 = 801; break;
      case 2: textcode1 = "переменная облачность"; coded1 = 802; break;
      case 3: textcode1 = "плотная облачность"; coded1 = 804; break;
      case 45: textcode1 = "Туман"; coded1 = 701; break;
      case 48: textcode1 = "Изморозь"; coded1 = 600; break;
      case 51: textcode1 = "Легкая морось"; coded1 = 300; break;
      case 53: textcode1 = "Умеренная морось"; coded1 = 300; break;
      case 55: textcode1 = "Плотная морось"; coded1 = 300; break;
      case 56: textcode1 = "Легкая ледяная морось"; coded1 = 300; break;
      case 57: textcode1 = "Плотная ледяная морось"; coded1 = 300; break;
      case 61: textcode1 = "Слабый дождь"; coded1 = 300; break;
      case 63: textcode1 = "Умеренный дождь"; coded1 = 300; break;
      case 65: textcode1 = "Сильный дождь"; coded1 = 300; break;
      case 66: textcode1 = "Ледяной легкий дождь"; coded1 = 300; break;
      case 67: textcode1 = "Ледяной сильный дождь"; coded1 = 300; break;
      case 71: textcode1 = "Легкий снегопад"; coded1 = 601; break;
      case 73: textcode1 = "Умеренный снегопад"; coded1 = 601; break;
      case 75: textcode1 = "Сильный снегопад"; coded1 = 601; break;
      case 77: textcode1 = "Снежные зерна"; coded1 = 601; break;
      case 80: textcode1 = "Ливнь слабый"; coded1 = 313; break;
      case 81: textcode1 = "Ливень умеренный"; coded1 = 313; break;
      case 82: textcode1 = "Ливень сильный"; coded1 = 313; break;
      case 86: textcode1 = "Сильный снег"; coded1 = 601; break;
      case 95: textcode1 = "Слабая гроза"; coded1 = 200; break;
      case 96: textcode1 = "Гроза со слабым градом"; coded1 = 200; break;
      case 99: textcode1 = "Гроза с сильным градом"; coded1 = 200; break;
    }
    if (printCom) {
      Serial.print("Температура: ");
      Serial.print(temperature);
      Serial.println("С");
      Serial.print("Давление: ");
      Serial.print(surface_pressure / 1.33372, 0);
      Serial.println("ммРс");
      Serial.print("Влажность: ");
      Serial.print(relativehumidity_2m);
      Serial.println("%");
      //Serial.println(summary);
      Serial.print("Облачность: ");
      Serial.print(cloudcover);
      Serial.println("%");
      Serial.print("Скорость ветра: ");
      Serial.print(windspeed);
      Serial.println("м/с");
      Serial.print("Направление ветра: ");
      Serial.print(winddirection);
      Serial.println("°");
      Serial.print("Скорость ветра: ");
      Serial.print(windspeed_10m);
      Serial.println("м/с");
      Serial.println(degString);
      Serial.print("Код погоды: ");
      Serial.println(weathercode);
      Serial.println(textcode);


      Serial.print("Температура завтра минимальная: ");
      Serial.print(temperature_2m_min);
      Serial.println("С");
      Serial.print("Температура завтра максимальная: ");
      Serial.print(temperature_2m_max);
      Serial.println("С");
      Serial.print("Давление: ");
      Serial.print(surface_pressure1 / 1.33372, 0);
      Serial.println("ммРс");
      Serial.print("Влажность: ");
      Serial.print(relativehumidity_2m1);
      Serial.println("%");
      Serial.print("Направление ветра: ");
      Serial.print(winddirection_10m);
      Serial.println("°");
      Serial.println(degString1);
      Serial.print("Код погоды: ");
      Serial.println(weathercode1);
      Serial.println(textcode1);

      // Serial.println(line);
    }

    location_temp = temperaturedarc;
    tempfor2 = temperatureHighdarc;

    weatherString = "         ";
    weatherStringZ = "         ";
    if (displayForecastNow) {
      if (temperaturedarc > 0) {
        texttemp = "+" ;
        weatherString +=  "Сейчас в г " + String(gorod) + ":" + " температура " + texttemp + String(temperaturedarc, 1) + "\260" + "С";
      } else {
        weatherString +=  "Сейчас в г " + String(gorod) + ":" + " температура " + String(temperaturedarc, 1) + "\260" + "С";
      }
      weatherString += " влажность " + String(humiditydarc, 0) + "% ";
      weatherString += "давление " + String(pressuredarc / 1.33372, 0) + "ммРс ";
      weatherString += " ветер " + degString + " " + String(windSpeeddarc, 1) + "м/с";
      weatherString += " облачность " + String(cloudCoverdarc, 0) +  "% " + String(textcode) + "                ";
    }

    weatherStringZ += "Прогноз на завтра: температура от ";
    if (temperatureLowdarc > 0) {
      texttempmin = "+" ;
      weatherStringZ += texttempmin + String(temperatureLowdarc, 1) + " до ";
    } else {
      weatherStringZ += String(temperatureLowdarc, 1) + " до ";
    }
    if (temperatureHighdarc > 0) {
      texttempmax = "+" ;
      weatherStringZ += texttempmax + String(temperatureHighdarc, 1) + "\260" + "C";
    } else {
      weatherStringZ += String(temperatureHighdarc, 1) + "\260" + "C";
    }

    weatherStringZ += " влажность " + String(humiditydarc0, 0) + "%";
    weatherStringZ += " ветер " + degString1 + " " + String(windSpeeddarc0, 1);//+ tSpeed
    weatherStringZ += "м/с " + String(textcode1);
    weatherStringZ += "                   ";
  }
}
