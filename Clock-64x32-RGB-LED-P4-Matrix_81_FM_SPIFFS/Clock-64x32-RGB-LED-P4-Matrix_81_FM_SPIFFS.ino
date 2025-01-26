#include <WiFi.h>
#include <WiFiManager.h>
#include <Wire.h>
#include <OneWire.h>
#include <GyverPortal.h>
#include <iarduino_RTC.h>
#include <time.h>
#include <SPI.h>
#include <DallasTemperature.h>
#include <RDA5807M.h> 
#include <FS.h>
#include <TimerMs.h>
#include "Adafruit_BME280.h"
#include "SparkFun_SGP30_Arduino_Library.h" 
#include <Adafruit_BMP280.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/TomThumb.h>
#include <Adafruit_Sensor.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <Ticker.h>
#include <NTPClient.h>
#include <DNSServer.h>
#include <DFRobotDFPlayerMini.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include "Config.h"
#include <ArduinoJson.h>
#include <Adafruit_AHTX0.h>
#include "imege.h"
#include "vozduh.h"
#include "Fonts.h"
#include <stdlib.h>
#include <GyverHTU21D.h>
GyverHTU21D htu;
Ticker display_ticker;
#define CLK  15
#define OE   33
#define LAT 32
#define A   12
#define B   16
#define C   17
#define D   18
#define matrix_width 64
#define matrix_height 32
OneWire oneWire(4);
DallasTemperature sensors(&oneWire);
#define FIX_BAND     RADIO_BAND_FM   
#define SEALEVELPRESSURE_HPA (1013.25)
unsigned long period_time = (long)1*24*60*60*1000;//раз в час
unsigned long work_time = 600000;//10 мин
#define TIMER_START 0    // 1 - отсчёт периода с момента ВЫКЛЮЧЕНИЯ , 0 - с ВКЛЮЧЕНИЯ
unsigned long period_timer, work_timer;
Adafruit_AHTX0 aht;
Adafruit_Sensor *aht_humidity, *aht_temp;
Adafruit_BME280 bme;
WiFiClient ESPclient;
HardwareSerial hwSerial(1);
DFRobotDFPlayerMini dfPlayer;
RDA5807M radio;
int hFMon,mFMon,hFMoff,mFMoff;
bool FMradio;
String listStation1,listStation2,listStation3,listStation4,listStation5,listStation6,listStation7,listStation8,nslist1,nslist2,nslist3,nslist4,nslist5,nslist6,nslist7,nslist8,textNst;
int stan;
int st;
int list1,list2,list3,list4,list5,list6,list7,list8;
int vol = 4;
byte UT = true;
//iarduino_RTC watch(RTC_DS1302, 2, 3, 4);                // Объявляем объект watch для работы с RTC модулем на базе чипа DS1302, указывая выводы Arduino подключённые к выводам модуля RST, CLK, DAT.
//iarduino_RTC watch(RTC_DS1307);                         // Объявляем объект watch для работы с RTC модулем на базе чипа DS1307, используется шина I2C.
iarduino_RTC watch(RTC_DS3231);                         // Объявляем объект watch для работы с RTC модулем на базе чипа DS3231, используется шина I2C.
// iarduino_RTC watch(RTC_RX8025);
float tempds = 0;  
int dst = 0;
int ii, nn;
float hd;
float td;
String rh;
String weatherString;
String weatherStringZ;
String mqttstring;
String weatherDescription = "";
String weatherLocation = "";
String sensorath;
static uint32_t lastTime = 0;
unsigned long start_time = 0;
unsigned long timing, timeNar, LostWiFiMillis, lastUpd, lastUpd1, lastUpd2, lastDay, lastScr; //Переменные для хранения точек отсчета
TimerMs tmr(10000, 1, 1);
TimerMs tmr1(2000, 1, 1);
TimerMs tmr2(1000, 1, 1);
TimerMs tmr3(800, 1, 1);
static bool flasher = false;
const char*textmqtt[] = { " температура: ", " влажность: ", " давление: ", " радиация: ",  " за 1 доллар - ", " за 1 евро - ", " за 1 руб.РФ - ", " за 1 гривну - ", " за 1 злотый - "};
const char*textmd[] = {" воскресенье",  " понедельник", " вторник", " среда", " четверг", " пятница", " суббота",};
const char* months[] = {"января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря"};
int Hb[] = {0, Hbyd1, Hbyd2, Hbyd3, Hbyd4, Hbyd5, Hbyd6, Hbyd7};
int Mb[] = {0, Mbyd1, Mbyd2, Mbyd3, Mbyd4, Mbyd5, Mbyd6, Mbyd7};
int ModBYD[] = {0, Modbyd1, Modbyd2, Modbyd3, Modbyd4, Modbyd5, Modbyd6, Modbyd7};
int mel;
int MPov;
int Pov;
int posnr[] = {56, 2, 11, 20, 29, 38, 47,};
int httpCode;
int x = 4, x1 = 5, x2 = 8, x3 = 0, x4 = 1, x5 = 6, x6 = 0, x7 = 4, e = 0, x8 = 4, x21 = 8, x22 = 8, x23 = 8, x24 = 8, x25 = 8, x26 = 8, x27 = 8, x28 = 8, x29 = 6, xob, x30 = 5, x31 = 0, x32 = 1, x33 = 2, x34 = 0, x35 = 4, x36 = 1, x37 = 2, x39 = 6, x40 = 5, x41 = 0, x42 = 6, x43 = 5, x44 = 0, x45 = 5, x46 = 0, x47 = 0, xnews = 3, xchut = 3, xvalu = 2, xprik = 8;
int h, m, s, d, yr, day, month, year, daynow;
uint8_t dow;
String date;
String text;
byte ll = 0;
int y, o, cc, j, U;
byte humidity, clouds, solar;                  //Влажность и облака и солнечная радиация в процентах
String name ;
unsigned int code;
String weather;
String tNow, tCurr, tPress, tPress0, tSpeed, tMin, tTom, tYour, tPoint, tIp, tPass, tWeatrNot, tWeatrTN;
int wind_dir, speed, pressure, pressurehPa, pres, temp;
String wind_spd;
String location, description; //Местоположение, погода, подробное описание погоды
uint8_t icon_index = 0;
unsigned int NewRTCh = 24;
unsigned int NewRTCm = 60;
unsigned int NewRTCs = 60;
static time_t last_t;
unsigned long epochNM;
char   personalCityName[51] = "";
bool LostWiFi = false;
bool printCom = true;
bool pressSys = 1;
bool displayCityName = true;
bool displayForecast = true;
bool displayForecastNow = true;
bool displayForecastToday = true;
bool displayForecastTomorrow = true;
bool updateForecastNot = true;
int updateForecast = 0;
int updateForecasttomorrow = 0;
char szTime[8];
char szMesg[20] = "";
char  szBuf[20];
const char*  win = "";
WiFiUDP ntpUDP;
HTTPClient http;
WiFiManager wm; // global wm instance
WiFiManagerParameter custom_field; // global param ( for non blocking w params )
WiFiClient wifiClient;
PubSubClient client(wifiClient);
#define MSG_BUFFER_SIZE  (200)
char msg[MSG_BUFFER_SIZE];
String weatherHost0 = "api.weatherbit.io";
String line;
byte httpErrCount = 0;
String texttd;
String texttempmin;
String texttempmax;
String texttemp;
String texttempBme;
String texttempBmp;
String texttempATH;
String textmonth;
String texttempNM;
String textkurs;
String textkurs1;
byte sch = 0;
String location_name = "";
String location_region = "";
String location_country = "";
String location_localtime = "";
float  location_temp;
float  location_app_temp;
int    location_rh;
float  location_pres;
int    location_code;

