# MAKEFILE: emplearemos esta utilidad para preparar ejecutables en los que 
# intervienen varias clases, de forma que con una unica instruccion 
# se compilan o linkan los ficheros estrictamente necesarios.
#
# Si en el directorio solo hay un proyecto y un makefile, para ejecutar este
# simplemente se escribe "make"
#
# Nuestros makefile se componen de una creación de variables seguida de
# una serie de instrucciones con la estructura:
#
#           fichero1":" lista de ficheros 
#           "tabulador" instrucción de compilación o linkado	
#
#           fichero2":" lista de ficheros 
#           "tabulador" instrucción de compilación o linkado	
#        
#           etc
#
# Esto significa: para obtener el fichero1 es necesario que existan todos
# los ficheros de su lista; si no existe o es más antiguo que alguno de
# ellos, se obtiene o actualiza con su instruccion; si no existe alguno de
# los ficheros de la lista, el proceso acaba con error; lo mismo para el
# fichero2, etc
# 
# Mediante este esquema, cada uno de nuestros makefile ha de contener todas
# las instrucciones que sean necesarias para obtener los .o y .exe del
# proyecto correspondiente.
#
# Ejemplos:
#
# La siguiente instruccion define una variable de entorno local, para compilar
# con las opciones habituales: 
#
Opts = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
# Si no teneis definidas las variables Inc y Objs, se pueden definir aqui:

#
# La siguiente instruccion significa:
# para obtener pro2_especif.exe es necesario que exista pro2_especif.o;
# si pro2_especif.exe no existe o es mas antiguo que pro2_especif.o,
# se obtiene con el g++ -o ... (el tabulador antes de g++ es necesario)
#
time_program.exe: time_program.o Evaluator.o Users_set.o User.o Sessions_set.o Session.o Problems_set.o Problem.o Courses_set.o Course.o
	g++ -o time_program.exe time_program.o Evaluator.o Users_set.o User.o Sessions_set.o Session.o Problems_set.o Problem.o Courses_set.o Course.o
#
# La siguiente instruccion significa:
# para obtener pro2_especif.o es necesario que exista pro2_especif.cc;
# si pro2_especif.o no existe o es mas antiguo que pro2_especif.cc,
# se obtiene con el g++ -c ... 
#

time_program.o: time_program.cc 	Evaluator.hh
	g++ -c time_program.cc $(Opts) -I.

Users_set.o: Users_set.cc 	Users_set.hh User.hh Courses_set.hh Sessions_set.hh
	g++ -c Users_set.cc $(Opts) -I.

User.o: User.cc User.hh
	g++ -c User.cc $(Opts) -I.

Sessions_set.o: Sessions_set.cc 	Sessions_set.hh Session.hh
	g++ -c Sessions_set.cc $(Opts) -I.

Session.o: Session.cc 	Session.hh BinTree.hh User.hh Course.hh 
	g++ -c Session.cc $(Opts) -I.

Problems_set.o: Problems_set.cc Problems_set.hh Problem.hh
	g++ -c Problems_set.cc $(Opts) -I.

Problem.o: Problem.cc 	Problem.hh
	g++ -c Problem.cc $(Opts) -I.

Courses_set.o: Courses_set.cc 	Courses_set.hh Sessions_set.hh Course.hh
	g++ -c Courses_set.cc $(Opts) -I.

Course.o: Course.cc Course.hh
	g++ -c Course.cc $(Opts) -I.

Evaluator.o: Evaluator.cc 	Evaluator.hh Sessions_set.hh Problems_set.hh \
									Courses_set.hh Users_set.hh Session.hh \
									Problem.hh Course.hh User.hh
	g++ -c Evaluator.cc $(Opts) -I.

#
# Realizad las modificaciones necesarias para gestionar las clases de la
# sesión cuando os toque implementarlas a vosotros.
#
# Esta última opción sirve para limpiar el directorio de ficheros 
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm -f *.o
	rm -f *.exe

tar:
	tar -cvf practica.tar *.cc *.hh Makefile html.zip jp_ankush.rana.zip
