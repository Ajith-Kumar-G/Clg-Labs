#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
int main()
{
	#ifdef _POSIX_JOB_CONTROL
		printf("System supports job control\n");
	#else
	 	printf("System does not support job control \n");
	#endif
	#ifdef _POSIX_SAVED_IDS
		printf("System supports saved set-UID and saved set-GID\n");
	#else
		printf("System does not support saved set-UID and saved set-GID \n");
	#endif
	#ifdef _POSIX_CHOWN_RESTRICTED
		printf("chown_restricted option is %d\n",_POSIX_CHOWN_RESTRICTED);
	#else
		printf("System does not support chown_restricted option \n");
	#endif
	#ifdef _POSIX_NO_TRUNC
		printf("Pathname trunc option is %d\n",_POSIX_NO_TRUNC);
	#else
		printf("System does not support system-wide pathname trunc option \n");
	#endif
	#ifdef _POSIX_VDISABLE
		printf("Disable character for terminal files is %d\n",_POSIX_VDISABLE);
	#else
		printf(" System does not support _POSIX_VDISABLE \n");
	#endif
	return 0;
}
