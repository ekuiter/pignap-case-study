#ifndef HTTPD_H
#define HTTPD_H

#include "esp_http_server.h"

// The C files are copied from the esp_http_server component, only httpd_start() is modified.

esp_err_t httpd_start_pinned_to_core(httpd_handle_t *handle, const httpd_config_t *config, const BaseType_t coreID);

#endif