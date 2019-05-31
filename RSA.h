/* The following code uses the RSA algorithm to encrypt and decrypt a given string(message) */

/************************************************
- Variables used within the RSA algorithm where:
		p&q are the prime numbers
		n is the modulus (product of p&q)
		t is the totient
- Declaration of arrays
************************************************/


/* Checks to see whether the numbers chosen are prime or not */
int x, y, n, t, i, flag; 
int e[50], d[50], temp[50], j,m[50], en[50];
char msg[100]; 
char* encrypted;
char* decrypted;

/* The functions used in the creation of the encryption key */
void encryption_key(); 
long int cd(long int); 

/* The functions for encrypting and decrypting */
void encrypt(); 
void decrypt(); 
/*
int main()
{

	printf("\nPlease enter the first prime\n");
	scanf("%d", &x); 
	flag = prime(x);
		if(flag == 0)
		{
			printf("\nNot valid\n");
			exit(0);
		}

	printf("\nPlease enter the second prime\n");
	scanf("%d", &y); 
	flag = prime(y);
		if(flag == 0 || x == y)
		{
			printf("\nNot valid\n");
			exit(0);
		}
*/
	/* Calculates the modulus and totient (phi) */
	/*printf("\nEnter the message to be encrypted\n");
	scanf("%s",msg); 
		for(i = 0; msg[i] != '\0'; i++) 
			m[i] = msg[i];

			n = x * y; 
			t = (x-1) * (y-1); */

	/* Creation of the encryption key */
	/*encryption_key(); 
	printf("\nValues that e and d could be\n");
		for(i = 0; i < j-1; i++)
			printf("\n%d\t%d", e[i], d[i]);
				encrypt();
				decrypt();
		return 0;
}*/

/* Checking for primes once again */


/* - Following is the function to create the encryption key 
     where e = encrypt and d = decrypt.
   - Possible values for the integers (e&d) are shown in the arrays
   - k is just an integer  */
int prime(long int);
void encryption_key()
{
	int k;
	k = 0;

	for(i = 2; i < t; i++) 
	{
		if(t % i == 0)
		continue;
		flag = prime(i);

		if(flag == 1 && i != x && i != y)
		{
			e[k] = i;
			flag = cd(e[k]); 
/* Selecting the private key d */
			if(flag > 0)
			{
				d[k] = flag;
				k++;
			}

			if(k == 99)
			break;
		}
	}
}

/* Showing that d satisfies part of the RSA algorithm d*e = 1+k*t */
long int cd(long int a)
{
	long int k = 1;
	while(1)
	{
		k = k + t;
		if(k % a == 0)
		return(k / a);
	}
}

/* The function where the message is encrypted
   Satisfies c=(msg^e)%n */

void encrypt()
{
	long int pt, ct, key = e[0], k, len;
	i = 0;
	len = strlen(msg);
	while(i != len)
	{
		pt = m[i];
		pt = pt - 96;
		k = 1;

		for(j = 0; j < key; j++)
		{
			k = k * pt;
			k = k % n;
		}

		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}

	en[i] = -1;
	/*
	printf("\n\nThe message encrypted:\n");
	for(i = 0; en[i] != -1; i++)
		printf("%c", en[i]);*/

}

/*The function where the message is decrypted 
  Satisfies m=(c^d)%n */
void decrypt()
{
	long int pt, ct, key = d[0], k;
	i = 0;
	while(en[i] != -1)
		{
			ct = temp[i];
			k = 1;
			for(j = 0; j < key; j++) 
			{
				k = k * ct;
				k = k % n;
			}

			pt = k + 96;
			m[i] = pt;
			i++;
		}

		m[i] = -1;
		/*printf("\n\nThe message decrypted:\n");*/
		for(i = 0; m[i] != -1; i++)
			printf("%c", m[i]);
		printf("\n");
}

/* End of RSA implementation */
