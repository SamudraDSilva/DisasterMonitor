#include "RFIDScanner.h"
#include "AuthorizationManager.h"

RFIDScanner rfid(5, 4); // SDA: GPIO 5, RST: GPIO 4
String authorizedUIDs[] = {"03CC1F2D", "23A0E107"}; // Authorized UIDs
AuthorizationManager auth(authorizedUIDs, 2); // Pass array and count

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Starting RFID scanner...");
    rfid.init();
    Serial.println("Ready to scan RFID cards...");
}

void handleRFIDScan() {
    String cardUID = rfid.scanCard();
    if (cardUID != "") {
        Serial.println("--- RFID Card Detected ---");
        Serial.println("UID: " + cardUID);
        if (auth.isAuthorized(cardUID)) {
            Serial.println("Access OK");
        } else {
            Serial.println("Access Blocked");
        }
        Serial.println("------------------------");
    }
}

void loop() {
    handleRFIDScan();
    delay(1000); // Prevent rapid scanning
}