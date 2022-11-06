#include <stdio.h>      
#include <math.h>
#include <cstdlib>
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <string>

#include "vcpkg/packages/curl_x86-windows/include/curl/curl.h"
#include "vcpkg/packages/gumbo_x86-windows/include/gumbo.h"
#include "scrape.h"
using namespace std;

typedef size_t(*curl_write)(char*, size_t, size_t, string*);

string request(string url) { 
    
    CURLcode res_code = CURLE_FAILED_INIT;
    CURL * curl = curl_easy_init();
    string result;
    curl_global_init(CURL_GLOBAL_ALL);

    if (curl) {
        curl_easy_setopt(curl,
            CURLOPT_WRITEFUNCTION,
            static_cast <curl_write> ([](char* contents, size_t size,
                size_t nmemb, string* data) -> size_t {
                    size_t new_size = size * nmemb;
                    if (data == NULL) {
                        return 0;
                    }
                    data->append(contents, new_size);
                    return new_size;
                }));
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "simple scraper");

        res_code = curl_easy_perform(curl);

        if (res_code != CURLE_OK) {
            return curl_easy_strerror(res_code);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return result;
}