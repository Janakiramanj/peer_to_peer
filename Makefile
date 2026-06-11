CC = gcc
CFLAGS = -Wall -g -Iinclude

BUILD = build

APP = $(BUILD)/p2p

all: $(APP)

$(APP): src/user_handler.c src/replace.c src/find.c src/signal_handler.c src/conv.c  
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rf $(BUILD)/*