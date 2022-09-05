int lightPin = A1;
int humidityPin = A6;

int light;
int humidity;
int val;

void setup()
{
    pinMode(lightPin, INPUT);
    pinMode(humidityPin, INPUT);

    Serial.begin(115200);
    Serial1.begin(115200);
}

char light_c;
char humidity_c;

void loop()
{
    int light = analogRead(lightPin);
    int humidity = analogRead(humidityPin);

    light = 1024 - light;
    light_c = (char)map(light, 0, 1024, 0, 100);

    humidity = 1024 - humidity;
    humidity_c = (char)map(humidity, 0, 1024, 0, 100);

    Serial.print("light = ");
    Serial.println(light_c);

    Serial.print("humidity = ");
    Serial.println(humidity_c);

    Serial1.print(light_c);
    Serial1.print(humidity_c);

    delay(2000);
}