float temper;
float pressures;
int humiditys;
int cloudsis;
float speeder;
int deg;
String dt_txt ="";
int id_0;
String descriptions ="";
float temp_1;
float pressure_1;
int humidity_1;
int clouds_1;
float speed_1;
int deg_1;
String dt_txt_1 ="";
int id_1;
String description_1 ="";
float temp_2;

int    coded1;
int    mintext;
int    g = 9;
int    F = 300;// скорость анимации
float  location_wind_spd;
String location_wind_cdir_full = "";
String location_wind_cdir_full1 = "";
String location_sunrise = "";
String location_sunset = "";
int    location_clouds;
int    location_vis;
int    location_uv;
float  tempfor1;
float  tempfor2;
int   data_1_weather_code;
float data_1_max_temp;
float data_1_min_temp;
float data_1_wind_spd;
float valid_date_1;
float tempmin;
float tempmax;
float tempNM = 0.0;
float pressNM = 0;
float humNM = 0;
float vetNM = 0;
float cloutNM = 0;
float tempGY = 0;
float humGY = 0;
float tempBme = 0;
float humBme = 0;
float pressBme = 0;
float altBme = 0;
float temp1 = 0;
float humidity1 = 0;
float humAT = 0;
float tempAT = 0;
Adafruit_BMP280 bmp;
Adafruit_BMP085 bmp180;
float tempBmp = 0;
float pressBmp = 0;
float altBmp = 0;
bool bmp280 = false;
bool BMP180 = false;
String location_weather_description = "";
uint8_t display_draw_time = 50; //10-50 is usually fine
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);

uint16_t myRED = matrix.Color333(1,0,0);
uint16_t myGREEN = matrix.Color333(0,1,0);
uint16_t myBLUE = matrix.Color333(0,0,1);
uint16_t myWHITE = matrix.Color333(1, 1,1);
uint16_t myYELLOW = matrix.Color333(1,1,0);
uint16_t myCYAN = matrix.Color333(0,1,1);
uint16_t myMAGENTA = matrix.Color333(1,0,1);
uint16_t myShadow = matrix.Color333(3,0,1);
uint16_t myROSE = matrix.Color333(1,0,3);
uint16_t myORANGE = matrix.Color333(3,1,0);


uint16_t myRED1 = matrix.Color333(2,0,0);
uint16_t myGREEN1 = matrix.Color333(0,2,0);
uint16_t myBLUE1 = matrix.Color333(0,0,2);
uint16_t myWHITE1 = matrix.Color333(2, 2,2);
uint16_t myYELLOW1 = matrix.Color333(2,2,0);
uint16_t myCYAN1 = matrix.Color333(0,2,2);
uint16_t myMAGENTA1 = matrix.Color333(2,0,2);
uint16_t myShadow1 = matrix.Color333(4,0,2);
uint16_t myROSE1 = matrix.Color333(2,0,4);
uint16_t myORANGE1 = matrix.Color333(4,2,0);

uint16_t myRED2 = matrix.Color333(3,0,0);
uint16_t myGREEN2 = matrix.Color333(0,3,0);
uint16_t myBLUE2 = matrix.Color333(0,0,3);
uint16_t myWHITE2 = matrix.Color333(3,3,3);
uint16_t myYELLOW2 = matrix.Color333(3,3,0);
uint16_t myCYAN2 = matrix.Color333(0,3,3);
uint16_t myMAGENTA2 = matrix.Color333(3,0,3);
uint16_t myShadow2 = matrix.Color333(4,0,2);
uint16_t myROSE2 = matrix.Color333(2,0,4);
uint16_t myORANGE2 = matrix.Color333(4,2,0);

uint16_t myRED3 = matrix.Color333(4,0,0);
uint16_t myGREEN3 = matrix.Color333(0,4,0);
uint16_t myBLUE3 = matrix.Color333(0,0,4);
uint16_t myWHITE3 = matrix.Color333(4,4,4);
uint16_t myYELLOW3 = matrix.Color333(4,4,0);
uint16_t myCYAN3 = matrix.Color333(0,4,4);
uint16_t myMAGENTA3 = matrix.Color333(4,0,4);
uint16_t myShadow3 = matrix.Color333(5,0,3);
uint16_t myROSE3 = matrix.Color333(3,0,5);
uint16_t myORANGE3 = matrix.Color333(5,3,0);

uint16_t myRED4 = matrix.Color333(5,0,0);
uint16_t myGREEN4 = matrix.Color333(0,5,0);
uint16_t myBLUE4 = matrix.Color333(0,0,5);
uint16_t myWHITE4 = matrix.Color333(5,5,5);
uint16_t myYELLOW4 = matrix.Color333(5,5,0);
uint16_t myCYAN4 = matrix.Color333(0,5,5);
uint16_t myMAGENTA4 = matrix.Color333(5,0,5);
uint16_t myShadow4 = matrix.Color333(6,0,3);
uint16_t myROSE4 = matrix.Color333(3,0,6);
uint16_t myORANGE4 = matrix.Color333(6,3,0);

uint16_t myRED5 = matrix.Color333(6,0,0);
uint16_t myGREEN5 = matrix.Color333(0,6,0);
uint16_t myBLUE5 = matrix.Color333(0,0,6);
uint16_t myWHITE5 = matrix.Color333(6,6,6);
uint16_t myYELLOW5 = matrix.Color333(6,6,0);
uint16_t myCYAN5 = matrix.Color333(0,6,6);
uint16_t myMAGENTA5 = matrix.Color333(6,0,6);
uint16_t myShadow5 = matrix.Color333(7,0,3);
uint16_t myROSE5 = matrix.Color333(3,0,7);
uint16_t myORANGE5 = matrix.Color333(7,3,0);
 
uint16_t myRED6 = matrix.Color333(1, 0, 0);
uint16_t myGREEN6 = matrix.Color333(0, 1, 0);
uint16_t myBLUE6 = matrix.Color333(0, 0, 1);
uint16_t myWHITE6 = matrix.Color333(1, 1, 1);
uint16_t myYELLOW6 = matrix.Color333(1, 1, 0);

//uint16_t myCOLORS[][10] = {{myRED1, myGREEN1, myWHITE1, myMAGENTA1, myBLUE1, myYELLOW1, myCYAN1, myShadow1, myROSE1, myORANGE1},{myRED, myGREEN, myWHITE, myMAGENTA, myBLUE, myYELLOW, myCYAN, myShadow, myROSE,  myORANGE},{myRED2, myGREEN2, myWHITE2, myMAGENTA2, myBLUE2, myYELLOW2, myCYAN2, myShadow2, myROSE2,  myORANGE2}};
uint16_t myCOLORS[][10] = {{myRED, myGREEN, myWHITE, myMAGENTA, myBLUE, myYELLOW, myCYAN, myShadow, myROSE,  myORANGE},{myRED1, myGREEN1, myWHITE1, myMAGENTA1, myBLUE1, myYELLOW1, myCYAN1, myShadow1, myROSE1,  myORANGE1},{myRED2, myGREEN2, myWHITE2, myMAGENTA2, myBLUE2, myYELLOW2, myCYAN2, myShadow2, myROSE2,  myORANGE2},{myRED3, myGREEN3, myWHITE3, myMAGENTA3, myBLUE3, myYELLOW3, myCYAN3, myShadow3, myROSE3,  myORANGE3},{myRED4, myGREEN4, myWHITE4, myMAGENTA4, myBLUE4, myYELLOW4, myCYAN4, myShadow4, myROSE4,  myORANGE4},{myRED5, myGREEN5, myWHITE5, myMAGENTA5, myBLUE5, myYELLOW5, myCYAN5, myShadow5, myROSE5,  myORANGE5}};

