import { onEvent, startServer } from "soquetic";
import fs from "fs";
import {SerialPort} from "serialport";

if (fs.existsSync("opcionesElegidas.json")) {
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify([]), "utf-8");
}

const port = new SerialPort({
    path: 'COM10',
    baudRate: 9600
});

port.on("open", ()=>{
    console.log("Puerto Abierto");

port.on('data', (data) => {
    console.log('Respuesta del Arduino:', data.toString());
})
})


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
        const datosSerial = `${Sabor} ${Tamaño}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        port.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
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

startServer();