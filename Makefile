all: rsvd

rsvd:
	mkdir -p build \
		&& cd build \
		&& cmake ../ \
		&& make


clean:
	clean:
	rm -rf ./build