uint16_t myCOLORN[5] = {myRED6, myGREEN6, myBLUE6, myWHITE6, myYELLOW6};
uint16_t myCOLORZ[][1] = {{myCYAN},{myCYAN1},{myCYAN2},{myCYAN3},{myCYAN4},{myCYAN5}};
uint16_t myCOLORA[][6] = {{myRED, myGREEN, myBLUE, myYELLOW, myCYAN, myMAGENTA},{myRED1, myGREEN1, myBLUE1, myYELLOW1, myCYAN1, myMAGENTA1},{myRED2, myGREEN2, myBLUE2, myYELLOW2, myCYAN2, myMAGENTA2},{myRED3, myGREEN3, myBLUE3, myYELLOW3, myCYAN3, myMAGENTA3},{myRED4, myGREEN4, myBLUE4, myYELLOW4, myCYAN4, myMAGENTA4},{myRED5, myGREEN5, myBLUE5, myYELLOW5, myCYAN5, myMAGENTA5}};


uint16_t myBLACK = matrix.Color333(0, 0, 0);
uint16_t myCOLORSW[4] = {myRED, myBLACK, myWHITE, myGREEN};
int Modsen = 0;
int Modsen1 = 0;
int ModTD = 0;// Точка доступа отключена.
bool M1, M2, M3, M4, M5;
bool Mod1;
int MG = 1;
int Mgl = 23;
//bool ModPl = true;//========================================================
bool Modebst1,Modebst2,Modebst3,Serv,Modmqtt,Modekr1,Modekr2,Modekr3,Modebst4,Modenews,Modenewspod,flagpr;
bool Modebst5 = true;
int modfch = 0;
int modfss = 0;
int fch = 0;
int fss = 1;
int ModN = 0;
int ModB = 0;
int modNul = 0;
int ModNreg = 0;
int pos = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
SGP30 mySensor;
int counter = 0;
int NarFlag;
int ModKey = 0;
String tmod1, tmod2, tmod3, tmod4, tmod5, tmod6, tmod7;
int modchrift = 0;
int font = 0;//
int address = 0;
int hbigon = 10;
int hbigoff = 17;
int mbigon = 0;
int mbigoff = 0;
int str = 0;
int FlagNr = 0;
bool BCH;
bool MNR;
String file1, file2, file3, file4, file5, file6, file7, file8, file9;
int chm = 0;
int w = 2;
int r = 0;
bool effekt;
int freq = 2000;
int channel = 0;
int resolution = 8;
String TextU;
const char*Moddat1[] = {"NO",  "BME280", "WB", "BMP280", "BMP180",};//давление//wetu
const char*Moddat2[] = {"NO",  "BME280", "AHTXX", "BMP280", "BMP180", "GY21",};//температура//weti
const char*Moddat3[] = {"NO",  "BME280", "AHTXX", "NM", "GY21",};//влажность//wety
int weti;
int wety;
int wetu;
int HUM = 40;
int CO2 = 800;
int co2;
String Domtemhumpres;
String Budilaki;
int nextmqtt = 0;
String tex = " ";
String tex1 = " ";
int humath;
int modPleer = 0;
int mem = 0;
int W = 0;
int PLR = 1;
bool PLU = false;
int flagrtc = 0;
int flagpbudik = 0;
int cords18 = 0;
int ModFM = 0;
//int pod = 0;
bool bz;
int papk = 4;//изм
bool modtoch = false;
bool ser = false;
bool modAnclock = false;
bool modeffeck1; 
int xef = 0;
int yef = 8;
int zadef = 75;
bool ANCKL = true;
int Ball = 0;
int ballef = 75;
String Novosti;
int newsIndex = 0;
String Novosti1;
String Novine;
int myS = 0;
bool kch = false;
String location_news = "";
String location_fulnews = "";
String location_news1 = "";
String location_fulnews1 = "";
String location_news2 = "";
String location_fulnews2 = "";
String location_news3 = "";
String location_fulnews3 = "";
String location_news4 = "";
String location_fulnews4 = "";
String location_news5 = "";
String location_fulnews5 = "";
String location_news6 = "";
String location_fulnews6 = "";
String location_news7 = "";
String location_fulnews7 = "";
String location_news8 = "";
String location_fulnews8 = "";
String location_news9 = "";
String location_fulnews9 = "";
String location_anek = "";
String location_awt = "";
String degString1;
String degString;

float usd;
float eur;
float byn;
float uah;
bool chut = false;
bool chutflag = false;
bool pogflag = false;
bool pog_forflag = false;
bool flagMap = false;
bool nmonflag = false;
bool newsflag = false;
bool valu = false;
int np = 0;
int hcor;
String nowosti = "";
String nowostidiscript = "";
String location_newsreplase = "";
String aforizm;
int framflag = 0;
int pars;
int POG = 2;
String summarydarc ="";
float temperaturedarc;
float apparentTemperaturedarc;
float humiditydarc;
float pressuredarc;
float windSpeeddarc;
float windBearingdarc;
float cloudCoverdarc; 
String summarydarc0 = "";
String valutedok = "";
String segodnya ="";
float temperatureHighdarc;
float temperatureLowdarc;
float humiditydarc0;
float pressuredarc0;
float windSpeeddarc0;
float windBearingdarc0;
float cloudCoverdarc0;
bool flagDarc = false;
bool flagstring = true;
bool flagval = true;
bool flagP;
// переменные

String gorod, lat, lon, weatherKey0, uuid, api_key;// myApiKey=9bfa63c56c564757bca37af0ff257d30
char mqtt_server[25] = "";
int  mqtt_port;
char MQTT_USER[16] = "";
char MQTT_PASSWORD[16] = "";
String servername = "newsapi.org";  // remote server we will connect to//9bfa63c56c564757bca37af0ff257d30//newsapi.org
String mySource = "";//entertainment//health//science//sport//technology//business
String myApiKey;//9bfa63c56c564757bca37af0ff257d30

String server, port, USER, PASSWORD, PUBLISH_CH, PUBLISH_CH1, PUBLISH_CH2, PUBLISH_CH3, PUBLISH_CH4, PUBLISH_CH5, PUBLISH_CH6, PUBLISH_CH7,RECEIVER_CH1, RECEIVER_CH2, RECEIVER_CH3, RECEIVER_CH4,  RECEIVER_CH5, RECEIVER_CH6;
String ID0, ID1, ID2, ID3;
String Text;

bool web = 0;;
int m9 = 0;
int null;
long lastMsg = 0;
String textpr = "";
String jsonConfig = "{}";
String jsonPrazdnik = "{}";
String payload;
const char* nprik;
int iprik;
String BUFFER;
String inString = "";
int kategpr;
int ktg = 0;
bool prikflag = true;
bool prik = true;
String textprik;
GyverPortal portal;

