all: euler_01.dat euler_001.dat euler_0001.dat rompeku_01.dat rompeku_001.dat rompeku_001.dat solucion_01.png solucion_001.png solucion_0001.png

%.png: %.dat graf.py
	python3 graf.py

%.dat: sol.x
	./sol.x

sol.x: solucion_t.cpp
	g++ solucion_t.cpp -o sol.x

clean:
	rm -rf *.x *.dat *.png
