void initGSM() {
  Serial.println("Start Initializing SIM800\r\n");

  sendData("AT",1000,DEBUG_TRUE); // AT - Check SIM800

  sendData("AT+CMGF=1",1000,DEBUG_TRUE); //AT+CMGF=1 - Set Text Message
  sendData("AT+CMGD=1",1000,DEBUG_TRUE); //AT+CMGD=1 - Delete all read messages
  
  Serial.println("End Initializing SIM800");
  Serial.println("You may now send a message");
  
}

String sendData(String command, int timeout, boolean debug)
{
    String response = "";
    
    sim800Serial.println(command); 
    
    long start_time = millis();
    
    while( (start_time + timeout) > millis()) {
      while(sim800Serial.available()) {
        char c = sim800Serial.read();
        response+=c;
      }  
    }
    
    if(debug) {
      Serial.println(response);
    }
    
    return response;
}

void checkGsmResponse() {
  String response = "";
  
  if(sim800Serial.available()) {  
    while(sim800Serial.available()) {
     char c = sim800Serial.read();
     response+=c;
    }
    Serial.print(response);
  }
}


void sendMessage(char *number, char *msg)
{
  char at_cmgs_cmd[30] = {'\0'};
  char msg1[160] = {'\0'};
  char ctl_z = 0x1A;

  sprintf(msg1, "%s%c", msg, ctl_z);
  sprintf(at_cmgs_cmd, "AT+CMGS=\"%s\"\r\n",number);
  
  sendGSM(at_cmgs_cmd);
  delay(100);
  delay(100);
  delay(100);
  sendGSM(msg1);
  delay(100);
}

void sendGSM(char *string){
  sim800Serial.write(string);
  delay(90);
}
