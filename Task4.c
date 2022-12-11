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

//

int main(int argc, char const *argv[])
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *m = BN_new();
	BIGNUM *sign = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *d = BN_new();

	BN_hex2bn(&n,"DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");

	BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    // m is I owe you $2000 ==> 49206f776520796f75202432303030
    //I owe you $3000 ==> 49206f776520796f75202433303030
	BN_hex2bn(&m,"49206f776520796f75202433303030");

	BN_mod_exp(sign,m,d,n,ctx);
	printBN("signed message = ", sign);
	

	return 0;
}

/*


┌──(root㉿kali)-[/home/kali/Algorithm]
└─# ./task4                        
signed message =  80A55421D72345AC199836F60D51DC9594E2BDB4AE20C804823FB71660DE7B82
                                                                                                                                                    
┌──(root㉿kali)-[/home/kali/Algorithm]
└─# gcc  Task4.c  -o task4 -lcrypto
                                                                                                                                                    
┌──(root㉿kali)-[/home/kali/Algorithm]
└─# ./task4                        
signed message =  04FC9C53ED7BBE4ED4BE2C24B0BDF7184B96290B4ED4E3959F58E94B1ECEA2EB


*/