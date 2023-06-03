

// Inclusão das bibliotecas
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Configração do WiFi
const char* ssid = "DIE_GO 2G";  // SSID Wifi
const char* password = "die@go123";  // Senha Wifi

// Variáveis de Server e Status do LED
ESP8266WebServer server(80);

// Definindo os pinos com a nomeclatura utilizada

bool LUZsala = HIGH;
bool LUZcozinha = HIGH;
bool LUZgaragem = HIGH;
bool LUZbanheiroum = HIGH;
bool LUZvaranda = HIGH;
bool LUZquartoum = HIGH;
bool LUZquartodois = HIGH;
bool LUZescada = HIGH;
bool LUZbanheirodois = HIGH;
bool LUZteste = HIGH;


void setup() {
  // Inicia Serial e LED
  Serial.begin(9600);
  
  // Inicia Conexão WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT); 
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(1, OUTPUT);

  // Aguarda Conexão e Informa IP
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Rede WiFi: ");
  Serial.println(ssid);
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  delay(100);

  // Configura Handles do Server e Inicia Server
  server.on("/", handle_OnConnect);
  server.on("/sala1", handle_sala1);
  server.on("/sala0", handle_sala0);
  server.on("/cozinha1", handle_cozinha1);
  server.on("/cozinha0", handle_cozinha0);
  server.on("/garagem1", handle_garagem1);
  server.on("/garagem0", handle_garagem0);
  server.on("/varanda1", handle_varanda1);
  server.on("/varanda0", handle_varanda0);
  server.on("/escada1", handle_escada1);
  server.on("/escada0", handle_escada0);
  server.on("/quartoum1", handle_quartoum1);
  server.on("/quartoum0", handle_quartoum0);
  server.on("/quartodois1", handle_quartodois1);
  server.on("/quartodois0", handle_quartodois0);
  server.on("/banheiro11", handle_banheiro11);
  server.on("/banheiro10", handle_banheiro10);
  server.on("/banheiro21", handle_banheiro21);
  server.on("/banheiro20", handle_banheiro20);
     
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("Servidor HTTP iniciado!");

}

