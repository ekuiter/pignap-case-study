#ifndef WIFI_H
#define WIFI_H

char* wifi_get_ap_ssid();
char* wifi_get_ap_psk();
char* wifi_get_sta_ssid();
char* wifi_get_sta_psk();
void wifi_set_config(char* ap_ssid, char* ap_psk, char* sta_ssid, char* sta_psk);
void _wifi_init();

#endif