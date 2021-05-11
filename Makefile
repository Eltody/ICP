# Projekt: VUT FIT ICP
# File: Makefile
# Popis: Editor blokov
# Autori: Zaùko Tom·ö
#         Rak˙s Martin


compile: update
	make -f qMakefile

run: compile
	./EliteEditor


update: ICP_Project.pro
	qmake -o qMakefile ICP_Project.pro

pack:
	zip -r xzatko02-xrakus04.zip src res examples ICP_Project.pro Makefile README.txt README.md doc/Doxyfile
	
clean:
	rm -f EliteEditor *.o ui_EliteEditor.h qMakefile
	
doxygen:
	doxygen doc/Doxyfile


