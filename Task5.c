#include<stdio.h>
#include<openssl/bn.h>

#define NBITS 256 


void printBN(char * msg, BIGNUM *a){


	// BN_bn2hex(a) for hex string 
	// BN_bn2dec(a) for decimal strings 


	char * number_str = BN_bn2hex(a);
	printf("%s %s\n", msg,number_str);
	OPENSSL_free(number_str);
}


int main(int argc, char const *argv[])
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *s = BN_new();	
	BIGNUM *n = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *message = BN_new();

	BN_hex2bn(&s,"643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");

	BN_hex2bn(&n,"AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
	BN_hex2bn(&e,"010001");


    BN_mod_exp(message,s,e,n,ctx);
    printBN("message is = ",message);

	return 0;
}

//Launch a missile.?


//change  the value of the signature than again check the output , then see how file was corrupted or not 


