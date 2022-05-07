int old_delay=200;        //creating a variable to led delay and setting it as 200ms
char var;             //creating a variable to input value
String new_delay;          //creating a variable to store new delay

void LED(void *parameter) { 
  
  while(1) {                         //starting infinite loop
    digitalWrite(LED_BUILTIN, HIGH);                         
    vTaskDelay(pdMS_TO_TICKS( old_delay ));               
    digitalWrite(LED_BUILTIN, LOW);                         
    vTaskDelay(pdMS_TO_TICKS( old_delay ));               
    Serial.print("present LED delay  ");
    Serial.println(old_delay);          
  }
}

void input(void *parameter){  // function to get input delay

 while(1) {                         //starting an infinity while loop
  if(Serial.available()>0){         //checking availability of input
     var=Serial.read();             //storing input value in variable
     new_delay=new_delay+var;       //putting that value to pass string
     old_delay=new_delay.toInt();            //converting to int and storing that value to delay
  }  
  if(Serial.available()==0){        //checking input was not there
     vTaskDelay(pdMS_TO_TICKS( 100 ));  //giving a delay
     new_delay="";                       //resetting pass variable
  }
 }   
}
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);          

  xTaskCreate(input,"Input",1024,NULL,1,NULL);        //setting the Task1

  xTaskCreate(LED,"LED",1024,NULL,1,NULL);    //setting the Task2 
}
void loop() {

}
