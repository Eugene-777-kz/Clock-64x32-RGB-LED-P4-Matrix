void zppMqtt()
{
  publmqtt();
  if (MQTR == 1 && Serv == true)getRelay();
  if (MQTR == 2 && Serv == true)getRelay1();
  if (MQTR == 3 && Serv == true)getRelay2();
  if (MQTR == 4 && Serv == true) {
    getRelay();
    getRelay1();
    getRelay2();
  }
  if (MQTR == 0 && Serv == true)getRelay3();
}
