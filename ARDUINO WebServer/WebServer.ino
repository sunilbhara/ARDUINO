#include <Ethernet.h>
#include<SPI.h>

byte mac[] = {0011, 002B, 003C, 004D, 005E, 0066}; //Define your mac address
EthernetServer serve = EthernetServer(55);  //Create a server which listens on port 55


void setup()
{
  Serial.begin(9600);
  if(Ethernet.begin(mac) == 0)                        
  { 
    Serial.println("Configuration failed");
    return;
  }
  else
  {
    Serial.print("Arduino IP:");   //Displays your Arduino's local IP address
    Serial.println(Ethernet.localIP());
  }
  serve.begin();
  Serial.println("Server Running");
}

void loop()
{
  Serial.println("Waiting For Client Connection");
  EthernetClient client = serve.available();  //Looks for incoming client connections
  if(client)
  {
    Serial.print("Connected to client: ");
    while(client.available())
    {             
      char c = client.read();
      Serial.print(c);
    }
    if(client.connected())                        
    {
      Serial.println("Webpage Sent To Client");   //Delivers a web page to the client
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html\n");
      client.println("<center><h1>Connected To Your Arduino</h1></center>");
      client.println("<center><h2>Hello John</h2></center>");   
    }  
    delay(8);
    client.stop();    //Closes the client connection
    Serial.println("Disconnected from client");
  }
  delay(1500);
}

