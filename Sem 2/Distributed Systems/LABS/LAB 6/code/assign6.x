/* This is the IDL file -- name it as add.x*/

/*combine the arguments to be passed to the server side in a structure*/

#define MAX 200
struct numb{
	int a;
	int b;
};

struct strings{
	char str1[MAX];
	char str2[MAX];
};

struct arr{
	int ar[MAX];
	int len;

};

struct stat{
	int max;
	int min;
	int avg;

};

/*1*/
program PALINDROME_PROG{
	version PALINDROME_VERS{
		int palindrome(strings)=1;
	}=1;
}=0x4562871;

/*2*/
program LEAP_PROG{
	version LEAP_VERS{
		int leap(numb)=1;
	}=1;
}=0x4562873;

/*3*/
program GCD_PROG{
	version GCD_VERS{
		int gcd(numb)=1;
	}=1;
}=0x4562875;

/*4*/
program ROOT_PROG{
	version ROOT_VERS{
		float root(numb)=1;
	}=1;
}=0x4562877;

/*5*/
program SWAP_PROG{
	version SWAP_VERS{
		numb swap(numb)=1;
	}=1;
}=0x4562879;

/*6*/
program STATE_PROG{
	version STATE_VERS{
		stat state(arr)=1;
	}=1;
}=0x4562881;


/*7*/
program CMP_PROG{
	version CMP_VERS{
		int cmp(strings)=1;
	}=1;
}=0x4562883;

/*8*/
program SUB_PROG{
	version SUB_VERS{
		int sub(strings)=1;
	}=1;
}=0x4562885;


/*9*/
program CONT_PROG{
	version CONT_VERS{
		strings cont(strings)=1;
	}=1;
}=0x4562887;

/*10*/
program REV_PROG{
	version REV_VERS{
		arr rev(arr)=1;
	}=1;
}=0x4562889;

