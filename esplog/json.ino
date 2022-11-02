void handleJsonData()
{
  DynamicJsonDocument doc(1024);
  sp("sendJsonData: ");    
    char queryRealName[7][20] = {"Tagesverbrauch","Jahresverbrauch","Monatsverbrauch","Leistung","Maximal","Voltage","RSSI"};
    for( int i = 0; i < lenStore; i++)
    {
        for( int j = 0; j < (sizeof(queryRealName)/sizeof(queryRealName[0])); j++ )
        {
        //if( strncmp(ausgabe[i].realName,queryRealName[j],20) == 0 )
        //{   
            JsonObject obj1 = doc.createNestedObject();
            obj1["title"] = ausgabe[i].realName;
            obj1["value"] = ausgabe[i].printValue;
            obj1["unit"] = ausgabe[i].unit;
            // doc.add(obj1);
            break;
        //}
        }
    }

    JsonObject obj1 = doc.createNestedObject();
    obj1["title"] = "Free RAM";
    obj1["value"] = String(ESP.getFreeHeap());
    obj1["unit"] = "Byte";

    String output = "";
    serializeJson(doc, output);
    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
    server.sendHeader("Pragma", "no-cache");
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.setContentLength(CONTENT_LENGTH_UNKNOWN);
    server.send(200, "text/json", output);
  

}