void loop() {
  server.handleClient();    // Faz o Handle
  if (LUZsala){           // Checa se LED deve acender
    digitalWrite(5, HIGH);}
  else{
    digitalWrite(5, LOW);}
  if (LUZcozinha){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }
  if (LUZgaragem){
    digitalWrite(0, HIGH);
  }
  else{
    digitalWrite(0, LOW);
  }
  if (LUZvaranda){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
  if (LUZescada){
    digitalWrite(14, HIGH);
  }
  else{
    digitalWrite(14, LOW);
  }
  if (LUZquartoum){
    digitalWrite(12, HIGH);
  }
  else{
    digitalWrite(12, LOW);
  }
  if (LUZquartodois){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
  if (LUZbanheiroum){
    digitalWrite(16, HIGH);
  }
  else{
    digitalWrite(16, LOW);
  }
  if (LUZbanheirodois){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3, LOW);
  }
 
}

// FUNÇÕES HANDLE PARA HTML SERVER

void handle_OnConnect() {
  LUZvaranda = LOW;
  server.send(200, "text/html", SendHTML(false));
  delay(5000);
  LUZvaranda = HIGH;
}

void handle_sala1() {
  LUZsala = LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz da sala acesa");
}

void handle_sala0() {
  LUZsala = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz da sala apagada");
}

void handle_cozinha1(){
  LUZcozinha = LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz da cozinha acesa");
}

void handle_cozinha0(){
  LUZcozinha = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz da cozinha apagada");
}

void handle_garagem1(){
  LUZgaragem = LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz da garagem acesa");
}

void handle_garagem0(){
  LUZgaragem = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz da garagem apagada");
}

void handle_varanda1(){
  LUZvaranda = LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz da varanda acesa");
}

void handle_varanda0(){
  LUZvaranda = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz da varanda apagada");
}

void handle_escada1(){
  LUZescada= LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz da escada acesa");
}

void handle_escada0(){
  LUZescada = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz da escada apagada");
}

void handle_quartoum1(){
  LUZquartoum= LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz do quarto um acesa");
}

void handle_quartoum0(){
  LUZquartoum = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz do quarto um apagada");
}

void handle_quartodois1(){
  LUZquartodois= LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz do quarto dois acesa");
}

void handle_quartodois0(){
  LUZquartodois = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz do quarto dois apagada");
}

void handle_banheiro11(){
  LUZbanheiroum= LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz do banheiro um acesa");
}

void handle_banheiro10(){
  LUZbanheiroum = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz do banheiro um apagada");
}

void handle_banheiro21(){
  LUZbanheirodois= LOW;
  server.send(200, "text/html", SendHTML(true));
  Serial.println("Luz do banheiro um acesa");
}

void handle_banheiro20(){
  LUZbanheirodois = HIGH;
  server.send(200, "text/html", SendHTML(false));
  Serial.println("Luz do banheiro dois apagada");
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t casa) {
  String ptr = "<!DOCTYPE html>\n";
  ptr += "<html>\n";
  ptr += "<head>\n";
  ptr += "<title>Controle da Casa</title>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h0>Comodos</h0>\n";
  ptr += "<p>Clique para Ligar e Desligar as luzes.</p>\n";
  ptr += "<form method=\"get\">\n";
  if (casa){
    ptr += "<input type=\"button\" value=\"Desligar Sala\" onclick=\"window.location.href='/sala0'\">\n";
    ptr += "<input type=\"button\" value=\"Desligar Cozinha\" onclick=\"window.location.href='/cozinha0'\">\n";
    ptr += "<input type=\"button\" value=\"Desligar Garagem\" onclick=\"window.location.href='/garagem0'\">\n";
    ptr += "<input type=\"button\" value=\"Desligar Varanda\" onclick=\"window.location.href='/varanda0'\">\n";
    ptr += "<input type=\"button\" value=\"Desligar Escada\" onclick=\"window.location.href='/escada0'\">\n";
    ptr += "<input type=\"button\" value=\"Desligar Quarto Um\" onclick=\"window.location.href='/quartoum0'\">\n";
    ptr += "<input type=\"button\" value=\"Desligar Quarto Dois\" onclick=\"window.location.href='/quartodois0'\">\n";
    ptr += "<input type=\"button\" value=\"Desligar Banheiro Um\" onclick=\"window.location.href='/banheiro10'\">\n";
    ptr += "<input type=\"button\" value=\"Desligar Banheiro Dois\" onclick=\"window.location.href='/banheiro20'\">\n";
  }
  else{
    ptr += "<input type=\"button\" value=\"Ligar Sala\" onclick=\"window.location.href='/sala1'\">\n";
    ptr += "<input type=\"button\" value=\"Ligar Cozinha\" onclick=\"window.location.href='/cozinha1'\">\n";
    ptr += "<input type=\"button\" value=\"Ligar Garagem\" onclick=\"window.location.href='/garagem1'\">\n";
    ptr += "<input type=\"button\" value=\"Ligar Varanda\" onclick=\"window.location.href='/varanda1'\">\n";
    ptr += "<input type=\"button\" value=\"Ligar Escada\" onclick=\"window.location.href='/escada1'\">\n";
    ptr += "<input type=\"button\" value=\"Ligar Quarto Um\" onclick=\"window.location.href='/quartoum1'\">\n";
    ptr += "<input type=\"button\" value=\"Ligar Quarto Dois\" onclick=\"window.location.href='/quartodois1'\">\n";
    ptr += "<input type=\"button\" value=\"Ligar Banheiro Um\" onclick=\"window.location.href='/banheiro11'\">\n";
    ptr += "<input type=\"button\" value=\"Ligar Banheiro Dois\" onclick=\"window.location.href='/banheiro21'\">\n";
  }
  ptr += "</form>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
  

}
