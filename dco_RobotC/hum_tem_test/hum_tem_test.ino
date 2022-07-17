#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            2     //DATA Pin 
#define DHTTYPE           DHT22 //DHT22 라고 TYPE을 정의함

//dht 클랙서 생성 (Data Pin, Sensor Type)
DHT_Unified dht(DHTPIN, DHTTYPE);

//대기 시간 변수
uint32_t delayMS;

void setup() {
  //모니터 프로그램을 위한 시리얼 시작
  Serial.begin(9600); 

  //DHT22 시작
  dht.begin();
  
  
  sensor_t sensor;
  dht.humidity().getSensor(&sensor);

  //최소한의 대기시간을 얻어 온다.
  delayMS = sensor.min_delay / 1000;  
}

void loop() {

  //대기
  delay(delayMS);
  
  
  sensors_event_t event;  
  //온도값 얻기
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    //얻기 실패했다면...
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    //실제 온도 값
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
    

  //습도값 얻기
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    //얻기 실패했다면...
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity: ");
    //실제 습도 값
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
}
