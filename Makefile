compile: update
	make -f qMakefile

run: compile
	./blockeditor


update: ICP_Project.pro
	qmake -o qMakefile ICP_Project.pro

clean:
	rm -f blockeditor *.o ui_blockeditor.h moc_blockeditor.cpp qMakefile
