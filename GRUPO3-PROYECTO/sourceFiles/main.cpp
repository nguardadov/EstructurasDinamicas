#include "F:/Desarrollo/Cpp/Juego/headerFiles/Ventana.h"
#include "F:/Desarrollo/Cpp/Juego/headerFiles/Ranking.h"

//Metodo que inicializa SDL
void iniciarSDL(){
    //Inicializando el subistema de video de SDL
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        cout<<SDL_GetError()<<endl;
    }
    //Inicializando SDL_Image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
        cout<<SDL_GetError()<<endl;

    }
    //Inicalizando subsistemas de ttf
    if(TTF_Init()!=0){
        cout<<SDL_GetError()<<endl;

    }
}

void iniciarSDL();
void cambiarTexto(bool,Ventana,int,int,int,int,SDL_Texture*,string,int,int,int);
void cambiarTextoJugar(bool);
void dibujarXO(int);
void setJugada(int,int,int,int);
void actualizarTablero(bool,int,int);
string verificarTablero();
void mostrarGanador(int,int,int,int,string);
bool modificarMotor(int,int);
void cambiarTextoTurno();
void reiniciarTodo();

Ventana ventanas[5];


string 
BG_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/background.png",
X_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/redX.png",
O_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/blueO.png",
V_LINE_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/line-col.png",
H_LINE_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/line.png",
D1_LINE_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/line-dg2.png",
D2_LINE_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/line-dg.png",
FIELD_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/tablero.png",
FONT_ROUTE = "F:/Desarrollo/Cpp/Juego/assets/sample.ttf";

SDL_Texture *tablero = NULL;
SDL_Texture *redX = NULL;
SDL_Texture *blueO = NULL;
SDL_Texture *line = NULL;
SDL_Texture *lineCol = NULL;
SDL_Texture *lineDg1 = NULL;
SDL_Texture *lineDg2 = NULL;
SDL_Texture *usuarioActual = NULL;
string motorTablero[3][3];


//Recursos
SDL_Texture *titulo = NULL;
SDL_Texture *jugar = NULL;
SDL_Texture *textoAceptar = NULL;
SDL_Texture *miFuente = NULL;
SDL_Texture *textoTurno = NULL;
SDL_Texture *textoReinicio = NULL;
SDL_Texture *textoVolver = NULL;
SDL_Texture *textoIngrese = NULL;
SDL_Texture *textoSalir = NULL;
SDL_Texture *textoAyuda = NULL;
SDL_Texture *textoCreditos = NULL;
SDL_Texture *textoSalirCredits = NULL;
SDL_Texture *textoAbrirRanking = NULL;


SDL_Color colorNormal = {255,255,255,255};
SDL_Color colorHoover = {255,64,0,255};
SDL_Color zeroTurn = {46,138,228,1};

SDL_Rect rg, rt;

bool hoovered = false, huboResultado = false;

int contador = 0,contador2 = 0, tamaLetra = 95;
string usr1[6],usuario1,usr2[6],usuario2;

bool turno = true;
bool isValid = true;

Ranking miRanking;

