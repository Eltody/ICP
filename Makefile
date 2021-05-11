compile: update
	make -f qMakefile

run: compile
	./EliteEditor


update: ICP_Project.pro
	qmake -o qMakefile ICP_Project.pro

clean:
	rm -f EliteEditor *.o ui_EliteEditor.h qMakefile
