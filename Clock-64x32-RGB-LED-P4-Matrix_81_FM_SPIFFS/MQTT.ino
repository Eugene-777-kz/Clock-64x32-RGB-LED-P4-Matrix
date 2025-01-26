void callback(char* topic, byte* payload, unsigned int length) {

    if(printCom){
    Serial.println("-------new message from broker-----");
    Serial.print("channel:");
    Serial.println(topic);
    Serial.print("data:");
    } 
    String strTopic = String(topic);
    String Text;
    
     for (int i = 0; i < length; i++){
      if(printCom)Serial.print((char)payload[i]);
      Text += ((char)payload[i]);
     }
     for (byte i = 0; i < 1; i++){
     Text += "";
    //Serial.println(Text);
     }
    if (String(topic) == MQTT_SERIAL_RECEIVER_CH1)file1 = Text;
    if (String(topic) == MQTT_SERIAL_RECEIVER_CH2)file2 = Text;
    if (String(topic) == MQTT_SERIAL_RECEIVER_CH3)file3 = Text;
    if (String(topic) == MQTT_SERIAL_RECEIVER_CH4)file4 = Text;
    if(file1 != 0){
    if(Text > "0")texttemp = '+';
    mqttstring = TEXT + texttemp + file1 + "\260С";
    }else{
      mqttstring = "Температура - нет данных ";
    }
    if(file2 != 0){
      mqttstring += TEXT1 + file2 + "%";
    }else{
      mqttstring += " Влажность - нет данных "; 
    }
    if(file3 != 0){
      mqttstring += TEXT2 + file3 + "ммРс.";
    }else{
     mqttstring += " Давление - нет данных ";  
    }

}
void reconnectid() {
  chm = 0;
  if(WiFi.status() == WL_CONNECTED){
    int mqtt_port = port.toInt();
      while (!client.connected()) {
      if(printCom)Serial.print("Attempting MQTT connection...");
     String clientId = "ESP8266Client-";
     clientId +=  WiFi.macAddress();
     if (client.connect(clientId.c_str(),MQTT_USER,MQTT_PASSWORD)) {
       if(printCom){
      Serial.println("connected");
      Serial.println(mqtt_server);
      Serial.println(mqtt_port);
      Serial.println(MQTT_USER);
      Serial.println(MQTT_PASSWORD);
        }
      if(RECEIVER_CH1 != 0){client.subscribe(MQTT_SERIAL_RECEIVER_CH1);Serial.println(MQTT_SERIAL_RECEIVER_CH1);}
      if(RECEIVER_CH2 != 0){client.subscribe(MQTT_SERIAL_RECEIVER_CH2);Serial.println(MQTT_SERIAL_RECEIVER_CH2);}
      if(RECEIVER_CH3 != 0){client.subscribe(MQTT_SERIAL_RECEIVER_CH3);Serial.println(MQTT_SERIAL_RECEIVER_CH3);}
      if(RECEIVER_CH4 != 0){client.subscribe(MQTT_SERIAL_RECEIVER_CH4);Serial.println(MQTT_SERIAL_RECEIVER_CH4);}
     
      nextmqtt = 0;
       } else {
      if(printCom){
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
       }
      chm++;
      delay(5000);
      if(chm == 5){
        Serv = false;
        nextmqtt = 1;
        saveConfig();
        break;
      }
    }
   }
  }else{
     w = 0;
     if (flagRTC == 1 && flagrtc == 1)Serv = false;
  }
}

void publmqtt()
{
     if (Serv == true) {
    if (!client.connected())reconnectid();
    switch(weti){
     case 1:client.publish(MQTT_SERIAL_PUBLISH_CH, String(tempBme + CorTemp, 1).c_str());break; 
     case 2:sensors_event_t temp;aht_temp->getEvent(&temp);client.publish(MQTT_SERIAL_PUBLISH_CH, String(temp.temperature + CorTemp, 1).c_str());break;
     case 3:client.publish(MQTT_SERIAL_PUBLISH_CH, String(tempBmp + CorTemp, 1).c_str());break;
     case 4:client.publish(MQTT_SERIAL_PUBLISH_CH, String(tempBmp + CorTemp, 1).c_str());break;
     case 5:client.publish(MQTT_SERIAL_PUBLISH_CH, String(htu.getTemperature() + CorTemp, 1).c_str());break;
     }
    switch(wety){
     case 1:client.publish(MQTT_SERIAL_PUBLISH_CH1, String(humBme + CorHum, 0).c_str());break;
     case 2:sensors_event_t humidity;aht_humidity->getEvent(&humidity);client.publish(MQTT_SERIAL_PUBLISH_CH1, String(humidity.relative_humidity + CorHum, 0).c_str());break;
     case 4:client.publish(MQTT_SERIAL_PUBLISH_CH1, String(htu.getHumidity() + CorHum, 0).c_str());break;
     }
    switch(wetu){
    case 1:client.publish(MQTT_SERIAL_PUBLISH_CH2, String(pressBme + corrPress, 0).c_str());break;
    case 2:
    if(POG == 0){client.publish(MQTT_SERIAL_PUBLISH_CH2, String((location_pres), 0).c_str());} 
    if(POG == 1){client.publish(MQTT_SERIAL_PUBLISH_CH2, String((pressures/1.355269), 0).c_str());}//
    if(POG == 2){client.publish(MQTT_SERIAL_PUBLISH_CH2, String((pressuredarc/1.33372), 0).c_str());}
    break;
    case 3:
    case 4:
    client.publish(MQTT_SERIAL_PUBLISH_CH2, String(pressBmp + corrPress, 0).c_str());
    break;
    }
    if(Mod1 == true){client.publish(MQTT_SERIAL_PUBLISH_CH7, String(mySensor.CO2).c_str());client.publish(MQTT_SERIAL_PUBLISH_CH6, String(mySensor.TVOC).c_str());}
  
  }
}
