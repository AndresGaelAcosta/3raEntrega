#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Videojuego {
    int numero_articulo;
    string nombre;
    string fecha_de_lanzamiento;
    string genero;
    string clasificacion;
    string consola;
    string caracteristicas;
    string descripcion;
    double precio_unitario;
    double impuesto;
    double total;
};

vector<Videojuego> videojuegos;

void agregar_articulo();
void modificar_articulo();
void eliminar_articulo();
void listar_articulos_vigentes();
void limpiar_pantalla();
void guardar_archivo();
void cargar_archivo();
void mostrar_menu();

int main() {
    cargar_archivo();
    int opcion;

    do {
        mostrar_menu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregar_articulo();
            break;
        case 2:
            modificar_articulo();
            break;
        case 3:
            eliminar_articulo();
            break;
        case 4:
            listar_articulos_vigentes();
            break;
        case 5:
            limpiar_pantalla();
            break;
        case 6:
            guardar_archivo();
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}

void agregar_articulo() {
    Videojuego juego;

    cout << "Ingrese el numero de articulo: ";
    cin >> juego.numero_articulo;
    cin.ignore();

    cout << "Ingrese el nombre del videojuego: ";
    getline(cin, juego.nombre);

    cout << "Ingrese la fecha de lanzamiento: ";
    getline(cin, juego.fecha_de_lanzamiento);

    cout << "Ingrese el genero del videojuego: ";
    getline(cin, juego.genero);

    cout << "Ingrese la clasificacion del videojuego: ";
    getline(cin, juego.clasificacion);

    cout << "Ingrese la consola del videojuego: ";
    getline(cin, juego.consola);

    cout << "Ingrese las caracteristicas del videojuego: ";
    getline(cin, juego.caracteristicas);

    cout << "Ingrese la descripcion del videojuego: ";
    getline(cin, juego.descripcion);

    cout << "Ingrese el precio unitario: ";
    cin >> juego.precio_unitario;

    juego.impuesto = juego.precio_unitario * 0.16;
    juego.total = juego.precio_unitario + juego.impuesto;

    videojuegos.push_back(juego);

    cout << "El articulo ha sido agregado correctamente." << endl;
}

void modificar_articulo() {
    int numero_articulo;
    bool encontrado = false;

    cout << "Ingrese el numero de articulo a modificar: ";
    cin >> numero_articulo;

    for (int i = 0; i < videojuegos.size(); i++) {
        if (videojuegos[i].numero_articulo == numero_articulo) {
            encontrado = true;

            cout << "Articulo encontrado. Ingrese los nuevos datos:" << endl;

            cout << "Ingrese el numero de articulo: ";
            cin >> videojuegos[i].numero_articulo;
            cin.ignore();

            cout << "Ingrese el nombre del videojuego: ";
            getline(cin, videojuegos[i].nombre);

            cout << "Ingrese la fecha de lanzamiento: ";
            getline(cin, videojuegos[i].fecha_de_lanzamiento);

            cout << "Ingrese el genero del videojuego: ";
            getline(cin, videojuegos[i].genero);

            cout << "Ingrese la clasificacion del videojuego: ";
            getline(cin, videojuegos[i].clasificacion);

            cout << "Ingrese la consola del videojuego: ";
            getline(cin, videojuegos[i].consola);

            cout << "Ingrese las caracteristicas del videojuego: ";
            getline(cin, videojuegos[i].caracteristicas);

            cout << "Ingrese la descripcion del videojuego: ";
            getline(cin, videojuegos[i].descripcion);

            cout << "Ingrese el precio unitario: ";
            cin >> videojuegos[i].precio_unitario;

    
            videojuegos[i].impuesto = videojuegos[i].precio_unitario * 0.16;
            videojuegos[i].total = videojuegos[i].precio_unitario + videojuegos[i].impuesto;

            cout << "El articulo ha sido modificado correctamente." << endl;

            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun articulo con el numero ingresado." << endl;
    }
}

void eliminar_articulo() {
    int numero_articulo;
    bool encontrado = false;

    cout << "Ingrese el numero de articulo a eliminar: ";
    cin >> numero_articulo;

    for (int i = 0; i < videojuegos.size(); i++) {
        if (videojuegos[i].numero_articulo == numero_articulo) {
            encontrado = true;
            videojuegos.erase(videojuegos.begin() + i);
            cout << "El articulo ha sido eliminado correctamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun articulo con el numero ingresado." << endl;
    }
}

void listar_articulos_vigentes() {
    if (videojuegos.empty()) {
        cout << "No hay articulos vigentes." << endl;
    }
    else {
        cout << "Listado de Articulos Vigentes:" << endl;
        for (const auto& juego : videojuegos) {
            cout << "Numero de articulo: " << juego.numero_articulo << endl;
            cout << "Nombre: " << juego.nombre << endl;
            cout << "Fecha de lanzamiento: " << juego.fecha_de_lanzamiento << endl;
            cout << "Genero: " << juego.genero << endl;
            cout << "Clasificacion: " << juego.clasificacion << endl;
            cout << "Consola: " << juego.consola << endl;
            cout << "Caracteristicas: " << juego.caracteristicas << endl;
            cout << "Descripcion: " << juego.descripcion << endl;
            cout << "Precio unitario: " << juego.precio_unitario << endl;
            cout << "Impuesto: " << juego.impuesto << endl;
            cout << "Total: " << juego.total << endl;
            cout << "-----------------------------------" << endl;
        }
    }
}

void limpiar_pantalla() {
    
    system("cls");
}

void guardar_archivo() {
    ofstream archivo("videojuegos.txt");

    if (archivo.is_open()) {
        for (const auto& juego : videojuegos) {
            archivo << juego.numero_articulo << ";";
            archivo << juego.nombre << ";";
            archivo << juego.fecha_de_lanzamiento << ";";
            archivo << juego.genero << ";";
            archivo << juego.clasificacion << ";";
            archivo << juego.consola << ";";
            archivo << juego.caracteristicas << ";";
            archivo << juego.descripcion << ";";
            archivo << juego.precio_unitario << ";";
            archivo << juego.impuesto << ";";
            archivo << juego.total << "\n";
        }

        archivo.close();
        cout << "Los datos han sido guardados correctamente en el archivo 'videojuegos.txt'." << endl;
    }
    else {
        cout << "No se pudo abrir el archivo 'videojuegos.txt'." << endl;
    }
}

void cargar_archivo() {
    ifstream archivo("videojuegos.txt");

    if (archivo.is_open()) {
        videojuegos.clear();

        string linea;
        while (getline(archivo, linea)) {
            Videojuego juego;
            size_t pos = 0;
            string token;
            int i = 0;

            while ((pos = linea.find(";")) != string::npos) {
                token = linea.substr(0, pos);
                linea.erase(0, pos + 1);

                switch (i) {
                case 0:
                    juego.numero_articulo = stoi(token);
                    break;
                case 1:
                    juego.nombre = token;
                    break;
                case 2:
                    juego.fecha_de_lanzamiento = token;
                    break;
                case 3:
                    juego.genero = token;
                    break;
                case 4:
                    juego.clasificacion = token;
                    break;
                case 5:
                    juego.consola = token;
                    break;
                case 6:
                    juego.caracteristicas = token;
                    break;
                case 7:
                    juego.descripcion = token;
                    break;
                case 8:
                    juego.precio_unitario = stod(token);
                    break;
                case 9:
                    juego.impuesto = stod(token);
                    break;
                case 10:
                    juego.total = stod(token);
                    break;
                }

                i++;
            }

            videojuegos.push_back(juego);
        }

        archivo.close();
        cout << "Los datos han sido cargados correctamente desde el archivo 'videojuegos.txt'." << endl;
    }
    else {
        cout << "No se pudo abrir el archivo 'videojuegos.txt'." << endl;
    }
}

void mostrar_menu() {
    cout << "Menu de opciones:" << endl;
    cout << "1. Agregar Articulo" << endl;
    cout << "2. Modificar Articulo" << endl;
    cout << "3. Eliminar Articulo" << endl;
    cout << "4. Lista de Articulos Vigentes" << endl;
    cout << "5. Limpiar pantalla" << endl;
    cout << "6. Salir" << endl;
    cout << "Ingrese la opcion deseada: ";
}
