push:
	git add --all
	git commit -am "MK"
	git push
project:
	g++ main.cpp matrix.cpp matrix.h -o program
clean:
	rm -f *.o
	rm -f program
test:
	g++ main.cpp matrix.cpp matrix.h -o test
	./test
	rm test