
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

void Task1(void *parameters) {
  while(1){
  Serial.print("I am Task A I am Running on CORE_");
  Serial.println(xPortGetCoreID());
  Serial.println();
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}
void Task2(void *parameters) {
  while(1){
  Serial.print("I am Task B I am Running on CORE_");
  Serial.println(xPortGetCoreID());
  Serial.println();
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}
void setup() {


Serial.begin(115200);
vTaskDelay(1000 / portTICK_PERIOD_MS);
Serial.println();


xTaskCreatePinnedToCore(Task1,"Task1",10000,NULL,1,NULL,0);
xTaskCreatePinnedToCore(Task2,"Task2",10000,NULL,2,NULL,1); 


} 
void loop() {

}