void getHome()
{
  if (Modbyd1 == 1) tmod1 = "Вс.$";
  if (Modbyd2 == 1) tmod2 = "Пн.$";
  if (Modbyd3 == 1) tmod3 = "Вт.$";
  if (Modbyd4 == 1) tmod4 = "Ср.$";
  if (Modbyd5 == 1) tmod5 = "Чт.$";
  if (Modbyd6 == 1) tmod6 = "Пт.$";
  if (Modbyd7 == 1) tmod7 = "Сб.";
}
void getStr2()
{ 
    xob = x21;
    flagstring = false;
    segodnya = " ";
    segodnya += "Сегодня ";
    segodnya += String(day);
    segodnya += " ";
    segodnya += months[month];
    segodnya += " ";
    segodnya += String(year);
    segodnya += " года ";
    segodnya += textmd[dow - 1];
    if(flagpr == true){
     segodnya += " "; 
     segodnya += textpr; 
    }
    if (Modebst5 == true)scroll_text(24, framflag = frameDelay7, (segodnya));
}
void getStr3()
{  
     Budilaki = "    ";
     Budilaki += "Будильник включен на ";
     if(Modbyd1 == true)Budilaki += String(tmod1);
     if(Modbyd2 == true)Budilaki += String(tmod2);
     if(Modbyd3 == true)Budilaki += String(tmod3);
     if(Modbyd4 == true)Budilaki += String(tmod4);
     if(Modbyd5 == true)Budilaki += String(tmod5);
     if(Modbyd6 == true)Budilaki += String(tmod6);
     if(Modbyd7 == true)Budilaki += String(tmod7);
     if ( Modbyd1 == true || Modbyd2 == true || Modbyd3 == true || Modbyd4 == true || Modbyd5 == true || Modbyd6 == true || Modbyd7 == true)scroll_text(24, framflag = frameDelay, (Budilaki));
}
void getStr4()
{
    xob = x22;
    if (Modebst1 == true && flagrtc == 0 && kch == true)scroll_text(24, framflag = frameDelay, (weatherString));
     pogflag = false;
     flagMap = false;
     flagDarc = false;
}
void getStr5()
{
    if (m < 55 && Modmqtt == false && Serv == true && (file1 != 0 || file2 != 0 || file3 != 0 || file5 != 0 || file6 != 0)){xob = x28;scroll_text(24, framflag = frameDelay5, (" MQTT  " + mqttstring));}
}
void getStr6()
{
    xob = x23;
    if (Modebst2 == true && flagrtc == 0 && kch == true)scroll_text(24, framflag = frameDelay1, (weatherStringZ));
    pog_forflag = false;
    flagMap = false;
    flagDarc = false;
}
void getStr7()
{
    if(flagrtc == 1)scroll_text2(24, framflag = frameDelay, ("Нет wi-fi!!!"));
}
void getStr8() 
{
    if (NarFlag == 1 && Modebst3 == true && flagrtc == 0) {
      xob = x24;
      if (tempNM > 0) {
       texttempNM = "+" ;
        scroll_text(24, framflag = frameDelay2, ("Народный мониторинг - Сейчас на улице Температура: " + texttempNM + String(tempNM, 1) + "\260С"));
      } else {
        scroll_text(24, framflag = frameDelay2, ("Народный мониторинг - Сейчас на улице Температура: " + String(tempNM, 1) + "\260C"));
      }
    }
    nmonflag = false;
}
void getStr9() 
{
    xob = x25;
    if(file4 != 0){scroll_text(24, framflag = frameDelay5, ("Текстовое сообщение - " + String(file4))); }
}
void getSens()
{
  Domtemhumpres = "    ";
     Domtemhumpres += "В помещении";
     if(weti == 1 || weti == 2 || weti == 3 || weti == 4 || weti == 5)Domtemhumpres += ", температура: +";
     if(weti == 1){getsensorsBme();Domtemhumpres += String(tempBme + CorTemp, 0);}
     if (weti == 2){getsensorsAth();sensors_event_t temp;aht_temp->getEvent(&temp);Domtemhumpres += String(temp.temperature + CorTemp, 0);}
     if (weti == 3){sensorsBmp280();Domtemhumpres += String(tempBmp + CorTemp, 0);}
     if (weti == 4){sensorsBmp180();Domtemhumpres += String(tempBmp + CorTemp, 0);}
     if (weti == 5){getsensGY21();Domtemhumpres += String(htu.getTemperature() + CorTemp, 0);}
     if (weti == 1 || weti == 2 || weti == 3 || weti == 4 || weti == 5)Domtemhumpres += "\260C,";
     if (wety == 1 || wety == 2 || wety == 3 || wety == 4)Domtemhumpres += " влажность: ";
     if (wety == 1)Domtemhumpres += String(humBme + CorHum, 0);
     if (wety == 2) {getsensorsAth();sensors_event_t humidity;aht_humidity->getEvent(&humidity);Domtemhumpres += String(humidity.relative_humidity + CorHum, 0);}
     if (wety == 3)Domtemhumpres += String(humNM , 0);
     if (wety == 4){getsensGY21();Domtemhumpres += String(htu.getHumidity(), 0);}
     if (wety == 1 || wety == 2 || wety == 3 || wety == 4)Domtemhumpres += "%";
     if (wetu == 1 ||(wetu == 2 && Modebst1 == true) || wetu == 3 || wetu == 4)Domtemhumpres += ", давление: " ;
     if (wetu == 1){getsensorsBme();Domtemhumpres += String(pressBme + corrPress, 0);}
     if (wetu == 2 && Modebst1 == true && POG == 0)Domtemhumpres += String((location_pres), 0) + (pressSys == 1 ? tPress : tPress0);
     if (wetu == 2 && Modebst1 == true && POG == 1)Domtemhumpres += String(pressures/1.355269, 0);
     if (wetu == 2 && Modebst1 == true && POG == 2)Domtemhumpres += String(pressuredarc/1.33372, 0);
     if (wetu == 3){sensorsBmp280();Domtemhumpres += String(pressBmp + corrPress, 0);}
     if (wetu == 4){sensorsBmp180();Domtemhumpres += String(pressBmp + corrPress, 0);}
     if (wetu == 1 ||(wetu == 2 && Modebst1 == true)|| wetu == 3 || wetu == 4)Domtemhumpres += " ммРс";
     if (FlagNr != 1 && Modebst4 == true){xob = x26;scroll_text(24, framflag = frameDelay6, (Domtemhumpres));}
}
void getStr10() 
{       
      if (Modsen == 1 && FlagNr != 1) {
      getds18b20();
      if(tempds != -127){
      if (tempds > 0){
      TextU = "+";
      scroll_text2(24, frameDelay+6, ("Улица:" + TextU + String(tempds + cords18, 0) + "\260"));
      }else{
      scroll_text2(24, frameDelay+6, ("Улица:" + String(tempds + cords18, 0) + "\260")); 
      }
String location_news = "";
    }else{
     scroll_text2(24, frameDelay + 10, ("Нет ds!!!"));  
    }
  }
}
void getStr11()
{    
     if(Text != 0){xob = x27;scroll_text(24, framflag = frameDelay3, (Text));}
    
}
void getStr12()
{   
      if(FlagNr != 1 && Modenews == true && location_news != 0){xob = xnews;rep(); repl();scroll_text(24, framflag = frameDelay8,("Новости : " + nowosti));}
     
}
void getStr13()
{   
      if(FlagNr != 1 && BUFFER != 0){xob = xprik;scroll_text(24, framflag = frameDelay12,(textprik + BUFFER));}
      prikflag  = false;
}
void getStr14()
{  
     aforizm = "      ";
     aforizm += "Афоризм : ";
     aforizm += location_anek;
     if(location_awt != 0){
     aforizm += " Автор : ";
     aforizm += location_awt;
     }
      if(FlagNr != 1 && chut == true && location_anek != 0){xob = xchut;repl();scroll_text(24, framflag = frameDelay10,(aforizm));chutflag = false;}
}
void getStr15()
{  
     valutedok = " ";
     valutedok += "1 доллар = ";
     valutedok += String(usd, 2);
     valutedok += " рублей. ";
     valutedok += "1 евро = ";
     valutedok += String(eur, 2);
     valutedok += " рублей. ";
     valutedok += "1 беллоруский рубль = ";
     valutedok += String(byn, 2);
     valutedok += " рублей. ";
       
      flagstring = false;
      if(FlagNr != 1 && valu == true){xob = xvalu;scroll_text(24, framflag = frameDelay11,(valutedok));}
      flagval = false;
}
void rep()
{
  nowosti.reserve(500);
  nowostidiscript.reserve(1000);
  switch(np){
 case 0:nowosti = location_news;nowostidiscript = location_fulnews;break;
 case 1:nowosti = location_news1;nowostidiscript = location_fulnews1;break;
 case 2:nowosti = location_news2;nowostidiscript = location_fulnews2;break;
 case 3:nowosti = location_news3;nowostidiscript = location_fulnews3;break;
 case 4:nowosti = location_news4;nowostidiscript = location_fulnews4;break;
 case 5:nowosti = location_news5;nowostidiscript = location_fulnews5;break;
 case 6:nowosti = location_news6;nowostidiscript = location_fulnews6;break;
 case 7:nowosti = location_news7;nowostidiscript = location_fulnews7;break;
 case 8:nowosti = location_news8;nowostidiscript = location_fulnews8;break;
 case 9:nowosti = location_news9;nowostidiscript = location_fulnews9;break;
  }
}
void repl()
{
 nowosti.replace("»", ">");
 nowosti.replace("«", "<");
 nowostidiscript.replace("»", ">");
 nowostidiscript.replace("«", "<"); 
 nowosti.replace("–", "-");
 nowostidiscript.replace("–", "-");
 nowosti.replace("—", "-");
 nowostidiscript.replace("—", "-");
 nowosti.replace("╜", "-");
 nowostidiscript.replace("╜", "-");
 nowosti.replace("вВ", "в");
 nowostidiscript.replace("ДоВ", "До");
 nowosti.replace("…", "...");
 nowostidiscript.replace("…", "...");
 aforizm.replace("»", ">");
 aforizm.replace("«", "<");
 aforizm.replace("—", "-");

}
void getGov_vrema()
{
  if(MG == 3 && flagpbudik == 0)buser(); 
  else {dfPlayer.playFolder(Mgl, h);yield();}
}
void getDate()
{
  matrix.fillRect(49, 7, 14, 9, myBLACK);//
  matrix.setFont(&fontss[1]);
  matrix.setCursor(49, 14);
  switch(dow){
  case 1: 
    matrix.setTextColor(myCOLORS[e][x6]);
    matrix.print("Bc");
  break;
  case 2:
    matrix.setTextColor(myCOLORS[e][x5]);
    matrix.print("Kn");
  break;
  case 3:
    matrix.setTextColor(myCOLORS[e][x5]);
    matrix.print("Bt");
  break;
  case 4:
    matrix.setTextColor(myCOLORS[e][x5]);
    matrix.print("Cp");
  break;
  case 5:
    matrix.setTextColor(myCOLORS[e][x5]);
    matrix.print("Ht");
  break;
  case 6:
    matrix.setTextColor(myCOLORS[e][x5]);
    matrix.print("Kt");
  break;
  case 7: 
    matrix.setTextColor(myCOLORS[e][x6]);
    matrix.print("Cb");
  break;
  }
  matrix.setFont();
}
void getDate1()
{
  matrix.fillRect(0, 0, 64, 7, myBLACK);//
  matrix.setFont(&fontss[1]);
  matrix.setTextColor(myCOLORS[e][x3]);
  if (day < 10 && (months[month] == months[0] || months[month] == months[3] || months[month] == months[10])) matrix.setCursor(9, 5); // 1
  if (day >= 10 && (months[month] == months[0] || months[month] == months[3] || months[month] == months[10])) matrix.setCursor(6, 5); // 10 января-апреля-ноября
  if (day < 10 && (months[month] == months[1])) matrix.setCursor(5, 5); // 1
  if (day >= 10 && (months[month] == months[1])) matrix.setCursor(2, 5); // 10 февраля
  if (day < 10 && (months[month] == months[2])) matrix.setCursor(11, 5); // 1
  if (day >= 10 && (months[month] == months[2])) matrix.setCursor(8, 5); // 10 марта
  if (day < 10 && (months[month] == months[4])) matrix.setCursor(17, 5); // 1
  if (day >= 10 && (months[month] == months[4])) matrix.setCursor(14, 5); // 10 мая
  if (day < 10 && (months[month] == months[5] || months[month] == months[6])) matrix.setCursor(14, 5); // 1
  if (day >= 10 && (months[month] == months[5] || months[month] == months[6])) matrix.setCursor(11, 5); // 10 июня-июля
  if (day < 10 && (months[month] == months[7] || months[month] == months[9] || months[month] == months[11])) matrix.setCursor(6, 5); // 1
  if (day >= 10 && (months[month] == months[7] || months[month] == months[9] || months[month] == months[11])) matrix.setCursor(3, 5); // 10 августа-октября-декабря
  if (day < 10 && (months[month] == months[8])) matrix.setCursor(3, 5); // 1
  if (day >= 10 && (months[month] == months[8])) matrix.setCursor(0, 5); // 10 сентября
  matrix.print(String(day));
  matrix.setFont(&fontsk[0]);
  matrix.setTextColor(myCOLORS[e][x4]);
  matrix.println(utf8rus(String(months[month])));
  matrix.setFont();
  matrix.swapBuffers(true);
}
void getRTCh(char *psz)
{
  sprintf(psz, "%02d", h);
  matrix.setCursor(1, 15);//16
  matrix.setFont(&fonts[fch]);
  matrix.setTextColor(myCOLORS[e][x]);
  matrix.fillRect(0, 8, 20, 15, myBLACK);//if (NewRTCh != h)matrix.fillRect(0, 8, 20, 15, myBLACK);
  matrix.print(szTime);
  matrix.setFont();
  matrix.swapBuffers(true);
  if (h < 10) matrix.fillRect(0, 8, 10, 14, myBLACK);
   NewRTCh = h;
}
void getRTCm(char *psz)
{
  sprintf(psz, "%02d", m);
  matrix.setCursor(27, 15);//16
  matrix.setFont(&fonts[fch]);
  matrix.setTextColor(myCOLORS[e][x]);
  matrix.fillRect(26, 8, 20, 15, myBLACK);//if (NewRTCm != m)matrix.fillRect(26, 8, 20, 15, myBLACK);
  matrix.print(szTime);
  matrix.setFont();
  matrix.swapBuffers(true);
  NewRTCm = m;
}
void getTim(char *psz, bool f)
{
  int pozx = 0;
  int pozy = 0;
  matrix.setCursor(22, 12);
  matrix.setTextSize(1);
  matrix.setTextColor(myCOLORS[e][x]);
  matrix.fillRect(20, 10, 7, 13, myBLACK);
  matrix.setFont(&fonts[fch]);
  matrix.print(":"); 
  matrix.setTextSize(1);
  matrix.fillRect(47, 12, 17, 10, myBLACK);
  matrix.setFont(&fonts[fch]);
  if (s % 2 == 0) {
      if (modtoch == false)matrix.fillRect(22, 12, 4, 2, myBLACK);
      if(modtoch == true){matrix.fillRect(22, 11, 4, 2, myBLACK);matrix.fillRect(22, 17, 4, 2, myBLACK);}
    }
  if (s % 2 != 0) {
  if (modtoch == false)matrix.fillRect(22, 16, 4, 2, myBLACK);
    }
  matrix.setFont();
  matrix.setCursor(49, 15);
  matrix.setTextColor(myCOLORS[e][x1]);
  sprintf(psz, "%02d", s);
  matrix.fillRect(49, 16, 13, 6, myBLACK);//
  matrix.setFont(&fontss[fss]);
  if(Y == 0){
    if(s % 2 == 0){
    matrix.drawPixel(24, 14, myCOLORS[e][x]);
    matrix.drawPixel(23, 15, myCOLORS[e][x]);
   }else{
    matrix.drawPixel(24, 15, myCOLORS[e][x]);
    matrix.drawPixel(23, 14, myCOLORS[e][x]);
   }
  }
  matrix.print(szTime);
  matrix.setFont();
  if(Y == 0){
    if(s % 2 == 0){
    matrix.drawPixel(24, 14, myCOLORS[e][x]);
    matrix.drawPixel(23, 15, myCOLORS[e][x]);
   }else{
    matrix.drawPixel(24, 15, myCOLORS[e][x]);
    matrix.drawPixel(23, 14, myCOLORS[e][x]);
   }
  }
  matrix.drawPixel(55, 15, myCOLORSW[w]);
   ysl();
}
void ysl()
{
  if ( h >= hof &&  m == 00 && s == 00 && FlagNr != 1)getGov_vrema();
  portal.tick();
  if (h == 00 && m == 00 && s == 00)matrix.fillScreen(0);
  if(FMradio == true)vklFm();
  getDate();
  getDate1();
  matrix.drawPixel(55, 15, myCOLORSW[w]);
  if (m % 5 == 0 && chut == true)chutflag = true;
  if (m % 3 == 0 && prik == true)prikflag = true;
  if (m == 02 && s == 5 && kch == true && POG == 0)pogflag = true;
  if (h % 2 == 0 && m == 05 && s == 30 && kch == true && POG == 0)pog_forflag = true;
  if (m % 10 == 0 && kch == true && pogflag == false && pog_forflag == false && POG == 1)flagMap = true;
  if (m % 10 == 0 && kch == true && pogflag == false && pog_forflag == false && POG == 2)flagDarc = true;
  if (m == 30 && s == 00)nmonflag = true;
  if (m == 15 && s == 00)newsflag = true;
  if (h == hon && m == minon && MNR == true){FlagNr = 1;getNreg();}
  if ((hon < hof) && (h > min(hon, hof) && h < max(hon, hof-1))&& MNR == true){FlagNr = 1;getNreg();}
  if ((hon > hof) && (h > max(hon, hof) || h < min(hon, hof-1))&& MNR == true){FlagNr = 1;getNreg();}
  if ((h == hbigon && m == mbigon) && (BCH == true)){getPilik();modBig = 1;saveConfig();getBigTime();}
  if (h % 3 == 0 && m == 10 && s == 15)flagval = true;
  if(h == 00 && m == 00 && s == 00)flagP = true;
  if(s == 00 && flagpr == true && flagP == true){
  if(printCom)Serial.println("Праздники");
     switch(month){
        case 0:loadPrazdnik1();break;
        case 1:loadPrazdnik2();break;
        case 2:loadPrazdnik3();break;
        case 3:loadPrazdnik4();break;
        case 4:loadPrazdnik5();break;
        case 5:loadPrazdnik6();break;
        case 6:loadPrazdnik7();break;
        case 7:loadPrazdnik8();break;
        case 8:loadPrazdnik9();break;
        case 9:loadPrazdnik10();break;
        case 10:loadPrazdnik11();break;
        case 11:loadPrazdnik12();break;
       }
       flagP = false;
     }
  if(Serv == true)client.loop();
  if (!client.connected() && Serv == true && flagstring == true)reconnectid();
  if(Modbyd1 == true || Modbyd2 == true || Modbyd3 == true || Modbyd4 == true || Modbyd5 == true || Modbyd6 == true || Modbyd7== true){getper();getprbud();}
  if(papk != papk)dfPlayer.disableLoop();
  if (nextmqtt == 1 && Serv == false && (h % 2 == 0 && m  == 05 && s == 00)){
    if(printCom)Serial.println("Реконнект!!"); 
    Serv = true;//попытка переподключения к серверу mqtt раз в два часа
    saveConfig();
  }
}
void scroll_text(uint8_t ypos, unsigned long scroll_delay, String text)
{
  uint16_t text_length = text.length();
   for (int xpos = matrix_width; xpos > -(matrix_width + text_length * 5); xpos--)
  {
    ArduinoOTA.handle();
    matrix.setCursor(xpos, ypos);                //
    matrix.fillRect(0, ypos - 1, 64, 9, myBLACK);    //
    matrix.setTextColor(myCOLORS[e][xob]);//
    matrix.setFont();
   matrix.setFont(&Heebo7pt8b);
   matrix.print(utf8rus(text));                 //
    matrix.setFont();
    matrix.swapBuffers(true);
    delay(2 + framflag);
    newTime();
    yield();
    newTime();
  }
   if(Serv == true)zppMqtt();
   flagstring = true;
}

