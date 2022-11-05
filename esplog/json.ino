void handleJsonData()
{
  DynamicJsonDocument doc(2048);
  sp("sendJsonData: ");    
    
    for( int i = 0; i < lenStore; i++)
    {
        JsonObject obj1 = doc.createNestedObject();
        obj1["title"] = ausgabe[i].realName;
        obj1["value"] = ausgabe[i].printValue;
        obj1["unit"] = ausgabe[i].unit;
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