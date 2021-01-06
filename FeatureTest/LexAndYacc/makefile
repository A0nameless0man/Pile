BUILD_DIR = target/
TARGET = $(BUILD_DIR)out.exe


all:$(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir $@

$(TARGET):$(BUILD_DIR)lex.yy.c $(BUILD_DIR)HelloWorld.tab.c
	g++ $^ -lfl -ly -o $@

$(BUILD_DIR)lex.yy.c:HelloWorld.l
	flex -o $@ $<

$(BUILD_DIR)HelloWorld.tab.c:HelloWorld.y
	bison -o $(BUILD_DIR)HelloWorld.tab.c --defines=$(BUILD_DIR)HelloWorld.tab.h $<