void scroll_text2(uint8_t ypos, unsigned long scroll_delay, String text)
{
  int xyz = 0;
  uint16_t text_length = text.length();
  for (int xpos = matrix_width; xpos > -((matrix_width - 44) + text_length * 5); xpos--)
  {
    ArduinoOTA.handle();
    matrix.setCursor(xpos, ypos);                //
    matrix.fillRect(0, ypos - 1, 64, 9, myBLACK);    //matrix.fillRect(0, ypos , 64, 9, myBLACK);
    matrix.setTextColor(myCOLORS[e][x36]);//цвет выплывающей строки..."Улица"
    matrix.setFont();
    matrix.setFont(&Heebo7pt8b);
    matrix.print(utf8rus(text)); 
    if((xpos == 1)&& xyz!= 200)xpos++;
      xyz++;
     matrix.setFont();
     matrix.swapBuffers(true);
    delay(scroll_delay);
    yield(); 
    newTime();
  }
  if(Serv == true)zppMqtt();
}
void getYtro() {
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes, 64, 32);
      matrix.swapBuffers(true);
      delay(300);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes1, 64, 32);
      matrix.swapBuffers(true);
      delay(200);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes2, 64, 32);
      matrix.swapBuffers(true);
      dfPlayer.setTimeOut(1900);
      dfPlayer.EQ(EQ);
      delay(300);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes3, 64, 32);
      matrix.swapBuffers(true);
      delay(300);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes4, 64, 32);
      matrix.swapBuffers(true);
      delay(200);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes5, 64, 32);
      matrix.swapBuffers(true);
      delay(100);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes6, 64, 32);
      matrix.swapBuffers(true);
      delay(100);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes7, 64, 32);
      matrix.swapBuffers(true);
      delay(10);
      matrix.drawRGBBitmap(0, 0, image_data_eyes, 64, 32);
      matrix.swapBuffers(true);
      delay(10);
      if (MG == 3){
        dfPlayer.volume(0);
      }else{
        dfPlayer.volume(Y); 
      }
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes1, 64, 32);
      matrix.swapBuffers(true);
      delay(300);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes2, 64, 32);
      matrix.swapBuffers(true);
      delay(300);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes3, 64, 32);
      matrix.swapBuffers(true);
      delay(300);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes4, 64, 32);
      matrix.swapBuffers(true);
      delay(200);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes5, 64, 32);
      matrix.swapBuffers(true);
      delay(100);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes6, 64, 32);
      matrix.swapBuffers(true);
      delay(100);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes7, 64, 32);
      matrix.swapBuffers(true);
      delay(100);
      matrix.fillScreen(0);
      matrix.drawRGBBitmap(0, 0, image_data_eyes, 64, 32);
      matrix.swapBuffers(true);
      delay(500);
      
  if (MG == 3) {
    buser();
  } else {
    loadConfig();
    if(W != 0)Y = W;
    dfPlayer.volume(Y);
    dfPlayer.playFolder(Mgl, 40);//доброе утро
  }
  delay(1000);
   WetMap();
   Meteo();
  getWeatherData0();
  getWeatherDataz0();
  delay(1000);
  matrix.fillScreen(0);
  getRTCh(szTime);
  getRTCm(szTime);
}
void newTime()
{
  if (millis() - lastTime >= 1000)
   {
    lastTime = millis();
    updateTime();
    getTim(szTime, flasher);
    flasher = !flasher;
    if (NewRTCh != h){getTime();getRTCh(szTime);}
    if (NewRTCm != m)getRTCm(szTime);
   }
}
void buser() {
  if (MG == 3) {ledcWriteTone(channel, 2000);delay(200);ledcWriteTone(channel, 0);}
}
void Wifi_connected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Successfully connected to Access Point");
}

