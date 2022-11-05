void readDHT() {
 // delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  ausgabe[11].value = temperature;
  dtostrf(ausgabe[11].value, 2, 2, ausgabe[11].printValue);
  ausgabe[12].value = humidity;
  dtostrf(ausgabe[12].value, 2, 2, ausgabe[12].printValue);

  sp(dht.getStatusString());
  sp("\t");
  sp(humidity, 1);
  sp("\t\t");
  sp(temperature, 1);
  sp("\t\t");
  sp(dht.toFahrenheit(temperature), 1);
  sp("\t\t");
  sp(dht.computeHeatIndex(temperature, humidity, false), 1);
  sp("\t\t");
  spn(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
}