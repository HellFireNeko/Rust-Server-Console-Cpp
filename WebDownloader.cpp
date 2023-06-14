#define _CRT_SECURE_NO_DEPRECATE
#include "WebDownloader.h"

size_t WebDownloader::write_data(void* ptr, size_t size, size_t nmemb, FILE* stream)
{
	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}

bool WebDownloader::DownloadFile(std::string url, std::string file)
{
	CURL* curl;
	FILE* fp;
	CURLcode res;

	curl = curl_easy_init();
	if (curl)
	{
		fp = fopen(file.c_str(), "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

		res = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
		fclose(fp);

		return true;
	}
	return false;
}