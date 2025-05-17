#include "RFIDScanner.h"

RFIDScanner::RFIDScanner(uint8_t ssPin, uint8_t rstPin) : mfrc522(ssPin, rstPin) {}

void RFIDScanner::init() {
    SPI.begin();
    mfrc522.PCD_Init();
    uint8_t version = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
    if (version == 0x00 || version == 0xFF) {
        Serial.println("ERROR: MFRC522 not detected! Check wiring.");
    } else {
        Serial.println("MFRC522 detected, version: 0x" + String(version, HEX));
        Serial.println("RFID scanner initialized");
    }
}

String RFIDScanner::scanCard() {
    if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
        return "";
    }
    String uid = getCardUID();
    mfrc522.PICC_HaltA();
    return uid;
}

String RFIDScanner::getCardUID() {
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        if (mfrc522.uid.uidByte[i] < 0x10) uid += "0";
        uid += String(mfrc522.uid.uidByte[i], HEX);
    }
    uid.toUpperCase();
    return uid;
}