#ifndef WIFI_H
#define WIFI_H

#include "esp_wifi.h"

typedef enum {
    DISCONNECTED, CONNECTING, RETRYING, CONNECTED
} wifi_sta_state_t;

char* wifi_get_ap_ssid();
char* wifi_get_ap_psk();
char* wifi_get_sta_ssid();
char* wifi_get_sta_psk();
wifi_sta_state_t wifi_get_sta_state();
ip4_addr_t wifi_get_sta_ip();
void wifi_set_config(char* ap_ssid, char* ap_psk, char* sta_ssid, char* sta_psk);
void wifi_reconnect();
void _wifi_init();

#endif