void Get_IPAddress(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("WIFI is connected!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void Wifi_disconnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Disconnected from WIFI access point");
  Serial.print("WiFi lost connection. Reason: ");
  Serial.println(info.disconnected.reason);
  Serial.println("Reconnecting...");
  
}
void setup() {
  hwSerial.begin(9600, SERIAL_8N1, 4, 19);// TX,RX
  Serial.begin(115200);
  delay(500);
  tmr.setPeriodMode();
  tmr1.setPeriodMode();
  tmr2.setPeriodMode();
  tmr3.setPeriodMode();
  SPIFFS.begin();
  loadConfig();
  period_timer = millis();   // "сбросить" таймер
  radio.init();
  dfPlayer.begin(hwSerial);
  dfPlayer.volume(Y);
  dfPlayer.setTimeOut(1900);
  dfPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(2, channel);
  if (flagRTC == true) {
    watch.begin(); 
    Serial.println("RTC begin!!!");
  } else {
    Serial.println("Couldn't find RTC");
    flagRTC = false;
  }

  matrix.begin();
  matrix.cp437(true);
  bool status;
  if(Modsen == true)sensors.begin();//ds18b20
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor!");
  } else {
    Serial.println("YES!!! find BME280 sensor!");
    M1 = true;
    Serial.println ("Mod = 1");
  }
  if (bmp.begin()) {
    if (printCom) Serial.println("YES!!! find BMP280 sensor!");
    M3 = true;
    Serial.println ("Mod = 3");
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     
                  Adafruit_BMP280::SAMPLING_X2,     
                  Adafruit_BMP280::SAMPLING_X16,    
                  Adafruit_BMP280::FILTER_X16,      
                  Adafruit_BMP280::STANDBY_MS_500); 
    bmp280 = true;
    sensorsBmp280();
  } else if (printCom) Serial.println("Did not find BMP280 sensor!");
  if (bmp180.begin()) {
    if (printCom) Serial.println("YES!!! find BMP180 sensor!");
    M4 = true;
    Serial.println ("Mod = 4");
    BMP180 = true;
    sensorsBmp180();
  } else if (printCom) Serial.println("Did not find BMP180 sensor!");
  if (aht.begin()) {
    Serial.println("AHT10 or AHT20 found");
    M2 = true;
    Serial.println ("Mod = 2");
    aht_temp = aht.getTemperatureSensor();
    aht_temp->printSensorDetails();
    aht_humidity = aht.getHumiditySensor();
    aht_humidity->printSensorDetails();
  }
  Serial.println("Did not find AHT10 or AHT20 sensor!");

  if (!htu.begin()) {
    Serial.println(F("HTU21D error"));
   } else {
    Serial.println(F("HTU21D YES!!!"));
    getsensGY21();
    M5 = true;
   }
    if (mySensor.begin() == true) {
      mySensor.initAirQuality();
      Mod1 = true;
    } else {
    Serial.println("Sensor  not found : SGP30");
  }
  matrix.setRotation(0);
  matrix.setTextWrap(false);
   if(bz == false){
  matrix.setTextColor(myCOLORZ[e][0]);
  matrix.setCursor(8, 0);
  matrix.println("ESPClock");
  matrix.swapBuffers(true);
  matrix.setCursor(8, 10);
  matrix.setFont(&TomThumb);
  matrix.println("192.168.4.1");
  matrix.setFont();
  matrix.swapBuffers(true);
   }
  WiFi.disconnect(true);
  WiFi.onEvent(Wifi_connected,SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(Get_IPAddress, SYSTEM_EVENT_STA_GOT_IP);
  WiFi.onEvent(Wifi_disconnected, SYSTEM_EVENT_STA_DISCONNECTED); 
  Serial.println("Waiting for WIFI network..."); 
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  Serial.setDebugOutput(true);
  delay(500);
  Serial.println("\n Starting");

  int customFieldLength = 40;
  const char* custom_radio_str = "<br/><label for='customfieldid'>Custom Field Label</label><input type='radio' name='customfieldid' value='1' checked> One<br><input type='radio' name='customfieldid' value='2'> Two<br><input type='radio' name='customfieldid' value='3'> Three";
  new (&custom_field) WiFiManagerParameter(custom_radio_str); // custom html input

  wm.addParameter(&custom_field);
  wm.setSaveParamsCallback(saveParamCallback);
  std::vector<const char *> menu = {"wifi", "info", "param", "sep", "restart", "exit"};
  wm.setMenu(menu);
  wm.setClass("invert");
  wm.setConfigPortalTimeout(90); // auto close configportal after n seconds
  bool res;
  res = wm.autoConnect("ESPClock", ""); // password protected ap
  if (!res) {
    Serial.println("Failed to connect or hit timeout");
  }
  else {
    Serial.println("connected...yeey :)");
  }
  if(bz == false){
  getAnim();
  }
  delay(100);
  if(flagrtc == 0)getNarodmon();
  if(M1 == true)getsensorsBme();
  Anek();
  getTime();
  updateTime();
  ArduinoOTA.setPort(3232);
  ArduinoOTA.setHostname("esp32Matrix-Cloick");
  ArduinoOTA.begin();
  portal.attachBuild(build);
  portal.attach(Portal);
  portal.start();
  portal.log.start(30);
  int sensors_ID0 = ID0.toInt();
  int sensors_ID1 = ID1.toInt();
  int sensors_ID2 = ID2.toInt();
  int sensors_ID3 = ID3.toInt();
  server.toCharArray(mqtt_server, 32);
  int mqtt_port = port.toInt();
  USER.toCharArray(MQTT_USER, 25);
  PASSWORD.toCharArray(MQTT_PASSWORD, 25);
  PUBLISH_CH.toCharArray(MQTT_SERIAL_PUBLISH_CH,32);
  PUBLISH_CH1.toCharArray(MQTT_SERIAL_PUBLISH_CH1,32);
  PUBLISH_CH2.toCharArray(MQTT_SERIAL_PUBLISH_CH2,32);
  PUBLISH_CH3.toCharArray(MQTT_SERIAL_PUBLISH_CH3,32);
  PUBLISH_CH4.toCharArray(MQTT_SERIAL_PUBLISH_CH4,32);
  PUBLISH_CH5.toCharArray(MQTT_SERIAL_PUBLISH_CH5,32);
  PUBLISH_CH6.toCharArray(MQTT_SERIAL_PUBLISH_CH6,32);
  PUBLISH_CH7.toCharArray(MQTT_SERIAL_PUBLISH_CH7,32);
  RECEIVER_CH1.toCharArray(MQTT_SERIAL_RECEIVER_CH1,32);
  RECEIVER_CH2.toCharArray(MQTT_SERIAL_RECEIVER_CH2,32);
  RECEIVER_CH3.toCharArray(MQTT_SERIAL_RECEIVER_CH3,32);
  RECEIVER_CH4.toCharArray(MQTT_SERIAL_RECEIVER_CH4,32);
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  delay(500);
  flagP = true;
}
String httpGETRequest(const char* serverName) {
  HTTPClient http;
  http.begin(serverName);             // Ваш IP адрес и путь или Domain name и URL path
  int httpResponseCode = http.GET();  // Send HTTP POST request
  String payload = "{}";
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();                         // Освобождаем ресурсы
  return payload;
  
}
void getAnim() {
  matrix.fillScreen(0);
  dfPlayer.volume(Y);
  matrix.setTextColor(myCOLORZ[e][0]);
  matrix.setCursor(22, 0);
  matrix.println("WiFi");
  dfPlayer.playFolder(Mgl, 26);
  matrix.swapBuffers(true);
  matrix.fillScreen(0);
  getwifi();
  delay(100);
   matrix.setCursor(22, 0);
  if (WiFi.status() != WL_CONNECTED) {
    matrix.setCursor(16, 0);
    matrix.println("No WiFi");
    matrix.swapBuffers(true);
    dfPlayer.playFolder(Mgl, 27);
  } else {
    matrix.println("WiFi");
    matrix.swapBuffers(true);
    matrix.setCursor(6, 10);
    matrix.println(utf8rus("Подключен"));
    matrix.swapBuffers(true);
    dfPlayer.playFolder(Mgl, 28);
  }
  delay(1000);
  matrix.fillScreen(0);
  matrix.setCursor(18, 0);
  matrix.println(utf8rus("Время"));
  matrix.swapBuffers(true);
  dfPlayer.playFolder(Mgl, 29);
   delay(1000);
  if (WiFi.status() != WL_CONNECTED && flagRTC  == true) {
    flagrtc = 1;
    matrix.fillScreen(0);
    matrix.setCursor(15, 0);
    matrix.print(utf8rus("RTC!!!"));
    matrix.swapBuffers(true);
    dfPlayer.playFolder(Mgl, 34);
    updateTime();
  }
  if(WiFi.status() == WL_CONNECTED){
    matrix.fillScreen(0);
    matrix.setCursor(12, 0);
    matrix.print(utf8rus("NTP ОК"));
    matrix.swapBuffers(true);
    dfPlayer.playFolder(Mgl, 30);
  }
  delay(500);
  if(M1 == true)dfPlayer.playFolder(Mgl, 55);
  delay(500);
  if(M2 == true)dfPlayer.playFolder(Mgl, 56);
  delay(500);
  if(M3 == true)dfPlayer.playFolder(Mgl, 57);
  delay(500);
  if(M4 == true)dfPlayer.playFolder(Mgl, 58);
  delay(500);
  if(M5 == true)dfPlayer.playFolder(Mgl, 59);
  delay(500);
  if(Mod1 == true)dfPlayer.playFolder(Mgl, 60);
  delay(500);
  matrix.fillScreen(0);
  matrix.setCursor(8, 1);
  matrix.print(utf8rus("IP адрес:"));
  matrix.swapBuffers(true);
  matrix.setCursor(6, 10);
  matrix.setFont(&TomThumb);
  matrix.println(WiFi.localIP());
  matrix.swapBuffers(true);
  dfPlayer.playFolder(Mgl, 31);
  delay(1000);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(18, 3, image_data_Image30, 26, 26);
  matrix.swapBuffers(false);
  delay(200);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(18, 3, image_data_Image31, 26, 26);
  matrix.swapBuffers(false);
  delay(200);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(18, 3, image_data_Image32, 26, 26);
  matrix.swapBuffers(false);
  delay(200);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(18, 3, image_data_Image33, 26, 26);
  matrix.swapBuffers(false);
  delay(200);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(18, 3, image_data_Image34, 26, 26);
  matrix.swapBuffers(false);
  delay(200);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(18, 3, image_data_Image35, 26, 26);
  matrix.swapBuffers(false);
  delay(200);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(18, 3, image_data_Image36, 26, 26);
  matrix.swapBuffers(false);
  delay(500);
  matrix.fillScreen(0);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_01, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_02, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_03, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_04, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_05, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_06, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_07, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  dfPlayer.playFolder(Mgl, 42);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_08, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_09, 64, 32);
  matrix.swapBuffers(false);
  delay(100);
  matrix.fillScreen(0);
  matrix.drawRGBBitmap(0, 0, image_10, 64, 32);
  matrix.swapBuffers(false);
  delay(300);
  matrix.fillScreen(0);
}
String getParam(String name) {
  String value;
  if (wm.server->hasArg(name)) {value = wm.server->arg(name);}
  return value;
}
void saveParamCallback() {
  Serial.println("[CALLBACK] saveParamCallback fired");
  Serial.println("PARAM customfieldid = " + getParam("customfieldid"));
}
void vklFm()
{
 if(h == hFMon && m == mFMon && s == 00){getPilik();UT = false;saveConfig();getradiofm();} 
 if(h == hFMoff && m == mFMoff && s == 00){getPilik();UT = true;radio.setMute(UT);saveConfig();}
}
void loop() {
  ArduinoOTA.handle();
  portal.tick();
  getwifi();
  getHome();
  if (modBig == 1 && BCH == true)getBigTime();
  getStr2();
  getStr3();
  if (Mod1 == 1 && Modekr3 == true && (m < 55 || m == minon -1)) getNow2();
  if (pogflag == true && kch == true && POG == 0)getWeatherData0();
  if (flagMap == true && kch == true && POG == 1)WetMap();
  if (flagDarc == true && kch == true && POG == 2)Meteo();
  getStr4();
  if ((m < 55 || m == minon -1) && Modmqtt == true  && Serv == true && (file1 != 0 || file2 != 0 || file3 != 0 || file5 != 0 || file6 != 0))getNow4();
  getStr5();
  if (pog_forflag == true && kch == true && POG == 0)getWeatherDataz0();
  getStr6();
  if(chut == true && chutflag == true){Anek();getStr14();}
  getStr7();
  if ((Modekr2 == true && (m < 55 || m == minon -1)) && (M1 == true || M2 == true || M3 == true || M4 == true || M5 == true))getNow1();
  if (nmonflag == true)getNarodmon();
  getStr8();
  getStr9();
 if(Modekr1 == true && (m < 55 || m == minon -1) && flagrtc == 0)getNow();
  getSens();
  getStr10();
  getStr11();
  if(newsflag == true && (Modenews == true || Modenewspod == true))News();
  getStr12();
  if(prikflag == true)Prikol();
  if(prik == true)getStr13();
  if(flagval == true)Val();
  getStr15();
   np++;
  if(np>9)np = 0;
    if (FlagNr == 0){
    if(W != 0)Y = W;
    dfPlayer.volume(Y);
  }else{
    dfPlayer.volume(0);
  }
}
void getwifi()
{
  if (WiFi.status() != WL_CONNECTED) {
      w = 0;
      if(printCom)Serial.println("no wifi");
      WiFi.mode(WIFI_STA);
      WiFi.disconnect(true);
      WiFi.begin();
      flagrtc = 1;
      updateTime();
    } else {
      if(printCom)Serial.println("yes wifi");
      w = 1;
      getTime();
      flagrtc = 0;
      updateTime();
    }
}

