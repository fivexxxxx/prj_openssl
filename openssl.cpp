#define _CRT_SECURE_NO_WARNINGS

#include<openssl/md5.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void  get_md5(const char* str, char* result)
{
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, str, strlen(str));

	unsigned char md[16] = { 0 };
	MD5_Final(md, &ctx);
	for (int i = 0; i < 16; ++i) {
		sprintf(&result[i * 2], "%02x", md[i]);
	}
}
int main() {
	char result[33] = { 0 };
	get_md5("hello,md5", result);
	printf("md5 value:%s\n", result);
	system("pause");
	return 0;
}