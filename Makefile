all:
	@echo "<<< Compiling >>>"
	# compile all the source files.
	# the .c files have to be given for the linker.
	@cc main.c ysh_string.c ysh_io.c ysh_builtins.c
	# the directory where we will lay our compiled files.
	@mkdir ./build/
	# move our compiled file in the build file.
	# (and call it ysh.out)
	@mv ./a.out ./build/ysh.out

	# generate the config files.
	# without this step, the program WILL fail.
	@make config

clean:
	@echo "<<< Cleaning up. >>>"
	# remove the build folder to start clean
	# if the remove failed, the folder did not exist
	# or it was cleaned before.
	@rm -r ./build/ && echo "already clean"

config:
	@echo "<<< Creating Config >>>"
	# generate the launch script.
	@echo "" > ./build/.yshrc
	# a warm welcome message.
	@echo "YSH - A shell to learn to shell" > ./build/.yshwelcome
	@echo "Copyright by HackedPixels et al." >> ./build/.yshwelcome 
