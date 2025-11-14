#include <stdio.h>
#include <curl/curl.h>

int main(void) {
	CURL *curl;
	CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
	if(res) {
		printf("CANNOT INIT CURL\n");
		return (int)res;
	}
	curl = curl_easy_init();
	if(curl){
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~gc");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK) printf("Please check your URL\n");
		
	}
	curl_global_cleanup();
}
