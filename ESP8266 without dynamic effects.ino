#include <FastLED.h>   // библиотека для светодиодки
#include <IRremote.h>  // библиотека для ик датчика
byte bright = 100;     // яркость LED светодиодов
byte baza = 0;
#define LED_PIN 4
#define LED_NUM 150

IRrecv irrecv(11);  // указываем вывод, к которому подключен приемник
decode_results results;

CRGB leds[LED_NUM];

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);   // выставляем скорость COM порта
  irrecv.enableIRIn();  // запускаем прием
  FastLED.addLeds< WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(bright);
}

void loop() {

  if (irrecv.decode(&results)) {  // если данные пришли
    Serial.println(results.value, HEX);
    Serial.println(results.value);
   
    switch (results.value) {
      case 0xFF3AC5:  //добавить яркость
        bright = bright + 10;
        FastLED.setBrightness(bright);
        FastLED.showColor(CRGB::Red);

        break;
      case 0xFFBA45:  //убавить яркость
        if (bright - 10 >= 0) {
          bright = bright - 10;
          FastLED.setBrightness(bright);
          FastLED.showColor(CRGB::Red);
        }


        break;
      case 0xFF1AE5:  //красный
        FastLED.showColor(CRGB::Red);
        FastLED.setBrightness(bright);
        Serial.println('Lol');
        break;
      case 0xFF9A65:
        FastLED.showColor(CRGB::Green);
        FastLED.setBrightness(bright);

        break;
      case 0xFFA25D:
        FastLED.showColor(CRGB::Blue);


        break;
      case 0xFF22DD:
        FastLED.showColor(CRGB::White);


        break;
      case 0xFF2AD5:
        FastLED.showColor(CRGB::OrangeRed);


        break;
      case 0xFF0AF5:
        FastLED.showColor(CRGB::Orange);


        break;
      case 0xFF18E7:
        FastLED.showColor(CRGB::Yellow);


        break;
      case 0xFFAA55:
        FastLED.showColor(CRGB::YellowGreen);


        break;
      case 0xFF8A75:
        FastLED.showColor(CRGB::Turquoise);  //кнопка под светлозеленым


        break;
      case 0xFF926D:
        FastLED.showColor(CRGB::SlateBlue);  //под синим


        break;
      case 0xFFB24D:
        FastLED.showColor(CRGB::Purple);  //темнофиолетовый


        break;
      case 0xFF7887:
        FastLED.showColor(CRGB::MediumVioletRed);  //


        break;
      case 0xFF58A7:
        FastLED.showColor(CRGB::Violet);  //


        break;
      case 0xFF38C7:  //РАДУГА)
        
        while ((irrecv.decode(&results)) and (results.value == 16726215)) {
          
          Serial.println(results.value, HEX);
          irrecv.resume();
          
          for (int r = 0; r < 10000; r++) {
            for (int i = 0; i < LED_NUM; i++) {
              leds[i] = CHSV(baza + i * 5, 255, 255);
              
            }
            irrecv.resume();
            FastLED.show();
            
              baza++;
          }
        }
        break;



      case 0xFFB847:  //ЦИКЛОН
        for (int i = 0; i < LED_NUM; i++) {
          leds[i].nscale8(250);
        }
        for (int i = 0; i < LED_NUM; i++) {
          leds[i] = CHSV(baza++, 255, 255);
        }
        FastLED.setBrightness(bright);
        FastLED.show();
        delay(20);
        break;
      case 0xFF9867:  //БЕГУЩИЙ ОГОНЕК
        fadeToBlackBy(leds, LED_NUM, 2);
        int pos = beatsin16(13, 0, LED_NUM - 1);
        leds[pos] += CHSV(baza++, 255, 192);
        FastLED.setBrightness(bright);
        FastLED.show();
        break;
      case 0xFFE01F:


        FastLED.show();
        break;
      case 0xFFE01F:


        FastLED.show();
        break;
      case 0xFFE01F:


        FastLED.show();
        break;
      case 0xFFE01F:


        FastLED.show();
        break;
      case 0xFFE01F:


        FastLED.show();
        break;
      case 0xFFE01F:


        FastLED.show();
        break;
    }
    irrecv.resume();  // принимаем следующую команду
  }
}