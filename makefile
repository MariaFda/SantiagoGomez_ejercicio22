PDE.pdf: datos.txt grafica.py
	python grafica.py
datos.txt: difusion.cpp
	c++ difusion.cpp
	./a.out > datos.txt
	rm a.out
