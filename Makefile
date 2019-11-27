LD=gcc
LIB = -lm
BUILD_DIR = "./build"
TRAIN_EXECUTABLE = build/train
TEST_EXECUTABLE = build/test

all: create_build train_executable test_executable make_run_script

create_build:
	mkdir -p $(BUILD_DIR)

test_executable:
	$(LD) -o $(TEST_EXECUTABLE) src/test.c $(LIB)

train_executable:
	$(LD) -o $(TRAIN_EXECUTABLE) src/train.c $(LIB)

clean:
	rm -f -r $(BUILD_DIR)
	rm -f runscript

make_run_script:
	echo -e "cd build\n\
	./train\n\
	./test\n"\
	> runscript
	chmod a+x runscript
