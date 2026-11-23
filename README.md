# agenda-contactos
# Agenda de Contactos
Gestor de agenda de contactos en C++ para consola. Permite agregar, listar, buscar, modificar y eliminar contactos. Proyecto del curso Organización de archivos y estructuras de datos (UISIL).
## Funcionalidades
- Agregar contacto (nombre, teléfono, correo) con validaciones.
- Listar contactos ordenados por nombre (ordenamiento por inserción).
- Buscar por teléfono (búsqueda secuencial) y por nombre (búsqueda binaria).
- Eliminar y modificar contactos.
- Historial de operaciones (pila), de la más reciente a la más antigua.
- Cola de contactos pendientes que se transfieren a la agenda.
- Árbol binario de búsqueda por nombre con recorrido inorden.
## Estructuras de datos (implementadas desde cero)
| Estructura | Uso |

 Arreglo dinámico | Almacenamiento principa
Lista enlazada | Eliminación de contactos 
 Pila | Historial de operaciones 
Cola | Contactos pendientes 
Árbol binario de búsqueda - Recorrido ordenado 
No se usan `vector`, `list`, `stack` ni `queue`. Los datos viven solo en memoria.   --.Requisitos técnicos
- Lenguaje: C++ 
- Visual Studio 2022 
 Instalación y ejecución
1. Clonar el repositorio:
   `git clone https://github.com/andres2000-pixel/agenda-contactos.git`
2. Abrir `agenda-contactos.slnx` en Visual Studio y presionar Ctrl+F5.
3. O compilar con g++:
   `g++ agenda-contactos/agenda-contactos.cpp -o agenda`
## Licencia
MIT.
## Declaración de uso de inteligencia artificial
- **Herramienta:** Claude (Anthropic).
- **Para qué se usó:** orientación para organizar el proyecto  y apoyo para depurar errores de compilación.
- **Partes apoyadas: Guía y depuración: los pasos para Git, GitHub y Visual Studio, y el diagnóstico de los errores de compilación. ordenamiento por inserción  y menú
- **Modificaciones y validaciones realizadas por mí: El repositorio y los commits, la integración y las pruebas de cada estructura,  y la opción de modificar contacto, estructura inicial de las clases (arreglo dinámico, lista enlazada, pila, cola y árbol), ordenamiento por inserción, búsquedas y menú.