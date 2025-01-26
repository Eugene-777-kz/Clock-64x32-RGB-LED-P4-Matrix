
void getRelay()
{
  if(Serv == true){
   Serial.println(hron); 
   Serial.println(mron);
  if (h == hron && m == mron && s >= 00 && s <= 50) {reconnectid();client.publish(MQTT_SERIAL_PUBLISH_CH3, "ВКЛ"); if(printCom)Serial.println("ВКЛ");}
  if (h == hroff && m == mroff && s >= 00 && s <= 50) {reconnectid();client.publish(MQTT_SERIAL_PUBLISH_CH3, "ВЫКЛ");if(printCom)Serial.println("ВЫКЛ");}
  }
}
void getRelay1()
{
  if(Serv == true){
    if ((humBme <= HUM && wety == 1) || (humath <= HUM && wety == 2) || (htu.getHumidity() < HUM && wety == 4)) {        
    if(printCom){
    Serial.println(humath);
    Serial.println(HUM);
    }
    reconnectid();
    client.publish(MQTT_SERIAL_PUBLISH_CH4, "ВКЛ");
    if(printCom)Serial.println("ВКЛ");
   }else{
    reconnectid();
    client.publish(MQTT_SERIAL_PUBLISH_CH4, "ВЫКЛ");
    if(printCom)Serial.println("ВЫКЛ");
   }
  }
}
void getRelay2()
{
   if(Serv == true){
  if(printCom){
  Serial.println(mySensor.CO2);
  Serial.println(CO2);
  }
  if (mySensor.CO2 >= CO2) {
    reconnectid();
    client.publish(MQTT_SERIAL_PUBLISH_CH5, "ВКЛ");
    if(printCom)Serial.println("ВКЛ");
    }else{
    reconnectid();
    client.publish(MQTT_SERIAL_PUBLISH_CH5, "ВЫКЛ");
    if(printCom)Serial.println("ВЫКЛ");
    }
  }
}
void getRelay3()
{
    reconnectid();
    client.publish(MQTT_SERIAL_PUBLISH_CH3, "ВЫКЛ");
    client.publish(MQTT_SERIAL_PUBLISH_CH4, "ВЫКЛ");
    client.publish(MQTT_SERIAL_PUBLISH_CH5, "ВЫКЛ");
   
}
