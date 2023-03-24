push:
	git add --all
	git commit -am "MK"
	git push
we5_solution:
	g++ matrix.cpp we5_test.cpp matrix.h -o we5_solution
clean:
	rm we5_solution
test:
	g++ matrix.cpp matrix.h test.cpp -o test
	./test
	rm test