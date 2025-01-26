void Prikol()
{
   BUFFER = "";//буфер
   switch(ktg){ 
    case 0:kategpr = 1;textprik = "Анекдот :";break;
    case 1:kategpr = 3;textprik = "Стишок :";break;
    case 2:kategpr = 4;textprik = "Афоризм :";break;
    case 3:kategpr = 5;textprik = "Цитата :";break;
    case 4:kategpr = 6;textprik = "Тост :";break;
    case 5:kategpr = 8;textprik = "Статус :";break;
    case 6:kategpr = 11;textprik = "Анекдот +18:";break;
    case 7:kategpr = 13;textprik = "Стишок +18 :";break;
    case 8:kategpr = 14;textprik = "Афоризм +18 :";break;
    case 9:kategpr = 15;textprik = "Цитата +18 :";break;
    case 10:kategpr = 16;textprik = "Тост +18 :";break;
    case 11:kategpr = 18;textprik = "Статус +18 :";break;
   }
   if(WiFi.status() == WL_CONNECTED){
  HTTPClient http;
  String serverPath = "http://rzhunemogu.ru/RandJSON.aspx?CType=" + String(kategpr);
  http.begin(serverPath);
  int httpCode = http.GET();
   if(httpCode > 0) {
   if (printCom)Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    if(httpCode == HTTP_CODE_OK) {
      payload = http.getString();
          }
        } else {
     if (printCom)Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
       }
     for (iprik=0;iprik<payload.length();iprik++){
     decod();
     inString = inString+nprik;
      if (inString.length()!= payload.length()){ 
       BUFFER += inString;
        inString = ""; 
        }

     if (printCom)Serial.print(nprik);
   }
    if (printCom)Serial.println();
}

void decod()
{
   switch((int)payload[iprik]){
  case 1 ... 31:nprik = "";break;
  case 32:nprik = " ";break;
  case 33:nprik = "!";break;
  case 34:nprik = "";break;
  case 35 ... 37:nprik = "";break;
  case 38:nprik = "&";break;
  case 39 ... 43:nprik = "";break;
  case 44:nprik = ",";break;
  case 45:nprik = "-";break;
  case 46:nprik = ".";break;
  case 47:nprik = "/";break;
  case 48:nprik = "0";break;
  case 49:nprik = "1";break;
  case 50:nprik = "2";break;
  case 51:nprik = "3";break;
  case 52:nprik = "4";break;
  case 53:nprik = "5";break;
  case 54:nprik = "6";break;
  case 55:nprik = "7";break;
  case 56:nprik = "8";break;
  case 57:nprik = "9";break;
  case 63:nprik = "?";break;
  case 64:nprik = "@";break;
  case 65 ... 167:nprik = "";break;
  case 168:nprik = "Ё";break;
  case 169 ... 183:nprik = "";break;
  case 184:nprik = "ё";break;
  case 192:nprik = "А";break;
  case 193:nprik = "Б";break;
  case 194:nprik = "В";break;
  case 195:nprik = "Г";break;
  case 196:nprik = "Д";break;
  case 197:nprik = "Е";break;
  case 198:nprik = "Ж";break;
  case 199:nprik = "З";break;
  case 200:nprik = "И";break;
  case 201:nprik = "Й";break;
  case 202:nprik = "К";break;
  case 203:nprik = "Л";break;
  case 204:nprik = "М";break;
  case 205:nprik = "Н";break;
  case 206:nprik = "О";break;
  case 207:nprik = "П";break;
  case 208:nprik = "Р";break;
  case 209:nprik = "С";break;
  case 210:nprik = "Т";break;
  case 211:nprik = "У";break;
  case 212:nprik = "Ф";break;
  case 213:nprik = "Х";break;
  case 214:nprik = "Ц";break;
  case 215:nprik = "Ч";break;
  case 216:nprik = "Ш";break;
  case 217:nprik = "Щ";break;
  case 218:nprik = "Ъ";break;
  case 219:nprik = "Ы";break;
  case 220:nprik = "Ь";break;
  case 221:nprik = "Э";break;
  case 222:nprik = "Ю";break;
  case 223:nprik = "Я";break;
  case 224:nprik = "а";break;
  case 225:nprik = "б";break;
  case 226:nprik = "в";break;
  case 227:nprik = "г";break;
  case 228:nprik = "д";break;
  case 229:nprik = "е";break;
  case 230:nprik = "ж";break;
  case 231:nprik = "з";break;
  case 232:nprik = "и";break;
  case 233:nprik = "й";break;
  case 234:nprik = "к";break;
  case 235:nprik = "л";break;
  case 236:nprik = "м";break;
  case 237:nprik = "н";break;
  case 238:nprik = "о";break;
  case 239:nprik = "п";break;
  case 240:nprik = "р";break;
  case 241:nprik = "с";break;
  case 242:nprik = "т";break;
  case 243:nprik = "у";break;
  case 244:nprik = "ф";break;
  case 245:nprik = "х";break;
  case 246:nprik = "ц";break;
  case 247:nprik = "ч";break;
  case 248:nprik = "ш";break;
  case 249:nprik = "щ";break;
  case 250:nprik = "ъ";break;
  case 251:nprik = "ы";break;
  case 252:nprik = "ь";break;
  case 253:nprik = "э";break;
  case 254:nprik = "ю";break;
  case 255:nprik = "я";break;
  }
}
 