void crearSubVentana(int ind){
    if(ind>0 && ind!=4){
        SDL_DestroyRenderer(ventanas[ind-1].ren);
        SDL_DestroyWindow(ventanas[ind-1].ventana);
    }
    switch(ind){
        case 0:
            ventanas[0].crearVentana();
            contador = contador2 = 0;
            tamaLetra = 95;

            ventanas[0].crearContorno(80,50,740,64);
            ventanas[0].crearContorno(372,320,136,50);
            ventanas[0].crearContorno(372,320+70,136,50);
            ventanas[0].crearContorno(372,(320+70)+70,136,50);
            ventanas[0].crearContorno(372,((320+70)+70)+70,136,50);

            SDL_RenderPresent(ventanas[0].ren);

            titulo = ventanas[0].crearTexto("Bienvenido a Great XO's",75,colorNormal);
            jugar = ventanas[0].crearTexto("Jugar!",55,colorNormal);
            textoSalir = ventanas[0].crearTexto("Salir",55,colorNormal);
            textoAyuda = ventanas[0].crearTexto("Ayuda",55,colorNormal);
            textoCreditos = ventanas[0].crearTexto("Creditos",40,colorNormal);
            
            
            ventanas[0].dibujar(titulo,80,55);
            ventanas[0].dibujar(jugar,377,321);
            ventanas[0].dibujar(textoSalir,377+12,321+75);
            ventanas[0].dibujar(textoAyuda,377,(321+75)+64);
            ventanas[0].dibujar(textoCreditos,377,((321+75)+64)+80);
            SDL_RenderPresent(ventanas[0].ren);
        break;
        case 1:
        case 2:
            ventanas[ind].crearVentana(300,300);
            ventanas[ind].crearContorno(25,67,250,20);

            //SDL_DestroyTexture(textoIngrese);
            textoIngrese = ventanas[ind].crearTexto("Ingrese el nombre del usuario",20,colorNormal);
            ventanas[ind].dibujar(textoIngrese,25+4,67+2);
            SDL_DestroyTexture(textoIngrese);
            
            ventanas[ind].crearContorno(57,125,200,35,255,255,255);
            ventanas[ind].crearContorno(91,200,120,35);

            //SDL_DestroyTexture(textoAceptar);
            textoAceptar = ventanas[ind].crearTexto("Aceptar",34,colorNormal);
            ventanas[ind].dibujar(textoAceptar,100,204);
            SDL_DestroyTexture(textoAceptar);
        break;
        case 3:

            ventanas[ind].crearVentana();
            tablero = ventanas[ind].crearDibujo(FIELD_ROUTE);
            redX = ventanas[ind].crearDibujo(X_ROUTE);
            blueO = ventanas[ind].crearDibujo(O_ROUTE);
            line = ventanas[ind].crearDibujo(H_LINE_ROUTE);
            lineCol = ventanas[ind].crearDibujo(V_LINE_ROUTE);
            lineDg1 = ventanas[ind].crearDibujo(D1_LINE_ROUTE);
            lineDg2 = ventanas[ind].crearDibujo(D2_LINE_ROUTE);

            miFuente = ventanas[ind].crearTexto("Turno:",32,colorNormal);
            textoReinicio = ventanas[ind].crearTexto("Reiniciar Partida",28,colorNormal);
            textoVolver = ventanas[ind].crearTexto("Volver al menu",28,colorNormal);
            textoAbrirRanking = ventanas[ind].crearTexto("Ranking",28,colorNormal);
            
                        
            cambiarTextoTurno();
            
            reiniciarTodo();

        break;
        case 4:
            ventanas[ind].crearVentana(930,630,"F:/Desarrollo/Cpp/Juego/assets/creditos.png");
        break;
    }
    SDL_RenderPresent(ventanas[ind].ren);

    
}

void crearSubVentana();

