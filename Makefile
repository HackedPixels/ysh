all:
	cc main.c ysh_string.c ysh_io.c ysh_builtins.c
	mkdir ./build/
	mv ./a.out ./build/ysh.out

	make config

clean:
	rm -r ./build/ && echo "already clean"

config:
	echo "" > ./build/.yshrc
	echo "YSH - A shell to learn to shell" > ./build/.yshwelcome
	echo "Copyright by HackedPixels et al." >> ./build/.yshwelcome
