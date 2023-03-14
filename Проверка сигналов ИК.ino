#include <IRremote.h> // подключаем библиотеку

int reciverPin = 11; // пин, к котрому подключен ИК-приемник
IRrecv irrecv(reciverPin);
  
decode_results results;
  
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // запуск приемника

}
void loop() {
  // постоянно считываем данные с приемника
  if (irrecv.decode(&results)) {
    // выводим в консольку, что получили, число в 16-ричном виде
    Serial.println('Lol');
    Serial.println(results.value, HEX);
    // проверяем сигналы - и если это те, что нам нужны, то вкл или выкл светодиод
    irrecv.resume(); // готовы принимать следующий сигнал
  }
}