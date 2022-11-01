void handleJsonData()
{
  DynamicJsonDocument doc(1024);
  sp("sendJsonData: ");    
    char queryRealName[7][20] = {"Tagesverbrauch","Jahresverbrauch","Monatsverbrauch","Leistung","Maximal","Voltage","RSSI"};
    for( int i = 0; i < lenStore; i++)
    {
        for( int j = 0; j < (sizeof(queryRealName)/sizeof(queryRealName[0])); j++ )
        {
        if( strncmp(ausgabe[i].realName,queryRealName[j],20) == 0 )
        {
            doc[ausgabe[i].realName] = ausgabe[i].printValue;
            break;
        }
        }
    }

    String output = "";
    serializeJson(doc, output);
    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
    server.sendHeader("Pragma", "no-cache");
    server.setContentLength(CONTENT_LENGTH_UNKNOWN);
    server.send(200, "text/json", output);
  

}