int main(int argc, char *argv[]){
    //Inicializando la matriz
    for(int c = 0; c<3; c++){
        for(int i = 0; i<3; i++){
            motorTablero[c][i] = "nan";
        }
    }
    iniciarSDL();
    crearSubVentana(0);
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    SDL_StartTextInput();

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ))
        {
            //User requests quit
            /*if( e.type == SDL_QUIT )
            {
                quit = true;
            }*/
            //Handle window events
            for( int i = 0; i < 4; ++i )
            {   
                ventanas[ i ].controlarEventos( e );
            }
            switch(e.type){
                case SDL_MOUSEBUTTONDOWN:
                    switch(e.button.button){
                        case SDL_BUTTON_LEFT:
                            if(ventanas[0].focused){
                                if(e.motion.x>=372 && e.motion.x<=488 && e.motion.y>=322 && e.motion.y<=370){
                                    crearSubVentana(1);
                                }
                                if(e.motion.x>=372 && e.motion.x<=372+136 && e.motion.y>=320+70 && e.motion.y<=(320+70)+50){
                                    SDL_DestroyRenderer(ventanas[0].ren);
                                    SDL_DestroyWindow(ventanas[0].ventana); 
                                    quit = true;   
                                }
                                if(e.motion.x>=372 && e.motion.x<=372+136 && e.motion.y>=(320+70)+70 && e.motion.y<=((320+70)+70)+50){
                                    system("start chrome.exe \"F:/Desarrollo/Cpp/Juego/assets/instrucciones juego.pdf\"" );
                                }
                                if(e.motion.x>=372 && e.motion.x<=372+136 && e.motion.y>=((320+70)+70)+70 && e.motion.y<=(((320+70)+70)+50)+50){
                                    crearSubVentana(4);
                                }

                            }
                            if(ventanas[1].focused){
                                tamaLetra = 95;

                                if(e.motion.x>=91 && e.motion.x<=211 && e.motion.y>=210 && e.motion.y<=255){
                                    for(int c= 0; c<6; c++){
                                        usuario1+=usr1[c];
                                        usr1[c].clear();
                                    }
                                    crearSubVentana(2);                                    
                                }      
                            }
                            if(ventanas[2].focused){
                                if(e.motion.x>=91 && e.motion.x<=211 && e.motion.y>=210 && e.motion.y<=255){
                                    for(int c= 0; c<6; c++){
                                        usuario2+=usr2[c];
                                        usr2[c].clear();
                                    }
                                    crearSubVentana(3);

                                }
                            }
                            if(ventanas[3].focused){
                                int mouseX = e.motion.x;
                                int mouseY = e.motion.y;
                                //Validando primer cuadrante
                                if (mouseX>=20 && mouseX<=210.48 && mouseY>=23 && mouseY<=213.8){
                                    dibujarXO(1);
                                    break;
                                }

                                //Validando segundo cuadrante
                                if (mouseX>=244.8 && mouseX<=397.9 && mouseY>=23 && mouseY<=213.8){
                                    dibujarXO(2);
                                    break;
                                }

                                //Validando tercer cuadrante
                                if (mouseX>=432 && mouseX<=614.5 && mouseY>=23 && mouseY<=213.8){
                                    dibujarXO(3);
                                    break;
                                }

                                //Validando cuarto cuadrante
                                if (mouseX>=23 && mouseX<=210 && mouseY>=247 && mouseY<=402){
                                    dibujarXO(4);
                                    break;
                                }
                                //Validando quinto cuadrante
                                if (mouseX>=245 && mouseX<=397 && mouseY>=247 && mouseY<=402){
                                    dibujarXO(5);
                                    break;
                                }
                                //Validando sexto cuadrante
                                if (mouseX>=432 && mouseX<=619 && mouseY>=247 && mouseY<=402){
                                    dibujarXO(6);
                                    break;
                                }
                                //Validando septimo cuadrante
                                if (mouseX>=20 && mouseX<=210.48 && mouseY>=437 && mouseY<=616){
                                    dibujarXO(7);
                                    break;
                                }
                                //Validando octavo cuadrante
                                if (mouseX>=244.8 && mouseX<=397.9 && mouseY>=437 && mouseY<=616){
                                    dibujarXO(8);
                                    break;
                                }
                                //Validando noveno cuadrante
                                if (mouseX>=432 && mouseX<=619 && mouseY>=437 && mouseY<=616){
                                    dibujarXO(9);
                                    break;
                                }
                                if(e.motion.x>=670 && e.motion.x <= 670+200 && e.motion.y >= (50*5.5) && e.motion.y <= (50*5.5) + 54 ){
                                    if(!huboResultado){
                                        ventanas[3].mostrarMensaje("Se reiniciara la partida, nadie obtendra puntaje");
                                        miRanking.escribiendoArchivo(usuario1,0,usuario2,0);
                                        miRanking.lecturaDeArchivo();
                                        reiniciarTodo();
                                        break;
                                    }
                                    else{
                                        ventanas[3].mostrarMensaje("Se reiniciara la partida, hubo un victoria");
                                        reiniciarTodo();
                                    }    
                                } 
                                if(e.motion.x>=670 && e.motion.x <= 670+200 && e.motion.y >= 375 && e.motion.y <= ((50*5.5)+100) + 54 ){
                                    usuario1 = usuario2 = "";
                                    SDL_RenderClear(ventanas[3].ren);
                                    SDL_DestroyWindow(ventanas[3].ventana);
                                    crearSubVentana(0);
                                }
                                if(e.motion.x>=670 && e.motion.x <= 670+200 && e.motion.y >= ((50*5.5)+100)+100 && e.motion.y <= (((50*5.5)+100)+100)+54){
                                    system("start notepad  \"F:/Desarrollo/Cpp/Juego/assets/Jugadores.txt\"" );
                                    system("start notepad  \"F:/Desarrollo/Cpp/Juego/assets/Ranking.txt\"" );
                                    
                                }
                            }
                        break;
                    }
                break;

                case SDL_MOUSEMOTION:
                    if(ventanas[0].focused){
                        if(e.motion.x>=372 && e.motion.x<=488 && e.motion.y>=322 && e.motion.y<=370){
                            if(!hoovered){
                                hoovered = true;
                                cambiarTexto(true,ventanas[0],372,321,136,50,jugar,"Jugar!",55,377,322);

                            }
                        }
                        else {
                            hoovered = false;
                            cambiarTexto(false,ventanas[0],372,321,136,50,jugar,"Jugar!",55,377,322);
                        }

                        if(e.motion.x>=372 && e.motion.x<=372+136 && e.motion.y>=320+70 && e.motion.y<=(320+70)+50){
                            if(!hoovered){
                                hoovered = true;
                                cambiarTexto(true,ventanas[0],372,320+70,136,50,textoSalir,"Salir",55,377+12,321+75);

                            }
                        }
                        else {
                            hoovered = false;
                            cambiarTexto(false,ventanas[0],372,320+70,136,50,textoSalir,"Salir",55,377+12,321+75);
                        }

                        if(e.motion.x>=372 && e.motion.x<=372+136 && e.motion.y>=(320+70)+70 && e.motion.y<=((320+70)+70)+50){
                            if(!hoovered){
                                hoovered = true;
                                cambiarTexto(true,ventanas[0],372,(320+70)+70,136,50,textoAyuda,"Ayuda",55,377,(321+75)+64);
                            }
                        }
                        else {
                            hoovered = false;
                            cambiarTexto(false,ventanas[0],372,(320+70)+70,136,50,textoAyuda,"Ayuda",55,377,(321+75)+64);
                        }

                        if(e.motion.x>=372 && e.motion.x<=372+136 && e.motion.y>=((320+70)+70)+70 && e.motion.y<=(((320+70)+70)+50)+50){
                            if(!hoovered){
                                hoovered = true;
                                cambiarTexto(true,ventanas[0],372,((320+70)+70)+70,136,50,textoCreditos,"Creditos",40,377,((321+75)+64)+80);
                            }
                        }
                        else {
                            hoovered = false;
                            cambiarTexto(false,ventanas[0],372,((320+70)+70)+70,136,50,textoCreditos,"Creditos",40,377,((321+75)+64)+80);
                        }

                    }            
                    if(ventanas[1].focused){
                       
                        if(e.motion.x>=91 && e.motion.x<=211 && e.motion.y>=210 && e.motion.y<=255){
                            if(!hoovered){
                                hoovered = true;
                                cambiarTexto(true,ventanas[1],91,200,120,35,textoAceptar,"Aceptar",34,100,204);
                            }
                        }
                        else {
                            hoovered = false;
                            cambiarTexto(false,ventanas[1],91,200,120,35,textoAceptar,"Aceptar",34,100,204);
                        }
                              
                            
                    }
                    if(ventanas[2].focused){
                       
                        if(e.motion.x>=91 && e.motion.x<=211 && e.motion.y>=210 && e.motion.y<=255){
                            if(!hoovered){
                                hoovered = true;
                                cambiarTexto(true,ventanas[2],91,200,120,35,textoAceptar,"Aceptar",34,100,204);
                            }
                        }
                        else {
                            hoovered = false;
                            cambiarTexto(false,ventanas[2],91,200,120,35,textoAceptar,"Aceptar",34,100,204);
                        }
                              
                            
                    }
                    if(ventanas[3].focused){
                        
                        if(e.motion.x>=670 && e.motion.x <= 670+200 && e.motion.y >= (50*5.5) && e.motion.y <= (50*5.5) + 54 ){
                            if(!hoovered){
                                hoovered = true;
                                cambiarTexto(true,ventanas[3],670,50*5.5,200,54,textoReinicio,"Reiniciar Partida",28,670+8,(50*5.5)+15 );
                            }
                        }
                        else {
                            hoovered = false;
                            cambiarTexto(false,ventanas[3],670,50*5.5,200,54,textoReinicio,"Reiniciar Partida",28,670+8,(50*5.5)+15 );
                        }

                        if(e.motion.x>=670 && e.motion.x <= 670+200 && e.motion.y >= 375 && e.motion.y <= ((50*5.5)+100) + 54 ){
                            if(!hoovered){
                                hoovered = true;
                                cambiarTexto(true,ventanas[3],670,375,200,54,textoVolver,"Volver al menu",28,670+12,((50*5.5)+100)+15 );
                            }
                        }
                        else {
                            hoovered = false;
                            cambiarTexto(false,ventanas[3],670,375,200,54,textoVolver,"Volver al menu",28,670+12,((50*5.5)+100)+15 );
                        }
                    }
                    
                break;
                case SDL_TEXTINPUT:
                    if (ventanas[1].focused){
                        if(contador<6){
                            usr1[contador] = e.text.text;
                            SDL_Texture *textoUsr = ventanas[1].crearTexto(usr1[contador],35,{0,0,0,1});
                            ventanas[1].dibujar(textoUsr,tamaLetra,130);
                            tamaLetra+=19;
                            contador++;
                            SDL_RenderPresent(ventanas[1].ren);
                            SDL_DestroyTexture(textoUsr);
                        }
                    }
                    if (ventanas[2].focused){
                        if(contador2<6){                          
                            usr2[contador2] = e.text.text;
                            SDL_Texture *textoUsr2 = ventanas[2].crearTexto(usr2[contador2],35,{0,0,0,1});
                            ventanas[2].dibujar(textoUsr2,tamaLetra,130);
                            tamaLetra+=19;
                            contador2++;
                            SDL_RenderPresent(ventanas[2].ren);
                            SDL_DestroyTexture(textoUsr2);
                        }
                    }
                break;
            }
        }
        
    }
    for(int i = 0; i<4 ;i++){
        SDL_DestroyWindow(ventanas[i].ventana);
    }
}

