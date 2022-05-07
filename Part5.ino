/**
* FreeRTOS Stack Overflow Demo
*
*
* Date: December 5, 2020
* Author: Shawn Hymel
* License: 0BSD
*/
// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif


void setup() {

Serial.begin(115200);
vTaskDelay(100 / portTICK_PERIOD_MS);
Serial.println();
Serial.println("---FreeRTOS Memory Demo---");
xTaskCreatePinnedToCore(testTask,"testTask",10000,NULL,1,NULL,app_cpu);
vTaskDelete(NULL);
}

void testTask(void *parameter) {
 int a = 1;
 int b[100];
 while(1){
 for (int i = 0; i < 100; i++) {
 b[i] = a + 1;
 Serial.println(b[3]); 
 vTaskDelay(100 / portTICK_PERIOD_MS);
 }

}
} 



void loop() {
// Execution should never get here

}
