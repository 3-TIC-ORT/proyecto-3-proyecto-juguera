import { onEvent, startServer } from "soquetic";
import fs from "fs";
import {SerialPort} from "serialport";

if (fs.existsSync("opcionesElegidas.json")) {
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify([]), "utf-8");
}

let Sabor = "";
let Tamaño = "";
let Estrellas = "";
let Confirmado = false;

function guardarDatos(datos) {
    let listaVacia = JSON.parse(fs.readFileSync("opcionesElegidas.json", "utf-8"));
    listaVacia.push(datos);
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify(listaVacia, null, 2), "utf-8");
}

onEvent("opcionesSabor", (opcionesSabor) => {
    Sabor = opcionesSabor;
    console.log("Sabor recibido:", Sabor);
});

onEvent("opcionesTamaño", (opcionesTamaño) => {
    Tamaño = opcionesTamaño;
    console.log("Tamaño recibido:", Tamaño);
    if (Sabor && Tamaño) {
        const lista = { "opcionSabor": Sabor, "opcionTamaño": Tamaño };
        guardarDatos(lista);
    } else {
        console.error("No funco");
    }
});

onEvent("Confirmar", (Confirmar) => {
    if (!Confirmado) {
        console.log(Tamaño, "confirmado?", Confirmar);
        const lista = { "Confirmacion": Tamaño + "? " + Confirmar };
        guardarDatos(lista);
        Confirmado = true;
    } else {
        console.log("Ya fue confirmado");
    }
});

onEvent("mandarOpinion", (mandarOpinion) => {
    if (mandarOpinion){
        Estrellas = mandarOpinion;
        console.log("Opinión recibida:", Estrellas);
        const lista = { "Estrellas": Estrellas };
        guardarDatos(lista); 
    }
    else{
        console.log("No funco las estrellas")
    }
});


/*const port = new SerialPort({
    path: '',
    baudRate: ,
})

port.on("open", ()=>{
    console.log("Puerto Abierto");
})

port.on("data",(data)=>{
    console.log("Pitufina")
})*/

startServer();