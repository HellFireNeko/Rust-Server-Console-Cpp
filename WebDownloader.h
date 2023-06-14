#pragma once
#include <string>
#include <curl/curl.h>

class WebDownloader
{
public:
	static bool DownloadFile(std::string url, std::string file);

private:
	static size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream);
};

