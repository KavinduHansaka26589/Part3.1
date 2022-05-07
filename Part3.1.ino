TaskHandle_t Task_1;



void LED(void *parameter){   //Function of the Task 
  
  while(1){                         //starting an infinity while loop
    digitalWrite(LED_BUILTIN,HIGH);                         //light up LED
    vTaskDelay(pdMS_TO_TICKS( 500 ));               //500ms delay
    digitalWrite(LED_BUILTIN,LOW);                          //turn off LED
    vTaskDelay(pdMS_TO_TICKS( 500 ));               //500ms delay
  } 
}

void setup() {

  pinMode(LED_BUILTIN,OUTPUT);          //setting LED pin as output

  //setting the Task 
  xTaskCreate(LED,"LED",1024,NULL,1,&Task_1);

}

void loop() {

}
