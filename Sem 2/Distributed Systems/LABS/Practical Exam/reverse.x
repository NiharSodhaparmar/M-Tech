struct A {
	int a;
};

program PROG_REV {
	version VER_REV{
		int reverse(A) = 1;
	}=1;
}=0x1234567;
