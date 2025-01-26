void getradiofm()
{ 
   loadConfig();
    St();  
    radio.setBandFrequency(FIX_BAND, stan);
    radio.setVolume(vol);
    radio.setMono(true);
    if(UT == true){
     Serial.println("FM STOP"); 
    }else{
     Serial.println("FM PLAY");  
    }
    
}
void St()
{
  switch(st){
    case 0:stan = list1;textNst = nslist1;break;
    case 1:stan = list2;textNst = nslist2;break;
    case 2:stan = list3;textNst = nslist3;break;
    case 3:stan = list4;textNst = nslist4;break;
    case 4:stan = list5;textNst = nslist5;break;
    case 5:stan = list6;textNst = nslist6;break;
    case 6:stan = list7;textNst = nslist7;break;
    case 7:stan = list8;textNst = nslist8;break;
  }    
}
