BEGIN {
	system("cc mutex.c -lpthread")
	for (i=1; i<=1000000; i++) system("./a.out >> out.mutex")
}
