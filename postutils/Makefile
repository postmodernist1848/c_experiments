CC=cc
ALL=ascii_table commentscanner myage nigger

.PHONY: all install clean uninstall

all: $(ALL)

%: %.c
	$(CC) -o $@ $<

#if prefix is not set
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

install: $(ALL)
	mkdir -p $(PREFIX)/bin/
	cp $(ALL) $(PREFIX)/bin/

uninstall:
	$(foreach fil,$(ALL),$(shell rm $(PREFIX)/bin/$(fil)))

clean:
	rm $(ALL)
