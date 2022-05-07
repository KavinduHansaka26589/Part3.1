/**
* FreeRTOS Task Demo
*
* Toggles LED and prints "Hello, World" to console in separate tasks.
*
* Date: December 3, 2020
* Author: Shawn Hymel
* License: 0BSD
*/
// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif
// Some string to print
const char msg[] = "";
// Task handles

static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;
//*****************************************************************************
// Tasks
// Task: print to Serial Terminal with lower priority
void startTask1(void *parameter) {    //task 1 function
// Count number of characters in string
  int msg_len = strlen(msg);            //msg_len is equalls to msg as an argument and returens its length
// Print string to Terminal
  while (1) {                         //infinite loop starting
     Serial.println();
      for (int i = 0; i < msg_len; i++) {
      Serial.print(msg[i]);
      
      }
     Serial.println();
     vTaskDelay(1000 / portTICK_PERIOD_MS);
  }  
  vTaskDelete(task_1);                //Remove the task 1 from the RTOS real time kernel’s management.
}
// Task: print to Serial Terminal with higher priority

void startTask2(void *parameter) {  //task 2 function
  while (1) {                       //infinite loop starting
  Serial.print('*');
  vTaskDelay(100 / portTICK_PERIOD_MS);
  }   
  vTaskDelete(task_2);                //Remove the task 2 from the RTOS real time kernel’s management.
}

void setup() {
  Serial.begin(115200);
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  Serial.println();
  xTaskCreatePinnedToCore(startTask1,"startTask1",1024,NULL,1,NULL,app_cpu);  //task 1 named as startTask1 is pinned to core 1.//Function=startTask1.name of function=startTask1.stack size=1024byts.task handle=null.core=1
  xTaskCreatePinnedToCore(startTask2,"startTask2",1024,NULL,1,NULL,app_cpu);  //task 2 named as startTask2 is pinned to core 1.//Function=startTask1.name of function=startTask1.stack size=1024byts.task handle=null.core=1

  vTaskDelete(NULL);
} 
void loop() {
// Execution should never get here
}
