/* This is the IDL file -- name it as add.x*/

/*combine the arguments to be passed to the server side in a structure*/

#define MAX 200
struct numb{
	int a;
	
};


struct calc{
	int a;
	int b;
	char c;
};

struct arr{
	int ar[MAX];
	int len;

};

program FACT_PROG{
	version FACT_VERS{
		int fact(numb)=1;
	}=1;
}=0x4562877;

program PRIME_PROG{
	version PRIME_VERS{
		int prime(numb)=1;
	}=1;
}=0x4562879;


program CALCB_PROG{
	version CALCB_VERS{
		int calcb(calc)=1;
	}=1;
}=0x4562882;

program FIB_PROG{
	version FIB_VERS{
		arr fib(numb)=1;
	}=1;
}=0x4562884;

program FINDMAX_PROG{
	version FINDMAX_VERS{
		int findmax(arr)=1;
	}=1;
}=0x4562886;
	
	
	
