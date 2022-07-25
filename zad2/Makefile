program: main.o comparators.o
	gcc -lm main.o comparators.o -o $@

sprogram: main.o libcomparators.a
	gcc -lm main.o -o $@ -L . libcomparators.a

dprogram: main.o libcomparators.so
	gcc -lm main.o -o $@ -L . libcomparators.so

libcomparators.so: picomparators.o
	gcc -shared -o $@ $<

picomparators.o: comparators.c
	gcc -fPIC -c comparators.c -o $@

libcomparators.a: comparators.o
	ar -rcs $@ $<

main.i: main.c
	gcc -E main.c -DMIN=1 -DMAX=15 -DCOUNT=5 -o $@

main.o: main.s
	gcc -c $< -o $@

main.s: main.i
	gcc -S $< -o $@
comparators.o: comparators.s
	gcc -c $< -o $@

comparators.s: comparators.i
	gcc -S $< -o $@

comparators.i: comparators.c
	gcc -E $< -o $@

clean:
	rm -f *.o *.i *.s *.out program dprogram sprogram *.so *.a
