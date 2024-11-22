import { onEvent, startServer } from "soquetic";
import fs from "fs";
import {SerialPort, ReadlineParser} from "serialport";
import path from "path";

if (fs.existsSync("opcionesElegidas.json")) {
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify([]), "utf-8");
}

const port = new SerialPort({
    path: "COM6",
    baudRate: 9600
});

const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

port.on("open", ()=>{
    console.log("Puerto Abierto");
})

let Sabor = "";
let Tamaño = "";
let Estrellas = "";
let Confirmado = false;
const datosSerial = "";

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
    if (Sabor && Tamaño){
        const lista = { "opcionSabor": Sabor, "opcionTamaño": Tamaño };
        guardarDatos(lista);
        datosSerial = `${Sabor} ${Tamaño}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            Sabor = "";
            Tamaño = "";
            datosSerial = "";
        });
    } else {
        console.error("No funco");
    }
});

onEvent("Confirmar", (Confirmar) => {
    if (!Confirmado){
        console.log(Tamaño, "confirmado?", Confirmar);
        const lista = { "Confirmacion": Tamaño + "? " + Confirmar };
        guardarDatos(lista);
        Confirmado = true;
        datosSerial = `confirmado\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            Confirmado = false;
            datosSerial = "";
        });
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

onEvent("EmpezarLimpieza", (limpieza) => {
    if (limpieza){
        console.log("Proceso de Limpieza activado");
        datosSerial = `${limpieza}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            datosSerial = "";
        });
    }
});

onEvent("Recipiente", (confirmadoRecipiente) => {
    if (confirmadoRecipiente){
        console.log("Recipiente colocado");
        datosSerial = `${confirmadoRecipiente}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            datosSerial = "";
        });
    }
});

onEvent("Agua", (confirmadoAgua) => {
    if (confirmadoAgua){
        console.log("Agua colocada");
        datosSerial = `${confirmadoAgua}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            datosSerial = "";
        });
    }
});

onEvent("EmpezarRecarga", (Recarga) => {
    if (Recarga){
        console.log("Proceso de Recarga activado");
        datosSerial = `${Recarga}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            datosSerial = "";
        });
    }
});

onEvent("vasoRecarga", (colocarVaso) => {
    if (colocarVaso){
        console.log("Vaso para el concentrado Confirmado");
        datosSerial = `${colocarVaso}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            datosSerial = "";
        });
    }
});

onEvent("vasoConcentrado", (colocarPolvo) => {
    if (colocarPolvo){
        console.log("Polvo Confirmado");
        datosSerial = `${colocarPolvo}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            datosSerial = "";
        });
    }
});

onEvent("recipienteRevolver", (RecipienteRevolver) => {
    if (RecipienteRevolver){
        console.log("Recipiente Revuelto");
        datosSerial = `${RecipienteRevolver}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            datosSerial = "";
        });
    }
});

onEvent("RecargaFinal", (RecargaFinal) => {
    if (RecargaFinal){
        console.log("Recarga Final");
        datosSerial = `${RecargaFinal}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
            datosSerial = "";
        });
    }
});

startServer();