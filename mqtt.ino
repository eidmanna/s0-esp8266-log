void reconnect() 
{
  // Loop until we're reconnected
  while (!mqttClient.connected()) 
  {
    sp("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    //if you MQTT broker has clientID,username and password
    //please change following line to    if (client.connect(clientId,userName,passWord))
    if (mqttClient.connect(clientId.c_str()))
    {
      spn("connected");
     //once connected to MQTT broker, subscribe command if any
      mqttClient.subscribe("OsoyooCommand");
    } else {
      sp("failed, rc=");
      sp(mqttClient.state());
      spn(" try again in 5 seconds");
      // Wait 6 seconds before retrying
      delay(6000);
    }
  }
}
// const char *mqtt_server_ip = "192.168.0.34";
void setupMQTT() 
{ 
  mqttClient.setServer(mqtt_server_ip, 1883);
}

void sendMQTT() {
    sp("sendMQTT: ");    
    char queryRealName[7][20] = {"Tagesverbrauch","Jahresverbrauch","Monatsverbrauch","Leistung","Maximal","Voltage","RSSI"};
    for( int i = 0; i < lenStore; i++)
    {
        for( int j = 0; j < (sizeof(queryRealName)/sizeof(queryRealName[0])); j++ )
        {
        if( strncmp(ausgabe[i].realName,queryRealName[j],20) == 0 )
        {
            mqttClient.publish(ausgabe[i].realName, ausgabe[i].printValue);
            break;
        }
        }
    }
    
}