/** @mainpage
    <div style="display: flex; align-items: center; color:#000000; width:98%; margin:0 auto; background:#e0e0e0; text-align: center; padding: 1em; border-radius: 15px;">
        <img style="border-radius: 15px;" src="logo.png" alt="" width="100"> 
        <div style="margin: 1em; font-size:1.3em;" > The project is about an evaluator that has courses made up of a session and problems and users.
            Users can enroll to the courses and do the problems belongs to the course and send to evaluator ot test thier ability.
            This program is formed by classes: Evaluator, Users_set, User, Courses_set, Course, Sessions_set, Session, Problems_set and Problem. 
        </div>
    </div>
*/


/** @file   program.cc
    @brief  The main file of program, that has main funcion.
    @author Ankush Rana
*/

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <chrono>
#endif // NO_DIAGRAM

#include "Evaluator.hh"

using namespace std;

/** @brief  Function to control options.
 *  \include program.cc
 *  @author Ankush Rana
 *  
*/



struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
    string function;

    Timer(const string& function) : function(function) {
      start_point = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
      auto end_point = std::chrono::high_resolution_clock::now();

      auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count();
      auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();

      auto duration = end - start;
      //double ms = duration * 0.001;
	  double s = duration * 0.000001;

		cerr << s <<endl;
    }
};




void program(){
    Evaluator evl;
    evl.read_problems();
    evl.read_sessions();
    evl.read_courses();
    evl.read_users();
    string command;
    cin >> command;
    while (command != "fin"){
        string str;
        cout << '#' << command;
        if (command == "nuevo_problema" or command == "np"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.new_problem(str);
        }
        else if (command == "nueva_sesion" or command == "ns"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.new_session(str);
        }
        else if (command == "nuevo_curso" or command == "nc"){
            cout << endl;
            evl.new_course();
        }
        else if (command == "alta_usuario" or command == "a"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.register_user(str);
        }
        else if (command == "baja_usuario" or command == "b"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.remove_user(str);
        }
        else if (command == "inscribir_curso" or command == "i"){
            int c;
            cin >> str >> c;
            cout << ' ' << str << ' ' << c << endl;
            evl.subscribe_curse(str, c);
        }
        else if (command == "curso_usuario" or command == "cu"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.user_course(str);
        }
        else if (command == "sesion_problema" or command == "sp"){
            int c;
            cin >> c >> str;
            cout << ' ' << c << ' ' << str << endl;
            evl.session_problem(c, str);
        }
        else if (command == "problemas_resueltos" or command == "pr"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.solved_problems(str);
        }
        else if (command == "problemas_enviables" or command == "pe"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.problems_sendable(str);
        }
        else if (command == "envio" or command == "e"){
            string p;
            bool r;
            cin >> str >> p >> r;
            cout << ' ' << str << ' ' << p << ' ' << r << endl;
            evl.send(str, p, r);
        }
        else if (command == "listar_problemas" or command == "lp"){
            cout << endl;
            evl.list_problems();
        }
        else if (command == "escribir_problema" or command == "ep"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.write_problems(str);
        }
        else if (command == "listar_sesiones" or command == "ls"){
            cout << endl;
            evl.list_sessions();
        }
        else if (command == "escribir_sesion" or command == "es"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.write_session(str);
        }
        else if (command == "listar_cursos" or command == "lc"){
            cout << endl;
            evl.list_courses();
        }
        else if (command == "escribir_curso" or command == "ec"){
            int c;
            cin >> c;
            cout << ' ' << c << endl;
            evl.write_course(c);
        }
        else if (command == "listar_usuarios" or command == "lu"){
            cout << endl;
            evl.list_users();
        }
        else if (command == "escribir_usuario" or command == "eu"){
            cin >> str;
            cout << ' ' << str << endl;
            evl.write_users(str);
        }

        cin >> command;
    }
}

/** @brief  Main function of program.
 *  \include program.cc
 * 
*/
int main(){
	
    
	
	{
		Timer timer("program");
		program();
	}
}
