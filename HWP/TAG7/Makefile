compile: tetrominos.c tetrominos.h
	gcc tetrominos.c -o tetrominos -Wall -Wmissing-prototypes -Werror -std=c99 -g

clean:
	rm -f tetrominos
	rm -rf ausgabe
	rm -rf diff
	rm -rf valgrind

testausgabe: compile eingabe/0.txt eingabe/5.txt eingabe/10.txt eingabe/20.txt eingabe/50.txt  eingabe/100.txt eingabe/150.txt eingabe/200.txt erwartete_ausgabe/0.txt erwartete_ausgabe/5.txt erwartete_ausgabe/10.txt erwartete_ausgabe/20.txt erwartete_ausgabe/50.txt erwartete_ausgabe/100.txt erwartete_ausgabe/150.txt erwartete_ausgabe/200.txt
	mkdir -p ausgabe
	./tetrominos eingabe/0.txt ausgabe/0.txt
	./tetrominos eingabe/5.txt ausgabe/5.txt
	./tetrominos eingabe/10.txt ausgabe/10.txt
	./tetrominos eingabe/20.txt ausgabe/20.txt
	./tetrominos eingabe/50.txt ausgabe/50.txt
	./tetrominos eingabe/100.txt ausgabe/100.txt
	./tetrominos eingabe/150.txt ausgabe/150.txt
	./tetrominos eingabe/200.txt ausgabe/200.txt

diff: clean compile testausgabe
	./diff.sh

valgrind_korrekte_eingabe: clean compile valgrind_korrekte_eingabe.sh
	./valgrind_korrekte_eingabe.sh

valgrind_fehlerhafte_eingabe: clean compile valgrind_fehlerhafte_eingabe.sh
	./valgrind_fehlerhafte_eingabe.sh

valgrind: 

run: diff valgrind
