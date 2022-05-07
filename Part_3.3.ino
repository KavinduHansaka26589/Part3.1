TaskHandle_t task_1;
TaskHandle_t task_2;


void LED1(void *parameter1){   //function for task1
  
  while(1){                         //starting infinite loop
    digitalWrite(26,HIGH);                         
    vTaskDelay(pdMS_TO_TICKS( 500 ));               
    digitalWrite(26,LOW);                         
    vTaskDelay(pdMS_TO_TICKS( 500 ));               

  } 
}

void LED2(void *parameter2){   //function for task2
  
  while(1){                         //starting infinite loop
    digitalWrite(27,HIGH);                       
    vTaskDelay(pdMS_TO_TICKS( 300 ));            
    digitalWrite(27,LOW);                      
    vTaskDelay(pdMS_TO_TICKS( 300 ));              
    
  } 
}


void setup() {

  pinMode(26,OUTPUT);          //setting LED pin as output
  pinMode(27,OUTPUT); 

  xTaskCreate(LED1,"LED1",1024,NULL,1,&task_1);      //setting the Task1

  xTaskCreate(LED2,"LED2",1024,NULL,1,&task_2);      //setting the Task2

}

void loop() {

}