void dibujarXO(int cuadra){

    if(isValid){
        switch(cuadra){               
            case 1: setJugada(0,0,40,43); break;
            case 2: setJugada(0,1,248,43); break;
            case 3: setJugada(0,2,452,43); break;
            case 4: setJugada(1,0,47,252); break;
            case 5: setJugada(1,1,248,250); break;
            case 6: setJugada(1,2,450,249); break;
            case 7: setJugada(2,0,40,457); break;
            case 8: setJugada(2,1,250,457); break;
            case 9: setJugada(2,2,452,457); break;
        }
    }
}

void cambiarTextoTurno(){
    ventanas[3].crearContorno(780,65,96,30);
    if(turno) textoTurno  = ventanas[3].crearTexto(usuario1,32,colorHoover);
    else textoTurno  = ventanas[3].crearTexto(usuario2,32,zeroTurn);
    ventanas[3].dibujar(textoTurno,780,65);
    SDL_RenderPresent(ventanas[3].ren);
    SDL_DestroyTexture(textoTurno);
}


void actualizarTablero(bool fig,int x, int y){
    if(fig) ventanas[3].dibujar(redX,x,y); 
    else ventanas[3].dibujar(blueO,x,y);
    SDL_RenderPresent(ventanas[3].ren);
}

void mostrarGanador(int nFil,int nCol,int x, int y, string tipo){    
    if(tipo == "f") ventanas[3].dibujar(line,x,y);
    else if(tipo == "c") ventanas[3].dibujar(lineCol,x,y);
    else if(tipo == "d1") ventanas[3].dibujar(lineDg1,x,y);
    else if(tipo == "d2") ventanas[3].dibujar(lineDg2,x,y);
    SDL_RenderPresent(ventanas[3].ren);
    if(turno){
        huboResultado = true; 
        ventanas[3].mostrarMensaje("El ganador es "+usuario2);
        miRanking.escribiendoArchivo(usuario2,1,usuario1,-1);
    }
    else{
        huboResultado = true;
        ventanas[3].mostrarMensaje("El ganador es "+usuario1);
        miRanking.escribiendoArchivo(usuario1,1,usuario2,-1);
    }
}

