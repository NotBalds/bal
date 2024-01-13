all: build install clean

build:
	g++ -I./include/ ./src/main.cpp -o out

install:
	cp ./out ~/.local/bin/bal
	chmod +x ~/.local/bin/bal

clean:
	rm -rf ./out
