/*
  Device.h - Handle the controlled device
  Saul bertuccio 4 feb 2017
  Released into the public domain.
*/

#ifndef Device_h
#define Device_h

#include "Arduino.h"
#include "WString.h"
#include "RfKey.h"

// GPIO16 -> D0 ->
// GPIO05 -> D1 -> Pin Ricevitore RF433
// GPIO04 -> D2 -> Pin Trasmettitore RF433
// GPIO00 -> D3 -> 
// GPIO02 -> D4 -> 


class Device {

  public:

    static const int MAX_NAME_LENGTH = 16;
    static String TYPES[];
    static String TYPES_DESCRIPTION[];
    static const int TYPE_NUM=2;


    static const int RF_RX_PIN = D2;
    static const int RF_TX_PIN =  D1;

 
    Device(const String &dev_name, const String &dev_type);
    ~Device();

    void setName(const String &new_name);
    void setType(const String &new_type);
    String getName();
    String getType();
    Key * getKeys();

    String * getKeysPropertyNames();
    int getKeysPropertyNum();
    boolean isValidPropertyById(int id, const String &val);

    boolean addKey(String * key_data);
    boolean removeKey(const String &key_name );
    Key * acquireKeyData();


  private:
    String dev_name;
    String dev_type;
    Key * first_key = NULL;
    Key * last_key = NULL;

    Key * findPreviousKeyByName(const String &key_name );

    String * getProperties(const String names[], int len);


    static Key * acquireRfKeyData();

};

#endif