void setJugada(int nFil,int nCol,int x, int y){
    //Verificando disponibilidad del cuadrante
    if(motorTablero[nFil][nCol]!="X" && motorTablero[nFil][nCol]!="O"){
        actualizarTablero(modificarMotor(nFil,nCol),x,y);
        string hayGanador = verificarTablero();
        if(hayGanador!="nan"){
            isValid = false;
            if(hayGanador == "emp"){ 
                huboResultado = true;
                ventanas[3].mostrarMensaje("Empate, inicie una nueva partida o regrese al menu");
                miRanking.escribiendoArchivo(usuario1,0,usuario2,0);
                miRanking.lecturaDeArchivo();
                return;
            }
            if(hayGanador == "f1") mostrarGanador(nFil,nCol,20,115,"f");
            if(hayGanador == "f2") mostrarGanador(nFil,nCol,20,318,"f");
            if(hayGanador == "f3") mostrarGanador(nFil,nCol,20,525,"f");

            if(hayGanador == "c1") mostrarGanador(nFil,nCol,104,40,"c");
            if(hayGanador == "c2") mostrarGanador(nFil,nCol,310,35,"c");
            if(hayGanador == "c3") mostrarGanador(nFil,nCol,515,35,"c");

            if(hayGanador == "d1") mostrarGanador(nFil,nCol,30,35,"d1");
            if(hayGanador == "d2") mostrarGanador(nFil,nCol,30,40,"d2");
        
        }
        else  cambiarTextoTurno();
        //cout<<SDL_GetError()<<endl;

    
    }
    else ventanas[3].mostrarMensaje("Ya existe un elemento en este espacio");
}
string verificarTablero(){
    string salida = "nan";
    //Verificando filas
    for(int c = 0; c<3; c++){
        for(int i = 0; i<3; i++){
            if(
                motorTablero[c][i] == motorTablero[c][i+1] &&
                motorTablero[c][i+1] == motorTablero[c][i+2] &&
                motorTablero[c][i]!="nan"
            ){
                switch(c){
                    case 0:
                        salida = "f1";
                        return salida;
                    break;
                    case 1:
                        salida = "f2";
                        return salida;
                    break;
                    case 2:
                        salida = "f3";
                        return salida;
                    break;
                }
            }
            else break;
        }
    }
    //Verificando columnas
    for(int c = 0; c<3; c++){
        for(int i = 0; i<3; i++){
            if(
                motorTablero[c][i] == motorTablero[c+1][i] &&
                motorTablero[c+1][i] == motorTablero[c+2][i] &&
                motorTablero[c][i]!="nan"
            ){
                switch(i){
                    case 0:
                        salida = "c1";
                        return salida;
                    break;
                    case 1:
                        salida = "c2";
                        return salida;
                    break;
                    case 2:
                        salida = "c3";
                        return salida;
                    break;
                }
            }
        }
    }
    //Verificando diagonales
    
    //Diagonal izquierda
    if(motorTablero[0][0] == motorTablero[1][1] && 
    motorTablero[0][0] == motorTablero[2][2] &&
    motorTablero[0][0]!="nan"){
        salida = "d1";
        return salida;
    }
    //Diagonal derecha
    if(motorTablero[0][2] == motorTablero[1][1] && 
    motorTablero[0][2] == motorTablero[2][0] &&
    motorTablero[0][2]!="nan"){
        salida = "d2";
        return salida;
    }
    //Verificando cada espacio para validar empate
    int contador = 0;
    for(int c = 0; c<3; c++){
        for(int i = 0; i<3; i++){
            if(motorTablero[c][i] != "nan"){
                contador++;
            }
        }
    }
    if (contador == 9){
        salida = "emp";
        return salida; 
    }

    return salida;

}
void reiniciarTodo(){
    turno = true;
    isValid = true;
    huboResultado = false;
    ventanas[3].dibujar(ventanas[3].bg,0,0);
    ventanas[3].dibujar(tablero,20,20);
    //Contorno del turno
    ventanas[3].crearContorno(670,50,225,54);
    //Contorno del boton reiniciar
    ventanas[3].crearContorno(670,50*5.5,200,54);
    //Contorno del boton volver
    ventanas[3].crearContorno(670,(50*5.5)+100,200,54);
    //Contorno del boton ranking
    ventanas[3].crearContorno(670,((50*5.5)+100)+100,200,54);

    
    ventanas[3].dibujar(miFuente,680,65);
    cambiarTextoTurno();
    ventanas[3].dibujar(textoReinicio,670+8,(50*5.5)+15 );
    ventanas[3].dibujar(textoVolver,670+12,((50*5.5)+100)+15);
    ventanas[3].dibujar(textoAbrirRanking,670+60,(((50*5.5)+100)+15)+100);
    
    
    for(int c = 0; c<3; c++){
        for(int i = 0; i<3; i++){
            motorTablero[c][i] = "nan";
        }
    }
    SDL_RenderPresent(ventanas[3].ren);           
}
bool modificarMotor(int fil, int col){
    //si turno vale true, se dibujara una X, si vale false, se dibujara un 0
    if(turno){
        motorTablero[fil][col] = "X";
        turno = false;
        return true;

    }
    else{
        motorTablero[fil][col] = "O";
        turno = true;
        return false;
    }
}

void cambiarTexto(
bool cual,
Ventana v,
int contornoX,
int contornoY,
int contornoW,
int contornoH,
SDL_Texture *text,
string texto,
int tamaTexto,
int posX,
int posY){
    v.crearContorno(contornoX,contornoY,contornoW,contornoH);
    if(cual) text = v.crearTexto(texto,tamaTexto,colorHoover);
    else text = v.crearTexto(texto,tamaTexto,colorNormal);
    v.dibujar(text,posX,posY);
    SDL_DestroyTexture(text);
    SDL_RenderPresent(v.ren);
}
//Arboles binarios de busqueda