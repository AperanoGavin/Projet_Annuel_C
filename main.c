#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
int main(int argc, char **argv)
{



    CURL *hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, "https://community-open-weather-map.p.rapidapi.com/weather?q=London%2Cuk&lat=0&lon=0&callback=test&id=2172797&lang=null&units=imperial&mode=xml");

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "X-RapidAPI-Host: community-open-weather-map.p.rapidapi.com");
    headers = curl_slist_append(headers, "X-RapidAPI-Key: 3ae49bd480msh5a2534d4142299ep1d1970jsn9bdcd8eb72ba");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    CURLcode ret = curl_easy_perform(hnd);

    printf("CURLCODE := %u \n ",'curl_easy_perform(hnd)');





    FILE *fp = fopen("ApiFetch.json", "wb");
    //FILE *fp = fopen("ApiFetch.xml", "wb");
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, fp);
    curl_easy_perform(hnd);
    fclose(fp);
    curl_easy_cleanup(hnd);


    //fprintf(fptr,"CURLCODE := %s \n ",curl_easy_perform(hnd));

    fclose(fp);




    //system ( 'gcc -o test -lcurl main.c && ./test >fetchApi.json' );

    return 0;
}