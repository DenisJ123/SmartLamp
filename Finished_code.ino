#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "DEJ";
const char* password = "Johnson1";

WiFiServer server(80);

// Variable to store the HTTP request
String header;

String LEDState = "off";

#define yLED1 5
#define yLED2 18
#define yLED3 19
#define yLED4 21
#define rLED1 15
#define rLED2 16
#define rLED3 2
#define rLED4 17
#define wLED1 32
#define wLED2 22

void setup() {
  Serial.begin(9600);
  
  pinMode(yLED1, OUTPUT);
  pinMode(yLED2, OUTPUT);
  pinMode(yLED3, OUTPUT);
  pinMode(yLED4, OUTPUT);
  pinMode(rLED1, OUTPUT);
  pinMode(rLED2, OUTPUT);
  pinMode(rLED3, OUTPUT);
  pinMode(rLED4, OUTPUT);
  pinMode(wLED1, OUTPUT);
  pinMode(wLED2, OUTPUT);

 
  digitalWrite(yLED1, LOW);
  digitalWrite(yLED2, LOW);
  digitalWrite(yLED3, LOW);
  digitalWrite(yLED4, LOW);
  digitalWrite(rLED1, LOW);
  digitalWrite(rLED2, LOW);
  digitalWrite(rLED3, LOW);
  digitalWrite(rLED4, LOW);
  digitalWrite(wLED1, LOW);
  digitalWrite(wLED2, LOW);


  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,

    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() ) {  // loop while the client's connected

      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then

        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the LED on and off and updates LEDState
            if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO 5 LED on");
              LEDState = "on";
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
            } 
            if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("GPIO 5 LED off");
              LEDState = "off";
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              
            }
            if (header.indexOf("GET /led/wave") >= 0) {
              Serial.println("Led Wave Mode");
              LEDState = "wave";

              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);


              
              digitalWrite(wLED1, HIGH);
             delay(250);
             digitalWrite(wLED1, LOW);
             delay(250);
            
             digitalWrite(rLED2, HIGH);
             digitalWrite(rLED4, HIGH);
             delay(250);
             digitalWrite(rLED2, LOW);
             digitalWrite(rLED4, LOW);
             delay(250);
            
             digitalWrite(yLED3, HIGH);
             digitalWrite(yLED4, HIGH);
             delay(250);
             digitalWrite(yLED3, LOW);
             digitalWrite(yLED4, LOW);
             delay(250);
            
             digitalWrite(yLED2, HIGH);
             digitalWrite(yLED1, HIGH);
             delay(250);
             digitalWrite(yLED2, LOW);
             digitalWrite(yLED1, LOW);
             delay(250);
            
             digitalWrite(rLED1, HIGH);
             digitalWrite(rLED3, HIGH);
             delay(250);
             digitalWrite(rLED1, LOW);
             digitalWrite(rLED3, LOW);
             delay(250);
            
             digitalWrite(wLED2, HIGH);
             delay(250);
             digitalWrite(wLED2, LOW);
             delay(250);
            
             digitalWrite(wLED2, HIGH);
             delay(250);
             digitalWrite(wLED2, LOW);
             delay(250);
            
             digitalWrite(rLED1, HIGH);
             digitalWrite(rLED3, HIGH);
             delay(250);
             digitalWrite(rLED1, LOW);
             digitalWrite(rLED3, LOW);
             delay(250);
            
             digitalWrite(yLED2, HIGH);
             digitalWrite(yLED1, HIGH);
             delay(250);
             digitalWrite(yLED2, LOW);
             digitalWrite(yLED1, LOW);
             delay(250);
            
             digitalWrite(yLED3, HIGH);
             digitalWrite(yLED4, HIGH);
             delay(250);
             digitalWrite(yLED3, LOW);
             digitalWrite(yLED4, LOW);
             delay(250);
            
             digitalWrite(rLED2, HIGH);
             digitalWrite(rLED4, HIGH);
             delay(250);
             digitalWrite(rLED2, LOW);
             digitalWrite(rLED4, LOW);
             delay(250);
            
             digitalWrite(wLED1, HIGH);
             delay(250);
             digitalWrite(wLED1, LOW);
             delay(250);
              digitalWrite(wLED1, HIGH);
             delay(250);
             digitalWrite(wLED1, LOW);
             delay(250);
            
             digitalWrite(rLED2, HIGH);
             digitalWrite(rLED4, HIGH);
             delay(250);
             digitalWrite(rLED2, LOW);
             digitalWrite(rLED4, LOW);
             delay(250);
            
             digitalWrite(yLED3, HIGH);
             digitalWrite(yLED4, HIGH);
             delay(250);
             digitalWrite(yLED3, LOW);
             digitalWrite(yLED4, LOW);
             delay(250);
            
             digitalWrite(yLED2, HIGH);
             digitalWrite(yLED1, HIGH);
             delay(250);
             digitalWrite(yLED2, LOW);
             digitalWrite(yLED1, LOW);
             delay(250);
            
             digitalWrite(rLED1, HIGH);
             digitalWrite(rLED3, HIGH);
             delay(250);
             digitalWrite(rLED1, LOW);
             digitalWrite(rLED3, LOW);
             delay(250);
            
             digitalWrite(wLED2, HIGH);
             delay(250);
             digitalWrite(wLED2, LOW);
             delay(250);
            
             digitalWrite(wLED2, HIGH);
             delay(250);
             digitalWrite(wLED2, LOW);
             delay(250);
            
             digitalWrite(rLED1, HIGH);
             digitalWrite(rLED3, HIGH);
             delay(250);
             digitalWrite(rLED1, LOW);
             digitalWrite(rLED3, LOW);
             delay(250);
            
             digitalWrite(yLED2, HIGH);
             digitalWrite(yLED1, HIGH);
             delay(250);
             digitalWrite(yLED2, LOW);
             digitalWrite(yLED1, LOW);
             delay(250);
            
             digitalWrite(yLED3, HIGH);
             digitalWrite(yLED4, HIGH);
             delay(250);
             digitalWrite(yLED3, LOW);
             digitalWrite(yLED4, LOW);
             delay(250);
            
             digitalWrite(rLED2, HIGH);
             digitalWrite(rLED4, HIGH);
             delay(250);
             digitalWrite(rLED2, LOW);
             digitalWrite(rLED4, LOW);
             delay(250);
            
             digitalWrite(wLED1, HIGH);
             delay(250);
             digitalWrite(wLED1, LOW);
             delay(250);
            }
            if (header.indexOf("GET /led/red") >= 0) {
              Serial.println("Led Red Mode");
              LEDState = "red";
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);


              
               digitalWrite(rLED1, HIGH);
               digitalWrite(rLED2, HIGH);
               digitalWrite(rLED3, HIGH);
               digitalWrite(rLED4, HIGH);
              
            }
            if (header.indexOf("GET /led/yellow") >= 0) {
              Serial.println("Led yellow Mode");
              LEDState = "yellow";
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);

              
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            }
             if (header.indexOf("GET /led/green") >= 0) {
              Serial.println("Led green Mode");
              LEDState = "green";
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);

              
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
            }
             if (header.indexOf("GET /led/red flicker") >= 0) {
              Serial.println("Led red flicker Mode");
              LEDState = "redFlicker";
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);

              
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
            
              delay(150);
              
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
            
              delay(150);
              
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
            
              delay(150);
              
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            }

            
             if (header.indexOf("GET /led/yellow flicker") >= 0) {
              Serial.println("Led yellow flicker Mode");
              LEDState = "yellowFlicker";
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);

              
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(150);
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
            
              delay(150);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(150);
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
            
              delay(150);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(150);
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
            
              delay(150);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(150);
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
            
              delay(150);
             
            }
            if (header.indexOf("GET /led/green flicker") >= 0) {
              Serial.println("Led green flicker Mode");
              LEDState = "greenFlicker";
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);

              
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
             
              delay(150);
              
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
             
              delay(150);
              
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
             
              delay(150);
              
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
             
              delay(150);
              
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
             
            }
             if (header.indexOf("GET /led/ christmas") >= 0) {
              Serial.println("Led christmas Mode");
              LEDState = "christmas";
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);


              
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);

              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              
            }
            if (header.indexOf("GET /led/ christmas") >= 0) {
              Serial.println("Led christmas Mode");
              LEDState = "christmas";
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);

              
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);

              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
            
              delay(150);
              
            }
            if (header.indexOf("GET /led/ sunset") >= 0) {
              Serial.println("Led sunset Mode");
              LEDState = "sunset";
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);

              
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              
              delay(150);
            
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(150);
            
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(150);
            
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
            
              delay(150);
            
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
               delay(150);
            
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(150);

              
            }
            if (header.indexOf("GET /led/ traffic") >= 0) {
              Serial.println("Led traffic Mode");
              LEDState = "traffic";
              
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              delay(50);

              
              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
            
              delay(3000);
            
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(1000);
            
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
            
              delay(3000);

              digitalWrite(rLED1, LOW);
              digitalWrite(rLED2, LOW);
              digitalWrite(rLED3, LOW);
              digitalWrite(rLED4, LOW);
              digitalWrite(wLED1, HIGH);
              digitalWrite(wLED2, HIGH);
            
              delay(3000);
            
              digitalWrite(wLED1, LOW);
              digitalWrite(wLED2, LOW);
              digitalWrite(yLED1, HIGH);
              digitalWrite(yLED2, HIGH);
              digitalWrite(yLED3, HIGH);
              digitalWrite(yLED4, HIGH);
            
              delay(1000);
            
              digitalWrite(yLED1, LOW);
              digitalWrite(yLED2, LOW);
              digitalWrite(yLED3, LOW);
              digitalWrite(yLED4, LOW);
              digitalWrite(rLED1, HIGH);
              digitalWrite(rLED2, HIGH);
              digitalWrite(rLED3, HIGH);
              digitalWrite(rLED4, HIGH);
            
              delay(3000);
            }
            
            
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { width: 20%; background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>Smart Lamp</h1>");
            // Display buttons
            client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            client.println("<p><a href=\"/led/wave\"><button class=\"button button3\">WAVE</button></a></p>");
            client.println("<p><a href=\"/led/red\"><button class=\"button button4\">RED</button></a></p>");
            client.println("<p><a href=\"/led/yellow\"><button class=\"button button5\">YELLOW</button></a></p>");
            client.println("<p><a href=\"/led/green\"><button class=\"button button6\">GREEN</button></a></p>");
            client.println("<p><a href=\"/led/redFlicker\"><button class=\"button button7\">REDFLICKER</button></a></p>");
            client.println("<p><a href=\"/led/yellowFlicker\"><button class=\"button button8\">YELLOWFLICKER</button></a></p>");
            client.println("<p><a href=\"/led/greenFlicker\"><button class=\"button button9\">GREENFLICKER</button></a></p>");
            client.println("<p><a href=\"/led/christmas\"><button class=\"button button10\">CHRISTMAS</button></a></p>");
            client.println("<p><a href=\"/led/sunset\"><button class=\"button button11\">SUNSET</button></a></p>");
            client.println("<p><a href=\"/led/traffic\"><button class=\"button button12\">TRAFFIC</button></a></p>");
            
            // Display current state, and ON/OFF button for GPIO 5
            client.println("<p>LED - State " + LEDState + "</p>");
           


            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
