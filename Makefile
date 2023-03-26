push:
	git add --all
	git commit -am "MK"
	git push
project:
	g++ SOLVER.cpp matrix.cpp matrix.h -o SOLVER
clean:
	rm -f *.o
	rm -f program
	rm test
test:
	g++ SOLVER.cpp matrix.cpp matrix.h -o test
	./test
	rm test