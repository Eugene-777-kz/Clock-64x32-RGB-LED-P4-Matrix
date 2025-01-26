
void St()
{
  if (tmr2.tick())audio.setVolume(vol);
  switch (NEWStation) {
    case 0: listStation.toCharArray(Station, 150); textNst =  nStation; break;
    case 1: listStation1.toCharArray(Station, 150); textNst =  nStation1; break;
    case 2: listStation2.toCharArray(Station, 150); textNst =  nStation2; break;
    case 3: listStation3.toCharArray(Station, 150); textNst =  nStation3; break;
    case 4: listStation4.toCharArray(Station, 150); textNst =  nStation4; break;
    case 5: listStation5.toCharArray(Station, 150); textNst =  nStation5; break;
    case 6: listStation6.toCharArray(Station, 150); textNst =  nStation6; break;
    case 7: listStation7.toCharArray(Station, 150); textNst =  nStation7; break;
    case 8: listStation8.toCharArray(Station, 150); textNst =  nStation8; break;
    case 9: listStation9.toCharArray(Station, 150); textNst =  nStation9; break;
    case 10: listStation10.toCharArray(Station, 150); textNst =  nStation10; break;
    case 11: listStation11.toCharArray(Station, 150); textNst =  nStation11; break;
  }
  audio.connecttohost(Station); // переключаем станцию
}

void audio_showstation(const char *info) {
  String text1(info);
  webRadio1 = "Станция: " + text1 + "   ";
}

void audio_showstreamtitle(const char *info) {
  String text(info);
  webRadio = "Композиция: " + text;

}