void getTime()
{
  configTime(timezone * 3600, dst, "ru.pool.ntp.org", "time.nist.gov");// "ru.pool.ntp.org", "time.nist.gov"//"ntp.nict.jp", "ntp.jst.mfeed.ad.jp"
  if(printCom)Serial.println("getTime");
  while (!time(nullptr)) {
    delay(2000);
  }
}
void printTime() {
  if (printCom) Serial.print((h < 10 ? "0" : "") + String(h) + ":" + (m < 10 ? "0" : "") + String(m) + ":" + (s < 10 ? "0" : "") + String(s) + "  ");
}
void updateTime()
{
  if(flagrtc == 0){
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  dow = p_tm->tm_wday + 1;
  day = p_tm->tm_mday; 
  month = p_tm->tm_mon;//+1
  year = p_tm->tm_year + 1900;
  h = p_tm->tm_hour;
  m = p_tm->tm_min;
  s = p_tm->tm_sec;
    }else{
     watch.gettime();                                                  
      day = watch.day;
      dow = watch.weekday + 1; 
       if( watch.month == 12){
        month = 0;                                                  
       }else{
      month = watch.month;
       }
      h = watch.Hours;                                                
      m = watch.minutes;                                              
      s = watch.seconds;
      w = 3;
      
    }
}
// ================================ Вывод Русских Букв
String utf8rus(String source)
{
  int i, k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };

  k = source.length(); i = 0;

  while (i < k) {
    n = source[i]; i++;

    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
            n = source[i]; i++;
            if (n == 0x81) {
              n = 0xA8;
              break;
            }
            if (n >= 0x90 && n <= 0xBF) n = n + 0x30;
            break;
          }
        case 0xD1: {
            n = source[i]; i++;
            if (n == 0x91) {
              n = 0xB8;
              break;
            }
            if (n >= 0x80 && n <= 0x8F) n = n + 0x70;
            break;
          }
      }
    }
    m[0] = n; target = target + String(m);
  }
  return target;
}
