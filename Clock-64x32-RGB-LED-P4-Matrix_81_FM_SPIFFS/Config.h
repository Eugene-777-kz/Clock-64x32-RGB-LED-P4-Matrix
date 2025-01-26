char MQTT_SERIAL_PUBLISH_CH[32] = "";//топик температуры публикация
char MQTT_SERIAL_PUBLISH_CH1[32] = "";//топик влажности публикация
char MQTT_SERIAL_PUBLISH_CH2[32] = "";//топик давления публикация
char MQTT_SERIAL_PUBLISH_CH3[32] = "";//топик реле1
char MQTT_SERIAL_PUBLISH_CH4[32] = "";//топик реле2
char MQTT_SERIAL_PUBLISH_CH5[32] = "";//топик реле3
char MQTT_SERIAL_PUBLISH_CH6[32] = "";//топик TVO
char MQTT_SERIAL_PUBLISH_CH7[32] = "";//топик CO2

char MQTT_SERIAL_RECEIVER_CH1[32] = "";//топик температуры
char MQTT_SERIAL_RECEIVER_CH2[32] = "";//топик влажности
char MQTT_SERIAL_RECEIVER_CH3[32] = "";//топик давления
char MQTT_SERIAL_RECEIVER_CH4[32] = "";//топик текст
char MQTT_SERIAL_RECEIVER_CH5[32] = "";//топик приема чего захотите
char MQTT_SERIAL_RECEIVER_CH6[32] = "";//топик приема чего захотите
String TEXT = "Температура: ";// Текст перед выводом данных вна экран MQTT
String TEXT1 = ", Влажность: ";
String TEXT2 = ", Давление: ";
String TEXT3 = "Курс валют ЦБРФ: ";
String weatherLang = "ru";
int sensors_ID0; // ID датчика температуры c народмона
int sensors_ID1; // ID датчика влажности c народмона
int sensors_ID2;// ID давление
int sensors_ID3;// ID ветер
int timezone = 3;// часовой пояс
int hof = 7;// начало воспроизведение времени, окончание ночного режима, от 00 до 23 часов
int minof = 0;
int hon = 23;// конец воспроизведения времени, начало ночного режима, от 00 до 23 часов
int minon = 0;
int MQTR = 0;
int hron = 10;
int hroff = 10;
int mron = 00;
int mroff = 00;
int sron = 00;
int sroff = 00;
uint8_t frameDelay = 4;// задержка кадра,скорость бегущей строки
uint8_t frameDelay1 = 4;
uint8_t frameDelay2 = 4;
uint8_t frameDelay3 = 4;
uint8_t frameDelay4 = 4;
uint8_t frameDelay5 = 4;
uint8_t frameDelay6 = 4;
uint8_t frameDelay7 = 4;
uint8_t frameDelay8 = 4;
uint8_t frameDelay9 = 4;
uint8_t frameDelay10 = 4;
uint8_t frameDelay11 = 4;
uint8_t frameDelay12 = 4;
uint8_t frameEff = 25;
uint8_t frameSkrull = 15;
int Y = 10;//Громкость плеера.
int EQ = 0;//Эквалайзер.
int CorTemp = 0;// коррекция температуры 
int  corrPress = 0;// коррекция давления 
int CorHum = 0;// коррекция влажности
int RGB = 3;// яркость от 1 до 5
int ekrPog = 10;
int ekrDom = 20;
int ekrKach = 10;
int ekrmqtt = 1;
int modBig = 0;
int POS = 0;
bool flagRTC = false;// Если есть RTC...1

// ВОСКРЕСЕНЬЕ
int Hbyd1 = 7;//часы будильника1-воскресенье
int Mbyd1 = 00;//минуты будильника1
bool Modbyd1;//включение будильника1
int mel1 = 0;// мелодия будильника
 
// ПОНЕДЕЛЬНИК
int Hbyd2 = 6;//часы будильника2-понедельник
int Mbyd2 = 30;//минуты будильника2
bool Modbyd2;//включение будильника2
int mel2 = 0;// мелодия будильника

// ВТОРНИК
int Hbyd3 = 6;//часы будильника3-вторник
int Mbyd3 = 30;//минуты будильника3
bool Modbyd3;//включение будильника3
int mel3 = 0;// мелодия будильника

// СРЕДА
int Hbyd4 = 6;//часы будильника4-среда
int Mbyd4 = 30;//минуты будильника4
bool Modbyd4;//включение будильника4
int mel4 = 0;// мелодия будильника

// ЧЕТВЕРГ
int Hbyd5 = 6;//часы будильника5-четверг
int Mbyd5 = 30;//минуты будильника5
bool Modbyd5;//включение будильника5
int mel5 = 0;// мелодия будильника

// ПЯТНИЦА
int Hbyd6 = 6;//часы будильника6-пятница
int Mbyd6 = 50;//минуты будильника6
bool Modbyd6;//включение будильника6
int mel6 = 0;// мелодия будильника

// СУББОТА
int Hbyd7 = 17;//часы будильника7-суббота
int Mbyd7 = 15;//минуты будильника7
bool Modbyd7;//включение будильника7
int mel7 = 0;// мелодия будильника

int Pov1 = 0;// 1-й повтор будильника
int Pov2 = 0;// 1-й повтор будильника
int Pov3 = 0;// 1-й повтор будильника
int Pov4 = 0;// 1-й повтор будильника
int Pov5 = 0;// 1-й повтор будильника
int Pov6 = 0;// 1-й повтор будильника
int Pov7 = 0;// 1-й повтор будильника
int MPov1 = 0;// минуты через сколько повторить
int MPov2 = 0;
int MPov3 = 0;
int MPov4 = 0;
int MPov5 = 0;
int MPov6 = 0;
int MPov7 = 0;
//int repit = 3;//количество повторений мелодии будильника
