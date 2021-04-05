compile: update
	make -f qMakefile

run: compile
	./blockeditor

clean:
	rm -f blockeditor *.o ui_blockeditor.h moc_blockeditor.cpp qMakefile
