#include <Arduino.h>

#include <PicoJson.h>


void setup() {
    Serial.begin(115200);

    PicoJson json(Serial);

    json["one"] = 1;
    json["pi"] = 3.14;
    json["text"] = "PicoJson";

    json["true"] = true;
    json["false"] = false;

    auto list = json["list"];
    list.append() = 10;
    list.append() = 20;
    list.append() = 30;

    json["another_list"] = {"10", 20, 30.5, nullptr};

    auto nested = json["nested"];
    nested["foo"] = 10;
    nested["bar"] = "bar";
    nested["baz"] = nullptr;
}

void loop() {
    delay(1000);
}
