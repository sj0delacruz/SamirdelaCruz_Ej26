all: euler_0o5_ec1.dat rompeku_0o5_ec1.dat rana_0o5_ec1.dat graf_sol_0o5_ec1.png

%.png: %.dat grafica_ec1.py
	python3 grafica_ec1.py

%.dat: sol_ec1.x
	./sol_ec1.x

sol_ec1.x: solucion_ec1.cpp
	g++ solucion_ec1.cpp -o sol_ec1.x

clean:
	rm -rf *.x *.dat *.png
