#ifndef RFID_SCANNER_H
#define RFID_SCANNER_H

#include <MFRC522.h>

class RFIDScanner {
public:
    RFIDScanner(uint8_t ssPin, uint8_t rstPin);
    void init();
    String scanCard();

private:
    MFRC522 mfrc522;
    String getCardUID();
};

#endif